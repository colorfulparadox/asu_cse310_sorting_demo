CC = gcc
CFLAGS = -pedantic -Wall --std=c17
SRC_DIR = src
BUILD_DIR = build
INCLUDES_DIR = includes
EXECUTABLE = program

# List of source files in the src directory
SRCS = $(wildcard $(SRC_DIR)/*.c)

# List of header files in the includes directory
INCLUDES = $(wildcard $(INCLUDES_DIR)/*.h)

# Generate object file names from source file names
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

all: $(BUILD_DIR)/$(EXECUTABLE)

$(BUILD_DIR)/$(EXECUTABLE): $(BUILD_DIR) $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -o $@ $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES)
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)