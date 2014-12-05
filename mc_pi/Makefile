C = mpicc
CFLAGS = -g -lm -Wall -std=c99
OBJECTS = mc_pi_mpi.o
all : $(OBJECTS)
        $(CC) $(CFLAGS) $(OBJECTS) -o mc_pi_mpi


mc_pi_mpi: mc_pi_mpi.c
        $(CC) $(CFLAGS) -c mc_pi_mpi.c
