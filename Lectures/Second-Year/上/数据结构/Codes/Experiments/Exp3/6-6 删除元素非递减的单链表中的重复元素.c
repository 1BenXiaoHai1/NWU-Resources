#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */
List RemoveDuplicate( List L );

int main() {
	List L;

	L = Read();
	L = RemoveDuplicate(L);
	Print(L);

	return 0;
}

List RemoveDuplicate( List L ) {
	PtrToNode pre = L->Next;
	PtrToNode p = pre->Next;

	while (p != NULL) {
		//当后者的元素小于等于前者时，删除后者
		if (p->Data <= pre->Data) {
			//删除p所指结点
			PtrToNode temp = p;
			pre->Next = p->Next;
			p = p->Next; //p后移
			free(temp);
		} else { //后者大于前者，移动前后指针
			pre = pre->Next;
			p = p->Next;
		}
	}

	return L;

}
