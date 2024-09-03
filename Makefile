# Compiler
CC = clang

# Compiler flag
CFLAGS = -Wall -Wno-unused-variable -Wextra -Werror -g  
CFLAGS += -Ilib/SDL/include -Ilib/SDL_ttf -Ilib/SDL_image/include 

# Linker flags
LDFLAGS = -Llib/SDL/build -Llib/SDL_ttf/build -Llib/SDL_image/build -lSDL2 -lSDL2_ttf -lSDL_image -lm  

# Source files
SRCS = $(shell find src -name '*.c')  

# Output executable
TARGET = ./build/game


.PHONY: lib all 

all: lib game 

lib:
	cd lib/SDL && mkdir -p build && cd build && cmake -S .. && make 
	cd lib/SDL_ttf && mkdir -p build && cd build && cmake -S .. && make
	cd lib/SDL_image && mkdir -p build && cd build && cmake -S .. && make

game: 
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS) 

run:
	$(TARGET)

clean:
	rm -rf build/*