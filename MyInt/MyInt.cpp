#include "MyInt.h"

int MyInt::Get()
{
	return value;
}

bool MyInt::operator==(const MyInt& target)
{
	return !(value ^ target.value);
}

bool MyInt::operator!=(const MyInt& target)
{
	return (value ^ target.value);
}

int MyInt::operator+=(const MyInt& target)
{
	MyInt _target = target.value;
	while (_target != 0)
	{
		int carry = (value & _target.value) << 1;
		*this = value ^ _target.value;
		_target = carry;
	}
	return value;
}

int MyInt::operator-=(const MyInt& target)
{
	//2ÀÇ º¸¼ö ¹æ½ÄÀ¸·Î À½¼ö º¯È¯ÈÄ µ¡¼À
	return *this += ~target.value + 1;

	// µÎ ¼ö¸¦ »¬¼À
	/*MyInt _target = target.value;
	cout << _target.Get() << endl;

	while (_target != 0)
	{
		*this = value ^ _target.value;
		_target = (value & _target.value) << 1;
	}
	return value;*/
}

int MyInt::operator+(const MyInt& target)
{
	MyInt _target = target.value;
	MyInt result = value;
	while (_target != 0)
	{
		int carry = (result.value & _target.value) << 1;
		result = result.value ^ _target.value;
		_target = carry;
	}
	return result.value;
}

int MyInt::operator-(const MyInt& target)
{
	MyInt _target = target.value;
	MyInt result = value;
	while (_target != 0)
	{
		result = result.value ^ _target.value;
		_target = (result.value & _target.value) << 1;
	}
	return result.value;
}

int MyInt::operator=(const MyInt& target)
{
	value = target.value;
	return value;
}

int MyInt::operator++(int)
{
	return operator+=(MyInt(1));
}

int MyInt::operator--(int)
{
	return operator-=(MyInt(1));
}

int MyInt::operator++()
{
	return operator+=(MyInt(1));
}

int MyInt::operator--()
{
	return operator-=(MyInt(1));
}

int MyInt::operator*=(const MyInt& target)
{
	MyInt _target = target.value;
	int result = 0;
	if (_target == 0) return *this = result;
	else if (_target == 1) return value;
	while (_target != 1)
	{
		result += (value << 1) - value;
		_target--;
	}
	return *this = (result += value);
}

int MyInt::operator*(const MyInt& target)
{
	MyInt _target = target.value;
	int result = 0;
	if (_target == 0) return result;
	else if (_target == 1) return result = value;
	while (_target != 1)
	{
		result += (value << 1) - value;
		_target--;
	}
	return result += value;
}
