#pragma once
#include "_net.h"
int Net::setHostName(string str)
{
	str = str.substr(0, 7) == "http://" ? str.substr(7) : str;
	int tag = str.find_first_of('/');
	if (tag == string::npos)
	{
		Resource = "/";
		HostName = str;
	}
	else
	{
		HostName = str.substr(0, tag);
		Resource = str.substr(tag);
	}
	Port = 80;
	return 0;
	//cout << res;
}
string Net::getHtml()
{
	WSADATA wsaData;
	sockaddr_in addr;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	hostent *ht = gethostbyname(HostName.c_str());
	if (ht == NULL)
		return "#";
	//printf("%s\n", ht->h_aliases[0]);
	addr.sin_port = htons(Port);
	addr.sin_family = AF_INET;
	memmove(&addr.sin_addr, ht->h_addr, ht->h_length);
	SOCKET sto = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (0 != connect(sto, (SOCKADDR*)&addr, sizeof(addr)))
		cout << "error";
	else
	{
		//cout << "yes";

		string request = "GET " + Resource + " HTTP/1.1\r\nHost:" + HostName + "\r\nConnection:Close\r\n\r\n";
		//cout << request<<endl;
		cout << send(sto, request.c_str(), request.length(), 0) << endl;
		//cout << "send error" << endl;
		//cout << WSAGetLastError();
		char buf;
		char *pbuf = &buf;
		int ret = 1;
		string res;
		while (ret > 0)
		{
			ret = recv(sto, pbuf, 1, 0);
			res = res + buf;
		}
		return res;
	}
	return "0";
}
int Net::getPicture(string url,int number)
	{
		string filename = to_string(number).c_str();
		filename = filename + ".jpg";
		HRESULT k = URLDownloadToFile(NULL, url.c_str(),filename.c_str() , 0, NULL);
		return 0;
	}