#include "InfoManager.h"

int main()
{
	system("color F2");                  //���ñ���ɫ��ǰ��ɫ
	InfoManager infomanager;             //�������
	infomanager.init();                  //��ʼ��
	int choice = 0;

	while (1)
	{
		system("cls");                   //����
		             
		showMenu();                      //��ʾ�����˵�
		cin >> choice;                   //�������ѡ��
		if (choice == 0)
		{
			infomanager.saveInfo();           //�˳�
			break;
		}
		switch (choice)
		{
		case 1:
			infomanager.addInfo();       //������Ϣ
			break;
		case 2:
			infomanager.editInfo();      //�޸���Ϣ
			break;
		case 3:
			infomanager.delInfo();       //ɾ����Ϣ
			break;
		case 4:
			infomanager.showInfo();      //��ʾ��Ϣ
			break;
		default:
			cout << "\n������������������\n" << endl;
		}
		
	}
	
	return 0;
}


