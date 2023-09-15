CC = gcc
CFLAGS = -pedantic -Wall --std=c17
SRC_DIR = src
BUILD_DIR = build
INCLUDES_DIR = includes
EXECUTABLE = program

# List of header files in the includes directory
INCLUDES = $(wildcard $(INCLUDES_DIR)/*.h)

all: $(BUILD_DIR)/$(EXECUTABLE)

$(BUILD_DIR)/$(EXECUTABLE): $(BUILD_DIR) $(SRC_DIR)/main.c $(INCLUDES)
	$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -o $@ $(SRC_DIR)/main.c

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)