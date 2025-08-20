#include<stdio.h>
#include<stdlib.h>

#define Max_Vertex_Num 10 //最多顶点个数
#define ERROR 0
#define OK 1

//弧结点结构
typedef struct {
	int adjvex; //该弧指向的顶点位置
	struct ArcNode* nextarc;//下一条弧的地址
} ArcNode;

//表头结点结构
typedef struct {
	int data; //顶点的信息（顶点是谁）
	ArcNode * firstarc; //该顶点的第一条弧的指针（第一条出度边）
} VertexNode;

//邻接表
typedef struct {
	VertexNode vertex[Max_Vertex_Num];//邻接表表头（顶点数据+第一条弧）
	int vexnum;//顶点个数
	int arcnum;//弧个数
} AdjList;

//确定顶点vex在G.vertex中的序号(有向图)
int LocateVertex(AdjList G, int v) {
	for (int i = 0; i < G.vexnum; i++) { //有向图寻找结点
		if (G.vertex[i].data == v) {
			return i;
		}
	}
}

//创建有向图
void CreateDG(AdjList *G) {
	scanf("%d %d", &(G->vexnum), &(G->arcnum)); //输入第一行给出两个正整数——图的节点数N、边数M
	//构建邻接表表头（编号1-N）
	for (int i = 1; i <= G->vexnum; i++) {
		G->vertex[i - 1].data = i; //顶点信息
		G->vertex[i - 1].firstarc = NULL;
	}
	//输入各边，构建邻接表
	for (int k = 0; k < G->arcnum; k++) {
		int v1, v2; //输入的两个顶点——用来确定边
		scanf("%d %d", &v1, &v2);
		//寻找v1、v2结点所对应的邻接表表头的位置
		int i = LocateVertex(*G, v1);
		int j = LocateVertex(*G, v2);

		//生成边界点，将该边插入表头结点v1之后的链表中（头插法）
		ArcNode * p = (ArcNode *)malloc(sizeof(ArcNode));//申请空间
		p->adjvex = j; //该弧指向的顶点信息
		//将新的弧结点插到表头结点之后(头插法)
		p->nextarc = G->vertex[i].firstarc;
		G->vertex[i].firstarc = p;

	}
}

//求各顶点入度算法——indegree数组存储各顶点入度
void FindID(AdjList G, int indegree[Max_Vertex_Num]) {
	ArcNode *p;
	//入度数组初始化为0
	for (int i = 0; i < G.vexnum; i++) {
		indegree[i] = 0;
	}
	//求每个顶点的入度
	for (int i = 0; i < G.vexnum; i++) {
		p = G.vertex[i].firstarc; //从每个顶点的第一个出度边开始遍历
		while (p != NULL) {
			indegree[p->adjvex]++;//p->adjvex入度+1
			p = p->nextarc; //后移
		}
	}
}

//拓扑排序
int TopoSort(AdjList G) {
	int Stack[G.vexnum], top = -1; //顺序栈
	int indegree[Max_Vertex_Num];

	FindID(G, indegree); //求各顶点的入度
	//寻找入度为0（无前驱）的顶点
	for (int i = 0; i < G.vexnum; i++) {
		if (indegree[i] == 0) {
			top++;//栈顶指针上移
			Stack[top] = i; //将入度为0的顶点i压入栈中
		}
	}
	int count = 0;//判断有多少个顶点已删除（已排序）——用来判断图是否含有回路
	while (top != -1) { //栈非空
		int Del = Stack[top];//出栈
		top--;//栈顶元素下移
		count++;//已删除顶点+1
		//输出已删除顶点信息
		printf("%d ", G.vertex[Del].data);
		//将以此顶点为起点的所有边删除(所有边所对应的终点入度-1)
		ArcNode * p = G.vertex[Del].firstarc;
		while (p != NULL) {
			indegree[p->adjvex]--;
			if (indegree[p->adjvex] == 0) { //如果减少后的顶点入度为0，加入到待删除顶点栈中
				Stack[++top] = p->adjvex;
			}
			p = p->nextarc;
		}
	}
	//如果删除顶点数目少于图的顶点数，说明存在回路
	if (count < G.vexnum) {
		return ERROR;
	} else {
		return OK;
	}

}

int main() {
	AdjList G;
	CreateDG(&G);//创建有向图
	//拓扑排序
	if (!TopoSort(G)) { //该图为非连通图或图中有回路
		printf("\n0");
	}

	return 0;
}
