#include<string.h>
#include<stdio.h>
#include"MyString.h"
#include"vector.h"



String::String()
{
	max_size = 1;
	buffer = new char[max_size];
	strcpy_s(buffer, max_size, "");

}

String::String(const char *string)
{
	uint len = strlen(string);
	buffer = new char[len + 1];
	max_size = len + 1;
	strcpy_s(buffer, max_size, string);
	
}
String::String(const String &other)
{
	max_size = other.max_size;
	buffer = new char[max_size];
	strcpy_s(buffer, max_size, other.buffer);

}

String::~String()
{
	delete[] buffer;
}


const char* String:: c_str() const
{
	return buffer;
}


uint String::length() const
{
	return strlen(buffer);
}


const uint String::capacity() const
{
	return max_size;
}


bool String::empty()const
{
	return buffer[0] == 0;
}


bool String::operator==(const String &other) const
{
	return _stricmp(buffer, other.buffer) == 0;
}


bool String::operator==(const char *string) const
{
	return _stricmp(buffer, string) == 0;
}


void String::operator=(const String &other)
{
	if (max_size < other.length() + 1)
	{
		delete[] buffer;
		max_size = other.length() + 1;
		buffer = new char[max_size];
	}
	strcpy_s(buffer, max_size, other.buffer);
}

void String::operator=(const char *other)
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


void String::operator+=(const String &other)
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


String String::operator+(const String &other) const
{
	String newstring;
	newstring.max_size = length() + other.length() + 1;
	newstring.buffer = new char[newstring.max_size];
	strcpy_s(newstring.buffer, newstring.max_size, buffer);
	strcat_s(newstring.buffer, newstring.max_size, other.buffer);
	return newstring;
}


void String::clear()
{
	strcpy_s(buffer, max_size, "");
}

void String::shrink_to_fit()
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

Vector<String> String::TokenizeV2(const char *symbol, char* command)
{
	Vector<String> vector;
	char *cstr, *y, *context;

	
	uint len = strlen(command);
	cstr = new char[len + 1];
	strcpy_s(cstr, len + 1, command);
	

	y = strtok_s(cstr, symbol, &context);
	while (y != NULL)
	{
		vector.pushback(y);
		y = strtok_s(NULL, symbol, &context);
	}
	delete[] cstr;
	return vector;
}


