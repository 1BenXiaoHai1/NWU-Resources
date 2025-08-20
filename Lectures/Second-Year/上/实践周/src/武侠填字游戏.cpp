#include<iostream>
#include<string>
#include<stdlib.h>
#include <cstring>
#include <ctime>
#include <cstdio>

using namespace std;

typedef struct _user{
	int account;//账户
	string password;//密码
}User;

#define GAME "D:\\Desktop\\names.dat"
#define PLAYER "D:\\Desktop\\players.dat"
#define N 20

int menuPrint();//菜单打印函数
void rulePrint();//规则打印

void login();//登录
void fileWrite();//生成游戏文件
int gamePlay();//开始游戏
void addPoint();//加分函数
void Rank();//排行榜

char player_name[200];




int main(void)
{
	system("color f0");//设置背景颜色为白色
	cout<<"\t\t|武侠填字游戏|"<<endl<<endl;
	cout<<"欢迎来到武侠填字游戏"<<endl;
	rulePrint();//输出游戏规则
	cout<<"请您先登录"<<endl;
	login();//登录
	while(1){
		loop:switch (menuPrint()) {
		case 0:
			gamePlay();
			break;
		case 1:
			Rank();
			break;
		case 2:
			cout<<"欢迎下次再玩";
			break;
			default:
				cout<<"The input is invaluable.Please input again."<<endl;
				goto loop;//goto语句跳转到输入环节
				break;
		}
	}

	
	system("pause");
	return 0;
}

void fileWrite()//生成游戏文件
{
	//写文件流程：打开文件——写文件——关闭文件
	FILE* fp = fopen(GAME, "wb+");
	if (fp == NULL) {
		cout << "文件打开失败！";
		return;
	}
	fputs("20\n", fp);//小说数量
	
	//书名
	fputs("白发魔女传,练霓裳,卓一航,岳鸣珂,铁珊瑚,白石道人\n", fp);//1
	fputs("七剑下天山,凌未风,桂仲鸣,冒浣莲,易兰珠,张华昭\n", fp);//2
	fputs("萍踪侠影录,张丹枫,云蕾,澹台镜明,周山民,石翠凤\n", fp);//3
	fputs("云海玉弓缘,金世遗,厉胜男,谷之华,江南,李沁梅\n", fp);//4
	fputs("鹿鼎记,韦小宝,康熙,陈近南,苏荃,方怡\n", fp);//5
	fputs("天龙八部,段誉,萧峰,虚竹,段正明,刀白凤\n", fp);//6
	fputs("笑傲江湖,令狐冲,任盈盈,岳灵珊,林平之,岳不群\n", fp);//7
	fputs("神雕侠侣,杨过,小龙女,陆无双,公孙止,金轮法王\n", fp);//8
	fputs("射雕英雄传,郭靖,黄蓉,杨康,穆念慈,黄药师\n", fp);//9
	fputs("倚天屠龙记,张无忌,赵敏,周芷若,小昭,殷离\n", fp);//10
	fputs("玉钗盟,徐元平,萧姹姹,金老二,欧驼子,胡矮子\n", fp);//11
	fputs("金剑雕翎,萧翎,岳小钗,沈木风,百里冰,南宫玉\n", fp);//12
	fputs("水浒传,宋江,卢俊义,吴用,公孙胜,关胜\n", fp);//13
	fputs("仙鹤神针,马君武,李青鸾,蓝海萍,白云飞,蓝小蝶\n", fp);//14
	fputs("天蚕变,云飞扬,独孤凤,傅香君,傅玉书,伦婉儿\n", fp);//15
	fputs("多情剑客无情剑,李寻欢,阿飞,孙小红,林仙儿,孙白发\n", fp);//16
	fputs("楚留香传奇,楚留香,胡铁花,张洁洁,卜担夫,艾青\n", fp);//17
	fputs("陆小凤传奇,陆小凤,花满楼,西门吹雪,叶孤城,司空摘星\n", fp);//18
	fputs("七种武器,白玉京,袁紫霞,高立,秋风梧,段玉\n", fp);//19
	fputs("天涯明月刀,傅红雪,燕南飞,公子羽,明月心,卓玉贞\n", fp);//20

	
	fclose(fp);
	
}

