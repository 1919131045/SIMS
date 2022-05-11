#include "InfoManager.h"

int main()
{
	system("color F2");                  //设置背景色和前景色
	InfoManager infomanager;             //定义对象
	infomanager.init();                  //初始化
	int choice = 0;

	while (1)
	{
		system("cls");                   //清屏
		             
		showMenu();                      //显示操作菜单
		cin >> choice;                   //输入操作选择
		if (choice == 0)
		{
			infomanager.saveInfo();           //退出
			break;
		}
		switch (choice)
		{
		case 1:
			infomanager.addInfo();       //增加信息
			break;
		case 2:
			infomanager.editInfo();      //修改信息
			break;
		case 3:
			infomanager.delInfo();       //删除信息
			break;
		case 4:
			infomanager.showInfo();      //显示信息
			break;
		default:
			cout << "\n输入有误请重新输入\n" << endl;
		}
		
	}
	
	return 0;
}


