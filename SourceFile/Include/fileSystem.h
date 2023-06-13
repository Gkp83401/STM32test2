#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include "userSystem.h"

#define MAX_FILE_NUMBER     8
#define MAX_FILE_CAPACITY   300

#define FILE_NAME_LENGTH    20

#define IS_EXIST        1
#define IS_NOT_EXIST    0

#define FILE_SYSTEM_INIT_SUCCEED    0
#define FILE_SYSTEM_INIT_FAIL       1

// toBuildNewFile函数的状态退出码
// 文件成功创建
#define BUILD_SUCCEED       0
// 用来表示创建文件时存在文件同名
#define HAVE_SAME_NAME      1
// 以达到最大存储空间无法新建文件
#define NO_MORE_SPACE       2

// toDeleteFile函数的状退出码
// 文件成功删除
#define DELETE_SUCCEED                  0
// 不存在相同名字文件
#define CAN_NOT_FIND_TARGET_FILE_NAME   1
// 没有删除权限
#define NO_POWER_TO_DELETE              2

// toReadFile函数的状态退出码
// 成功读取
#define READ_SUCCEED                0
// 没有对应的文件名
#define READ_NO_TARGET_FILE_NAME    1

// toWriteFile函数的状态退出码
// 写入成功
#define WRITE_SUCCEED               0
// 没有对应的文件名
#define WRITE_NO_TARGET_FILE_NAME   1

typedef struct
{
    char fileName[FILE_NAME_LENGTH];
    char user[USER_NAME_LENGTH];
    int inode;
    int isExist;
} file;

int fileSystemInit(void);

int toBuildNewFile(user aUser, char *userName);

int toDeleteFile(user aUser, char *userName);

int toReadFile(user aUser, char *saveString);

int toWriteFile(user aUser, char *loadString);

#endif
