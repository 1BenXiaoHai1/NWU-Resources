/*
 * ex13_7.cpp
 *
 *  7. ��֪һ��������C++����
int main(){
//ʹ��C++��׼��
}
���޸�main()���Բ���C++��׼���еĺ������׳����κ��쳣��Ҫ���쳣���������
����abort()����main()֮ǰ��ӡ�����쳣����Ϣ��

 */

#include<exception>
#include<stdexcept>
#include<iostream>
using namespace std;
int main(){
	try{
		//......
		// call standard library functions here...
		//test:
		//throw runtime_error("error!");
		//......

	}
	catch(exception& e){
		cout<< e.what()<<endl;
		throw;
	}

	return 0;
}


