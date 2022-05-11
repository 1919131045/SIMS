#include "InfoManager.h"

void showMenu()
{
	cout << "******************************" << endl;
	cout << "*****    学生管理系统    *****" << endl;
	cout << "******************************" << endl;
	cout << "****   1.  增加学生信息   ****" << endl;
	cout << "****   2.  修改学生信息   ****" << endl;
	cout << "****   3.  删除学生信息   ****" << endl;
	cout << "****   4.  显示学生信息   ****" << endl;
	cout << "****       0.  退出       ****" << endl;
	cout << "******************************" << endl;
	cout << "********    请选择    ********" << endl;
	cout << "******************************" << endl;
	
}

//增加学生信息
void InfoManager::addInfo()
{
	long num = 0;
	if (count == MAX_COUNT)
	{
		cout<<"学生人数以达到最大值，不能再增加学生！" << endl;
		return;
	}
	while (1)
	{
		cout << "请输入学号:" << endl;
		cin >> num;
		if (num<=0)
		{
			cout << "学号不能为负数" << endl;
		}
		else
		{
			if (seekInfo(num) != -1)
			{
				cout << "学号已存在!\n" << endl;
				system("pause");
				return;
			}
			else
			{
				break;
			}
		}
	}
	inputInfo(num, count);
	count++;
	saveflag = true;
	cout << "学生信息已输入!\n" << endl;
	saveInfo();
	system("psuse");
}


// 增加学生信息时，要判断学号是否已存在
int InfoManager::seekInfo(long nu)
{
	for (int i = 0; i < count; i++)
	{
		if (stInfo[i].getnum() == nu)
		{
			return i;
		}
	}
	return -1;                                     //返回-1表明不存在
}

//若判断出学号不存在，则继续输入数据
void InfoManager::inputInfo(long num, int index)
{
	string name;
	string sex;
	string phone;
	int birthyear = 0;
	int se = 0;
	cout << "请输入姓名" << endl;
	cin >> name;
	cout << "请输入性别（1.男 2.女）" << endl;
	cin >> se;
	if (se == 1)
	{
		sex = "男";
	}
	if (se == 2)
	{
		sex = "女";
	}
	cout << "请输入出生年:" << endl;
	cin >> birthyear;
	cout << "请输入电话" << endl;
	cin >> phone;
//设置数据
	stInfo[index].setdata(num, name, sex, birthyear, phone);
}


//修改信息
void InfoManager::editInfo()
{
	long nu = 0;
	long i = 0;
	while (1)
	{
		cout << "请输入待修改的学生学号\n" << endl;
		cin >> nu;
		if (nu <= 0)
		{
			cout << "学号不能为0或负数" << endl;
			system("pause");
			return;
		}
		else
		{
			break;
		}
	}
	cout << "学号为:" << nu << "的学生原信息如下：" << endl;

	for (i = 0; i < count; i++)
	{
		if (nu == stInfo[i].getnum())
		{
			if (count > 0)
			{
				cout << "+----------+----------+----------+----------+----------+" << endl;
				stInfo[i].showdata();
			}
		}
		break;
	}
	inputInfo(nu, i);
	saveflag = true;
	cout << "学生信息已修改\n" << endl;
	saveInfo();
	system("pause");
}

//删除学生信息
void InfoManager::delInfo()
{
	long num = 0;
	long index = 0;
	while (1)
	{
		cout << "请输入待删除学生学号" << endl;
		cin >> num;
		if (num <= 0)
		{
			cout << "学号不能为负数" << endl;
			system("pause");

		}
		else
		{
			if ((index=seekInfo(num))==-1)        //检查学号是否存在
			{
				cout << "该学生不存在\n" << endl;
				system("pause");
				return;
			}
			else
			{
				break;
			}
		}
	}
	cout << "学号为\n" << num << "学生信息如下所示:" << endl;
	if (count > 0)
	{
		cout << "+----------+----------+----------+----------+----------+" << endl;
		stInfo[index].showdata();
	}
	cout << "确认删除（y/n）?" << endl;
	getchar();
	if (getchar() != 'y')
	{
		return;
	}
	else
	{
		for (int i = index; i < count - 1; i++)
		{
			stInfo[i] = stInfo[i + 1];
		}
	}
	count--;
	saveflag = true;
	cout << "学生信息已删除" << endl;
	saveInfo();
	system("pause");
}

//显示表
void InfoManager::showInfo()
{
	int choice;
	cout << "请选择：\n1.学号由小到大\n\n2.学号由大到小\n" << endl;
	cin >> choice;
	Info temp;
	for (int pass = 1; pass < count; pass++)             //排序
	{
		for (int j = 0; j < count - pass; j++)
		{
			if ((stInfo[j].getnum() > stInfo[j + 1].getnum() && choice == 1) || (stInfo[j].getnum() < stInfo[j + 1].getnum() && choice != 1))
			{
				temp = stInfo[j];
				stInfo[j] = stInfo[j + 1];
				stInfo[j + 1] = temp;
				saveflag = true;                         //设置保存标记为真
			}
		}
	}
	if (count > 0)
	{
		cout << "+----------+----------+----------+----------+----------+" << endl;
	}
	else
	{
		cout << "\n~(—_—)~无学生信息~(-_-)~\n" << endl;
	}

	for (int i = 0; i < count; i++)
	{
		
		stInfo[i].showdata();
		
	}
	system("pause");
}

//保存信息
void InfoManager::saveInfo()
{
	
	
	ofstream fout(filename, ios::out);
	if (!fout)
	{
		cout << "打开文件失败\n" << endl;
		system("pause");
		return;
	}
	for (int i = 0; i < count; i++)
	{
		fout << stInfo[i].getnum() << " "
			<< stInfo[i].getname() << " "
			<< stInfo[i].getsex() << " "
			<< stInfo[i].getbirthday() << " "
			<< stInfo[i].getphone() << endl;
		
		saveflag = false;
	}
	fout.close();
	cout << "学生信息已保存至硬盘\n" << endl;
}



void InfoManager::init()   //初始化函数
{
	readInfo();
}

void InfoManager::readInfo()  //读取
{

	long num;
	string name;
	string sex;
	string phone;
	int birthday;
	cout << "请输入文件名:" << endl;
	cin >> filename;
	ifstream fin(filename, ios::in);
	if (!fin)
	{
		cout << "打开文件失败\n" << endl;
		system("pause");
		return;
	}
	while (!fin.eof())
	{
		fin >> num >> name >> sex >> birthday >> phone;
		if (!fin.fail())
		{
			stInfo[count].setdata(num, name, sex, birthday, phone);
			count++;
		}
	}
	fin.close();
	cout << "学生信息已读取\n" << endl;
	system("pause");
}
