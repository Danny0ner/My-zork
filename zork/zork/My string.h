#ifndef _MYSTRING_
#define _MYSTRING_
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
class string{
private:
	char * buffer = nullptr;
	unsigned int max_allocation = 0;

public:
	string(){};
	string(const char* str){
		int len = strlen(str);
		buffer = new char[len + 1];
		max_allocation = (len + 1);
		strcpy_s(buffer, len + 1, str);
		
	}
	string(const string& g){
		unsigned int j = g.length();
		buffer = new char[j + 1];
		strcpy_s(buffer, j + 1, g.buffer);
	
	};

	unsigned int length() const {
		int j = 0;
		for (int i = 0; buffer[i] != '\0'; i++){
			j++;
		}
		return j;
	};
	const char * c_str() const{
	};
	bool empty() const{
		return strlen(buffer) == 0;
	};
	bool operator == (const string& g) const{
		return strcmp(buffer, g.buffer) == 0;
	};
	void operator = (const string& other){
		unsigned int len = strlen(other.buffer) + 1;
		if (len <= max_allocation){
			strcpy_s(buffer, len, other.buffer);
		
		}
		else {
			delete[] buffer;
			max_allocation = (len);
			buffer = new char[max_allocation];

			strcpy_s(buffer, len, other.buffer);
		
		}
	};
	unsigned int getmax_allocation() const {
		return max_allocation;
	};
	void operator += (const string& other){
		unsigned int len = ((length() + 1) + (other.length() + 1));
		if (len <= max_allocation){
			strcat_s(buffer, strlen(buffer), other.buffer);
		}
		else {
			char * buffer2 = buffer;
			delete[] buffer;
			max_allocation = len;
			buffer = new char[max_allocation];
			strcat_s(buffer2, strlen(buffer), other.buffer);
			buffer = buffer2;
		}
	};
	void copy(char* copy){
		for (int i = 0; buffer[i] != '\0'; i++) copy[i] = buffer[i];
		buffer = copy;
	}
	~string(){
		delete[] buffer;
	};
};
#endif