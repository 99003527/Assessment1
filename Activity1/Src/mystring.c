#include "mystring.h"

int mystrlen(const char *str1)
{
    return strlen(str1);
}

char* mystrcpy(char* str1, const char* str2)
{
    return strcpy(str1,str2);
}

char* mystrcat(char *str4, const char *str3)
{
    strcat(str4,str3);
    return str4;
}

int mystrcmp(const char *str6, const char *str5 )
{
    return strcmp(str6,str5);
}