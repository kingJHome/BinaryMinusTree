#include "BiMinusTree.h"

/***********************辅助函数**************************/
int search(BSTree t,int k){
	int pos = 0;
	
	if( t ){
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
	}

	return pos;
}

void insert(BSTree t,int pos,int k){
	for(int inst = t->fieldNum; inst > pos; --inst){
		t->key[inst] = t->key[inst-1];
		t->ptr[inst] = t->ptr[inst-1];
	}
	//插入结点
	t->key[pos] = k;
	t->ptr[pos] = t->ptr[pos-1];
	++t->keynum;
}
/*************************end*****************************/
void setBTreeLayer(int num){
	layer = num;
}

Result SearchBTree(BTree T,int k,int *mode){
	Result rt = {NULL,0,0};
	BTree p = T,
		  q = NULL;
	int found = 0;

	while( p && !found ){
		int i = search(p,k);

		if( i>0 && p->key[i]==k ){
			rt.pt = p;
			rt.i = i;
			rt.tag = 1;i
			found = 1;
			break;
		}else{
			if( !mode ){
				p = p->ptr[i];
			}else if( *mode == 1){
				break;
			}
		}
	}

	return rt;
}

void InsertBTree(BTree *T,int k,BTree q,int pos){
	if( q ){//插入结点非空
	}else{
		if( !(*T) ){//插入为空
			*T = (BTree)malloc(sizeof(BTNode));
			if( *T ){
				(*T)->key = (int*)malloc((layer+1) * sizeof(int));
				(*T)->ptr = (BTree)malloc(layer+1);
				if((*T)->key && (*T)->ptr){
					(*T)->parent = NULL;
					(*T)->keynum = 1;
					(*T)->key[1] = k;
					memset((*T)->ptr,NULL,layer+1);
				}
			}
		}else{
			int i = search(*T,k);

			if( i>0 && (*T)->key[i]==k ){
				return;
			}else{
				if( !((*T)->ptr[i]) ){//插入本结点

				}else{
					InsertBTree();
				}
			}
		}
	}
}

void DeleteBTree(BTree *T,int k){
}
