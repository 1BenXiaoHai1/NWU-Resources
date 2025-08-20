#include"ArrayList.h"

//线性表顺序存储的基本操作
int max(int a, int b) {
	if (a >= b) {
		return a;
	} else {
		return b;
	}
}
//查找
int Locate(SeqList L, int e) {
	int i = 0;
	while ((i <= L.last) && (L.elem[i] != e)) {
		i++;
	}
	if (i <= L.last) {
		return i + 1; //返回查找位置
	} else {
		return -1;//未找到
	}
}

//删除
int DelList(SeqList *L, int i, int *e) {
	int k;
	if ((i < 1) || (i > L->last + 1)) {
		printf("插入位置i不合法\n");
		return ERROR;
	}
	*e = L->elem[i - 1]; //返回删除的元素
	//元素前移
	for (k = i; i <= L->last; k++) {
		L->elem[k - 1] = L->elem[k];
	}
	L->last--;//修改尾指针
	return OK;
}

//插入
int InsList(SeqList *L, int i, int e) {
	int k;
	if ((i < 1) || (i > L->last + 2)) {
		printf("插入位置i不合法\n");
		return ERROR;
	}
	//元素后移
	for (k = L->last; k >= i - 1; k--) {
		L->elem[k + 1] = L->elem[k];
	}
	L->elem[i - 1] = e; //插入元素
	L->last++;//修改尾指针
	return OK;
}

//合并
void mergeList(SeqList *LA, SeqList *LB, SeqList *LC) {
	int i = 0, j = 0, k = 0;
	//两表重合部分先放小的元素
	while (i <= LA->last && j <= LB->last) {
		if (LA->elem[i] <= LB->elem[j]) {
			LC->elem[k] = LA->elem[i];
			i++;
			k++;
		} else {
			LC->elem[k] = LB->elem[j];
			j++;
			k++;
		}
	}
	//LA表有剩余
	while (i <= LA->last) {
		LC->elem[k] = LA->elem[i];
		i++;
		k++;
	}
	//LB表有剩余
	while (j >= LB->last) {
		LC->elem[k] = LB->elem[j];
		j++;
		k++;
	}
	LC->last = max(LA->last, LB->last) + 1;
}
