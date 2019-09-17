//#include"json.h"
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<queue>
#include <locale>
#include <codecvt>
#include <regex>
#include <iostream>
#include <iterator>
#include <fstream>
#include <cassert>

using namespace std;

void writeFileJson(string addr);
int level(string dz)    //判断级别
{
	int a = dz[0] - '0';
	return a;
}

string dz1(string dz)      //提取级别和句末'.'后的地址
{
	regex r("\\d{1}!");
	dz = regex_replace(dz, r, "");
	int a = dz.find('.');
	dz = dz.erase(a, 1);
	return dz;
}

string number(string dz)      //提取11位电话
{
	smatch result;
	regex r("\\d{11}");
	regex_search(dz, result, r);
	string number = result.str();
	return number;
}

string dz2(string dz)      //提取11位电话后的地址
{
	regex r("\\d{11}");
	dz = regex_replace(dz, r, "");
	return dz;
}

string name(string dz)      //提取姓名
{
	string name;
	int a = dz.find(',');
	name = dz.substr(0, a);
	return name;
}

string dz3(string dz)      //删除姓名和“，”
{
	string name;
	int a = dz.find(',');
	name = dz.substr(0, a);
	int b = name.length();
	dz.erase(0, b + 1);
	return dz;
}

void cut5(string dz)
{
	//省的匹配
	string sheng;
	if (dz.find('龙') != -1)
		sheng = dz.substr(0, 6);
	else if (dz.find('省') == -1)
		sheng = dz.substr(0, 4);
	else
	{
		int a = dz.find('省');
		sheng = dz.substr(0, a+1);
	}
	//删除省添加“省”
	int a = sheng.length();
		dz = dz.erase(0, a);     //只要删a位
	//市的匹配
	string shi;
	if (dz.find('市') == -1)
		shi = dz.substr(0, 4);
	else
	{
		int b = dz.find('市');
		shi = dz.substr(0, b+1);
	}
	//删除市添加“市”
	int c = shi.length();
	if (dz.find('市') == -1)
		dz = dz.erase(0, c);
	else
		dz = dz.erase(0, c );
	//匹配区|县
	smatch result;
	regex r("^.+(区|县)");
	regex_search(dz, result, r);
	string qx = result.str();
	//提取区|县后的地址
	dz = regex_replace(dz, r, "");
	//匹配街道|镇|乡
	smatch result1;
	regex r1("^.+((街道)|镇|乡)");
	regex_search(dz, result1, r1);
	string jzx = result1.str();
	//提取街道|镇|乡后的地址
	dz = regex_replace(dz, r1, "");
	cout << sheng << endl;
	cout << shi << endl;
	cout << qx << endl;
	cout << jzx << endl;
	cout << dz << endl;
}

void cut7(string dz)
{
	//省的匹配
	string sheng;
	if (dz.find('龙') != -1)
		sheng = dz.substr(0, 6);
	else if (dz.find('省') == -1)
		sheng = dz.substr(0, 4);
	else
	{
		int a = dz.find('省');
		sheng = dz.substr(0, a+1);
	}
	//删除省添加“省”
	int a = sheng.length();
	dz = dz.erase(0, a);     //只要删a位
	//市的匹配
	string shi;
	if (dz.find('市') == -1)
		shi = dz.substr(0, 4);
	else
	{
		int b = dz.find('市');
		shi = dz.substr(0, b+1);
	}
	//删除市添加“市”
	int c = shi.length();
	dz = dz.erase(0, c);
	//匹配区|县
	smatch result;
	regex r("^.+(区|县)");
	regex_search(dz, result, r);
	string qx = result.str();
	//提取区|县后的地址
	dz = regex_replace(dz, r, "");
	//匹配街道|镇|乡
	smatch result1;
	regex r1("^.+((街道)|镇|乡)");
	regex_search(dz, result1, r1);
	string jzx = result1.str();
	//提取街道|镇|乡后的地址
	dz = regex_replace(dz, r1, "");
	//匹配路
	smatch result2;
	regex r2("^.+路");
	regex_search(dz, result2, r2);
	string lu = result2.str();
	//提取路后的地址
	dz = regex_replace(dz, r2, "");
   //匹配门牌号
	smatch result3;
	regex r3("^.+号");
	regex_search(dz, result3, r3);
	string door = result3.str();
   //提取门牌号后的地址
	dz = regex_replace(dz, r3, "");
	cout << sheng << endl;
	cout << shi << endl;
	cout << qx << endl;
	cout << jzx << endl;
	cout << lu << endl;
	cout << door << endl;
	cout << dz << endl;
}

int main()
{
	string addr;
	//addr = readTxt();
	cin >> addr;
	int a = level(addr);
	addr = dz1(addr);
	cout << name(addr)<< endl;
	cout << number(addr)<< endl;
	addr = dz2(addr);
	addr = dz3(addr);
	if (a == 1)
		cut5(addr);
	else
		cut7(addr);
	//writeFileJson(addr);
	getchar();
	return 0;
}
