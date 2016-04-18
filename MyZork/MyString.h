#ifndef _String_
#define _String_

#include<string.h>
#include<stdio.h>
#include"vector.h"


typedef unsigned int uint;

class String
{
private:

	char *buffer = nullptr;
	uint max_size;

public:


	String();
	String(const char *string);
	String(const String &other);
	~String();



	const char *c_str() const;


	uint length()const;

	
	const uint capacity() const;

	
	bool empty()const;

	bool operator==(const String &other) const;


	bool operator==(const char *string) const;


	void operator=(const String &other);
	void operator=(const char *other);

	void operator+=(const String &other);

	
	String operator+(const String &other) const;


	void clear();

	
	void shrink_to_fit();

	Vector<String> TokenizeV2(const char *symbol, char* command);



};


#endif //String