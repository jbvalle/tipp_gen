/**
 *@file free_tipps.c
 * 
 *frees all pointers of tipps generated during runtime
 */
#include <stdlib.h>

/**
 * @param[in] tipps holds generated tipps
 * @param[in] total_tipps that was generated during runtime
 */
void free_tipps(int **tipps, int total_tipps){

    for(int i = 0; i < total_tipps; i++){

        free(tipps[i]);
    }
    free(tipps);
}
