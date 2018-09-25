#include "fileHander.h"

void getFileIntArr(char *filename,hander __getContent,void *oArg){
	FILE *fp = fopen(filename,"r");

	if( fp ){
		char *line = NULL;
		size_t setNum = 0;

		if( getline(&line, &setNum, fp) != -1 ){
			if( strlen(line) ){
				__getContent(line,0,oArg);
			}
		}
	}
}

void getFileIntArrMultiple(char *filename,hander __getContent,void *oArg){
	FILE *fp = fopen(filename,"r");

	if( fp ){
		int curRow = 1;
		char *line = NULL;
		size_t setNum = 0;

		while( getline(&line, &setNum, fp) != -1 ){
			setNum = 0;
			__getContent(line,curRow,oArg);
			++curRow;
		}
	}
}

char *getFileCharArr(char *filename){
}

char **getFileStringArr(char *filename){
}
