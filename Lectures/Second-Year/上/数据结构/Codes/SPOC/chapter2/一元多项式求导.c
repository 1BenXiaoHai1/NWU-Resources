/*某一元多项式采用带头结点的单链表存储，编写算法求其导数。
参数为一元多项式的头指针，该多项式按照幂次递增的次序排列，
结果仍为PL所指的链表。*/
void Derivative(PolyNode *PL) {
	//多项式求导 (ax^n)'= n * a * x^(n-1)
	PolyNode * p = PL->next;//指向多项式的第一项

	while (p != NULL) {
		p->coef = (p->coef) * (p->exp); //求导后的系数
		p->exp = (p->exp) - 1; //求导后的指数
		//计算下一个多项式
		p = p->next;
	}

}
