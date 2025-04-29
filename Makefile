# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Directories
SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SOURCES = main.c shell/shell.c modules/intro_modules.c modules/custom_ui_modules.c utilities/utilities.c

# Object files
OBJECTS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SOURCES))

# Executable
EXEC = $(BIN_DIR)/main

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJECTS) -o $(EXEC)

# Compile source files to object files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJECTS) $(EXEC)
