# Compiler and flags
CC := g++
CFLAGS := -std=c++11 -Wall

# Directories
SRC_DIR := src
INCLUDE_DIR := include
OBJ_DIR := obj
BIN_DIR := bin

# Source files
SRCS := $(wildcard $(SRC_DIR)/**/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
TARGET := $(BIN_DIR)/register.x

# Rule to compile .cpp files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

# Rule to link object files into the executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

# Rule to create the object and binary directories
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Default rule
all: create_dir $(TARGET)

# Rule to create the object directory
create_dir:
	mkdir -p $(OBJ_DIR)

# Clean rule
clean:
	rm -f $(TARGET)
	rm -rf $(OBJ_DIR)

.PHONY: all clean create_dir
