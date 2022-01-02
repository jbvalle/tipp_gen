/**
 *@file insertionsort.c
 *
 *This module sorts randomized numbers in an increasing order.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *@param[in] tipps Generated Tipps to be sorted
 *@param[in] total_tipps total tipps to be sorted
 *@param[in] XX total numbers per tipp to be sorted
 */
void insertionsort(int **tipps, int total_tipps, int XX){

    for(int index = 0; index < total_tipps; index++){

        for(int i = 1; i < XX; i++){

            int j, temp = *(tipps[index] + i);

            for(j = i - 1; (j >= 0) && (*(tipps[index] + j) > temp); j--){

                *(tipps[index] + j + 1) = *(tipps[index] + j);
            }
            
            *(tipps[index] + j + 1) = temp;
        }
    }
}
