#include<string.h>
#include<stdio.h>
#include"MyString.h"
#include"vector.h"



MyString::MyString()
{
	max_size = 1;
	buffer = new char[max_size];
	strcpy_s(buffer, max_size, "");

}

MyString::MyString(const char *string)
{
	uint len = strlen(string);
	buffer = new char[len + 1];
	max_size = len + 1;
	strcpy_s(buffer, max_size, string);
	
}
MyString::MyString(const MyString &other)
{
	max_size = other.max_size;
	buffer = new char[max_size];
	strcpy_s(buffer, max_size, other.buffer);

}

MyString::~MyString()
{
	delete[] buffer;
}


const char* MyString:: c_str() const
{
	return buffer;
}


uint MyString::length() const
{
	return strlen(buffer);
}


const uint MyString::capacity() const
{
	return max_size;
}


bool MyString::empty()const
{
	return buffer[0] == 0;
}


bool MyString::operator==(const MyString &other) const
{
	return _stricmp(buffer, other.buffer) == 0;
}


bool MyString::operator==(const char *string) const
{
	return _stricmp(buffer, string) == 0;
}


void MyString::operator=(const MyString &other)
{
	if (max_size < other.length() + 1)
	{
		delete[] buffer;
		max_size = other.length() + 1;
		buffer = new char[max_size];
	}
	strcpy_s(buffer, max_size, other.buffer);
}

void MyString::operator=(const char *other)
{
	unsigned int len = strlen(other);
	if (max_size < len + 1)
	{
		delete[] buffer;
		max_size = len +1;
		buffer = new char[max_size];
	}
	strcpy_s(buffer, max_size, other);
}


void MyString::operator+=(const MyString &other)
{
	char *temp = nullptr;

	if (max_size < other.length() + length() + 1)
	{
		max_size = other.length() + length() + 1;
		temp = new char[max_size];
		strcpy_s(temp, max_size, buffer);
		delete[]buffer;
		strcat_s(temp, max_size, other.buffer);
		buffer = temp;
	}
	else
	{
		strcat_s(buffer, max_size, other.buffer);
	}
}


MyString MyString::operator+(const MyString &other) const
{
	MyString newstring;
	newstring.max_size = length() + other.length() + 1;
	newstring.buffer = new char[newstring.max_size];
	strcpy_s(newstring.buffer, newstring.max_size, buffer);
	strcat_s(newstring.buffer, newstring.max_size, other.buffer);
	return newstring;
}


void MyString::clear()
{
	strcpy_s(buffer, max_size, "");
}

void MyString::shrink_to_fit()
{
	if (max_size != length() + 1)
	{
		char *temp = nullptr;
		max_size = length() + 1;
		temp = new char[max_size];
		strcpy_s(temp, max_size, buffer);
		delete[] buffer;
		buffer = temp;
	}
}

Vector<MyString> MyString::SplitString(const char *symbol, char* command)
{
	Vector<MyString> vec;
	char *cstr, *p, *context;

	
	uint len = strlen(command);
	cstr = new char[len + 1];
	strcpy_s(cstr, len + 1, command);
	

	p = strtok_s(cstr, symbol, &context);
	while (p != NULL)
	{
		vec.pushback(p);
		p = strtok_s(NULL, symbol, &context);
	}
	delete[] cstr;
	return vec;
}


