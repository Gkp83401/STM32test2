#include "fileSystem.h"

int toNewFileInode;

char fileGather[MAX_FILE_NUMBER][MAX_FILE_CAPACITY];

file fileIndex[MAX_FILE_NUMBER];

void fileSystemInit()
{
    int i;
    for (i = 0; i < MAX_FILE_CAPACITY; i++) {
        fileIndex[i].isExist = IS_NOT_EXIST;
    }
}
