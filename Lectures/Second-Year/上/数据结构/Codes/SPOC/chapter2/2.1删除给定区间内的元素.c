#include<stdio.h>

#define MaxSize 100

typedef struct{
	int elem[MaxSize];
	int last;
}SeqList;

void DelRange(int x,int y,SeqList *nums){
	int i = 0,j = 0;//双循环变量法
	while(i<=nums->last){
		if(nums->elem[i]>=x&&nums->elem[i]<=y){
			i++;
			continue;//如果在该区间，不做改变，直接进行下一趟循环
		}
		else{//不在该区间
			nums->elem[j]=nums->elem[i];
			i++;
			j++;
		}
	}
	nums->last=j-1;//修改尾指针变量
	return;
}

//打印函数
void PrintSeqList(SeqList num) {
	for (int i = 0; i <= num.last; i++) {
		printf("%d ", num.elem[i]);
	}
	printf("\n");
	return;
}

int main(){
	SeqList nums ={{1,2,3,5,4,2,7,7,9,10},9};
	
	PrintSeqList(nums);
	//删除给定区间元素
	int x,y;
	scanf("%d %d",&x,&y);
	DelRange(x,y,&nums);
	PrintSeqList(nums);
	
	return 0;
}
