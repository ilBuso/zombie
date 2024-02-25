# Folders
SRC_DIR            		:= ./src
GAME_DIR           		:= $(SRC_DIR)/game
MAP_DIR            		:= $(SRC_DIR)/map
GAMEOBJECT_DIR     		:= $(SRC_DIR)/gameobject
TEXTUREMANAGER_DIR 		:= $(SRC_DIR)/texturemanager
COLLISION_DIR           := $(SRC_DIR)/collision
VECTOR2D_DIR            := $(SRC_DIR)/vector2d
ECS_DIR            		:= $(SRC_DIR)/ECS
COMPONENTS_DIR     		:= $(ECS_DIR)/components
TRANSFORM_DIR      		:= $(COMPONENTS_DIR)/transform
SPRITE_DIR         		:= $(COMPONENTS_DIR)/sprite
COLLIDER_DIR         	:= $(COMPONENTS_DIR)/collider
KEYBOARDCONTROLLER_DIR  := $(COMPONENTS_DIR)/keyboardcontroller
TILE_DIR         	    := $(COMPONENTS_DIR)/tile
TIME_DIR         		:= $(COMPONENTS_DIR)/time
ANIMATIONS_DIR         	:= $(COMPONENTS_DIR)/animations
OBJ_DIR            		:= ./obj

# Source files
SRCS := \
    $(wildcard $(SRC_DIR)/*.cpp) \
    $(wildcard $(GAME_DIR)/*.cpp) \
    $(wildcard $(MAP_DIR)/*.cpp) \
    $(wildcard $(GAMEOBJECT_DIR)/*.cpp) \
    $(wildcard $(TEXTUREMANAGER_DIR)/*.cpp) \
    $(wildcard $(COLLISION_DIR)/*.cpp) \
    $(wildcard $(VECTOR2D_DIR)/*.cpp) \
    $(wildcard $(ECS_DIR)/*.cpp) \
    $(wildcard $(COMPONENTS_DIR)/*.cpp) \
    $(wildcard $(TRANSFORM_DIR)/*.cpp) \
    $(wildcard $(SPRITE_DIR)/*.cpp) \
    $(wildcard $(COLLIDER_DIR)/*.cpp) \
    $(wildcard $(KEYBOARDCONTROLLER_DIR)/*.cpp) \
    $(wildcard $(TILE_DIR)/*.cpp) \
    $(wildcard $(TIME_DIR)/*.cpp) \
    $(wildcard $(ANIMATIONS_DIR)/*.cpp) \
    $(wildcard $(SPRITE_DIR)/*.cpp)

# Libraries and flags
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    LIBS := -lSDL2 -lSDL2_image
endif
ifeq ($(UNAME_S),Darwin)
    LIBS := -framework SDL2 -framework SDL2_image
endif

# Output executable
EXECUTABLE := zombie

all: check build run

build:
	@echo " - Starting Build"
	@mkdir -p $(OBJ_DIR)
	@SECONDS=0; \
	total_files=$$(find $(SRC_DIR) -name '*.cpp' | wc -l); \
	completed_files=0; \
	progress="[..................................................]"; \
	for file in $$(find $(SRC_DIR) -name '*.cpp'); do \
		g++ -Wall -c $$file -o $(OBJ_DIR)/$$(basename $$file .cpp).o; \
		if [ $$? -ne 0 ]; then \
			echo "Error building $$file"; \
			exit 1; \
		fi; \
		completed_files=$$(($$completed_files + 1)); \
		percentage=$$(($$completed_files * 100 / $$total_files)); \
		bar_length=$$(($$percentage * 50 / 100)); \
		progress="["; \
		i=0; \
		while [ $$i -lt $$bar_length ]; do \
			progress="$${progress}="; \
			i=$$((i + 1)); \
		done; \
		i=$$bar_length; \
		while [ $$i -lt 50 ]; do \
			progress="$${progress}."; \
			i=$$((i + 1)); \
		done; \
		progress="$${progress}]"; \
		printf " - Building       %s %3d%%\r" "$$progress" $$percentage; \
	done; \
	g++ -Wall $(OBJ_DIR)/*.o -o $(EXECUTABLE) $(LIBS); \
	if [ $$? -ne 0 ]; then \
		echo "Error linking objects"; \
		exit 1; \
	fi; \
	duration=$$SECONDS; \
	echo -e "\n - Build completed successfully in $$duration seconds"


check:
	@echo " - Checking Code Formatting"
	@SECONDS=0; \
	total_files=$$(echo "$(SRCS)" | wc -w); \
	completed_files=0; \
	progress="[..................................................]"; \
	for file in $(SRCS); do \
		clang-format --style=file -i $$file >/dev/null 2>&1; \
		if [ $$? -ne 0 ]; then \
			echo "Error formatting $$file"; \
			exit 1; \
		fi; \
		completed_files=$$(($$completed_files + 1)); \
		percentage=$$(($$completed_files * 100 / $$total_files)); \
		bar_length=$$(($$percentage * 50 / 100)); \
		progress="["; \
		i=0; \
		while [ $$i -lt $$bar_length ]; do \
			progress="$${progress}="; \
			i=$$((i + 1)); \
		done; \
		i=$$bar_length; \
		while [ $$i -lt 50 ]; do \
			progress="$${progress}."; \
			i=$$((i + 1)); \
		done; \
		progress="$${progress}]"; \
		printf " - Checking       %s %3d%%\r" "$$progress" $$percentage; \
	done; \
	duration=$$SECONDS; \
	echo -e "\n - Check completed successfully in $$duration seconds"
	
run:
	./$(EXECUTABLE)

clean:
	@echo " - Cleaning up"
	@rm -rf $(OBJ_DIR)
	@rm -f $(EXECUTABLE)
