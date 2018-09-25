#ifndef _SELF_DEFINE_FILEHANDLE
#define _SELF_DEFINE_FINEHANDLE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*hander)(char *content,int rows,void *others);

typedef struct{
	int *elem;
	int length;
}IntArray;

typedef struct{
	char *elem;
	int length;
}CharArray;

typedef struct{
	char **elem;
	int length;
}StrArray;

//读取文件，并获取整形数据列表(只读取文件的一行)
void getFileIntArr(char *filename,hander __getContent,void *oArg);

//读取文件，并获取整形数据列表(读取文件的多行)
void getFileIntArrMultiple(char *filename,hander __getContent,void *oArg);

//读取文件，并获取字符列表
char *getFileCharArr(char *filename);

//读取文件，并获取字符串列表
char **getFileStringArr(char *filename);

#endif
