#include <iostream>
using namespace std;

#define MaxInt 32767
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;

int *D = new int[MVNum]; //目前已经找到的，从开始点v0到vi的最短路径长度
bool *S = new bool[MVNum]; //已求出最短路径的点的集合（T代表已求出）
int *Path = new int[MVNum]; //已经找到的，从开始点v0到终点vi的当前路径顶点序列(保存其最短路径所对应的前驱)

//邻接矩阵创建图
typedef struct {
	VerTexType vexs[MVNum];//顶点数组
	ArcType arcs[MVNum][MVNum]; //邻接矩阵
	int vexnum, arcnum; //结点数、边数
} AMGraph;

int LocateVex(AMGraph G, int v) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vexs[i] == v) { //找到节点返回其下标
			return i;
		}
	}
}

//创建无向网
void CreateUDN(AMGraph &G) {
	int i, j, k;
	cin >> G.vexnum >> G.arcnum;//顶点数、边数

	//初始化顶点信息
	for (i = 0; i < G.vexnum; ++i) {
		cin >> G.vexs[i];
	}
	//初始化边
	for (i = 0; i < G.vexnum; ++i)
		for (j = 0; j < G.vexnum; ++j)
			G.arcs[i][j] = MaxInt;
	//根据输入的两个顶点，确定边的权值，并修改邻接矩阵
	for (k = 0; k < G.arcnum; ++k) {
		VerTexType v1, v2;
		ArcType w;
		cin >> v1 >> v2 >> w;
		i = LocateVex(G, v1);  //寻找下标
		j = LocateVex(G, v2);
		//修改邻接矩阵——无向网（对称）
		G.arcs[i][j] = w;
		G.arcs[j][i] = G.arcs[i][j];
	}
}

//Dijistra
void ShortestPath_DIJ(AMGraph G, int v0) {
	//初始化dist（D）、S集合、路径path
	for (int i = 0; i < G.vexnum; i++) {
		D[i] = G.arcs[v0][i]; //dist
		//S初始只有v0为true
		S[i] = false;
		//如果顶点与v0之间存在弧(网——权值小于无穷)
		if (D[i] < MaxInt) {
			Path[i] = v0; //i顶点的前驱为v0;
		} else {
			Path[i] = -1;
		}
	}
	//将v0看成第一个已经找到的最短路径顶点——D(V0)和S(V0)为初始点
	D[v0] = 0;
	S[v0] = true;
	//求v0到其余n-1个顶点的最短路径
	for (int i = 1; i < G.vexnum; i++) {
		int min = MaxInt;
		int v;
		for (int j = 0; j < G.vexnum; j++) {
			if (S[j] == false && D[j] < min) { //S集合中顶点寻找
				v = j;
				min = D[j];
			}
		}
		S[v] = true; //将v顶点加入集合S
		for (int j = 0; j < G.vexnum; j++) {
			//存在一条边更新D[j]
			if (S[j] == false && (D[v] + G.arcs[v][j] < D[j])) {
				D[j] = D[v] + G.arcs[v][j];
				Path[j] = v; // 修改j顶点的前驱为v
			}
		}
	}
}

void DisplayPath(AMGraph G, int begin, int temp ) {
	//path存储
	if (Path[temp] != -1) {
		DisplayPath(G, begin, Path[temp]);
		cout << G.vexs[Path[temp]] << "->";
	}
}

int main() {
	AMGraph G;
	int i, j, num_start, num_destination;
	VerTexType start, destination;
	CreateUDN(G);//创建无向网
	cin >> start >> destination;
	num_start = LocateVex(G, start); //开始下标
	num_destination = LocateVex(G, destination); //结束下标
	ShortestPath_DIJ(G, num_start);
	DisplayPath(G, num_start, num_destination);  //输出最短路径
	cout << G.vexs[num_destination] << endl;
	return 0;
}
