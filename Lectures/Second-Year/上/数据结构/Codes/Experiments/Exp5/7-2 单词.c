#include<stdio.h>
#include<string.h>

//定义定长字符串
#define MaxLen 10000
typedef struct {
	char ch[MaxLen];
	int len;
} SString;

int CountEffectiveWord(SString sentence) {
	int cnt = 0;
	int i = 0;
	while (sentence.ch[i] != '\0') { //外层循环用来遍历整个句子
		int flag = 1;//判断变量
		//空格
		while (sentence.ch[i] == ' ') {//持续跳过
			i++;
		}
		
		//判断一个单词是否合法（空格或结束符为标志位）
		while (sentence.ch[i] != ' ' && sentence.ch[i] != '\0') {
			if (sentence.ch[i] >= 'a' && sentence.ch[i] <= 'z') { //字母
				//字母后面接着连字符情况
				if (sentence.ch[i + 1] == '-') {
					if (sentence.ch[i + 2] >= 'a' && sentence.ch[i + 2] <= 'z') { //若连字符后面为字母
						i = i + 1;//直接跳过连接符，从连接符后字母开始
					} else {
						flag = 0;; //连字符后不是字母不为有效单词
					}
				}
				//字母后紧跟标点符号
				if (sentence.ch[i + 1] == ',' || sentence.ch[i + 1] == '.' || sentence.ch[i + 1] == '!') {
					if (sentence.ch[i + 2] != ' ' && sentence.ch[i + 2] != '\0') { //若连字符后面不为空格或结束符
						flag = 0; //不合法单词
					}
				}
			} else if (sentence.ch[i] >= '0' && sentence.ch[i] <= '9') { //存在数字则不为有效单词
				flag = 0;
			} else if (sentence.ch[i] == '-') { //第一个字符为连接符
				flag = 0;
			} else if (sentence.ch[i] == '!' || sentence.ch[i] == ',' || sentence.ch[i] == '.') {//第一个字符为标点
				flag = 0;
			} else{//其他无效字符
				flag = 0;
			}
			i++;
		}
		
		//判断当前所遍历的一个单位是否为有效单词
		if (flag == 1) {
			cnt++;
		}
	}
	
	return cnt;
}

int main() {
	SString sentence;
	
	gets(sentence.ch);
	sentence.len = strlen(sentence.ch);
	int num = CountEffectiveWord(sentence);//统计有效单词数量
	printf("%d", num);
	
	return 0;
}
