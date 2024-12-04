# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
DEBUG_FLAGS = -g
TARGET = mtest
SRC = mallocs.c

# Default target
all: $(TARGET)

# Build the target
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Debug build
debug: $(SRC)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $(TARGET) $(SRC)

# Clean up
clean:
	rm -f $(TARGET)

