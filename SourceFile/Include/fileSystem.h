#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#define MAX_FILE_NUMBER     8
#define MAX_FILE_CAPACITY   300

#define IS_EXIST        1
#define IS_NOT_EXIST    0

extern int toNewFileInode;

extern char fileGather[MAX_FILE_NUMBER][MAX_FILE_CAPACITY];

typedef struct
{
    char user[20];
    int inode;
    int isExist;
} file;

#endif
