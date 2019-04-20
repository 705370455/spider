#include "_regex.h"
set<string> Regex::seach(string temple, string tagstr)//筛选出页面中的url 去重并返回
{
	string temp = temple;
	//string temp = "(https ? | ftp | file) ://[-A-Za-z0-9+&@#/%?=~_|!:,.;]+[-A-Za-z0-9+&@#/%=~_|]";
	regex t(temp);
	set<string> res;
	smatch result;
	string str=tagstr;
	string::const_iterator iter = str.begin();
	string::const_iterator iterEnd = str.end();
	while (regex_search(iter, iterEnd, result, t))
	{
		temp = result[0];
		res.insert(temp);
		iter = result[0].second;
	}
	return res;
}
bool  Regex::match(string temple, string tagstr)//匹配字符串
{
	regex t(temple);
	smatch re;
	return regex_match(tagstr, re, t);
}