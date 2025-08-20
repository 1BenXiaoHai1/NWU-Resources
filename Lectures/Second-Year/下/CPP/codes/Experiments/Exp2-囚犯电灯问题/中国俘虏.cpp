#include<iostream>
#include<fstream>
#include<time.h>
#include<cstdlib>

using namespace std;

enum StoneStatus {UP, DOWN}; //石头状态

int main() {
	
	ofstream fout("text.txt");//把放风数据写在文件中
	int members[50] = {0};//50个成员（0代表没开过灯，1代表开过灯）
	int daysCnt = 0;
	int Master = 49;//假定最后一个人为村长
	StoneStatus stone = UP ;//最开始石头向上
	int AlivePerson = 1;//村长必活着，所以只需判断其他49个人是否活着

	while (AlivePerson!=49) {
		//随机数生成
		time_t t;
		srand((unsigned)time(&t));//随机数种子
		int OutPerson = int(rand() % (49 - 0 + 1)) + 0; //随机派一个人出去望风（生成范围为0-49的数字）
		//如果派出去望风的人为村长
		if (OutPerson == Master) {
			if (stone == UP) { //如果石头向上，说明没人出来望风，因此石头保持原来向上的状态
				daysCnt++;//天数+1
//				fout<<"No one out"<<endl;
			} else { //石头向下，说明有人出来望风。石头被翻了，至少有一人活着
				daysCnt++;//天数+1
				stone = UP;//把石头从down变为up
				AlivePerson++;//活人数加1
				if (AlivePerson == 50) {//人数够了
					fout << "所有人均活着，判断所有人均活着的天数为" << daysCnt << endl;
					cout << "所有人均活着，判断所有人均活着的天数为" << daysCnt << endl;
					break;
				} else {//人数不够继续
					continue;
				}
			}
		} else { //望风的人不是村长
			if (stone == UP) { //如果朝上，说明还没有人翻过石头，村民可以翻石头
				daysCnt++;//天数+1
				if (members[OutPerson] == 0) { //如果没翻过石头，则可以翻石头
					stone = DOWN;//从村长的UP状态翻成DOWN状态
					members[OutPerson] = 1;//修改村民状态，已翻过石头
					fout<<OutPerson + 1<<"turns up to down"<<endl;
				} else { //翻过石头就不要翻石头（已统计过）
					continue;
				}
			} else { //DOWN就不要翻
				daysCnt++;//天数+1
				continue;
			}

		}
	}


	return 0;
}
