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
	
	void addInfo();                              //����
	int seekInfo(long nu);                       //����
	void inputInfo(long num,int index);          //����
	void editInfo();                             //�޸�
	void delInfo();                              //ɾ��
	void showInfo();                             //��ʾ
	void saveInfo();                             //����
	void readInfo();                             //��ȡ
	void init();                                 //��ʼ��


private:
	Info stInfo[MAX_COUNT];                      //���ѧ����Ϣ��Info����
	int count;                                   //ѧ������
	bool saveflag;                               //������
	string filename;                             //�ļ���
};

void showMenu();