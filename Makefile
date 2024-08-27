# Compiler
CC = gcc

# Compiler flag
CFLAGS = -Wall -Wno-unused-variable -g `sdl2-config --cflags` 

# Linker flags
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf -lSDL2_image 

# Source files
SRCS = $(shell find src -name '*.c')  

# Output executable
TARGET = ./build/game 

# Rules
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS) 

	$(TARGET)

clean:
	rm -f $(TARGET)
