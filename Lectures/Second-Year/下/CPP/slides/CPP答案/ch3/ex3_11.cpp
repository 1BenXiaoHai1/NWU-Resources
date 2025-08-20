/*
 * ex3_11.cpp
 *
 11. 编写程序提示用户输入体征和身高，然后显示身体质量指数（BMI）值和体重状况说明。
 BMI的计算公式为：BMI = weight / height2，体重单位公斤，身高单位米。
 成人BMI值说明：（1）BMI<18.5：偏瘦；（2）18.5≤BMI<25.0：正常；
 （3）25.5≤BMI<30.0：超重；（4）BMI≥30.0：过胖
 */

#include<iostream>
using namespace std;

int main()
{
	double weight, height, bmi;

	cout << "Enter your weight in KiloGram: ";
	cin >> weight;
	cout << "Enter you height in Meter: ";
	cin >> height;

	bmi = weight / (height * height);

	cout << "BMI is " << bmi << endl;

	if(bmi < 18.5)
		cout << "Underweight" << endl;
	else if (bmi < 25.0)
		cout << "Normal" << endl;
	else if(bmi < 30)
		cout << "Overweight" << endl;
	else
		cout << "Obese" << endl;

	return 0;
}


