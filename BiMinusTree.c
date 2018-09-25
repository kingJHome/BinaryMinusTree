#include <stdlib.h>
#include "BiMinusTree.h"

int MyCeil(int a,int b){
	int result;

	if( a%b == 0 ){
		result = a / b;		
	}else{
		result = a / b + 1;
	}

	return result;
}

void SplitNode(BTree prev,BTree *next,int diman){
	int splitPos = MyCeil(diman,2);
	BTree temp = (BTree)malloc(sizeof(BTNode));

	if( temp ){
		temp->grade = diman;
		temp->key = (int*)malloc((diman+1) * sizeof(int));
		temp->ptr = (BTNode**)malloc(sizeof(BTNode*) * (diman+1));

		if( temp->key && temp->ptr ){
			temp->keynum = 0;
			for(int i = splitPos+1,cur = 1; i <= prev->keynum; ++i,++cur){
				temp->key[cur] = prev->key[i];
				temp->ptr[cur] = prev->ptr[i];
				++temp->keynum;
			}
			temp->ptr[0] = prev->ptr[splitPos];
			prev->keynum = splitPos - 1;
			*next = temp;
		}
	}
}

void NewRoot(BTree *T,BTree lc,int k,BTree rc,int diman){
	int midPos = MyCeil(diman,2);
	BTree temp = (BTree)malloc(sizeof(BTNode));

	if( temp ){
		temp->grade = diman;
		temp->key = (int*)malloc((diman+1) * sizeof(int));
        temp->ptr = (BTNode**)malloc(sizeof(BTNode*) * (diman+1));
 
        if( temp->key && temp->ptr ){
			temp->parent = NULL;
			temp->keynum = 1;
		}

		if( *T ){//分裂结点产生新根结点
			temp->ptr[0] = *T;
			temp->ptr[1] = rc;
			(*T)->parent = temp;
			rc->parent = temp;
			temp->key[1] = (*T)->key[midPos];
			*T = temp;
		}else{
			temp->key[1] = k;
			*T = temp;
		}
	}
}

int Search(BTree t,int k){
	int result = 0;

	for(int i = t->keynum; i >= 1; --i){
		if( k >= t->key[i] ){
			result = i;
			break;
		}
	}

	return result;
}

void DestroyBTNode(BTree t){
	free(t->key);
	free(t->ptr);
	free(t);
}

Result SearchBTree(BTree T,int k){
	Result rt = {NULL,0,0};
	BTree p = T,
		  q = NULL;
	int found = 0,i = 0;

	while( p && !found ){
		i = Search(p,k);
		
		rt.pt = p;
		rt.i = i;
		if( i>0 && p->key[i]==k ){
			rt.tag = 1;
			found = 1;
			break;
		}else{
			rt.tag = 0;
			p = p->ptr[i];
		}
	}

	return rt;
}

void Insert(BTree q,int pos,int k,BTree ap){
	for(int i = q->grade; i > pos+1; --i){
		q->key[i] = q->key[i-1];
		q->ptr[i] = q->ptr[i-1];
	}
	q->key[pos+1] = k;
	q->ptr[pos+1] = ap;
	if( ap ){
		ap->parent = q;
	}
	++q->keynum;
}

void InsertBTree(BTree *T,int k,BTree q,int pos,int diman){
	BTree ap = NULL;
	int x = k,
		finished = 0;

	while( q && !finished ){
		Insert(q, pos, x, ap);//向q插入数据,q->key[i+1]=x,q->ptr[i+1]=ap

		if( q->keynum < diman ){
			finished = 1;
		}else{
			int s = MyCeil(diman,2);

			SplitNode(q, &ap, diman);
			x = q->key[s];
			q = q->parent;
			if( q ){
				pos = Search(q,k);
			}
		}
	}

	if( !finished ){//当q为空或q已经分裂，则建立新根节点
		NewRoot(T, q, k, ap, diman);
	}
}

void DeleteBTree(BTree *T,int k){
}
