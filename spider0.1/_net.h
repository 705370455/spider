#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1
#include<WinSock2.h>
#include<string>
#include<iostream>
#include <UrlMon.h>
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "ws2_32.lib")
using namespace std;
class Net
{
private:
	string HostName;//主机名
	string Resource;
	int Port;//端口号
	string url;
public:
	int setHostName(string str);
	string getHtml();
	int getPicture(string url,int number);
};