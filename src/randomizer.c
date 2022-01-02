/**
 *@file randomizer.c
 *
 * Randomizer() generates unique numbers for tipps
 */
#include <time.h>
#include <stdlib.h>


/**
@param[in] tipps holds elements of randomized tipp numbers
@param[in] total_tipps total tipps to be generated
@param[in] XX Total numbers of per tipp
@param[in] YY Max Value of tipp numbers
*/
void randomizer(int **tipps, int total_tipps, int XX, int YY){

    ///1. Plant Rand using current time
    srand(time(NULL));    
    
    ///2. Increment through total tipps
    for(int i = 0; i < total_tipps; i++){

        ///3. Increment though individual element of tipp
        for(int j = 0; j < XX;){

            ///4. Generate Random number
            int x, rand_num = rand()%YY + 1;

            ///5. Check for previous matching number
            for(x = 0; x < j; x++){

                if(*(tipps[i] + x)==rand_num)break;
            }

            ///6. if no matches found, then assign new Randomnumber to tipp element
            if(x==j)*(tipps[i] + j++) = rand_num;
        }
    }
}
