/*
 * ex3_4.cpp
 *
 * 4. 编写程序，随机产生一个1到12之间的整数，根据数值显示相应的英文月份名。如生成的数为3时显示March。
	生成随机数的库函数为rand()，返回一个0~RAND_MAX之间的int值，要包含标准库<cstdlib>。
	RAND_MAX是库中定义的常量，值最小为32767。例如，生成10以内的随机数代码为：rand()%10。
 */

#include<iostream>
#include<cstdlib>
//#include<string>		//solution 2
using namespace std;
int main()
{
	int month = (rand() % 12) + 1;
	//方法一：switch case
	switch(month){
	case 1:
		cout << "January" << endl; break;
	case 2:
		cout << "February" << endl; break;
	case 3:
		cout << "March" << endl; break;
	case 4:
		cout << "April" << endl; break;
	case 5:
		cout << "May" << endl; break;
	case 6:
		cout << "June" << endl; break;
	case 7:
		cout << "July" << endl; break;
	case 8:
		cout << "August" << endl; break;
	case 9:
		cout << "September" << endl; break;
	case 10:
		cout << "October" << endl; break;
	case 11:
		cout << "November" << endl; break;
	case 12:
		cout << "December" << endl; break;
	default:
		cout << "Something Wrong!" << endl;
	}

	//solution 2: string and array
//	string monthNames[] = {"", "January", "February", "March", "April", "May", "June",
//			"July", "August", "September","October", "November", "December"	};
//	cout << monthNames[month] << endl;

	return 0;
}



