# Folders
SRC_DIR           := ./src
GAME_DIR          := $(SRC_DIR)/game
MAP_DIR           := $(SRC_DIR)/map
GAMEOBJECT_DIR    := $(SRC_DIR)/gameobject
TEXTUREMANAGER_DIR := $(SRC_DIR)/texturemanager
ECS_DIR           := $(SRC_DIR)/ECS
COMPONENTS_DIR    := $(ECS_DIR)/components
TRANSFORM_DIR     := $(COMPONENTS_DIR)/transform
SPRITE_DIR        := $(COMPONENTS_DIR)/sprite

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

build:
    @echo " - Starting Build"
    @mkdir -p $(SRC_DIR)/obj
    @SECONDS=0; \
    total_files=$$(find $(SRC_DIR) -name '*.cpp' | wc -l); \
    completed_files=0; \
    progress="[..................................................]"; \
    for file in $$(find $(SRC_DIR) -name '*.cpp'); do \
        g++ -Wall -c $$file -o $(SRC_DIR)/obj/$(notdir $$file).o >/dev/null 2>&1; \
        completed_files=$$((completed_files + 1)); \
        percentage=$$((completed_files * 100 / total_files)); \
        bar_length=$$((percentage * 50 / 100)); \
        progress="["; \
        for ((i=0; i<bar_length; i++)); do progress+="="; done; \
        for ((i=bar_length; i<50; i++)); do progress+="."; done; \
        progress+="]"; \
        printf " - Building       %s %3d%%\r" "$$progress" $$percentage; \
    done; \
    g++ -Wall $(wildcard $(SRC_DIR)/obj/*.o) -o $(EXECUTABLE) $(LIBS) >/dev/null 2>&1; \
    duration=$$SECONDS; \
    echo -e "\n\n - Build completed successfully in $$duration seconds"

check:
    @echo " - Checking..."

run:
    ./$(EXECUTABLE)

clean:
    rm $(EXECUTABLE)
