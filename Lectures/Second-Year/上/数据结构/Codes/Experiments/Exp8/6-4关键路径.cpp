#include <iostream>
using namespace std;
#define MVNum 100
#define BDNum MVNum * (MVNum - 1)
#define OK 1
#define ERROR 0
typedef char VerTexType;
//邻接表表示图

//边结点
typedef struct ArcNode {
	int adjvex;
	int weight;
	struct ArcNode *nextarc;
} ArcNode;

//表头结点
typedef struct VNode {
	VerTexType data;
	ArcNode *firstarc;
} VNode, AdjList[MVNum]; //表头

//十字链表
typedef struct {
	AdjList vertices; //邻接表
	AdjList converse_vertices;//逆邻接表
	int vexnum, arcnum;
} ALGraph;

int indegree[MVNum];//数组indegree存放个顶点的入度
int ve[BDNum];    //事件vi的最早发生时间
int vl[BDNum];    //事件vi的最迟发生时间
int topo[MVNum];    //记录拓扑序列的顶点序号

int CreateUDG(ALGraph &G); //实现细节隐藏
void FindInDegree(ALGraph G, int indegree[]); //获取各个顶点的入度，indegree存放个顶点的入度，函数实现细节隐藏
int TopologicalOrder(ALGraph G, int topo[]); //拓扑排序，topo存放拓扑序列，函数实现细节隐藏
int CriticalPath(ALGraph G);
int main() {
	ALGraph G;
	CreateUDG(G);
	int *topo = new int [G.vexnum];
	CriticalPath(G);
	return 0;
}
/* 请在这里填写答案 */
int CriticalPath(ALGraph G) {
	int i, j, k, e, l;
	ArcNode* p;
	//对图进行拓扑排序，将排序后结果放到topo中
	if (!TopologicalOrder(G, topo))
		return ERROR;
	//初始化事件i最早发生时间为0
	for (i = 0; i < G.vexnum; i++)
		ve[i] = 0;
	//求事件的最早发生时间——从源点向前递推到汇点
	for (i = 0; i < G.vexnum; i++) {
		k = topo[i];//选择入度为0的顶点
		p = G.vertices[k].firstarc;//选择入度为0的顶点的第一个邻接点
		while (p) {
			j = p->adjvex;
			//选择最大的作为k的最早发生时间
			if (ve[j] < ve[k] + p->weight)
				ve[j] = ve[k] + p->weight;
			p = p->nextarc;
		}
	}
	//将各顶点的最迟发生时间初始化为汇点的最早发生时间
	for (i = 0; i < G.vexnum; i++)
		vl[i] = ve[G.vexnum - 1];//G.vexnum - 1 汇点
	//求事件的最迟发生时间——从汇点向后递推到源点
	for (i = G.vexnum - 1; i >= 0; i--) {
		k = topo[i];
		p = G.vertices[k].firstarc;
		while (p) {
			j = p->adjvex;
			//选择最小的作为k的最晚发生时间
			if (vl[k] > vl[j] - p->weight) {
				vl[k] = vl[j] - p->weight;
			}

			p = p->nextarc;
		}
	}
	//求关键活动
	string ss;
	for (i = 0; i < G.vexnum; i++) {
		p = G.vertices[i].firstarc;
		//i-j弧的活动
		while (p) {
			j = p->adjvex;
			e = ve[i];//i的最早发生时间
			l = vl[j] - p->weight;//j的最晚发生时间
			//时间余量为0，则其为关键活动
			if (e == l) {
//				cout<<G.vertices[i].data<<"->"<<G.vertices[j].data<<",";
				ss = ss + G.vertices[i].data + "->" + G.vertices[j].data + ",";
			}
			p = p->nextarc;
		}
	}
	//输出关键路径
	for (int i = 0; i < ss.size() - 1; i++) { //不输出最后一个字符——逗号
		cout << ss[i];
	}
	return OK;
}
