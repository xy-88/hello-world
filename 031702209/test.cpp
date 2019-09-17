#include"json.h"
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string.h>
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

string readTxt()       //读取txt文件
{
	ifstream infile;
	infile.open("C://Users//ASUS//source//repos//测试//测试//1.txt", ios::in);   //将文件流对象与文件连接起来 
	assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 
	string s;
	while (getline(infile, s))
	{
		cout << s << endl;
	}
	infile.close();
	return s;
}

/*string UnicodeToUTF8(const wstring&s) {
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
	int a = dz[0]-'0';
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
	regex_search(dz,result,r);
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
	int a=dz.find(',');
	name = dz.substr(0,a);
	return name;
}

string dz3(string dz)      //删除姓名和“，”
{
	string name;
	int a = dz.find(',');
	name = dz.substr(0, a);
	int b = name.length();
	dz.erase(0, b+1);
	return dz;
}

string sheng(string dz)      //匹配省
{
	string sheng;
	if (dz.find('龙')!= -1)
		sheng = dz.substr(0,6);
	else if (dz.find('省') == -1)
		sheng = dz.substr(0,4);
	else
	{
		int a = dz.find('省');
		sheng = dz.substr(0, a);
	}
	return sheng;
}

string dz4(string dz)      //删除省份
{
	string s = sheng(dz);
	int a = s.length();
	if (dz.find('省') == -1)
		dz=dz.erase(0, a);     //只要删a位
	else
		dz=dz.erase(0,a+1);
	return dz;
}

string shi(string dz)      //匹配市
{
	string shi;
	if (dz.find('市') == -1)
		shi = dz.substr(0,4);
	else
	{
		int b = dz.find('市');
		shi = dz.substr(0,b);
	}
	return shi;
}

string dz5(string dz)      //删除市
{
	string s = shi(dz);
	int a = s.length();
	if (dz.find('市') == -1)
		dz = dz.erase(0,a);         
	else
		dz = dz.erase(0,a+1);
	return dz;
}

string	qx(string dz)      //匹配区或县
{
	smatch result;
	regex r("^.+(区|县)");
	regex_search(dz, result, r);
	string qx = result.str();
	/*string qx;
	int b=0;
	if(dz.find('区') != -1)
	{
		b = dz.find('区');
		qx = dz.substr(0, b+1);
	}
	else
	{
		b = dz.find('县');
		qx = dz.substr(0, b+1);
	}*/
	return qx;
}

string dz6(string dz)      //提取区|县后的地址
{
	regex r("^.+(区|县)");
	dz = regex_replace(dz, r, "");
	return dz;
}

string jzx(string dz)      //匹配街道|镇|乡
{
	smatch result;
	regex r("^.+((街道)|镇|乡)");
	regex_search(dz, result, r);
	string jzx = result.str();
	return jzx;
}

string dz7(string dz)      //提取街道|镇|乡后的地址
{
	regex r("^.+((街道)|镇|乡)");
	dz = regex_replace(dz, r, "");
	return dz;
}

      //七级地址所需
string lu(string dz)      //匹配路
{
	smatch result;
	regex r("^.+路");
	regex_search(dz, result, r);
	string lu = result.str();
	return lu;
}

string dz8(string dz)      //提取路后的地址
{
	regex r("^.+路");
	dz = regex_replace(dz, r, "");
	return dz;
}

string door(string dz)      //匹配门牌号
{
	smatch result;
	regex r("^.+号");
	regex_search(dz, result, r);
	string door = result.str();
	return door;
}

string dz9(string dz)      //提取门牌号后的地址
{
	regex r("^.+号");
	dz = regex_replace(dz, r, "");
	return dz;
}

void writeFileJson(string addr)
{
	//根节点
	Json::Value root;
	//根节点属性
	string addr1 = dz1(addr);
	string addr2 = dz2(addr1);
	string addr3 = dz3(addr2);
	string addr4 = dz4(addr3);
	string addr5 = dz5(addr4);
	string addr6 = dz6(addr5);
	string addr7 = dz7(addr6);
	//子节点
	root["电话"] = Json::Value(number(addr1));
	root["姓名"] = Json::Value(name(addr2));
	//数组形式
	root["地址"].append(sheng(addr3));  
	root["地址"].append(shi(addr4));   
	root["地址"].append(qx(addr5));    cout << endl;
	root["地址"].append(jzx(addr6));   cout << endl;
	root["地址"].append(addr7);
	//缩进输出
	cout << "" << endl;
	Json::StyledWriter sw;
	cout << sw.write(root) << endl << endl;
	//输出到文件
	ofstream os;
	os.open("2.txt");
	os << sw.write(root);
	os.close();

}

int main()
{
	string addr;
	addr = readTxt();
	writeFileJson(addr);
	getchar();
	return 0;
 }


