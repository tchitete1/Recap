/*
 * NAME: main.c
 * CREATOR: Tanaka Chitete
 * PURPOSE: Act as the entry point for recap.c
 * CREATION: 03/02/2020
 * LAST MODIFICATION: 05/11/2020
 */

#include <stdio.h>
#include <stdint.h>

#ifndef RECAP_H
#define RECAP_H
#include "recap.h"
#endif

/*
 * NAME: main
 * IMPORT(S): argc (int), argv[] (char*)
 * EXPORT(S): (int)
 * PURPOSE: Act as the entry point for recoverImages
 * CREATION: 03/02/2020
 * LAST MODIFICATION: 05/11/2020
 */

int main(int argc, char *argv[]) {
    int exitStatus;

    FILE *diskImage = NULL;
    
    /* Checks if user has provided correct number of CL arguments */
    if (argc != 2) {
        perror("Usage: ./recap <disk image>.raw");
        exitStatus = 1;
    }

    /* Attempts to open disk image */
    diskImage = fopen(argv[1], "r");
    if (diskImage == NULL) {
        perror("Error: cannot open file");
        exitStatus = 1;
    }

    /* Recovers "deleted" JPG images */
    if (argc == 2 && diskImage != NULL) {
        recoverImages(diskImage);
        exitStatus = 0;
    }
    
    return exitStatus;
}
