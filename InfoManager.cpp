#include "InfoManager.h"

void showMenu()
{
	cout << "******************************" << endl;
	cout << "*****    ѧ������ϵͳ    *****" << endl;
	cout << "******************************" << endl;
	cout << "****   1.  ����ѧ����Ϣ   ****" << endl;
	cout << "****   2.  �޸�ѧ����Ϣ   ****" << endl;
	cout << "****   3.  ɾ��ѧ����Ϣ   ****" << endl;
	cout << "****   4.  ��ʾѧ����Ϣ   ****" << endl;
	cout << "****       0.  �˳�       ****" << endl;
	cout << "******************************" << endl;
	cout << "********    ��ѡ��    ********" << endl;
	cout << "******************************" << endl;
	
}

//����ѧ����Ϣ
void InfoManager::addInfo()
{
	long num = 0;
	if (count == MAX_COUNT)
	{
		cout<<"ѧ�������Դﵽ���ֵ������������ѧ����" << endl;
		return;
	}
	while (1)
	{
		cout << "������ѧ��:" << endl;
		cin >> num;
		if (num<=0)
		{
			cout << "ѧ�Ų���Ϊ����" << endl;
		}
		else
		{
			if (seekInfo(num) != -1)
			{
				cout << "ѧ���Ѵ���!\n" << endl;
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
	cout << "ѧ����Ϣ������!\n" << endl;
	saveInfo();
	system("psuse");
}


// ����ѧ����Ϣʱ��Ҫ�ж�ѧ���Ƿ��Ѵ���
int InfoManager::seekInfo(long nu)
{
	for (int i = 0; i < count; i++)
	{
		if (stInfo[i].getnum() == nu)
		{
			return i;
		}
	}
	return -1;                                     //����-1����������
}

//���жϳ�ѧ�Ų����ڣ��������������
void InfoManager::inputInfo(long num, int index)
{
	string name;
	string sex;
	string phone;
	int birthyear = 0;
	int se = 0;
	cout << "����������" << endl;
	cin >> name;
	cout << "�������Ա�1.�� 2.Ů��" << endl;
	cin >> se;
	if (se == 1)
	{
		sex = "��";
	}
	if (se == 2)
	{
		sex = "Ů";
	}
	cout << "�����������:" << endl;
	cin >> birthyear;
	cout << "������绰" << endl;
	cin >> phone;
//��������
	stInfo[index].setdata(num, name, sex, birthyear, phone);
}


//�޸���Ϣ
void InfoManager::editInfo()
{
	long nu = 0;
	long i = 0;
	while (1)
	{
		cout << "��������޸ĵ�ѧ��ѧ��\n" << endl;
		cin >> nu;
		if (nu <= 0)
		{
			cout << "ѧ�Ų���Ϊ0����" << endl;
			system("pause");
			return;
		}
		else
		{
			break;
		}
	}
	cout << "ѧ��Ϊ:" << nu << "��ѧ��ԭ��Ϣ���£�" << endl;

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
	cout << "ѧ����Ϣ���޸�\n" << endl;
	saveInfo();
	system("pause");
}

//ɾ��ѧ����Ϣ
void InfoManager::delInfo()
{
	long num = 0;
	long index = 0;
	while (1)
	{
		cout << "�������ɾ��ѧ��ѧ��" << endl;
		cin >> num;
		if (num <= 0)
		{
			cout << "ѧ�Ų���Ϊ����" << endl;
			system("pause");

		}
		else
		{
			if ((index=seekInfo(num))==-1)        //���ѧ���Ƿ����
			{
				cout << "��ѧ��������\n" << endl;
				system("pause");
				return;
			}
			else
			{
				break;
			}
		}
	}
	cout << "ѧ��Ϊ\n" << num << "ѧ����Ϣ������ʾ:" << endl;
	if (count > 0)
	{
		cout << "+----------+----------+----------+----------+----------+" << endl;
		stInfo[index].showdata();
	}
	cout << "ȷ��ɾ����y/n��?" << endl;
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
	cout << "ѧ����Ϣ��ɾ��" << endl;
	saveInfo();
	system("pause");
}

//��ʾ��
void InfoManager::showInfo()
{
	int choice;
	cout << "��ѡ��\n1.ѧ����С����\n\n2.ѧ���ɴ�С\n" << endl;
	cin >> choice;
	Info temp;
	for (int pass = 1; pass < count; pass++)             //����
	{
		for (int j = 0; j < count - pass; j++)
		{
			if ((stInfo[j].getnum() > stInfo[j + 1].getnum() && choice == 1) || (stInfo[j].getnum() < stInfo[j + 1].getnum() && choice != 1))
			{
				temp = stInfo[j];
				stInfo[j] = stInfo[j + 1];
				stInfo[j + 1] = temp;
				saveflag = true;                         //���ñ�����Ϊ��
			}
		}
	}
	if (count > 0)
	{
		cout << "+----------+----------+----------+----------+----------+" << endl;
	}
	else
	{
		cout << "\n~(��_��)~��ѧ����Ϣ~(-_-)~\n" << endl;
	}

	for (int i = 0; i < count; i++)
	{
		
		stInfo[i].showdata();
		
	}
	system("pause");
}

//������Ϣ
void InfoManager::saveInfo()
{
	
	
	ofstream fout(filename, ios::out);
	if (!fout)
	{
		cout << "���ļ�ʧ��\n" << endl;
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
	cout << "ѧ����Ϣ�ѱ�����Ӳ��\n" << endl;
}



void InfoManager::init()   //��ʼ������
{
	readInfo();
}

void InfoManager::readInfo()  //��ȡ
{

	long num;
	string name;
	string sex;
	string phone;
	int birthday;
	cout << "�������ļ���:" << endl;
	cin >> filename;
	ifstream fin(filename, ios::in);
	if (!fin)
	{
		cout << "���ļ�ʧ��\n" << endl;
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
	cout << "ѧ����Ϣ�Ѷ�ȡ\n" << endl;
	system("pause");
}
