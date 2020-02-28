// s2007_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

template <class T,int SIZE=50>
class mystack
{
public:
	mystack();
	void push(T a);
	T gettop();
	T pop();
	void clear();
	bool isfull();
	bool isempty();
private:
	int top;
	T list[SIZE];
};

template<class T,int SIZE>
mystack<T,SIZE>::mystack()
{
	top=-1;
}

template<class T,int SIZE>
void mystack<T,SIZE>::push(T a)
{
	assert(!isfull());
	list[++top]=a;
}

template<class T,int SIZE>
T mystack<T,SIZE>::gettop()
{
	assert(!isempty());
	return list[top];
}

template<class T,int SIZE>
T mystack<T,SIZE>::pop()
{
	assert(!isempty());
	return list[top--];
}

template<class T,int SIZE>
bool mystack<T,SIZE>::isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

template<class T,int SIZE>
bool mystack<T,SIZE>::isfull()
{
	if(top==SIZE-1)
		return 1;
	else
		return 0;
}

template<class T,int SIZE>
void mystack<T,SIZE>::clear()
{
	top=-1;
}

int main(int argc, char* argv[])
{
	mystack<int> a;
	int i;
	for(i=0;i<50;i++)
	{
		a.push(i);
	}
	cout<<"������ջ50�κ󣬵õ�ջ��Ԫ��Ϊ��"<<a.gettop()<<endl;
	cout<<"ջ�Ƿ�������"<<a.isfull()<<endl;
	for(i=0;i<49;i++)
	{
		a.pop();
	}
	cout<<"����49�κ󣬵õ���ջ��Ԫ��Ϊ��"<<a.gettop()<<endl;
	a.pop();
	cout<<"ջ�Ƿ�Ϊ�գ�"<<a.isempty()<<endl;
	system("pause");
	return 0;
}

