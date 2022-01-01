#include <time.h>
#include <stdlib.h>

void randomizer(int **tipps, int total_tipps, int XX, int YY){

    srand(time(NULL));    
    

    for(int i = 0; i < total_tipps; i++){

        for(int j = 0; j < XX;){

            int x, rand_num = rand()%YY + 1;

            for(x = 0; x < j; x++){

                if(*(tipps[i] + x)==rand_num)break;
            }

            if(x==j)*(tipps[i] + j++) = rand_num;
        }
    }
}
