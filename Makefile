CXX = g++
CXXFLAGS = -Wall -g

ENGINE_SOURCE_DIR = Engine
ENGINE_OBJ_DIR = Engine_obj
ENGINE_SOURCES = $(shell find $(ENGINE_SOURCE_DIR) -name '*.cpp')
ENGINE_OBJECTS = $(patsubst $(ENGINE_SOURCE_DIR)/%.cpp,$(ENGINE_OBJ_DIR)/%.o,$(ENGINE_SOURCES))
ENGINE_FLAGS = -fPIC -shared
ENGINE_INCL = -ILib
ENGINE_CXXFLAGS = $(CXXFLAGS) -fPIC

EDITOR_SOURCE_DIR = Editor
EDITOR_OBJ_DIR = Editor_obj
EDITOR_SOURCES = $(shell find $(EDITOR_SOURCE_DIR) -name '*.cpp')
EDITOR_OBJECTS = $(patsubst $(EDITOR_SOURCE_DIR)/%.cpp,$(EDITOR_OBJ_DIR)/%.o,$(EDITOR_SOURCES))
EDITOR_FLAGS = 
EDITOR_INCL = -ILib -ILib/Imgui -I$(ENGINE_SOURCE_DIR)

GAME_SOURCE_DIR = Game
GAME_OBJ_DIR = Game_obj
GAME_SOURCES = $(shell find $(GAME_SOURCE_DIR) -name '*.cpp')
GAME_OBJECTS = $(patsubst $(GAME_SOURCE_DIR)/%.cpp,$(GAME_OBJ_DIR)/%.o,$(GAME_SOURCES))
GAME_FLAGS = 
GAME_INCL = -I$(ENGINE_SOURCE_DIR) -ILib

ALL_INCL = 
ALL_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lGL

ENGINE_SO = Engine_output/libEngine.so
EDITOR_EXE = Editor_output/Editor
GAME_EXE = Game_output/Game

.PHONY: all clean

all: engine editor game

engine: $(ENGINE_SO)

$(ENGINE_SO): $(ENGINE_OBJECTS)
	@echo "Linking ENGINE objects to create shared library: $@"
	$(CXX) $(ENGINE_CXXFLAGS) $(ENGINE_FLAGS) -o $@ $^ $(ALL_FLAGS)

$(ENGINE_OBJ_DIR)/%.o: $(ENGINE_SOURCE_DIR)/%.cpp
	@echo "Compiling ENGINE source: $<"
	@mkdir -p $(dir $@)
	$(CXX) $(ENGINE_CXXFLAGS) -MMD -MP -c $< -o $@ $(ENGINE_INCL)

editor: $(EDITOR_EXE)

$(EDITOR_EXE): $(EDITOR_OBJECTS) $(ENGINE_SO)
	@echo "Linking EDITOR objects to create executable: $@"
	$(CXX) $(CXXFLAGS) $(EDITOR_FLAGS) -o $@ $^ -L$(dir $(ENGINE_SO)) -lEngine $(ALL_FLAGS)

$(EDITOR_OBJ_DIR)/%.o: $(EDITOR_SOURCE_DIR)/%.cpp
	@echo "Compiling EDITOR source: $<"
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@ $(EDITOR_INCL)

game: $(GAME_EXE)

$(GAME_EXE): $(GAME_OBJECTS) $(ENGINE_SO)
	@echo "Linking GAME objects to create executable: $@"
	$(CXX) $(CXXFLAGS) $(GAME_FLAGS) -o $@ $^ -L$(dir $(ENGINE_SO)) -lEngine $(ALL_FLAGS)

$(GAME_OBJ_DIR)/%.o: $(GAME_SOURCE_DIR)/%.cpp
	@echo "Compiling GAME source: $<"
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@ $(GAME_INCL)

clean:
	rm -rf $(ENGINE_OBJ_DIR) $(EDITOR_OBJ_DIR) $(GAME_OBJ_DIR) $(ENGINE_SO) $(EDITOR_EXE) $(GAME_EXE)

