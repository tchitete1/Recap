/*
 * NAME: recap.c
 * CREATOR: Tanaka Chitete
 * PURPOSE: Recover "deleted" JPG images from a disk image
 * CREATION: 03/02/2020
 * LAST MODIFICATION: 05/11/2020
 */

/* STANDARD LIBRARY HEADER FILES */

#include <stdio.h>

/* CUSTOM HEADER FILES */

#ifndef RECAP_H
#define RECAP_H
#include "recap.h"
#endif

#ifndef BOOL_H
#define BOOL_H
#include "bool.h"
#endif

/*
 * NAME: recoverImages
 * IMPORT(S): diskImage (FILE*)
 * EXPORT(S): NONE
 * PURPOSE: Recover "deleted" JPEGs from a disk image
 * CREATION: 03/02/2020
 * LAST MODIFICATION: 05/11/2020
 */

void recoverImages(FILE *diskImage) {
    BYTE block[CARD_BLOCK_SIZE];
    char fileName[FILENAME_LENGTH];
    FILE *JPG = NULL;
    int fileNumber, foundFile;
    size_t bytesRead;

    /* Reads disk image contents and writes them to JPEGs */
    fileNumber = 0;
    foundFile = FALSE;
    bytesRead = fread(block, BYTE_SIZE, BYTE_COUNT, diskImage);
    while (bytesRead > 0) {
        /* Checks for JPEG "signature" */
        if ((block[0] == 0xff) && 
            (block[1] == 0xd8) && 
            (block[2] == 0xff) && 
            ((block[3] & 0xf0) == 0xe0)) {
            foundFile = TRUE;

            /* Checks if a file is currently open */
            if (JPG != NULL) {
                /* Closes current file as recovery is finished */
                fclose(JPG);

                /* Creates new file name for next JPEG to recover */
                fileNumber++;
                sprintf(fileName, "%03i.jpg", fileNumber);
            }
            else {
                sprintf(fileName, "%03i.jpg", fileNumber);
            }

            /* Recovers first block and closes file for later appending */
            JPG = fopen(fileName, "a");
            fwrite(block, BYTE_SIZE, bytesRead, JPG);
        }
        else {
            /* Checks if recovery should be carried out */
            if (foundFile) {
                /* Recovers next block */
                fwrite(block, BYTE_SIZE, bytesRead, JPG);
            }
        }

        /* Reads subsequent bytes */
        bytesRead = fread(block, BYTE_SIZE, BYTE_COUNT, diskImage);
    }
}
