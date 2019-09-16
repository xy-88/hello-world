#include <regex>
#include <iostream>
#include <string>
#include <iterator>
#include<regex>
#include <fstream>

using namespace std;

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

int main()
{
	string addr;
	getline(cin, addr);
	string a, b, c, d, e, f, g;
	/*if (level(addr) == 1)
	{
		
	}
	else
	{

	}*/
	addr = dz1(addr);
	cout << name(addr) << endl;
	cout << number(addr) << endl;
	addr = dz2(addr);
	cout << addr << endl;
	addr = dz3(addr);
	cout << addr << endl;
	cout << sheng(addr) << endl;
	addr = dz4(addr);
	cout << addr << endl;
	cout << shi(addr) << endl;
	addr = dz5(addr);
	cout << addr << endl;
	cout << qx(addr) << endl;
	addr = dz6(addr);
	cout << addr << endl;
	cout << jzx(addr) << endl;
	addr = dz7(addr);
	cout << addr << endl;
	cout << lu(addr) << endl;
	addr = dz8(addr);
	cout << addr << endl;
	cout << door(addr) << endl;
	addr = dz9(addr);
	cout << addr << endl;

	getchar();
	return 0;
 }
