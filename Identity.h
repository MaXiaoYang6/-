#pragma once
#include <iostream>
using namespace std;

class Identity
{
public:
	virtual void openMenu() = 0;//Menu
	string m_Name;//User name
	string m_Pwd;//PassWord
};