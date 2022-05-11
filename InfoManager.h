#pragma once

#include "Info.h"
#define MAX_COUNT 100

class InfoManager
{
public:
	InfoManager()
	{
		count = 0;
		saveflag = false;
	}
	
	void addInfo();                              //增加
	int seekInfo(long nu);                       //查找
	void inputInfo(long num,int index);          //输入
	void editInfo();                             //修改
	void delInfo();                              //删除
	void showInfo();                             //显示
	void saveInfo();                             //保存
	void readInfo();                             //读取
	void init();                                 //初始化


private:
	Info stInfo[MAX_COUNT];                      //存放学生信息的Info数组
	int count;                                   //学生人数
	bool saveflag;                               //保存标记
	string filename;                             //文件名
};

void showMenu();