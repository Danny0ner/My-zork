#ifndef _MYSTRING_
#define _MYSTRING_

#include<string.h>
#include<stdio.h>
#include"vector.h"


typedef unsigned int uint;

class MyString
{
private:

	//PROPERTIES
	char *buffer = nullptr;
	uint max_size;

public:

	//CONSTRUCTORS-DESTRUCTOR
	MyString();
	MyString(const char *string);
	MyString(const MyString &other);
	~MyString();


	//MEMBER FUNCTIONS

	//returns the string
	const char *c_str() const;

	//returns the string size
	uint length()const;

	//returns the memory allocated
	const uint capacity() const;

	//checks if the string is empty
	bool empty()const;

	//compare 2 string classes
	bool operator==(const MyString &other) const;

	//compare string(class) - string
	bool operator==(const char *string) const;

	//iguala una classe a una altra
	void operator=(const MyString &other);
	void operator=(const char *other);

	//concatena dues cadenes
	void operator+=(const MyString &other);

	//cadena1 = cadena2 + cadena3
	MyString operator+(const MyString &other) const;

	//deixa la cadena sense caràcters
	void clear();

	//la memòria alocatada s'iguala al nombre de caràcters de la cadena (+1)
	void shrink_to_fit();

	//void set(char *command);

	//void Tokenize(const char*,Vector<MyString>&);

	Vector<MyString> SplitString(const char *symbol, char* command);



};


#endif //MYSTRING