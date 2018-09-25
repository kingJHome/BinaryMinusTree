#ifndef _MY_BTREE_NUM
#define _MY_BTREE_NUM

typedef struct BTNode{
	int grade;						// 阶数
	int keynum;						// 结点中关键字个数，即结点的大小
	struct BTNode *parent;			// 指向双亲结点
	int *key;						// 关键字向量
	struct BTNode **ptr;			// 子树指针向量
}BTNode,*BTree;

typedef struct{
	BTNode *pt;						// 指向找到的结点 
	int i;							// 在结点中的关键字序号
	int tag;						// 0:查找失败,1:查找成功
}Result;

//销毁结点
void DestroyBTNode(BTree t);

//分裂结点
void SplitNode(BTree prev,BTree *next,int diman);

//建立新根结点
void NewRoot(BTree *T,BTree lc,int k,BTree rc,int diman);

//查找关键字，如果关键字不在树中，返回最后一个小于k的位置；如果在树中，返回在树中的序号
int Search(BTree t,int k);

//查找关键字
Result SearchBTree(BTree T,int k);

//插入数据
void Insert(BTree q,int pos,int k,BTree ap);

//插入结点
void InsertBTree(BTree *T,int k,BTree q,int pos,int diman);

//删除结点
void DeleteBTree(BTree *T,int k);

#endif
