#pragma once
#include<regex>
#include<string>
#include<set>
using namespace std;
class Regex
{
private:
	string temple;
	string tagstr;
	smatch temp;
public:
	set<string> seach(string temple, string tagstr);//ɸѡ��ҳ���е�url ȥ�ز�����
	bool match(string temple, string tagstr);//ƥ���ַ���
};