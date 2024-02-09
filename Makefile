# Folders
SRC_DIR := ./src
GAME_DIR := $(SRC_DIR)/game
GAMEOBJECT_DIR := $(SRC_DIR)/gameobject
TEXTUREMANAGER_DIR := $(SRC_DIR)/texturemanager

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(GAME_DIR)/*.cpp) $(wildcard $(TEXTUREMANAGER_DIR)/*.cpp)

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
