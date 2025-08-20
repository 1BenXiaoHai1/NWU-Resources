#include"String.h"

int StrInsert(SString *s,int pos,SString t){
	int i;
	//判断插入位置是否合法
	if(pos<0||pos>s->len){
		return false;
	}
	//判断插入结果
	if(s->len+t.len<=MaxSize){//t可以全部插入
		//pos后的串B后移t.len个长度
		for(i=s->len-1+t.len-1;i>=t.len+pos;i--){
			s->ch[i] = s->ch[i-t.len];
		}
		//在pos和pos+t.len中插入t
		for(i=0;i<t.len;i++){
			s->ch[i+pos]=t.ch[i];
		}
	}else if(pos+t.len<=MaxSize){//pos后串B被截取，t可以完全插入
		//先把t串插入
		//pos后的串B后移
		for(i=MaxSize-1;i>t.len+pos-1;i--){
			s->ch[i]=s->ch[i-t.len];
		}
		//插入t
		for(i=0;i<t.len;i++){
			s->ch[i+pos]=t.ch[i];
		}
	}else{//pos后串被完全截取并且t也被截取
		
	}
}

int StrDelete(SString *s,int pos,int len){
	int i;
	
	//判断删除位置-不小于0 、pos+len>s->len多删除
	if(pos<0||pos+len>s->len){
		return 0;
	}
	//pos+len之后元素前移len个单位
	for(i=pos+len;i<s->len;i++){
		s->ch[i-len]=s->ch[i];//元素前移len个单位
	}
	s->len=s->len-len;//修改串长
	
	return 1;
}
//相等返回零，s>t返回正数，s<t返回负数
int StrCompare(SString s,SString t){
	int i;
	for(int i=0;i<s.len&&i<t.len;i++){
		//不相等
		if(s.ch[i]!=t.ch[i]){
			return s.ch[i]-t.ch[i];//通过字符的插值来反映正负
		}
	}
	//相同长度情况下完全相同
	//存在t比s短
	return s.len-t.len;//返回长度
}
int StrIndex(SString s,int pos,SString t);//简单模式匹配定位函数

