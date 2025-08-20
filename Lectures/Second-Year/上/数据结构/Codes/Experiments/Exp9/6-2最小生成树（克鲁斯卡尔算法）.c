#include <stdio.h>
#define MVNum 10
#define MaxInt 32767

//邻接矩阵
typedef struct {
	char vexs[MVNum];
	int arcs[MVNum][MVNum];
	int vexnum, arcnum;
} AMGraph;

//边表——头、尾、权值
struct Evode {
	char Head;
	char Tail;
	int lowcost;
} Edge[(MVNum * (MVNum - 1)) / 2]; //n个顶点，最多有n*（n-1）/2个边——无向图

int Vexset[MVNum];//存储根节点
void CreateUDN(AMGraph &G);//实现细节隐藏
void Kruskal(AMGraph G);
int main() {
	AMGraph G;
	CreateUDN(G);
	Kruskal(G);
	return 0;
}
/* 请在这里填写答案 */


int cmp(struct Evode a, struct Evode b) {
	return a.lowcost < b.lowcost;
}

//寻找一个顶点的根节点
int find(char x) {
	int y;
	y = x - '0';//将x转换成数字
	while (Vexset[y] != -1)y = Vexset[y]; //找到y的根节点（-1）
	return y;
}

/*判断两个顶点的根节点是否为一个根节点。如果相同，则代表位于同一连通分量
,如果添加到一起会形成环路,不是就加到一起*/
int add(char x, char y) {
	if (find(x) == find(y))return 0; //同一连通分量——不添加
	else {
		int fx = find(x);
		int fy = find(y);
		Vexset[fx] = fy; //将fx的根节点更新为fy
		return 1;
	}
}

void Kruskal(AMGraph G) {
	//初始化所有结点的根节点为-1，即本身就是根节点
	for (int i = 0; i < G.vexnum; i++) {
		Vexset[int(G.vexs[i] - '0')] = -1;
	}
	//按结构体中路径长短排序
	sort(Edge, Edge + G.arcnum, cmp);
	//Kruskal——从edge中选择最小的边
	for (int i = 0; i < G.arcnum; i++) {
		if (add(Edge[i].Head, Edge[i].Tail)) {
			printf("%c->%c\n", Edge[i].Head, Edge[i].Tail);
		}

	}
}

