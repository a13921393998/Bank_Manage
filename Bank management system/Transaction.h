#pragma once
#include "Header_Summary.h"
class Transaction {
private:
	//创建一个新时间结构体指针 times
	string timestr;
	string type;
	long long money;
public:
	void set_time(string timestr) {
		this->timestr = timestr;
	}
	string get_timestr() {
		return timestr;
	}
	string get_type() {
		return type;
	}
	long long get_money() {
		return money;
	}
	Transaction() {
		struct tm times;
		time_t nowtime = time(NULL);
		char s[26];
		//首先创建一个time_t 类型的变量nowtime
		//使用该函数就可得到当前系统时间，使用该函数需要将传入time_t类型变量nowtime的地址值。
		localtime_s(&times, &nowtime);
		asctime_s(s, &times);
		int i = 0;
		timestr = "";
		while (s[i] != '\n') {
			timestr += s[i];
			i++;
		}
		type = "";
		money = 0;
	}
	Transaction(string timestr, string ty, long long money) {
		this->timestr = timestr;
		this->type = ty;
		this->money = money;
	}
	Transaction(int ty, long long money) {
		struct tm times;
		time_t nowtime = time(NULL);
		char s[26];
		//首先创建一个time_t 类型的变量nowtime
		//使用该函数就可得到当前系统时间，使用该函数需要将传入time_t类型变量nowtime的地址值。
		localtime_s(&times, &nowtime);
		asctime_s(s, &times);
		/*timestr = string(s);*/
		int i = 0;
		timestr = "";
		while (s[i] != '\n') {
			timestr += s[i];
			i++;
		}
		this->money = money;
		switch (ty)
		{
			case 1: {
				type = "存钱";
				break;
			}
			case 2: {
				type = "取钱";
				this->money = -money;
				break;
			}
			case 3: {
				type = "转出";
				this->money = -money;
				break;
			}
			case 4: {
				type = "转入";
				this->money = money;
				break;
			}
		}
	}
};