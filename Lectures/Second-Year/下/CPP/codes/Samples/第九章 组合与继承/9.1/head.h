//组合，复用已有类的实现
#include"part.h"

//head类由已有类组成
class Head {
public:
	Eye LeftEye,RightEye;
	Nose nose;
	Mouth mouth;
	Ear LeftEar,RightEar;
	void turn(){
	}
};
