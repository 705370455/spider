#pragma once
#include "_file.h"
#include "_regex.h"
#include "_net.h"
using namespace std;
class spider
{
private:
	Net nethadle;
	Regex regehandle;
	set<string> Queue;
	set<string> vis;
public:
	int beginTOspider(string url);
	int putQueueToQueue(set<string> &q1, set<string> &q2,string &cur);
};