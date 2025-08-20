#include<stdio.h>

#define MaxVexNum 10
#define INFINTY 1E9

//邻接矩阵定义的图
typedef	int DataType;

typedef struct {
	int distance;//距离
	int charge;//收费
} ArcNode;

//图
typedef struct {
	DataType vertex[MaxVexNum];//顶点数组
	ArcNode arc[MaxVexNum][MaxVexNum];//邻接矩阵
	int vexnum, arcnum;
} AMGraph;

//寻找顶点下标函数
int LocateVex(AMGraph G, DataType v) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vertex[i] == v) {
			return i;
		}
	}

	return -1;//未找到
}

//创建无向网
void CreateUDN(AMGraph *G) {
	//顶点数组初始化
	for (int i = 0; i < G->vexnum; i++) {
		G->vertex[i] = i; //城市编号为0 - n-1
	}
	//邻接矩阵初始化
	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++) {
			G->arc[i][j].distance = INFINTY;
			G->arc[i][j].charge = INFINTY;
		}
	}
	//输入弧顶点（起点+终点）以及权值
	int v0, v1, distance, charge;
	for (int k = 0; k < G->arcnum; k++) {
		scanf("%d %d %d %d", &v0, &v1, &distance, &charge);
		//寻找v0、v1所对应下标信息（对应邻接矩阵的下标信息）
		int i = LocateVex(*G, v0);
		int j = LocateVex(*G, v1);
		G->arc[i][j].distance = G->arc[j][i].distance = distance;
		G->arc[i][j].charge = G->arc[j][i].charge = charge;
	}
}

ArcNode DisCost[MaxVexNum];//S到任意顶点的最短路径（包括损失）
DataType S[MaxVexNum];//已经找到最短路径的集合

void Dijkstra(AMGraph G, DataType v0) {
	//初始化最短路径
	for (int i = 0; i < G.vexnum; i++) {
		DisCost[i].distance = G.arc[v0][i].distance;
		DisCost[i].charge = G.arc[v0][i].charge;
		S[i] = -1; //所有结点均不在S中（v0在循环外加入即可）
	}
	//v0结点最开始已经在S中
	DisCost[v0].distance = 0;
	DisCost[v0].charge = 0;
	S[v0] = 1;
	//求v0到其余n-1个顶点的最短路径
	for (int i = 0; i < G.vexnum; i++) {
		int min = INFINTY;
		int k;
		//寻找与S直接相邻的顶点，并且选择直接相邻的距离最近的顶点加入到S中
		for (int j = 0; j < G.vexnum; j++) {
			if (S[j] == -1 && DisCost[j].distance < min) {
				k = j;
				min = DisCost[j].distance;
				S[j] = 1; //加入到S中
			}
		}
		if (min == INFINTY) {
			return;
		}
		//
		for (int j = 0; j < G.vexnum; j++) {
			//存在一条边更新D[j]
			if (S[j] == -1 && (DisCost[k].distance != INFINTY)) {
				//判断是否要修改花销
				//如果有若干条路径都是最短的，那么需要输出最便宜的一条路径。
				if (DisCost[k].distance + G.arc[k][j].distance < DisCost[j].distance) { //并且起点到v的路径要大于起点到u再到v的路径
					DisCost[j].distance = DisCost[k].distance + G.arc[k][j].distance;;//更新距离和开销
					DisCost[j].charge = DisCost[k].charge + G.arc[k][j].charge;
				} else if (DisCost[k].distance + G.arc[k][j].distance == DisCost[j].distance && DisCost[k].charge + G.arc[k][j].charge < DisCost[j].charge) { //如果距离相等，但是花费的钱不一样
					DisCost[j].charge = DisCost[k].charge + G.arc[k][j].charge;
				}
			}
		}
	}
}


int main() {
	AMGraph G;
	DataType S, D;

	//输入顶点个数+弧的个数+出发城市+目标城市
	scanf("%d %d %d %d", &G.vexnum, &G.arcnum, &S, &D);
	CreateUDN(&G);
	Dijkstra(G, S);
	int D_Pos = LocateVex(G, D);
	printf("%d %d", DisCost[D_Pos].distance, DisCost[D_Pos].charge);

	return 0;
}