void login()
{
	//char player_name[200]={0}, str[200]={0};
	char str[200] = { 0 };
	cout << "请输入用户名：";
	cin >> player_name;
	
	FILE* fp = fopen(PLAYER, "ab+");
	//PLAYER的存储方式为，每行存储一个【用户名-分数】
	
	int flag = 0;
	while (fgets(str, 200, fp))
	{
		/*cout << str << endl;*/
		char getname[200] = { 0 };
		for (int k = 0, j = 0; str[k] != '-' && k < strlen(str); k++, j++) //
		{
			getname[j] = str[k];
		}
		//判断用户是否注册过
		if (strcmp(getname, player_name) == 0) {
			cout << "\n欢迎回来，" << player_name << "\n登录成功！现在可以开始游戏了！\n" << endl;
			flag = 1;
			break;
		}
	}
	if (!flag)//如果该用户未注册过，则进行注册
	{
		//fputs("\n", fp);
		fputs(player_name, fp);
		fputs("-0\n", fp);//初始分数为0
		cout << "欢迎您，" << player_name << "。您是新用户，已为您完成注册！\n现在可以开始游戏了！" << endl;
	}
	fclose(fp);
	
}

int menuPrint()
{
	cout<<"0.开始游戏\t1.排行榜\t2.退出游戏"<<endl;
	cout<<"请输入你的选项:";
	int flag;
	cin>>flag;
	
	return flag;

}

void rulePrint()
{
	cout << "\n\n用户选择开始游戏，程序开始自上向下显示 5 行文本，\n"
	<< "第一行文本内容为随机填充的武侠小说的名字，第二--第五行文本为对应武侠小说中主要角色的名字，\n填充要求如下： \n\n"
	<< "首先随机选择一个武侠小说，并根据小说名字的长度，随机去掉名字中 50 % 的字符（可以连续，也可以不连续）；\n"
	<< "然后再次随机，从该小说列出的主要角色名字中选取 4 个，每个人名中随机选择 1 个字用“※”号代替，并显示在小说名字下方。\n"
	<< "用户可以按照顺序（命令行）或选中缺失文本（图形）通过输入的方式对小说名字和主要角色名字进行补全，\n"
	<< "输入完成后，输入“submit”（命令行）或者点击“提交”按钮提交答案，\n"
	<< "程序判断该输入是否正确，都正确弹出对话框提示用户正确并再次出题；\n"
	<< "不正确的继续显示错误文本并提示用户输入，\n\n"
	<< "三次错误后，程序显示正确结果并提示用户游戏结束，根据答对次数显示等额数字给出分数，并返回主菜单" << endl;
}

