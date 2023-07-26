/*Pratical Project MP1 2018/2019*/
/*Made by Tiago Ferreira(A85392) and Eduardo Paiva(A85312)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*function that returns the numbers above block to its original positions*/
void ReturnBlock(int n, int matrix[n][n], int block){

    int a=0;
    int b=0;
    int i=0;
    int j=0;

        for(i=0; i<n; i++){ /*cycle that runs through the matrix*/

                for(j=0; j<n; j++){

                        if(matrix[i][j] == block){/*checks whether the matrix number is equal to the block*/

                            for(b=j+1; b<n; b++){

                                    if(matrix[i][b]!=-1){/*checks if the number on the matrix[i][b] is different from -1*/

                                        a = matrix[i][b]; /*store in a the number that is in position [i][b]of the matrix*/
                                        matrix[a][0] = matrix[i][b]; /*places in position [a][0] of the matrix the number in position [i][b] of the matrix*/
                                        matrix[i][b] = -1;

                                    }

                            }

                        }

                }

        }

}
/*function that returns the numbers above block2 to its original positions*/
void ReturnBlock2(int n, int matrix[n][n],int block2){

        int a=0;
        int b=0;
        int i=0;
        int j=0;

        for(i=0; i<n; i++){/*cycle that runs through the matrix*/

                for(j=0; j<n; j++){

                        if(matrix[i][j] == block2){/*checks whether the matrix number is equal to the block2*/

                            for(b=j+1; b<n; b++){

                                    if(matrix[i][b]!=-1){/*checks is the number on the matrix[i][b] is different from -1*/

                                        a= matrix[i][b]; /*store in a the number that is in position [i][b]of the matrix*/
                                        matrix[a][0]= matrix[i][b]; /*places in position [a][0] of the matrix the number in position [i][b] of the matrix*/
                                        matrix[i][b] =-1;

                                    }

                            }

                        }

                }

        }

}
/*function that places the pile that contain block on the top of block2*/
void BlockOnTopOfBlock2(int n, int matrix[n][n], int block, int block2){

        int c=0;
        int i=0;
        int j=0;
        int k=0;
        int m=0;
        int o=0;
        int l=0;

          for(i=0; i<n; i++){ /*cycle that determines the row and column of the block and saves the line in [m] and the column in [o]. does the same for block2, line[k] and column[l]*/

                for(j=0; j<n; j++){

                        if(matrix[i][j] == block){

                            m=i;
                            o=j;

                            }else if(matrix[i][j]==block2){

                                           k=i;
                                           l=j;

                            }

                    }

        }


        for(c=l; c<=n; c++){/*cycle that runs the line where the block2 is*/

                if( matrix[k][c]== -1){ /*checks is the number on the matrix[k][c] is different from -1*/

                    if(matrix[m][o] == -1){/*if the number on the matrix[m][o] is equal to -1 exit the cycle*/

                        break;

                    }

                    matrix[k][c]= matrix[m][o]; /*the position [k] [c] takes the value of position [i] [j]*/
                    matrix[m][o]=-1; /*the position [m] [o]  takes the value of -1*/
                    o++; /*increase o*/

                }

        }

}
/*Main function*/
int main(){

      char move1[5]; /*string for the first type of move*/
      char move2[5]; /*string for the second type of move*/
      int block=0; /*variable for the first block*/
      int block2=0; /*variable for the second block*/
      int n=0; /*variable that stores the number of blocks*/
	  int i=0;
      int j=0;
      int a=0;
      int b=0;
      int c=0;

      scanf("%d", &n); /*scan how many blocks*/
      int matrix[n][n]; /*matrix which contain the blocks*/

     /*fills the first position of each column of the matrix with the numbers 0 to n-1 and the rest with the number -1*/
      for(i=0; i<n; i++){

            for(j=0; j<n; j++){

                  if(j==0){

                     matrix[i][j]=i;

                  }else{

                 matrix[i][j]=-1;

                 }

           }

      }

      /*cycle to read the moves*/
      while(a!=3){ /*the cycle runs while "a" is different from 3*/

                    scanf("%s", move1); /*read the type of move*/

                    if(strcmp(move1, "quit") == 0){ /*if the movement is "quit" it leaves the cycle*/

                        break;

                        }

                    scanf("%d %s %d", &block, move2, &block2); /*read  the first number, second type of move and the second number*/

                    for(i=0; i<n; i++){ /*cycle that determines which line of the matrix is the block and block and store it in b and c */

                            for(j=0; j<n; j++){

                                    if(matrix[i][j] == block){

                                        b=i;

                                    }else if(matrix[i][j]==block2){

                                        c=i;

                                    }

                            }

                    }

                 if(block!=block2 && b!=c  ){ /*if the block is different from block2 and b is different form c*/

                    if(strcmp(move1, "move") == 0){ /*verifies that move1 is equal to "move"*/

                        if(strcmp(move2, "onto") == 0){ /*verifies that move2 is equal to "onto"*/

                            ReturnBlock(n, matrix, block); /*call the function that returns the numbers above block to its original positions*/
                            ReturnBlock2(n, matrix, block2);/*call the function that returns the numbers above block2 to its original positions*/
                            BlockOnTopOfBlock2(n, matrix, block, block2);/*call the function that places the pile that contain block on the top of block2*/

                         }else if(strcmp(move2, "over") == 0){ /*verifies that move2 is equal to "over"*/

                                    ReturnBlock(n, matrix, block);/*call the function that returns the numbers above block to its original positions*/
                                    BlockOnTopOfBlock2(n, matrix, block, block2);/*call the function that places the pile that contain block on the top of block2*/

                        }

                    }else if(strcmp(move1, "pile") == 0){ /*verifies that move1 is equal to "pile"*/

                                if(strcmp(move2, "onto") == 0){ /*verifies that move2 is equal to "onto"*/

                                    ReturnBlock2(n, matrix, block2);/*call the function that returns the numbers above block2 to its original positions*/
                                    BlockOnTopOfBlock2(n, matrix, block, block2);/*call the function that places the block on the top of block2*/

                                }else if(strcmp(move2, "over") == 0){ /*verifies that move2 is equal to "onto"*/

                                     BlockOnTopOfBlock2(n, matrix, block, block2);/*call the function that places the pile that contain block on the top of block2*/

                                }

                    }

                 }

        }

        for(i=0,a=0; i<n; i++,a++){ /*prints the final matrix*/

                printf("%d:",i);

            for(j=0; j<n; j++){

                    if(matrix[i][j] !=-1){

                            printf("%d ",matrix[i][j]);

                    }

                }

                 printf("\n");

        }

        getch();

        return 0;

}

