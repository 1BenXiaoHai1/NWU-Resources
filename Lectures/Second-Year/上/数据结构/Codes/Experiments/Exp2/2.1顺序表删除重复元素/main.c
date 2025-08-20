#include<stdio.h>
#include"ArrayList.h"//引入线性表文件（里面包含了顺序表和链表的定义以及基本操作）

//删除重复元素函数
void DelDuplicateList(SeqList *num) {
	int i = 0, j = 0; //双循环变量
	for (i = 0; i <= num->last; i++) {
		if (num->elem[i] != num->elem[j]) { //二者不相等在j所指位置下一位置插入该元素
			num->elem[j + 1] = num->elem[i];
			j++;
		} else { //相等则不需要插入元素，移动i，判断下一个元素
			continue;//跳过当前循环
		}
	}
	num->last = j; //最终j的值即为最后一个元素的下标
	return;
};

//打印函数
void PrintSeqList(SeqList num) {
	for (int i = 0; i <= num.last; i++) {
		printf("%d ", num.elem[i]);
	}
	printf("\n");
	return;
}


int main() {
	SeqList nums = {{1, 2, 2, 3, 4, 4, 6, 6, 7, 8}, 9}; //结构体赋值（结构体在定义时不可赋值，因为未开辟内存）
	PrintSeqList(nums);
	//删除重复元素
	DelDuplicateList(&nums);
	PrintSeqList(nums);
	
	return 0;
}
