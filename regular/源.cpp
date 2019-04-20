#include<iostream>
#include<fstream>
#include<string>
#include<regex>
using namespace std;
fstream file;
int main()
{
	string temp = "http[s]*://[^\"\'<\?]+(.jpg|peng)";
	//string temp = "(https ? | ftp | file) ://[-A-Za-z0-9+&@#/%?=~_|!:,.;]+[-A-Za-z0-9+&@#/%=~_|]";
	regex t(temp);
	smatch res;
	file.open("test.txt");
	string str;
	string buffer;
	while (getline(file,buffer))
	{
		str = str + buffer;
	}
	cout << str;
	string::const_iterator iter = str.begin();
	string::const_iterator iterEnd = str.end();
	string str1;
	while (regex_search(iter, iterEnd, res, t))
	{
		temp = res[0];
		cout << temp << endl;
		str1 = str1 + temp+"\n";
		iter = res[0].second;
	}
	ofstream fout;
	fout.open("res.txt");
	fout << str1;
	system("pause");
	return 0;
}