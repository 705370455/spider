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
	set<string> seach(string temple, string tagstr);//筛选出页面中的url 去重并返回
	bool match(string temple, string tagstr);//匹配字符串
};