/**
 *@file show_tipps.c 
 *Display sorted tipps to STDOUT
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define RED "\033[0;33m"
#define YELLOW "\033[0;93m"
#define RESET "\033[0m"

/**
 * @param[in] tipps Generated Tipps to be sorted
 * @param[in] total_tipps total tipps to be sorted
 * @param[in] XX total numbers per tipp to be sorted
 */
void show_tipps(int **tipps, int total_tipps, int XX){

    printf("\n\n");
    for(int i = 0; i < total_tipps; i++){

        printf("       \t");
        for(int k = 0; k < XX; k++)printf(" +----+ ");
        printf("\n");

        printf("%02d. tip\t", i + 1);
        for(int j = 0; j < XX; j++){
            
            printf(" | ");printf(YELLOW);
            printf("%3d", *(tipps[i] + j));printf(RESET);
            printf("| ");
        }
        printf("\n");
    }

    printf("       \t");
    for(int k = 0; k < XX; k++)printf(" +----+ ");
    printf("\n\n\n");
}
