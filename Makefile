# Folders
SRC_DIR            		:= ./src
GAME_DIR           		:= $(SRC_DIR)/game
MAP_DIR            		:= $(SRC_DIR)/map
GAMEOBJECT_DIR     		:= $(SRC_DIR)/gameobject
TEXTUREMANAGER_DIR 		:= $(SRC_DIR)/texturemanager
COLLISION_DIR           := $(SRC_DIR)/collision
VECTOR2D_DIR            := $(SRC_DIR)/vector2d
ASSETMANAGER_DIR        := $(SRC_DIR)/assetmanager
ECS_DIR            		:= $(SRC_DIR)/ECS
COMPONENTS_DIR     		:= $(ECS_DIR)/components
TRANSFORM_DIR      		:= $(COMPONENTS_DIR)/transform
SPRITE_DIR         		:= $(COMPONENTS_DIR)/sprite
COLLIDER_DIR         	:= $(COMPONENTS_DIR)/collider
KEYBOARDCONTROLLER_DIR  := $(COMPONENTS_DIR)/keyboardcontroller
TILE_DIR         	    := $(COMPONENTS_DIR)/tile
TIME_DIR         		:= $(COMPONENTS_DIR)/time
ANIMATION_DIR         	:= $(COMPONENTS_DIR)/animation
UI_DIR					:= $(COMPONENTS_DIR)/UI
LABEL_DIR				:= $(UI_DIR)/label
APP_DIR		         	:= ./app
WORLD_DIR		        := $(APP_DIR)/world
PLAYER_DIR		        := $(APP_DIR)/player
OBJ_DIR            		:= ./obj

# Directories
SRC_DIRS := \
    $(SRC_DIR) \
    $(GAME_DIR) \
    $(MAP_DIR) \
    $(GAMEOBJECT_DIR) \
    $(TEXTUREMANAGER_DIR) \
    $(COLLISION_DIR) \
    $(VECTOR2D_DIR) \
    $(ASSETMANAGER_DIR) \
    $(ECS_DIR) \
    $(COMPONENTS_DIR) \
    $(TRANSFORM_DIR) \
    $(SPRITE_DIR) \
    $(COLLIDER_DIR) \
    $(KEYBOARDCONTROLLER_DIR) \
    $(TILE_DIR) \
    $(TIME_DIR) \
    $(ANIMATION_DIR) \
	$(LABEL_DIR) \
    $(APP_DIR) \
	$(WORLD_DIR) \
	$(PLAYER_DIR)

# Source files
SRCS := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))
HDRS := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.hpp))
OBJS := $(foreach dir,$(OBJ_DIR),$(wildcard $(dir)/*.o))
DEPS := $(OBJS:.o=.d)

# Include dependency files
-include $(DEPS)

# Compiler, Flags, Libraries
CXX := g++
CXXFLAGS := -Wall -Wextra -MMD -MP
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    LIBS := -lSDL2 -lSDL2_image -lSDL2_ttf
endif
ifeq ($(UNAME_S),Darwin)
    LIBS := -framework SDL2 -framework SDL2_image -framework SDL_ttf
endif

# Output executable
EXECUTABLE := zombie

# Valgrind options
VALGRIND_OPTIONS := --leak-check=full --show-leak-kinds=all

all: clean format build link run

clean:
	@echo "Cleaning"
	@rm -rf $(OBJ_DIR)
	@rm -f $(EXECUTABLE)

format:
	@echo "Formatting"
	@for file in $(SRCS) $(HDRS); do \
		clang-format --style=file -i $$file; \
		if [ $$? -ne 0 ]; then \
			echo "ERROR formatting $$file"; \
			exit 1; \
		fi; \
	done; \

build:
	@echo "Building"
	@mkdir -p $(OBJ_DIR)
	@for file in $(SRCS); do \
		filename=$$(basename $$file .cpp); \
		mkdir -p $(OBJ_DIR)/$$filename; \
		$(CXX) $(CXXFLAGS) -c $$file -o $(OBJ_DIR)/$$filename/$$filename.o; \
		if [ $$? -ne 0 ]; then \
			echo "ERROR building $$file"; \
			exit 1; \
		fi; \
	done

link: 
	@echo "Linking"
	@$(CXX) $(CXXFLAGS) $(wildcard $(OBJ_DIR)/**/*.o) -o $(EXECUTABLE) $(LIBS);
	@if [ $$? -ne 0 ]; then \
		echo "ERROR during linking"; \
		exit 1; \
	fi;
	
run:
	@echo "Running"
	./$(EXECUTABLE)

valgrind:
	@echo "Running Valgrind..."
	@valgrind $(VALGRIND_OPTIONS) ./$(EXECUTABLE)