#include "BiMinusTree.h"

/***********************辅助函数**************************/
int search(BSTree t,int k){
	int pos = 0;
	
	for(int i = 1; i <= t->keynum; ++i){
		if( t->key[i] == k ){
			pos = i;
			break;
		}else if( t->key[i] < k ){
			if( i+1>t->keynum || t->key[i+1]>k ){
				pos = i;
				break;
			}
		}
	}

	return pos;
}
/*************************end*****************************/

Result SearchBTree(BTree T,int k){
	Result rt = {NULL,0,0};
	BTree p = T,
		  q = NULL;
	int found = 0;

	while( p && !found ){
		int i = search(p,k);

		if( i>0 && p->key[i]==k ){
			rt.pt = p;
			rt.i = i;
			rt.tag = 1;
			found = 1;
		}else{
			p = p->ptr[i];
		}
	}

	return rt;
}

void InsertBTree(BTree *T,int k){
}

void DeleteBTree(BTree *T,int k){
}
