#include<stdio.h>

#define MaxVexNum 500
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

//弗洛伊德算法
void Floyd(AMGraph G, DataType S, DataType D) {
	ArcNode Cost[G.vexnum][G.vexnum];//存储任意顶点之间的最短路径(距离+损失)
	//初始化为邻接矩阵
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			Cost[i][j].distance = G.arc[i][j].distance;
			Cost[i][j].charge = G.arc[i][j].charge;
		}
	}
	for (int k = 0; k < G.vexnum; k++) {
		for (int i = 0; i < G.vexnum; i++) {
			for (int j = 0; j < G.vexnum; j++) {
				/*添加顶点后，使得i-j之间距离变小，则更新Cost（最短距离），
				  直到所有顶点都添加完为止*/
				if ((Cost[i][k].distance + Cost[k][j].distance <= Cost[i][j].distance)) {
					Cost[i][j].distance = Cost[i][k].distance + Cost[k][j].distance;
					//如果费用更小，则更新费用，否则不更新
					//如果有若干条路径都是最短的，那么需要输出最便宜的一条路径。
					if(Cost[i][k].charge + Cost[k][j].charge < Cost[i][j].charge){
						Cost[i][j].charge = Cost[i][k].charge + Cost[k][j].charge;
					}		
				}
			}
		}
	}
	//寻找最短路径
	printf("%d %d", Cost[S][D].distance, Cost[S][D].charge);
}


int main() {
	AMGraph G;
	DataType S, D;
	
	//输入顶点个数+弧的个数+出发城市+目标城市
	scanf("%d %d %d %d", &G.vexnum, &G.arcnum, &S, &D);
	CreateUDN(&G);
	Floyd(G, S, D);
	
	return 0;
}
