#pragma once
#include <iostream>
using namespace std;
class MyInt
{
private:
	int value = 0;
public:
	MyInt(int setValue) :value(setValue)
	{
	}
	~MyInt() {}

	int Get();
	bool operator==(const MyInt& target);
	bool operator!=(const MyInt& target);
	int operator+=(const MyInt& target);
	int operator-=(const MyInt& target);
	int operator+(const MyInt& target);
	int operator-(const MyInt& target);
	int operator=(const MyInt& target);
	int operator++(int);
	int operator--(int);
	int operator++();
	int operator--();
	int operator*=(const MyInt& target);
	int operator*(const MyInt& target);
	
};

