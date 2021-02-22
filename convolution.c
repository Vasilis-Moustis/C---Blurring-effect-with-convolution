#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main(){


    int matrix[128][128];
    for (int i = 0; i <128; i++)
    {
        for (int j = 0; j < 128; j++)
        {
            matrix[i][j] = rand() % 256;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int customArray[3][3];
    customArray[0][0] = -1;
    customArray[0][1] = -1;
    customArray[0][2] = -1;
    customArray[1][0] = -1;
    customArray[1][1] = 9;
    customArray[1][2] = -1;
    customArray[2][0] = -1;
    customArray[2][1] = -1;
    customArray[2][2] = -1;

    int upper, same, down;

    for (int i = 1; i <127; i++)
    {
        for (int j = 1; j < 127; j++)
        {
            upper = (matrix[i-1][j-1] * customArray[0][0]) + (matrix[i-1][j] * customArray[0][1]) + (matrix[i-1][j+1] * customArray[0][2]);
            same = (matrix[i][j-1] * customArray[1][0]) + (matrix[i][j] * customArray[1][1]) + (matrix[i][j+1] * customArray[1][2]);
            down = (matrix[i+1][j-1] * customArray[2][0]) + (matrix[i+1][j] * customArray[2][1]) + (matrix[i+1][j+1] * customArray[2][2]);
            matrix[i][j] = upper + same + down;
            matrix[i][j] = matrix[i][j] % 256;
        }
    }

    printf("\n\n");
    for (int i = 0; i <128; i++)
    {
        for (int j = 0; j < 128; j++)
        {
            matrix[i][j] = rand() % 256;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 1;

}
