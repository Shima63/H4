# Compiler

CC = g++

# Flags to the compiler

CFLAGS = -Wall

all: H4

H4: shima.cpp 
	$(CC) $(CFLAGS) shima.cpp -o shima

clean:
	rm -rf H4
