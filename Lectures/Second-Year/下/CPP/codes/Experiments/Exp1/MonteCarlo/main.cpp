//Monte Carlo算法
#include<iostream>
//随机数生成头文件
#include<cstdlib>
#include<ctime>

using namespace std;

//投点次数为100000次
const int nExper = 100000;

int main()
{
	int cnt=0;//总投掷点数 落在圆内的点数
	double Pi;

	//随机数生成
	unsigned seed;
	seed=time(0);
	srand(seed);

	//通过分析点的投掷落在不同区域的概率，来表示面积比
	for(int i=0;i<nExper;i++){
		//点的生成（x属于0~100 y属于0~100）
		int x = rand()%100;
		int y = rand()%100;
		//cout<<"生成的点为:"<<x<<' '<<y<<endl;
		//点的位置判断(点在圆内)
		if((x-50)*(x-50)+(y-50)*(y-50)<=2500){
			cnt++;
		}
	}
	//计算概率，求Pi
	Pi = static_cast<double>(cnt)/nExper*4;//概率表示面积比
	cout.precision(3);//设置输出格式为3位小数
	cout<<"Pi的值为"<<fixed<<Pi;

	return 0;

}
