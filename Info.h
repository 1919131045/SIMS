#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Info
{
public:
	Info()
	{ }

	Info(long nu, string na, string se, int bi, string ph) :
		num(nu), name(na), sex(se), birthday(bi), phone(ph)
	{ }

	void setdata(long nu, string na, string se, int bi, string ph)
	{
		num = nu;
		name = na;
		sex = se;
		birthday = bi;
		phone = ph;
	}

	void showdata()
	{
		cout << "|" <<setw(10) << num
			<< "|" <<setw(10) << name
			<< "|" <<setw(10) << sex
			<< "|" <<setw(10) << birthday 
			<< "|" <<setw(10) << phone
			<< "|" << endl;
		cout << "+----------+----------+----------+----------+----------+" << endl;
	}

	long getnum()
	{
		return num;
	}

	string getname()
	{
		return name;
	}

	string getsex()
	{
		return sex;
	}

	int getbirthday()
	{
		return birthday;
	}

	string getphone()
	{
		return phone;
	}
private:
	long num;        //学号
	string name;     //姓名
	string sex;      //性别
	int birthday;    //生日
	string phone;    //电话
};