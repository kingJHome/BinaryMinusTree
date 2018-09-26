#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileHander.h"
#include "BiMinusTree.h"

typedef struct TreeContent{
	int grade;
	int delete;
	int length;
	int *elem;
}TreeContent;

void readContent(char *content,int rows,void *others);
void visitBMTree(BTree header);

int main(int argc,char *argv[]){
	BTree header = NULL;
	TreeContent	*txtText = (TreeContent*)malloc(sizeof(TreeContent));
	
	if( txtText ){
		getFileIntArrMultiple("nodelist.txt",readContent,txtText);
		for(int i = 0; i < txtText->length; ++i){
			Result rt = SearchBTree(header,txtText->elem[i]);
			if( !rt.tag ){
				InsertBTree(&header,txtText->elem[i],rt.pt,rt.i,txtText->grade);
			}
		}
		visitBMTree(header);
		Result rt = SearchBTree(header,txtText->delete);
		if( rt.tag ){
			printf("\n当删除一个关键字后，树序列：");
			DeleteBTree(header,txtText->delete,rt.pt,rt.i);
			visitBMTree(header);
		}
		printf("\n");
	}
	
	return 0;
}

void readContent(char *content,int rows,void *others){
	char *split = strstr(content,":"),
		 *attr = strndup(content,(size_t)(split-content));
	TreeContent	*txtText = (TreeContent*)others;
	
	if( strcmp(attr,"grade") == 0 ){//B-树的阶数
		int grade = atoi(split+1);
		txtText->grade = grade;
	}else if( strcmp(attr,"data") == 0 ){//树的每个结点数据
		char *delim = NULL;
		size_t slen = 0;
		int cur = 0;

		txtText->length = 0;
		split = split + 1;
		slen = strlen(split);
		
		for(size_t i = 0; i < slen; ++i){
			if(split[i]==' ' || split[i]=='\n'){
				txtText->length++;
			}
		}
		
		txtText->elem = (int*)malloc(txtText->length * sizeof(int));
		if( txtText->elem ){
			delim = strtok(split," ");
			if(delim && strlen(delim)>0 ){
				txtText->elem[cur++] = atoi(delim);
				while( delim = strtok(NULL," ") ){
					txtText->elem[cur++] = atoi(delim);
				}
			}	
		}
	}else if( strcmp(attr,"delete") ){//要删除的关键字结点
		int delKey = atoi(split+1);
		txtText->delete = delKey;
	}
}

void visitBMTree(BTree header){
	if( header ){
		for(int i = 1; i <= header->keynum; ++i){
			printf("%-5d",header->key[i]);
		}
		
		for(int i = 0; i <= header->keynum; ++i){
			visitBMTree(header->ptr[i]);
		}
	}
}
