#ifndef _MYSTRING_
#define _MYSTRING_

#include<string.h>
#include<stdio.h>
#include"vector.h"


typedef unsigned int uint;

class MyString
{
private:

	char *buffer = nullptr;
	uint max_size;

public:


	MyString();
	MyString(const char *string);
	MyString(const MyString &other);
	~MyString();



	const char *c_str() const;


	uint length()const;

	
	const uint capacity() const;

	
	bool empty()const;

	bool operator==(const MyString &other) const;


	bool operator==(const char *string) const;


	void operator=(const MyString &other);
	void operator=(const char *other);

	void operator+=(const MyString &other);

	
	MyString operator+(const MyString &other) const;


	void clear();

	
	void shrink_to_fit();

	Vector<MyString> SplitString(const char *symbol, char* command);



};


#endif //MYSTRING