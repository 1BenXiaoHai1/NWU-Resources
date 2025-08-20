#include<stdio.h>
#include<string.h>

//定义定长字符串
#define MaxLen 10000
typedef struct {
	char ch[MaxLen];
	int len;
} SString;

//统计字串函数
void StrIndexAndCount(SString s, SString t) {
	//模式匹配
	int firstPos = -1, cnt = 0;//子串第一次出现位置 字串出现次数
	int pos = 0;

	while (pos < s.len) {
		//匹配二者公共部分
		int i = pos, j = 0;//遍历比对指针回归最初位置
		while (i < s.len && j < t.len) {
			if (s.ch[i] == t.ch[j]) {
				i++;
				j++;
			} else {
				pos++;//开始位置后移
				i = pos; //i回归
				j = 0; //j回归到最初位置
			}
		}
		//若t串还有剩余，说明s中不存在该字串,反之大于等于代表无剩余，存在子串t
		if (j >= t.len) {
			if (cnt == 0) {//保存第一次出现位置
				firstPos = pos;
			}
			cnt++;//存在子串——出现次数+1
		}
		pos++;
	}
	//输出判断
	if (firstPos != -1) {//firstPos不为-1，说明存在字串
		printf("%d %d\n", firstPos + 1, cnt);
	} else {
		printf("0 0\n");
	}

}

int main() {
	SString s, t;
	int T;

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		//两字符串直接采用空格进行区分，所以采用scanf
		scanf("%s", s.ch); //scanf读到空格、回车停止
		scanf("%s", t.ch);
		//初始化长度
		s.len = strlen(s.ch);
		t.len = strlen(t.ch);
		//统计字串
		StrIndexAndCount(s, t);
	}

	return 0;
}
