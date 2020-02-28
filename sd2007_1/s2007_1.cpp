// s2007_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class TDate
{
public:
	TDate();
	TDate(int year,int mouth,int day);
	void setDate(int year=2019,int month=3,int day=24);
	friend void PrintDate(TDate date);
private:
	int Month,Day,Year;
};

TDate::TDate()	//Ĭ�Ϲ��캯�����޲ι��캯�������ڲ��ṩʱ��ʱ��Ĭ�Ͻ�ʱ���ʼ��Ϊϵͳ��ǰ��ʱ��
{
	time_t now=time(NULL);	//�õ���ǰ��ʱ�䣨�������ʽ���棩
	tm *Itm=localtime(&now);	//�õ��ṹtm��ʽ��ʱ��
	Year=1900+Itm->tm_year;	
	Month=Itm->tm_mon;
	Day=Itm->tm_mday;
}

TDate::TDate(int year,int month,int day)
{
	Year=year;
	Month=month;
	Day=day;
}

void TDate::setDate(int year,int month,int day)
{
	Year=year;
	Month=month;
	Day=day;
}

void PrintDate(TDate date)
{
	cout<<"year:"<<date.Year<<" month:"<<date.Month<<" day:"<<date.Day<<endl;
}

int main(int argc, char* argv[])
{
	TDate date1;
	TDate date2(2019,2,23);
	cout<<"date1 :\n";
	PrintDate(date1);
	cout<<"date2 :"<<endl;
	PrintDate(date2);
	date2.setDate(2020,2,28);
	cout<<"date2 :"<<endl;
	PrintDate(date2);
	cout<<"date2 :"<<endl;
	date2.setDate();
	PrintDate(date2);
	return 0;
}

