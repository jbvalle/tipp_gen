#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/free_tipps.h"
#include "../include/randomizer.h"

#define RED "\033[0;33m"
#define YELLOW "\033[0;93m"
#define RESET "\033[0m"


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
void print_tipps(int **tipps, int total_tipps, int XX){

    FILE *file = fopen("tippgen.txt","w+");

    if(file==NULL){
       
        fprintf(stderr,RED);
        fprintf(stderr,"\nERROR: GENERATING OUTPUT FILE");
        fprintf(stderr,RESET);
        exit(1);
    }

    fprintf(file, "\n");
    for(int i = 0; i < total_tipps; i++){

        fprintf(file,"       \t");
        for(int k = 0; k < XX; k++)fprintf(file," +----+ ");
        fprintf(file,"\n");

        fprintf(file,"%02d. tip\t", i + 1);
        for(int j = 0; j < XX; j++){

            fprintf(file," | %3d| ", *(tipps[i] + j));
        }
        fprintf(file,"\n");
    }

    fprintf(file,"       \t");
    for(int k = 0; k < XX; k++)fprintf(file," +----+ ");
    fprintf(file,"\n\n\n");

    fclose(file);
}

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

int main(int argc, char **argv){

    int XX, YY, total_tipps = strtol(argv[1],NULL,10);
    (void)argc;

    sscanf(argv[2],"%doutof%d", &XX, &YY);

    int **tipps = (int **)malloc(total_tipps * sizeof(int*));
    
    for(int i = 0; i < total_tipps; i++){

        *(tipps + i) = (int *)malloc(XX * sizeof(int));
    }


    randomizer(tipps, total_tipps, XX, YY);

    insertionsort(tipps, total_tipps, XX);

    show_tipps(tipps, total_tipps, XX);

    print_tipps(tipps, total_tipps, XX);

    free_tipps(tipps, total_tipps);

    return 0;
}
