#include<stdio.h>
#include<stdlib.h>

typedef enum {FALSE, TRUE} Boolean;

#define MaxVertexNum 10     /*定义最大顶点数*/
typedef int Vertex;/* 用顶点下标表示顶点,为整型 */

typedef struct {
	int arcs[MaxVertexNum][MaxVertexNum]; /*邻接矩阵*/
	int vexnum, arcnum; /*图中的顶点数vexnum和边数arcnum*/
} MGraph; /*用邻接矩阵表示的图的类型*/

Boolean visited[MaxVertexNum]; /* 顶点的访问标记 */

void CreatMGraph(MGraph *G);/* 创建图并且将Visited初始化为false；裁判实现，细节不表 */

void DFS(MGraph G, Vertex v);

int main() {
	Vertex v;
	MGraph G;
	CreatMGraph(&G);
	scanf("%d", &v);
	printf("DFS from %d:", v);
	DFS(G, v);
	return 0;
}
/* 你的代码将被嵌在这里 */
void DFS(MGraph G, Vertex v) {
	printf(" %d", v); //访问v0结点
	visited[v] = TRUE; //设置访问状态为已访问
	for (int vj = 0; vj < G.vexnum; vj++) { 
		//为什么for循环从0开始，因为不知道那个点为起始点
		//结点未被访问并且v与vj之间存在边
		if (visited[vj] == FALSE && G.arcs[v][vj] == 1) {
			DFS(G, vj);//深度优先遍历vj
		}
	}
}
