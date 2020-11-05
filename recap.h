#include <stdio.h>
#include <stdlib.h>

/* TYPE DEFINITIONS */

typedef uint8_t BYTE;

/* FUNCTION PROTOTYPES */

void recoverImages(FILE *diskImage);
int isImageStart(BYTE block[]);

/* MACRO CONSTANTS */

#define BYTE_SIZE 1
#define BYTE_COUNT 512
#define CARD_BLOCK_SIZE 512
#define FILENAME_LENGTH 8
