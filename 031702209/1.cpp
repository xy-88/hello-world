//#include"json.h"

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
#define _CRT_SECURE_NO_WARNINGS

using namespace std;


/*string readTxt()       //读取txt文件
{
	ifstream infile;
	infile.open("C://Users//ASUS//source//repos//测试//测试//1.txt", ios::in);   //将文件流对象与文件连接起来 
	assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 
	string s;
	getline(infile, s);
	infile.close();
	//const char* c_s = s.c_str();
	//s = UnicodeToUTF8(c_s);
	cout << s << endl;
	return s;
}*/

/*string UnicodeToUTF8(const wstring &s) {
	string ret;
	wstring_convert<codecvt_utf8<wchar_t> > wcv;
	ret = wcv.to_bytes(s);
	return ret;
}

wstring UTF8ToUnicode(const string &s) {
	wstring ret;
	wstring_convert<codecvt_utf8<wchar_t> > wcv;
	ret = wcv.from_bytes(s);
	return ret;
}*/

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
		sheng = dz.substr(0, a + 1);
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
		shi = dz.substr(0, b + 1);
	}
	//删除市添加“市”
	int c = shi.length();
	if (dz.find('市') == -1)
		dz = dz.erase(0, c);
	else
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
	//利用ofstream类的构造函数创建一个文件输出流对象来打开文件
	ofstream fout("C://Users//ASUS//source//repos//测试//测试//2.txt", ios::app);
	if (!fout)
	{
		cout << "文件不能打开" << endl;
	}
	else
	{
		// 输出到磁盘文件
		fout << "“地址”" << ":" << "[" <<endl<< "“" << sheng << "”" << "," << endl;
		fout << "“" << shi << "”" << "," << endl;
		fout << "“" << qx << "”" << "," << endl;
		fout << "“" << jzx << "”" << "," << endl;
		fout << "“" << dz << "”" <<endl<< "]" <<endl<< "}" << endl;
		//关闭文件输出流
	}
	fout.close();
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
		sheng = dz.substr(0, a + 1);
	}
	//删除省
	int a = sheng.length();
	dz = dz.erase(0, a);     //只要删a位
	//市的匹配
	string shi;
	if (dz.find('市') == -1)
		shi = dz.substr(0, 4);
	else
	{
		int b = dz.find('市');
		shi = dz.substr(0, b + 1);
	}
	//删除市
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

	//利用ofstream类的构造函数创建一个文件输出流对象来打开文件
	ofstream fout("C://Users//ASUS//source//repos//测试//测试//2.txt", ios::app);
	if (!fout)
	{
		cout << "文件不能打开" << endl;
	}
	else
	{
		// 输出到磁盘文件
		fout << "“地址”" << ":" << "[" <<endl<< "“" << sheng << "”" << "," << endl;
		fout << "“" << shi << "”" << "," << endl;
		fout << "“" << qx << "”" << "," << endl;
		fout << "“" << jzx << "”" << "," << endl;
		fout << "“" << lu << "”" << "," << endl;
		fout << "“" << door << "”" << "," << endl;
		fout << "“" << dz << "”"<<endl << "]" <<endl<< "}" << endl;
		//关闭文件输出流
	}
	fout.close();
}

int main()
{
	string addr;
	cin >> addr;
	//addr = readTxt();
	int a = level(addr);
	addr = dz1(addr);
	//利用ofstream类的构造函数创建一个文件输出流对象来打开文件
	ofstream fout("C://Users//ASUS//source//repos//测试//测试//2.txt", ios::app);
	if (!fout)
	{
		cout << "文件不能打开" << endl;
	}
	else
	{
		// 输出到磁盘文件
		fout << "{" <<endl<< "“姓名”" << ":" << "“" << name(addr) << "”" << "," << endl;
		fout << "“手机”" << ":" << "“" << number(addr) << "”" << "," << endl;
		//关闭文件输出流
	}
	fout.close();

	addr = dz2(addr);
	addr = dz3(addr);
	if (a == 1)
		cut5(addr);
	else
		cut7(addr);
	getchar();
	getchar();
	getchar();
	getchar();
	return 0;
}
