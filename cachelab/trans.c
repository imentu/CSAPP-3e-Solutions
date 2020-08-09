/*
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/*
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded.
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, ii, jj, iie, jje, b2, b3, b4, b5, b6, b7;
    if (M == 32)
    {
        for (i = 0; i < M; i += 8)
        {
            for (j = 0; j < N; j += 8)
            {
                if (i != j) {

                    iie = i + 8;
                    jje = j + 8;
                    for (ii = i; ii < iie; ii++)
                    {
                        for (jj = j; jj < jje; jj++)
                        {
                            B[jj][ii] = A[ii][jj];
                        }
                    }
                }
                else {
                    //=======1
                    iie = A[i][j];
                    jje = A[i][j + 1];
                    b2 = A[i][j + 2];
                    b3 = A[i][j + 3];
                    b4 = A[i][j + 4];
                    b5 = A[i][j + 5];
                    b6 = A[i][j + 6];
                    b7 = A[i][j + 7];
                    B[j][i] = iie;
                    B[j + 1][i] = jje;
                    B[j + 2][i] = b2;
                    B[j + 3][i] = b3;
                    B[j + 4][i] = b4;
                    B[j + 5][i] = b5;
                    B[j + 6][i] = b6;
                    B[j + 7][i] = b7;
                    //=======1
                    //=======2
                    iie = A[i + 1][j];
                    jje = A[i + 1][j + 1];
                    b2 = A[i + 1][j + 2];
                    b3 = A[i + 1][j + 3];
                    b4 = A[i + 1][j + 4];
                    b5 = A[i + 1][j + 5];
                    b6 = A[i + 1][j + 6];
                    b7 = A[i + 1][j + 7];
                    B[j][i + 1] = iie;
                    B[j + 1][i + 1] = jje;
                    B[j + 2][i + 1] = b2;
                    B[j + 3][i + 1] = b3;
                    B[j + 4][i + 1] = b4;
                    B[j + 5][i + 1] = b5;
                    B[j + 6][i + 1] = b6;
                    B[j + 7][i + 1] = b7;
                    //=======2
                    //=======3
                    iie = A[i + 2][j];
                    jje = A[i + 2][j + 1];
                    b2 = A[i + 2][j + 2];
                    b3 = A[i + 2][j + 3];
                    b4 = A[i + 2][j + 4];
                    b5 = A[i + 2][j + 5];
                    b6 = A[i + 2][j + 6];
                    b7 = A[i + 2][j + 7];
                    B[j][i + 2] = iie;
                    B[j + 1][i + 2] = jje;
                    B[j + 2][i + 2] = b2;
                    B[j + 3][i + 2] = b3;
                    B[j + 4][i + 2] = b4;
                    B[j + 5][i + 2] = b5;
                    B[j + 6][i + 2] = b6;
                    B[j + 7][i + 2] = b7;
                    //=======3
                    //=======4
                    iie = A[i + 3][j];
                    jje = A[i + 3][j + 1];
                    b2 = A[i + 3][j + 2];
                    b3 = A[i + 3][j + 3];
                    b4 = A[i + 3][j + 4];
                    b5 = A[i + 3][j + 5];
                    b6 = A[i + 3][j + 6];
                    b7 = A[i + 3][j + 7];
                    B[j][i + 3] = iie;
                    B[j + 1][i + 3] = jje;
                    B[j + 2][i + 3] = b2;
                    B[j + 3][i + 3] = b3;
                    B[j + 4][i + 3] = b4;
                    B[j + 5][i + 3] = b5;
                    B[j + 6][i + 3] = b6;
                    B[j + 7][i + 3] = b7;
                    //=======4
                    //=======5
                    iie = A[i + 4][j];
                    jje = A[i + 4][j + 1];
                    b2 = A[i + 4][j + 2];
                    b3 = A[i + 4][j + 3];
                    b4 = A[i + 4][j + 4];
                    b5 = A[i + 4][j + 5];
                    b6 = A[i + 4][j + 6];
                    b7 = A[i + 4][j + 7];
                    B[j][i + 4] = iie;
                    B[j + 1][i + 4] = jje;
                    B[j + 2][i + 4] = b2;
                    B[j + 3][i + 4] = b3;
                    B[j + 4][i + 4] = b4;
                    B[j + 5][i + 4] = b5;
                    B[j + 6][i + 4] = b6;
                    B[j + 7][i + 4] = b7;
                    //=======5
                    //=======6
                    iie = A[i + 5][j];
                    jje = A[i + 5][j + 1];
                    b2 = A[i + 5][j + 2];
                    b3 = A[i + 5][j + 3];
                    b4 = A[i + 5][j + 4];
                    b5 = A[i + 5][j + 5];
                    b6 = A[i + 5][j + 6];
                    b7 = A[i + 5][j + 7];
                    B[j][i + 5] = iie;
                    B[j + 1][i + 5] = jje;
                    B[j + 2][i + 5] = b2;
                    B[j + 3][i + 5] = b3;
                    B[j + 4][i + 5] = b4;
                    B[j + 5][i + 5] = b5;
                    B[j + 6][i + 5] = b6;
                    B[j + 7][i + 5] = b7;
                    //=======6
                    //=======7
                    iie = A[i + 6][j];
                    jje = A[i + 6][j + 1];
                    b2 = A[i + 6][j + 2];
                    b3 = A[i + 6][j + 3];
                    b4 = A[i + 6][j + 4];
                    b5 = A[i + 6][j + 5];
                    b6 = A[i + 6][j + 6];
                    b7 = A[i + 6][j + 7];
                    B[j][i + 6] = iie;
                    B[j + 1][i + 6] = jje;
                    B[j + 2][i + 6] = b2;
                    B[j + 3][i + 6] = b3;
                    B[j + 4][i + 6] = b4;
                    B[j + 5][i + 6] = b5;
                    B[j + 6][i + 6] = b6;
                    B[j + 7][i + 6] = b7;
                    //=======7
                    //=======8
                    iie = A[i + 7][j];
                    jje = A[i + 7][j + 1];
                    b2 = A[i + 7][j + 2];
                    b3 = A[i + 7][j + 3];
                    b4 = A[i + 7][j + 4];
                    b5 = A[i + 7][j + 5];
                    b6 = A[i + 7][j + 6];
                    b7 = A[i + 7][j + 7];
                    B[j][i + 7] = iie;
                    B[j + 1][i + 7] = jje;
                    B[j + 2][i + 7] = b2;
                    B[j + 3][i + 7] = b3;
                    B[j + 4][i + 7] = b4;
                    B[j + 5][i + 7] = b5;
                    B[j + 6][i + 7] = b6;
                    B[j + 7][i + 7] = b7;
                    //=======8
                }
            }
        }
    }
    else if (M == 64)
    {
        for (i = 0; i < N; i += 8)
        {
            for (j = 0; j < M; j += 8)
            {
                for (ii=i;ii<i+4;ii++) {
                    iie=A[ii][j];jje=A[ii][j+1];b2=A[ii][j+2];b3=A[ii][j+3];
                    b4=A[ii][j+4];b5=A[ii][j+5];b6=A[ii][j+6];b7=A[ii][j+7];

                    B[j][ii]=iie;B[j+1][ii]=jje;B[j+2][ii]=b2;B[j+3][ii]=b3;
                    B[j][ii+4]=b4;B[j+1][ii+4]=b5;B[j+2][ii+4]=b6;B[j+3][ii+4]=b7;
                }
                for (jj=j;jj<j+4;jj++) {
                    iie=A[i+4][jj];jje=A[i+5][jj];b2=A[i+6][jj];b3=A[i+7][jj];
                    b4=B[jj][i+4];b5=B[jj][i+5];b6=B[jj][i+6];b7=B[jj][i+7];

                    B[jj][i+4]=iie;B[jj][i+5]=jje;B[jj][i+6]=b2;B[jj][i+7]=b3;
                    B[jj+4][i]=b4;B[jj+4][i+1]=b5;B[jj+4][i+2]=b6;B[jj+4][i+3]=b7;
                }
                for (ii=i+4;ii<i+8;ii++) {
                    iie=A[ii][j+4];jje=A[ii][j+5];b2=A[ii][j+6];b3=A[ii][j+7];
                    B[j+4][ii]=iie;B[j+5][ii]=jje;B[j+6][ii]=b2;B[j+7][ii]=b3;
                }
            }
        }
    }
    else if (M == 61)
    {
        for (i = 0; i < N; i += 17)
        {
            for (j = 0; j < M; j += 17)
            {
                iie = i + 17 < N ? i + 17: N;
                jje = j + 17 < M ? j + 17: M;
                for (ii = i; ii < iie; ii++)
                {
                    for (jj = j; jj < jje; jj++)
                    {
                        B[jj][ii] = A[ii][jj];
                    }
                }
            }
        }
    }
    else
    {
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                B[j][i] = A[i][j];
            }
        }
    }
}

/*
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started.
 */

 /*
  * trans - A simple baseline transpose function, not optimized for the cache.
  */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }
}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc);

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc);
}

/*
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; ++j)
        {
            if (A[i][j] != B[j][i])
            {
                return 0;
            }
        }
    }
    return 1;
}
