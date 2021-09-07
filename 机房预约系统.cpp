#include <iostream>
using namespace std;
#include "Identity.h"
#include <fstream>
#include <string>
#include "globalFile.h"
#include "Teacher.h"
#include "Student.h"
#include "Manager.h"

//登陆功能
//参数1 操作文件名 参数2 操作的身份类型
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接受用户的信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1)
	{
		//学生
		cout << "请输入你的学号:" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		//老师
		cout << "请输入你的职工号:" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生身份验证
		int fId;//从文件中读取的id号
		string  fName;//从文件中获取的姓名
		string fPwd;//从文件中获取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登陆成功 ！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份的子菜单

				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师身份验证
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登陆成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师子菜单界面

				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员身份验证
	}

	cout << "验证登陆失败" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select = 0;
	while (true)
	{
		cout << "======================  欢迎来到传智播客机房预约系统  ====================="
			<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select; //接受用户选择

		switch (select)
		{
		case 1://Student
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://Teacher
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://Admin
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://Exit
			cout << "欢迎下次使用！" << endl;
			return 0;

			break;

		default:
			cout << "Input Error!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	

	return 0;
}