SRC_DIR := ./src
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
CFLAGS := -Wall -Wextra -pedantic -g
BUILD_DIR := ./build

$(BUILD_DIR)/linked_list:
	@mkdir -p $(@D)
	clang $(CFLAGS) -o $@ $(SRC_FILES)