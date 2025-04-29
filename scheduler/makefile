# Makefile for CPU Scheduling Algorithms

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude

# Directories
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin
LOGDIR = logs

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

# Executable
TARGET = $(BINDIR)/cpu_scheduling

# Default target (build and create directories)
all: $(TARGET) | $(LOGDIR)

# Link object files to create executable
$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@

# Compile source files to object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create required directories
$(BINDIR) $(OBJDIR) $(LOGDIR):
	mkdir -p $@

# Run the program (ensures logs directory exists)
run: all
	@if [ ! -d "$(LOGDIR)" ]; then mkdir -p $(LOGDIR); fi
	./$(TARGET)

# Clean build artifacts and logs
clean:
	rm -rf $(OBJDIR) $(BINDIR) $(LOGDIR)
	
# Phony targets
# .PHONY: all clean run