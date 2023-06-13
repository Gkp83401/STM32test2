#include "fileSystem.h"
#include "string.h"

char fileGather[MAX_FILE_NUMBER][MAX_FILE_CAPACITY];

file fileIndex[MAX_FILE_NUMBER];

int fileSystemInit()
{
    int i;
    user aUser = "root";
    char fileName[FILE_NAME_LENGTH] = "user";
    char userFileInit[MAX_FILE_CAPACITY] = "root:123\nabc:12345";
    
    for (i = 0; i < MAX_FILE_NUMBER; i++) {
        fileIndex[i].isExist = IS_NOT_EXIST;
    }
    
    if (toBuildNewFile(aUser, fileName) != BUILD_SUCCEED) {
        return FILE_SYSTEM_INIT_FAIL;
    }
    
    if (toWriteFile(aUser, userFileInit) != WRITE_SUCCEED) {
        return FILE_SYSTEM_INIT_FAIL;
    }
    return FILE_SYSTEM_INIT_SUCCEED;
}

int toBuildNewFile(user aUser, char *username)
{
    int i;
    
    // 查看是否存在同名的文件
    for (i = 0; i < MAX_FILE_NUMBER; i++) {
        if (
            fileIndex[i].isExist == IS_NOT_EXIST &&
            strCmpNoIndex(fileIndex[i].fileName, (char *)aUser) == IS_SAME
        ) {
            return HAVE_SAME_NAME;
        }
    }
    
    // 寻找可以存放新文件的位置
    i = 0;
    while (1) {
        if (i == MAX_FILE_NUMBER) {
            return NO_MORE_SPACE;
        }
        if (fileIndex[i].isExist == IS_NOT_EXIST) {
            break;
        }
        i++;
    }
    
    strCopy((char *)aUser, fileIndex[i].fileName);
    strCopy(username, fileIndex[i].user);
    fileIndex[i].isExist = IS_EXIST;
    fileIndex[i].inode = i;
    
    strCopy("", fileGather[i]);
    
    return BUILD_SUCCEED;
}

int toDeleteFile(user aUser, char *userName)
{
    int i;
    
    // 查找是否有同名的文件
    i = 0;
    while (1) {
        if (i == MAX_FILE_NUMBER) {
            return CAN_NOT_FIND_TARGET_FILE_NAME;
        }
        if (
            fileIndex[i].isExist == IS_EXIST &&
            strCmpNoIndex(fileIndex[i].fileName, (char *)aUser) == IS_SAME
        ) {
            break;
        }
        i++;
    }
    
    // 用来判断该文件是否属于登录用户
    if (strCmpNoIndex(fileIndex[i].user, (char *)aUser) == IS_NOT_SAME) {
        return NO_POWER_TO_DELETE;
    }
    
    fileIndex[i].isExist = IS_NOT_EXIST;
    return DELETE_SUCCEED;
}

int toReadFile(user aUser, char *saveString)
{
    int i;
    
    i = 0;
    while (1) {
        if (i == MAX_FILE_NUMBER) {
            return READ_NO_TARGET_FILE_NAME;
        }
        if (
            fileIndex[i].isExist == IS_EXIST &&
            strCmpNoIndex(fileIndex[i].fileName, (char *)aUser) == IS_SAME
        ) {
            break;
        }
        i++;
    }
    
    strCopy(fileGather[i], saveString);
    return READ_SUCCEED;
}

int toWriteFile(user aUser, char *loadString)
{
    int i;
    
    i = 0;
    while (1) {
        if (i == MAX_FILE_NUMBER) {
            return WRITE_NO_TARGET_FILE_NAME;
        }
        if (
            fileIndex[i].isExist == IS_EXIST &&
            strCmpNoIndex(fileIndex[i].fileName, (char *)aUser) == IS_SAME
        ) {
            break;
        }
        i++;
    }
    
    strCopy(loadString, fileGather[i]);
    return WRITE_SUCCEED;
}
