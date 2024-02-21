# Folders
SRC_DIR            := ./src
GAME_DIR           := $(SRC_DIR)/game
MAP_DIR            := $(SRC_DIR)/map
GAMEOBJECT_DIR     := $(SRC_DIR)/gameobject
TEXTUREMANAGER_DIR := $(SRC_DIR)/texturemanager
ECS_DIR            := $(SRC_DIR)/ECS
COMPONENTS_DIR     := $(ECS_DIR)/components
TRANSFORM_DIR      := $(COMPONENTS_DIR)/transform
SPRITE_DIR         := $(COMPONENTS_DIR)/sprite
OBJ_DIR            := ./obj

# Source files
SRCS := \
    $(wildcard $(SRC_DIR)/*.cpp) \
    $(wildcard $(GAME_DIR)/*.cpp) \
    $(wildcard $(MAP_DIR)/*.cpp) \
    $(wildcard $(GAMEOBJECT_DIR)/*.cpp) \
    $(wildcard $(TEXTUREMANAGER_DIR)/*.cpp) \
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
	@mkdir -p $(OBJ_DIR)
	@SECONDS=0; \
	total_files=$$(find $(SRC_DIR) -name '*.cpp' | wc -l); \
	completed_files=0; \
	progress="[..................................................]"; \
	for file in $$(find $(SRC_DIR) -name '*.cpp'); do \
		g++ -Wall -c $$file -o $(OBJ_DIR)/$$(basename $$file .cpp).o >/dev/null 2>&1; \
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
	g++ -Wall $(OBJ_DIR)/*.o -o $(EXECUTABLE) $(LIBS) >/dev/null 2>&1; \
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
