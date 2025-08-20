//删除单链表L（L中各元素互不相同）中的最大值所对应的结点，并返回该结点的值。
Elemtype DelMaxelem(Linklist L) {
	Node *p = L->next; //遍历指针
	Node *pre = L; //指向遍历指针的前驱结点
	Node pMax = p;//假定第一个结点为最大的元素
	Node pMax_pre = pre;

	while (p != NULL) {
		if (p->data > pMax->data) { //如果p所指结点的值大于pMax所指的值
			pMax = p;
			pMax_pre = pre;
		}
		//指针后移
		pre = p;
		p = pre->next;
	}
	//遍历完后pMax指向最大结点,pMax_pre指向最大结点的前驱结点——删除结点
	pMax_pre->next = pMax->next;
	Elemtype maxElem = pMax->data;
	free(pMax);
	
	return maxElem;
}
