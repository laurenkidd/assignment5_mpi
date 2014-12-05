#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

//set size of string to pass around 
#define SIZE_STR 4

int main(int argc, char *argv[]){

  int rank, size;  
  
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Status status;
 
  char* message = "Tag"; 
  //int SIZE_STR =  
  //get random staring int
  srand(time(NULL));
  //int start = rand() % size;
  int start = 0;

 
  if (0 == rank){
    int tag = rank;
    MPI_Send(message, SIZE_STR, MPI_CHAR, start, tag, MPI_COMM_WORLD);
    printf("%d to %d : message", tag, start);
  }
  if (start == rank){
   int tag = rank ;
   MPI_Recv(message, SIZE_STR, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status);
  }
  //int sender = start;
 // for (int dest = 0; dest <size; dest++){
    // int next_dest = (sender+1) % size;
   //  MPI_Send(message, SIZE_STR, MPI_CHAR, next_dest, sender, MPI_COMM_WORLD);
    //Barrier makes sure all sends have run before it lets the code continue.
    // MPI_Barrier(MPI_COMM_WORLD);
    // MPI_Recv(message, SIZE_STR, MPI_CHAR, sender, next_dest, MPI_COMM_WORLD, &status);
    // MPI_Recv(message, SIZE_STR, MPI_CHAR, sender, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
    // printf("%d to %d : tag you're it\n", sender, next_dest);
    
  MPI_Finalize();
  return 0;
}
