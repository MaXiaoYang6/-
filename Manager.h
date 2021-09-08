#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include <fstream>
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include <algorithm>
#include "computerRoom.h"

class Manager : public Identity
{
public:
	
	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name, string pwd);

	//�˵�����
	virtual void openMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();
	
	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������
	void initVector();

	//����ظ� ����������id���������ͣ� ����ֵTrue or False
	bool checkRepeat(int id, int type);



	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	//������Ϣ
	vector<ComputerRoom> vCom;
};