CC=gcc
CFLAGS=-I. -Wall
DEP = kmeans.h
OBJ = kmeans.o points.o clusters.o

%.o : %.c $(DEP)
	$(CC) -c -o $@ $< $(CFLAGS) 

kmeans: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 

