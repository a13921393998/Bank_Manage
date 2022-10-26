#pragma once
#include "Header_Summary.h"
class Transaction {
private:
	//����һ����ʱ��ṹ��ָ�� times
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
		//���ȴ���һ��time_t ���͵ı���nowtime
		//ʹ�øú����Ϳɵõ���ǰϵͳʱ�䣬ʹ�øú�����Ҫ������time_t���ͱ���nowtime�ĵ�ֵַ��
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
		//���ȴ���һ��time_t ���͵ı���nowtime
		//ʹ�øú����Ϳɵõ���ǰϵͳʱ�䣬ʹ�øú�����Ҫ������time_t���ͱ���nowtime�ĵ�ֵַ��
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
				type = "��Ǯ";
				break;
			}
			case 2: {
				type = "ȡǮ";
				this->money = -money;
				break;
			}
			case 3: {
				type = "ת��";
				this->money = -money;
				break;
			}
			case 4: {
				type = "ת��";
				this->money = money;
				break;
			}
		}
	}
};