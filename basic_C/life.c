#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void life (char ** input, int n, int m) {
/*
 Initialization and passing parameters 
*/
  char command[] = "o";
  int nrows = n;
  int ncolumns = m;
  char ** array = input;
/*
  0 : originally alive --> still alive
  X : originally alive --> now dead
    : originally dead  --> still dead
  R : origianlly dead  --> now alive 
*/
  int i, j;
  int alive_count = 0;
  while (*command != 'q') {
      for (i = 0; i < nrows; i = i + 1) {
         for (j = 0; j < ncolumns; j = j + 1) {
/*
   calculate alive count
 */
            //1
            if (i - 1 >= 0    && j - 1 >= 0) {
               if (array[i-1][j-1] == '0' || array[i-1][j-1] == 'X') {
                  alive_count = alive_count + 1;
               }        
            }

            //2
            if (i - 1 >= 0) {
               if (array[i-1][j] == '0' || array[i-1][j] == 'X') {
                  alive_count = alive_count + 1;
               }        
            }
            //3
            if (i - 1 >= 0    && j + 1 < ncolumns) {
               if (array[i-1][j+1] == '0' || array[i-1][j+1] == 'X') {
                  alive_count = alive_count + 1;
               }        
            }
            //4
            if (                 j - 1 >= 0) {
               if (array[i][j-1] == '0' || array[i][j-1] == 'X') {
                  alive_count = alive_count + 1;
               }        
            }
            //6
            if (                 j + 1 < ncolumns) {
               if (array[i][j+1] == '0' || array[i][j+1] == 'X') {
                  alive_count = alive_count + 1;
               }        
            }
            //7
            if (i + 1 < nrows && j - 1 >= 0) {
               if (array[i+1][j-1] == '0' || array[i+1][j-1] == 'X') {
                  alive_count = alive_count + 1;
               }        
            }
            //8
            if (i + 1 < nrows) {
               if (array[i+1][j] == '0' || array[i+1][j] == 'X') {
                  alive_count = alive_count + 1;
               }        
            }
            //9
            if (i + 1 < nrows && j + 1 < ncolumns) {
               if (array[i+1][j+1] == '0' || array[i+1][j+1] == 'X') {
                  alive_count = alive_count + 1;
               }        
            }
  //          printf ("%d \n", alive_count);
/*
 * Determine based on alive count
*/
            if (alive_count > 1 && alive_count < 4) {
               if (array[i][j] == ' ') {
                  array[i][j] = 'R';
               }
            }
            else {
               if (array[i][j] == '0') {
                  array[i][j] = 'X';
               }
            }
            alive_count = 0;
         }
      }
     

/*
  Really Updating 
*/
      for (i = 0; i < nrows; i = i + 1) {
         for (j = 0; j < ncolumns; j = j + 1) {
            if (array[i][j] == '0' || array[i][j] == 'R') {
               array[i][j] = '0';
            }
            else {
               array[i][j] = ' ';
            }
         }
      }
 
/*
 Printing stuff
*/
      printf ("next phase \n");
      for (i = 0; i < nrows; i = i + 1) {
         for (j = 0; j < ncolumns; j = j + 1) {
            printf("%c", array[i][j]);
         }
         printf("\n");
      }
/*
 Ask for next Step
*/

      printf ("Press <Enter> to continue or type q to exit \n");
      *command = getchar();
  }


}


int main () {

/*
 Setting Parameter
*/
   int nrows = 4;
   int ncolumns = 4;

/*
 Allocate Memory
*/
   char ** array = NULL;
   array =  malloc (nrows*sizeof(char*));
   int i, j;
   for (i = 0; i < nrows; i = i + 1){
      array[i] =  malloc (ncolumns*sizeof(char));
   }  

/*
  Initialization step 1 : every one is dead 
*/
   for (i = 0; i < nrows; i = i + 1) {
      for (j = 0; j < ncolumns; j = j + 1) {
         array[i][j] = ' ';
      }
   }
/*
  Initialization step 2 : 
  User define
  pick positions that are alive
  change however the user want
*/
  array[0][2] = '0';

  array[1][1] = '0';
  array[1][3] = '0';
  
  array[2][0] = '0';
  
  array[3][1] = '0';

/*
  Check Current Array 
*/
   int input_wrong = 0;

   for (i = 0; i < nrows; i = i + 1) {
      for (j = 0; j < ncolumns; j = j + 1) {
        if (array[i][j] != '0' && array[i][j] != ' ') {
           input_wrong = 1;
        } 
      }
   }
 
/*
  Print Current Array 
*/

   printf("Initial Array \n"); 

   for (i = 0; i < nrows; i = i + 1) {
      for (j = 0; j < ncolumns; j = j + 1) {
         printf("%c", array[i][j]);
      }
      printf("\n");
   }

/*
  Running Function 
*/
   if (input_wrong == 0) {
      life (array, nrows, ncolumns);
   }
   else {
      printf ("Input is Wrong \n");
   }

/*
  Free up Memory
*/

   for (i = 0; i < nrows; i = i + 1){
      free(array[i]); 
   }  

   free(array);
   return 0;

}
