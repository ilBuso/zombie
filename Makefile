# Folders
SRC_DIR          	:= ./src
GAME_DIR         	:= $(SRC_DIR)/game
MAP_DIR          	:= $(SRC_DIR)/map
GAMEOBJECT_DIR   	:= $(SRC_DIR)/gameobject
TEXTUREMANAGER_DIR 	:= $(SRC_DIR)/texturemanager
ECS_DIR          	:= $(SRC_DIR)/ECS
COMPONENTS_DIR   	:= $(ECS_DIR)/components
TRANSFORM_DIR    	:= $(COMPONENTS_DIR)/transform
SPRITE_DIR       	:= $(COMPONENTS_DIR)/sprite

# Source files
SRCS := \
	$(wildcard $(SRC_DIR)/*.cpp) \
	$(wildcard $(GAME_DIR)/*.cpp) \
	$(wildcard $(MAP_DIR)/*.cpp) \
	$(wildcard $(TEXTUREMANAGER_DIR)/*.cpp) \
	$(wildcard $(GAMEOBJECT_DIR)/*.cpp) \
	$(wildcard $(ECS_DIR)/*.cpp) \
	$(wildcard $(COMPONENTS_DIR)/*.cpp) \
	$(wildcard $(TRANSFORM_DIR)/*.cpp) \
	$(wildcard $(SPRITE_DIR)/*.cpp)

# Libraries
LIBS := -lSDL2 -lSDL2_image

# Output executable
EXECUTABLE := zombie

build:
	@echo "Building..."
	@/bin/zsh -c 'SECONDS=0; g++ -Wall $(SRCS) $(LIBS) -o $(EXECUTABLE) >/dev/null 2>&1; echo "Build completed in $$SECONDS seconds"'

run:
	./$(EXECUTABLE)

clean:
	rm $(EXECUTABLE)
