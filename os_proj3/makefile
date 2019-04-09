CC = gcc47 -Wall -Wextra -lpthread
CCO = $(CC) -o
CCC = $(CC) -c

all: os_proj3.x

os_proj3.x: os_proj3.o
	$(CCO) os_proj3.x os_proj3.o

os_proj3.o: os_proj3.c buffer.h
	$(CCC) os_proj3.c
	
clean:
	rm -f *.o *.x