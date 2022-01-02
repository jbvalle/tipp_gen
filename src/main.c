/**
 *@file main.c
 * 
 * This Project aimes to demonstrate the usage of command line parameters
 * by using argc and argv
 *
 * main.c executes modules of Tipp generator
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/free_tipps.h"
#include "../include/randomizer.h"
#include "../include/show_tipps.h"
#include "../include/print_tipps.h"
#include "../include/insertionsort.h"

#define RED "\033[0;33m"
#define YELLOW "\033[0;93m"
#define RESET "\033[0m"


int main(int argc, char **argv){

    ///1. Initialize User Input and allocate Tipp Variables
    int XX, YY, total_tipps = strtol(argv[1],NULL,10);
    (void)argc;

    sscanf(argv[2],"%doutof%d", &XX, &YY);

    int **tipps = (int **)malloc(total_tipps * sizeof(int*));
    
    for(int i = 0; i < total_tipps; i++){

        *(tipps + i) = (int *)malloc(XX * sizeof(int));
    }

    ///2. Generates unique random numbers of tipps
    randomizer(tipps, total_tipps, XX, YY); 

    ///3. Sorts random numbers for each tipp in an increasing order
    insertionsort(tipps, total_tipps, XX);

    ///4. Display Sorted Tipps 
    show_tipps(tipps, total_tipps, XX);

    ///5. Prints Sorted Tipps to output file 
    print_tipps(tipps, total_tipps, XX);

    ///6. Free allocated pointers
    free_tipps(tipps, total_tipps);

    return 0;
}
