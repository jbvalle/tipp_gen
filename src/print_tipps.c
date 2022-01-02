/**
 *@file print_tipps.c
 *
 * Prints all tipps to an output textfile
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
 *@param[in] tipps Generated Tipps to be printed
 *@param[in] total_tipps total tipps to be printed
 *@param[in] Total numbers per tipp to be printed
 */
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
