#include <regex>
#include <iostream>
#include <string>
#include <iterator>
#include<regex>
#include <fstream>

using namespace std;

int level(string dz)    //�жϼ���
{
	int a = dz[0]-'0';
	return a;
}

string dz1(string dz)      //��ȡ����;�ĩ'.'��ĵ�ַ
{
	regex r("\\d{1}!");
	dz = regex_replace(dz, r, "");
	int a = dz.find('.');
	dz = dz.erase(a, 1);
	return dz;
}

string number(string dz)      //��ȡ11λ�绰
{
	smatch result;
	regex r("\\d{11}");
	regex_search(dz,result,r);
	string number = result.str();
	return number;
}

string dz2(string dz)      //��ȡ11λ�绰��ĵ�ַ
{
	regex r("\\d{11}");
	dz = regex_replace(dz, r, "");
	return dz;
}

string name(string dz)      //��ȡ����
{
	string name;
	int a=dz.find(',');
	name = dz.substr(0,a);
	return name;
}

string dz3(string dz)      //ɾ�������͡�����
{
	string name;
	int a = dz.find(',');
	name = dz.substr(0, a);
	int b = name.length();
	dz.erase(0, b+1);
	return dz;
}

string sheng(string dz)      //ƥ��ʡ
{
	string sheng;
	if (dz.find('��')!= -1)
		sheng = dz.substr(0,6);
	else if (dz.find('ʡ') == -1)
		sheng = dz.substr(0,4);
	else
	{
		int a = dz.find('ʡ');
		sheng = dz.substr(0, a);
	}
	return sheng;
}

string dz4(string dz)      //ɾ��ʡ��
{
	string s = sheng(dz);
	int a = s.length();
	if (dz.find('ʡ') == -1)
		dz=dz.erase(0, a);     //ֻҪɾaλ
	else
		dz=dz.erase(0,a+1);
	return dz;
}

string shi(string dz)      //ƥ����
{
	string shi;
	if (dz.find('��') == -1)
		shi = dz.substr(0,4);
	else
	{
		int b = dz.find('��');
		shi = dz.substr(0,b);
	}
	return shi;
}

string dz5(string dz)      //ɾ����
{
	string s = shi(dz);
	int a = s.length();
	if (dz.find('��') == -1)
		dz = dz.erase(0,a);         
	else
		dz = dz.erase(0,a+1);
	return dz;
}

string	qx(string dz)      //ƥ��������
{
	smatch result;
	regex r("^.+(��|��)");
	regex_search(dz, result, r);
	string qx = result.str();
	/*string qx;
	int b=0;
	if(dz.find('��') != -1)
	{
		b = dz.find('��');
		qx = dz.substr(0, b+1);
	}
	else
	{
		b = dz.find('��');
		qx = dz.substr(0, b+1);
	}*/
	return qx;
}

string dz6(string dz)      //��ȡ��|�غ�ĵ�ַ
{
	regex r("^.+(��|��)");
	dz = regex_replace(dz, r, "");
	return dz;
}

string jzx(string dz)      //ƥ��ֵ�|��|��
{
	smatch result;
	regex r("^.+((�ֵ�)|��|��)");
	regex_search(dz, result, r);
	string jzx = result.str();
	return jzx;
}

string dz7(string dz)      //��ȡ�ֵ�|��|���ĵ�ַ
{
	regex r("^.+((�ֵ�)|��|��)");
	dz = regex_replace(dz, r, "");
	return dz;
}

string lu(string dz)      //ƥ��·
{
	smatch result;
	regex r("^.+·");
	regex_search(dz, result, r);
	string lu = result.str();
	return lu;
}

string dz8(string dz)      //��ȡ·��ĵ�ַ
{
	regex r("^.+·");
	dz = regex_replace(dz, r, "");
	return dz;
}

string door(string dz)      //ƥ�����ƺ�
{
	smatch result;
	regex r("^.+��");
	regex_search(dz, result, r);
	string door = result.str();
	return door;
}

string dz9(string dz)      //��ȡ���ƺź�ĵ�ַ
{
	regex r("^.+��");
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
