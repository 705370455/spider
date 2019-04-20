#pragma once
#include "_spider.h"
int index;
int spider::beginTOspider(string url)
{
	index = 0;
	Queue.insert(url);
	while (!Queue.empty())
	{
		string cur = *Queue.begin();
		while (vis.find(cur) != vis.end())
		{
			Queue.erase(Queue.begin());
			cur = *Queue.begin();
		}
		vis.insert(cur);
		cout << cur << endl;
		Queue.erase(Queue.begin());
		if (regehandle.match("http[s]*://[^\"\'<\?]+(.jpg|.png)",cur))
		{
			//nethadle.getPicture(cur);
		}
		else
		{
			nethadle.setHostName(cur);
			string HtmlStr = nethadle.getHtml();
			if (HtmlStr == "#")
				continue;
			//cout <<"返回:" <<HtmlStr<<endl;
			cout << "待访问链接数量:" << Queue.size() << endl;
			cout << "已访问链接数量:" << vis.size() << endl;
			string temple = "http[s]*://[^\"\'<\?]+";
			set<string> temp = regehandle.seach(temple,HtmlStr);
			set<string> pic = regehandle.seach("http[s]*://[^\"\'<\?]+(.jpg|peng)", HtmlStr);
			while (!pic.empty())
			{
				if (vis.find(*pic.begin()) == vis.end())
				{
					nethadle.getPicture(*pic.begin(), index++);
					vis.insert(*pic.begin());
				}
				pic.erase(pic.begin());
			}
			putQueueToQueue(Queue,temp,cur);
		}
	}
	return 0;
}
int spider::putQueueToQueue(set<string> &q1, set<string> &q2, string &cur)
{
	while (!q2.empty())
	{
		if (cur != *q2.begin())
			q1.insert(*q2.begin());
		q2.erase(q2.begin());
	}
	return 0;
}