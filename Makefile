CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -g
MAIN = tree_tests
OBJS = tree_tests.o tree.o

all : $(MAIN)

$(MAIN) : $(OBJS) tree.h
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

array_list_tests.o : tree_tests.c tree.h
	$(CC) $(CFLAGS) -c tree_tests.c

array_list.o : tree.c tree.h
	$(CC) $(CFLAGS) -c tree.c

clean :
	rm *.o $(MAIN) core
