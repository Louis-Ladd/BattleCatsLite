# Compiler
CC = clang

# Compiler flag
CFLAGS = -Wall -Wno-unused-variable -Wextra -Werror -g `sdl2-config --cflags` 
CFLAGS += -Ilib/sdl2/include

# Linker flags
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf -lSDL2_image 

# Source files
SRCS = $(shell find src -name '*.c')  

# Output executable
TARGET = ./build/game 


run:
	make -B
	./build/game

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS) 

clean:
	rm -f $(TARGET)