int gamePlay()
{
	cout<<"\t\t|开始游戏|"<<endl;
	//玩游戏——文件随机读取
	FILE* fp = fopen(GAME, "rb");
	char str[200] = { 0 };
	//fgets函数每次随机读取一行数据，可通过随机生成读取第几行，来实现文件随机读取
	fgets(str, 200, fp);//先读掉第一行的数字N
	fgets(str, 200, fp);
	int n;
	srand((unsigned)time(NULL));//随机数种子
	
	n = rand() % N;//随机选择一个书名
	for (int i = 0; i < n; i++) {
		fgets(str, 200, fp);
	}//读取到第n行
	cout << str << endl;
	string s = str;
	string name = "";
	for (int i = 0; s[i] != ',' && i < s.length(); i++) {
		name += s[i];
	}
	cout << name << endl;//输出当前读取到的小说及其人物名
	
	//随机去掉字符
	int len = name.length();
	string sname = name;
	string ch = "※";
	
	int visited[10] = { 0 };	//访问标记数组
	for (int i = 0; i < len / 4; i++) {	//len除以4是因为每次需要替换2个字符。再除以2用来替换字符串中一半的字符
		int j = rand() % (len / 4);	//随机选择一个位置
		if (visited[j]) {	//检查是否有替换过
			i--;
			continue;
		}
		else {
			sname = sname.replace(j * 2, 2, ch);//每次替换2个字符才能成功替换
			visited[j] = 1;//已经替换，改变visit的值
		}
	}
	cout << sname << endl;
	//读取人物名字
	string pname[5];
	string qname[5];//qname用来存储没有修改过的pname
	int k = len;
	for (int j = 0; j < 5; j++) { //将人物名存入pname和qname数组
		k = k + 1;
		for (; s[k] != ',' && k < s.length() - 1; k++) //设定范围为length-1是为了不读到行末尾的回车
		{
			pname[j] += s[k];
			qname[j] += s[k];
		}
		cout << pname[j]<< " " ;
	}
	cout<<endl;
	
	n = rand() % 5;	//随机选择一个不显示的位置
	for (int j = 0; j < 5; j++) {
		if (j != n) {
			int r = rand() % (pname[j].length() / 2);	//随机选择一个字进行覆盖
			pname[j] = pname[j].replace(r * 2, 2, ch);//每次替换2个字符才能成功替换
			cout << pname[j] << endl;
		}
	}
	
	int loop = 1;//loop用来计算循环次数
	while (loop > 0 && loop <= 3)
	{
		cout << "请你猜猜被遮盖的字，在下面打出完整的名字（其间以空格或者回车分隔）：" << endl;
		string input[5];
		for (int i = 0; i < 5; i++) {
			cin >> input[i];
		}
		int flag = 1;
		if (input[0] == name) {
			for (int i = 1, j = 0; i < 5; i++, j++) {
				if (j != n) { //n为不显示的位置
					if (input[i] == qname[j]);
					else flag = 0;
				}
				else i--;
			}
		}
		else flag = 0;
		switch (flag)
		{
		case(0):
			if (loop < 3) cout << "答错了，请重新输入！" << "你还有" << 3 - loop << "次机会！\n" << endl;
			else {
				cout << "你的机会用完了！下次再来吧！" << endl;
				cout << "正确答案：";
				cout << name << "，";
				for (int i = 0, j = 0; i < 5; i++, j++) {
					if (j != n) { //n为不显示的位置
						if (n == 4) {
							if (j != 3) cout << qname[i] << "，";
							else cout << qname[i] << endl;
						}
						else {
							if (j != 4) cout << qname[i] << "，";
							else cout << qname[i] << endl;
						}
					}
				}
				cout << "\n\n=====================即将返回主菜单...=======================\n";
				//cout << "请选择：\n1.开始游戏\n2.游戏说明\n3.排行榜\n" << "请输入您的选择：";
				//int r;//记录返回值
				//cin >> r;
				return 0;
			}
			loop++;
			break;
		case(1):
			cout << "恭喜你答对了！继续看下一道题吧！\n" << endl;
			loop = 0;
			addPoint();	//给玩家加1分
			return 1;
			break;
		}
	}

}

void addPoint()
{
	FILE* f = fopen(PLAYER, "rb+");
	char point[200] = { 0 };//point用来记录用户名对应的分数
	char str[200] = { 0 };
	while (fgets(str, 200, f))
	{
		char getname[200] = { 0 };
		int k = 0; int j = 0;
		for (k = 0, j = 0; str[k] != '-' && k < strlen(str); k++, j++)
		{
			getname[j] = str[k];
		}
		if (strcmp(getname, player_name) == 0) { //在文件中找到用户名	
			for (k = k + 1, j = 0; str[k] != '\n' && k < strlen(str); k++, j++)
			{
				point[j] = str[k];//用point储存当前的分数
			}
			break;
		}
	}
	int len = strlen(point);
	string p = point;
	int n = stoi(p); //把存储在字符串中的数字转化为int
	p = std::to_string(n + 1); //给分数＋1后再转换成字符串
	for (int k = 0; p[k] != '\0'; k++) //把字符串复制到字符数组中
	{
		point[k] = p[k];
	}
	fseek(f, -len - 1, SEEK_CUR);
	fputs(point, f);
	
	fclose(f);
}

void Rank()//显示排行榜
{
	int max = 0;
	FILE* f = fopen(PLAYER, "rb+");
	char point[200] = { 0 };//point用来记录当前用户名对应的分数
	char str[200] = { 0 };
	while (fgets(str, 200, f))
	{
		int k = 0, j = 0;
		while (str[k] != '-') k++; //定位到当前用户名的分数之前
		
		for (k = k + 1, j = 0; str[k] != '\n' && k < strlen(str); k++, j++)
		{
			point[j] = str[k];//用point储存当前的分数
		}
	}
	string p = point;
	int n = stoi(p); //把存储在字符串中的数字转化为int
	if (n > max) max = n;
	cout << "\n==============排行榜=================" << endl;
	cout << "\n当前所有参与游戏用户的最高分为：" << max << endl;
	cout << "\n......" << endl;
	cout << "\n按任意键返回主菜单\n" << endl;
	getchar();
	getchar();
	fclose(f);
}
