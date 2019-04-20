#define _WINSOCK_DEPRECATED_NO_WARNINGS 1
#include<fstream>
#include<iostream>
#include<string>
#include<WinSock2.h>
#include <UrlMon.h>
#pragma comment(lib, "urlmon.lib")
using namespace std;
#pragma comment(lib, "ws2_32.lib")

int main()
{
	WSADATA wsaData;
	sockaddr_in addr;
	string host = "images1.wenming.cn";
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	//addr.sin_addr.s_addr = inet_addr("10.51.218.21");
	hostent *ht=gethostbyname(host.c_str());
		printf("%s\n", ht->h_aliases[0]);
	addr.sin_port = htons(80);
	addr.sin_addr.s_addr = inet_addr("");
	addr.sin_family = AF_INET;
	memmove(&addr.sin_addr, ht->h_addr, ht->h_length);
	SOCKET sto = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	cout << sto;
	if (0 != connect(sto, (SOCKADDR*)&addr, sizeof(addr)))
		cout << "error";
	else
	{
		cout << "yes";
		
		string resource = "/web_wenming/images/xgb-index20180623-2.jpg";
		string request = "GET " + resource + " HTTP/1.1\r\nHost:" + host + "\r\nConnection:Close\r\n\r\n";
		cout << request;
		cout<<send(sto, request.c_str(), request.length(), 0)<<endl;
			//cout << "send error" << endl;
		cout << WSAGetLastError();
		char buf;
		char *pbuf = &buf;
		int ret = 1;
		string res;
		cout << "ssss";
		fstream fout;
		fout.open("test.jpg");
		while (ret > 0)
		{
			ret = recv(sto, pbuf, 1, 0);
			fout.write(pbuf, ret);
			res = res + buf;
		}
		cout << "ssss";

		//cout << res;
		HRESULT k = URLDownloadToFile(NULL, "http://www.ylrc.net/images/ylrc_Qr.jpg", "123.jpg", 0, NULL);
		fout.close();
		cout << k;
	}



	closesocket(sto);
	system("pause");
	return 0;
}