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

// toBuildNewFile������״̬�˳���
// �ļ��ɹ�����
#define BUILD_SUCCEED       0
// ������ʾ�����ļ�ʱ�����ļ�ͬ��
#define HAVE_SAME_NAME      1
// �Դﵽ���洢�ռ��޷��½��ļ�
#define NO_MORE_SPACE       2

// toDeleteFile������״�˳���
// �ļ��ɹ�ɾ��
#define DELETE_SUCCEED                  0
// ��������ͬ�����ļ�
#define CAN_NOT_FIND_TARGET_FILE_NAME   1
// û��ɾ��Ȩ��
#define NO_POWER_TO_DELETE              2

// toReadFile������״̬�˳���
// �ɹ���ȡ
#define READ_SUCCEED                0
// û�ж�Ӧ���ļ���
#define READ_NO_TARGET_FILE_NAME    1

// toWriteFile������״̬�˳���
// д��ɹ�
#define WRITE_SUCCEED               0
// û�ж�Ӧ���ļ���
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
