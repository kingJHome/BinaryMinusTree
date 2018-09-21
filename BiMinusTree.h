#define m 3

typedef struct BTNode{
	int keynum;						// 结点中关键字个数，即结点的大小
	struct BTNode *parent;			// 指向双亲结点
	int key[m+1];					// 关键字向量，0号单元未用
	struct BTNode *ptr[m+1];		// 子树指针向量
}BTNode,*BTree;

typedef struct{
	BTNode *pt;						// 指向找到的结点 
	int i;							// 在结点中的关键字序号
	int tag;						// 0:查找失败,1:查找成功
}Result;

//查找关键字
Result SearchBTree(BTree T,int k);

//插入结点
void InsertBTree(BTree *T,int k);

//删除结点
void DeleteBTree(BTree *T,int k);
