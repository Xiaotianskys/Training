// s2007_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

class mystring
{
public:
	mystring();
	~mystring();
	mystring(char *str);
	mystring(mystring &s1);
	mystring operator+(mystring &s1);
	mystring& operator=(mystring &s1);
	void setstr(const char* str);
	int getlength();
	friend ostream& operator<<(ostream &out,mystring &s1);
private:
	char *s;
};

mystring::mystring()
{
	s=new char[1]();
}

mystring::mystring(char *str)
{
	if(str==NULL)
	{
		s=new char[1];
		s='\0';
	}
	else
	{
		int length=strlen(str);
		s=new char[length+1]();
		strcpy(s,str);
	}
}

mystring::~mystring()
{
	delete [] s;
}

mystring::mystring(mystring &s1)
{
	int length=strlen(s1.s);
	s=new char[length+1]();
	strcpy(s,s1.s);
}

int mystring::getlength()
{
	return strlen(s);
}

mystring mystring::operator+(mystring &s1)
{
	mystring temp;
	delete [] temp.s;
	int length=strlen(s)+strlen(s1.s)+1;
	temp.s=new char[length];
	strcpy(temp.s,s);
	strcat(temp.s,s1.s);
	return temp;
}

mystring& mystring::operator=(mystring &s1)
{
	if(this==&s1)
	{
		return *this;
	}
	delete [] s;
	int len = strlen(s1.s)+1;
	s=new char[len]();
	strcpy(s,s1.s);
	return *this;
}

ostream& operator<<(ostream &out,mystring &s1)
{
	out<<s1.s;
	return out;
}

void mystring::setstr(const char* str)
{
	if(s!=str)
	{
		delete [] s;
		s = new char[strlen(str)+1]();
		strcpy(s,str);
	}
}

int main(int argc, char* argv[])
{
	mystring s1,s2,s3;
	s1.setstr("This is my first string.");
	s2=mystring("This is my second string.");
	s3=s1+s2;
	cout<<"s3.length:"<<s3.getlength()<<endl;	
	cout<<"s3:"<<s3<<endl;
	system("pause");
	return 0;
}

