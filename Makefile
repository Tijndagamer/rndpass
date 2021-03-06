CC = gcc
VPATH = src
CFLAGS = -I include
HEADERS = $(wildcard include/*.h)
SRC = $(wildcard src/*.c)
OBJ = rndpass.o passgen.o
EXEC = rndpass

all : ll
%.o : %.c
	$(CC) -c $< -o $@ $(CFLAGS)
ll : $(OBJ) $(HEADERS)
	$(CC) -o $(EXEC) $(OBJ)

debug :
	$(CC) -o $(EXEC) $(CFLAGS) -g $(SRC)

.PHONY : clean
clean :
	-rm $(EXEC) $(OBJ)

run : ll
	./rndpass
