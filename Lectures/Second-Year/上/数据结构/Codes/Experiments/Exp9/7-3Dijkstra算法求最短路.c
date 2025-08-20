#include<stdio.h>

#define MaxVexNum 10 //最多顶点数
#define MaxArcNum 105//最多边数
#define INFINTY 10000//权值最大

typedef int DataType;//顶点类型

//邻接矩阵定义
typedef struct {
	DataType vertex[MaxVexNum];//存储顶点信息
	int arc[MaxVexNum][MaxVexNum];//存储边信息（邻接矩阵）
	int vexnum, arcnum;
} AMGraph;

//寻找顶点v所对应的下标
int LocateVex(AMGraph G, DataType v ) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vertex[i] == v) { //寻找到顶点
			return i;
		}
	}

	return -1;//未找到顶点
}

//创建有向图
void CreateDG(AMGraph * G) {
	//有向图初始化
	scanf("%d %d", &(G->vexnum), &(G->arcnum));
	//顶点信息初始化
	for (int i = 0; i < (G->vexnum); i++) {
		G->vertex[i] = i + 1; //编号从1开始，到n
	}
	//边邻接矩阵初始化
	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++) {
			G->arc[i][j] = INFINTY;
		}
	}
	//创建有向图
	DataType x, y; //边的起点、终点
	int z;//权值
	for (int k = 0; k < G->arcnum; k++) {
		scanf("%d %d %d", &x, &y, &z);
		int i = LocateVex(*G, x);
		int j = LocateVex(*G, y);
		//建立弧
		G->arc[i][j] = z;
	}

}

int dis[MaxVexNum]; //目前已经找到的，从开始点v0到vi的最短路径长度
int S[MaxVexNum]; //已求出最短路径的点的集合（T代表已求出）
int Path[MaxVexNum]; //已经找到的，从开始点v0到终点vi的当前路径顶点序列(保存其最短路径所对应的前驱)

void Dijkstra(AMGraph G) {
	//初始化dist（D）、S集合、路径path
	for (int i = 0; i < G.vexnum; i++) {
		dis[i] = G.arc[0][i]; //dist 1到其他n-1个顶点的距离（有则不为无穷）
		//S集合初始只有1顶点
		S[i] = -1;//先全部初始化为不在，后面在循环外加入即可
		//如果顶点与1之间存在弧(权值小于无穷)
		if (dis[i] < INFINTY) {
			Path[i] = 0; //i顶点的前驱为v0;
		} else {
			Path[i] = -1;
		}
	}
	//将1看成第一个已经找到的最短路径顶点——D(1)和S(1)为初始点
	dis[0] = 0;
	S[0] = 1;


	//求1到其余n-1个顶点的最短路径
	for (int i = 1; i < G.vexnum; i++) {
		int min = INFINTY;
		int v;
		//寻找与S集合相连的最短路径
		for (int j = 0; j < G.vexnum; j++) {
			if (S[j] == -1 && dis[j] < min) { //S集合中顶点寻找
				v = j;
				min = dis[j];
			}
		}
		S[v] = 1; //将v顶点加入集合S
		for (int j = 0; j < G.vexnum; j++) {
			//存在一条边更新D[j]
			if (S[j] == -1 && (dis[v] + G.arc[v][j] < dis[j])) {
				dis[j] = dis[v] + G.arc[v][j];
				Path[j] = v; // 修改j顶点的前驱为v
			}
		}
	}

}

int main() {
	AMGraph G;

	CreateDG(&G);
	Dijkstra(G);
	printf("%d", dis[G.vexnum - 1]);//输出到n顶点的最短距离

	return 0;
}
