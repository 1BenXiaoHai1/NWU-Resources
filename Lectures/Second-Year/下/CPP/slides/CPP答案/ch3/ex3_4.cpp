/*
 * ex3_4.cpp
 *
 * 4. ��д�����������һ��1��12֮���������������ֵ��ʾ��Ӧ��Ӣ���·����������ɵ���Ϊ3ʱ��ʾMarch��
	����������Ŀ⺯��Ϊrand()������һ��0~RAND_MAX֮���intֵ��Ҫ������׼��<cstdlib>��
	RAND_MAX�ǿ��ж���ĳ�����ֵ��СΪ32767�����磬����10���ڵ����������Ϊ��rand()%10��
 */

#include<iostream>
#include<cstdlib>
//#include<string>		//solution 2
using namespace std;
int main()
{
	int month = (rand() % 12) + 1;
	//����һ��switch case
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



