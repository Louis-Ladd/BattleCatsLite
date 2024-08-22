# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wno-unused-variable -g `sdl2-config --cflags`

# Linker flags
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf

# Source files
SRCS = ./src/*.c

# Output executable
TARGET = ./build/game 

# Rules
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS) 

clean:
	rm -f $(TARGET)
