#include <stdlib.h>

void free_tipps(int **tipps, int total_tipps){

    for(int i = 0; i < total_tipps; i++){

        free(tipps[i]);
    }
    free(tipps);
}
