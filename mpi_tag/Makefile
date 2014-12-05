C = mpicc
CFLAGS = -g -lm -Wall -std=c99
OBJECTS = mpi_tag.o
all : $(OBJECTS)
        $(CC) $(CFLAGS) $(OBJECTS) -o mpi_tag


mpi_tag: mpi_tag.c
        $(CC) $(CFLAGS) -c mpi_tag.c
