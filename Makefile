# Compiler
CC = clang

# Compiler flag
CFLAGS = -Wall -Wno-unused-variable -Wextra -Werror -g `sdl2-config --cflags` 

# Linker flags
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf -lSDL2_image 

# Source files
SRCS = $(shell find src -name '*.c')  

# Output executable
TARGET = ./build/game 

all: $(TARGET)

	$(TARGET): $(SRCS)
		$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS) 

run:
	make -B
	./build/game

clean:
	rm -f $(TARGET)
