SRC_DIR := ./src
CFLAGS := -Wall -Wextra -pedantic -ggdb
BUILD_DIR := ./build

$(BUILD_DIR)/linked_list:
	@mkdir -p $(@D)
	clang $(CFLAGS) -o $@ $(SRC_DIR)/linked_list.c