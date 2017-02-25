#pragma once

#include <time.h>
#include <string>

tm* GetTime()
{
	time_t tt = time(NULL);
	tm* t = localtime(&tt);
	return t;
}

std::string genTimeStr(std::string format)
{
	char buf[512] = { 0 };
	time_t tt = time(NULL);//这句返回的只是一个时间cuo
	tm* t = localtime(&tt);
	if (format == "")
	{
		format = "%d%02d%02d%02d%02d%02d";
	}
	sprintf(buf, format.c_str(),
		t->tm_year + 1900,
		t->tm_mon + 1,
		t->tm_mday,
		t->tm_hour,
		t->tm_min,
		t->tm_sec);

	return std::string(buf);

}