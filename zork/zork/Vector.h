#include <stdio.h>
#define uint unsigned int

template <class TYPE>
class vector {
private:
	TYPE* buffer;
	uint capacity = 10;
	uint num_elements = 0;

public:
	vector(){
		buffer = new TYPE[capacity];
		printf("por defecto\n");
	};
	vector(const vector& vector) : capacity(vector.capacity), num_elements(vector.num_elements){
		buffer = new TYPE[vector.capacity];
		for (uint i = 0; i < num_elements; i++) buffer[i] = vector.buffer[i];
		printf("de copia\n");
	};
	~vector(){
		delete[] buffer;
	};
	void pushback(const TYPE &elem){

		if (capacity == num_elements){
			TYPE* temp;
			capacity = capacity + 5;
			temp = new TYPE[capacity];
			for (uint i = 0; i < num_elements; i++) temp[i] = buffer[i];
			delete[] buffer;
			buffer = new TYPE[capacity];
			buffer = temp;
		}
		else buffer[num_elements++] = elem;
	};
	void pushfront(const TYPE &elem){

		if (capacity == num_elements){
			TYPE * temp;
			capacity = capacity + 5;
			temp = new TYPE[capacity];
			uint y = 1;
			for (uint i = 0; i < num_elements; i++)  temp[y++] = buffer[i];
			delete[] buffer;
			buffer = new TYPE[capacity];
			temp[0] = elem;
			buffer = temp;
		}
		else{
			TYPE * temp;
			uint y = num_elements - 1;
			temp = buffer;
			for (int i = num_elements; i > 0; i--)  buffer[i] = temp[y--];
			buffer[0] = elem;
		}
		num_elements++;
	};
	bool empty() const{
		return buffer[0] == '\0';
	};
	void clear(){
		buffer[0] = '\0';
		num_elements = 0;
	};
	uint Get_capacity() const {
		return capacity;
	};
	uint Getsize() const{
		return num_elements;
	};
	void popback(){
	};

};