#include<stdio.h>
#include<stdlib.h>

//二叉树结点的创建及二叉树（指向结点的指针）的创建
typedef struct Node {
	int data;
	struct Node* leftchild;//左孩子
	struct Node* rightchild;//右孩子
	struct Node* father;//父节点
} BiTNode, *BiTree;

//二叉树的创建(不带父节点指针的创建)——传二叉树的地址进来（因为要修改二叉树）
void CreateBiTree(BiTree * root) {
	int val;
	scanf("%d", &val);
	if (val == 0) { //0代表空指针
		*root = NULL;
	} else {
		//先根序列——根左右
		(*root) = (BiTree)malloc(sizeof(BiTNode));//申请空间
		(*root)->data = val;
		(*root)->father = NULL;
		CreateBiTree(&((*root)->leftchild));//左
		CreateBiTree(&((*root)->rightchild));//右
	}
}

//创建带父节点的二叉树
void CreateFatherBiTree(BiTree root) {
	//当前结点，其左右孩子的父节点就为自身
	if (root->leftchild != NULL) {
		root->leftchild->father = root;
		CreateFatherBiTree(root->leftchild);
	}
	if (root->rightchild != NULL) {
		root->rightchild->father = root;
		CreateFatherBiTree(root->rightchild);
	}
}

//遍历查找(先序查找)结点，比求其父结点
int Father = 0;//保存父结点的值，不存在则为0
int flag = 0;//判断变量——是否查找到值为K的结点
void Find_KandFather(BiTree root, int K) {

	if (root == NULL) {
		return;
	}
	//找到了值为K的结点
	if (root->data == K) {
		flag = 1; //存在值为K的结点，不需要再查找其他子树了
		//寻找父结点
		if (root->father != NULL) {
			Father = root->father->data;
		} else {
			Father = 0;
		}
	} else {
		/*为什么下面这段代码不能将两个if合并
		因为有可能在查找左子树的时候找到了结点*/
		//左
		if (flag != 1) {
			Find_KandFather(root->leftchild, K);
		}
		//右
		if (flag != 1) {
			Find_KandFather(root->rightchild, K);
		}
	}
}


int main() {
	BiTree root;

	//创建带父节点的二叉树
	CreateBiTree(&root);
	CreateFatherBiTree(root);
	//输入查找组数
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int K;
		scanf("%d", &K);
		//查找该数值所对应结点的父结点并输出其数值
		//查找全局变量初始化
		flag = 0;
		Father = 0;
		Find_KandFather(root, K);
		if (flag) {
			printf("%d\n", Father);
		} else {
			printf("0\n");//无结点K或K无父结点
		}
	}

	return 0;
}
