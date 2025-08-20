#include <stdio.h>
#define MAXN 100
#define INF 99999999

int checkpoints,activities;
int G[MAXN][MAXN],totaltime = 0;

typedef struct
{
	int earlytime;
	int lasttime;
	int indegree;
	int outdegree;
} Point;

Point Points[MAXN];

void InitGraph()
{
	int i,j;
	for(i=1;i<=checkpoints;i++)
		for(j=1;j<=checkpoints;j++)
			G[i][j] = 0;
	return;
}

void InitPoints()
{
	int i;
	for(i=1;i<=checkpoints;i++)
	{
		Points[i].earlytime = 0;
		Points[i].lasttime = INF;
		Points[i].indegree = 0;
		Points[i].outdegree = 0;
	}
	return;
}

void InsertActivities()
{
	int i,point1,point2,time;
	for(i=1;i<=activities;i++)
	{
		scanf("%d %d %d",&point1,&point2,&time);
		G[point1][point2] = time;
		Points[point1].outdegree++;
		Points[point2].indegree++;
	}
	return;
}

int EarlytimeCheck()
{
	int i,Queue[MAXN],top = 0,rear = 0,point,maxtime = 0;
	for(i=1;i<=checkpoints;i++)
	{
		if(!Points[i].indegree)
		{
			Points[i].indegree--;
			Queue[++top] = i;
		}
	}
	
	while(top != rear)
	{
		point = Queue[++rear];
		for(i=1;i<=checkpoints;i++)
		{
			if(G[point][i])
			{
				Points[i].indegree--;
				if(!Points[i].indegree) Queue[++top] = i;
				if(Points[i].earlytime < Points[point].earlytime + G[point][i])
				{
					Points[i].earlytime = Points[point].earlytime + G[point][i];
					if(Points[i].earlytime > maxtime)
						maxtime = Points[i].earlytime;
				}
			}
		}
	}
	if(top != checkpoints)
		return 0;
	else
		return maxtime;
}

void LasttimeCheck()
{
	int i,j,Queue[MAXN],top = 0,rear = 0,check,point,maxtime = 0;
	for(i=1;i<=checkpoints;i++)
	{
		if(!Points[i].outdegree)
		{
			Queue[++top] = i;
			Points[i].lasttime = totaltime;
			Points[i].outdegree--;
		}
	}
	
	while(top != rear)
	{
		point = Queue[++rear];
		for(i=1;i<=checkpoints;i++)
		{
			if(G[i][point])
			{
				Points[i].outdegree--;
				if(!Points[i].outdegree)  Queue[++top] = i;
				
				//这里就是为什么INF要设置的原因
				//思考一下就懂了嗷
				if(Points[point].lasttime - G[i][point] < Points[i].lasttime)
					Points[i].lasttime = Points[point].lasttime - G[i][point];
			}
		}
	}
	
	for(i=1;i<=checkpoints;i++)
	{
		if(Points[i].lasttime == Points[i].earlytime)
		{
			for(j=checkpoints;j>=1;j--)
			{
				if(G[i][j] && Points[j].lasttime == Points[j].earlytime && Points[i].lasttime == Points[j].lasttime - G[i][j])
					printf("%d->%d\n",i,j);
			}
		}
	}
	return;
}

int main()
{
	scanf("%d %d",&checkpoints,&activities);
	InitGraph();
	InitPoints();
	InsertActivities();
	totaltime = EarlytimeCheck();
	if(totaltime == 0)
		printf("0");
	else
	{
		printf("%d\n",totaltime);
		LasttimeCheck();
	}
	return 0;
}

