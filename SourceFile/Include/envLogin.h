#ifndef ENV_LOGIN_H
#define ENV_LOGIN_H

#include "envLoginOutImformation.h"

unsigned char envLogin(envLoginOutImformation *aEnvLoginOutImformationPoint);

int loginCheck(char *username, char *password);

#endif
