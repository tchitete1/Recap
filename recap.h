#include <stdio.h>
#include <stdlib.h>

/* FUNCTION PROTOTYPES */

void recoverImages(FILE *diskImage);

/* MACRO CONSTANTS */

#define BYTE_SIZE 1
#define BYTE_COUNT 512
#define CARD_BLOCK_SIZE 512
#define FILENAME_LENGTH 8

/* TYPE DEFINITIONS */

typedef uint8_t BYTE;
