# Folders
SRC_DIR := ./src
GAME_DIR := $(SRC_DIR)/game
MAP_DIR := $(SRC_DIR)/map
GAMEOBJECT_DIR := $(SRC_DIR)/gameobject
TEXTUREMANAGER_DIR := $(SRC_DIR)/texturemanager

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(GAME_DIR)/*.cpp) $(wildcard $(MAP_DIR)/*.cpp) $(wildcard $(TEXTUREMANAGER_DIR)/*.cpp) $(wildcard $(GAMEOBJECT_DIR)/*.cpp)

# Libraries
LIBS := -lSDL2 -lSDL2_image -lstdc++

# Output executable
EXECUTABLE := zombie

build:
	g++ -Wall $(SRCS) $(LIBS) -o $(EXECUTABLE)

run:
	./$(EXECUTABLE)

clean:
	rm $(EXECUTABLE)
