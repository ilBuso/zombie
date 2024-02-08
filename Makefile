# Folders
SRC_DIR := ./src
GAME_DIR := $(SRC_DIR)/game
GAMEOBJECT_DIR := $(SRC_DIR)/gameobject

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(GAME_DIR)/*.cpp)

# Libraries
LIBS := -lSDL2 -lstdc++

# Output executable
EXECUTABLE := zombie

build:
	g++ -Wall $(SRCS) $(LIBS) -o $(EXECUTABLE)

run:
	./$(EXECUTABLE)

clean:
	rm $(EXECUTABLE)
