#ifndef _MY_BTREE_NUM
int layer = 0;
#endif

typedef struct BTNode{
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

//设置树的阶数
void setBTreeLayer(int num);

//查找关键字
Result SearchBTree(BTree T,int k,int *mode);

//插入结点
void InsertBTree(BTree *T,int k,BTree q,int pos);

//删除结点
void DeleteBTree(BTree *T,int k);
