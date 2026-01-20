BUILD_DIR := build/
CMAKE_SOURCE_DIR := cmake/

# Config (Debug / Release)
BUILD_TYPE ?= Release

PURPUR_START := \033[35;m
PURPUR_END := \033[0m

.PHONY: all build example clean help

all: build example

build: $(BUILD_DIR)/CMakeCache.txt
	@echo -e "$(PURPUR_START)Building the project...$(PURPUR_END)"
	@cmake --build $(BUILD_DIR) --config $(BUILD_TYPE) --target todo
	@echo -e "$(PURPUR_START)The project has been successfully built!$(PURPUR_END)"

$(BUILD_DIR)/CMakeCache.txt:
	@echo -e "$(PURPUR_START)Configurate CMake with $(BUILD_TYPE) build...$(PURPUR_END)"
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && \
		cmake -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) ../$(CMAKE_SOURCE_DIR)
	@echo -e "$(PURPUR_START)The configuration is completed!$(PURPUR_END)"

example: build
	@echo -e "$(PURPUR_START)Building the example...$(PURPUR_END)"
	@cmake --build $(BUILD_DIR) --config $(BUILD_TYPE) --target example
	@echo -e "$(PURPUR_START)The example has been successfully built!$(PURPUR_END)"

clean:
	@echo -e "$(PURPUR_START)Cleaning build directory...$(PURPUR_END)"
	@rm -rf $(BUILD_DIR)
	@echo -e "$(PURPUR_START)Cleaning done!$(PURPUR_END)"

help:
	@echo -e "$(PURPUR_START)    make [all]$(PURPUR_END)"
	@echo -e "$(PURPUR_START)    make build$(PURPUR_END)"
	@echo -e "$(PURPUR_START)    make example$(PURPUR_END)"
	@echo -e "$(PURPUR_START)    make clean$(PURPUR_END)"