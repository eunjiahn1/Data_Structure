#pragma warning(disable:4996)

#include "MyDoubleVector.h"
#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

typedef double;

MyDoubleVector::MyDoubleVector(size_t init_capacity)
{
	data = new double[init_capacity];
	capa = init_capacity;
	used = 0;
}

MyDoubleVector::MyDoubleVector(const MyDoubleVector& v1) {
// pre:
//post:Deep Copy
	data = new double[v1.capacity()];
	capa = v1.capacity();
	used = v1.used;
	copy(v1.data, v1.data + used, data);
}

MyDoubleVector::~MyDoubleVector()
{
	if (capa == 0)
		return;

	delete[] data;
	capa = 0;
	used = 0;
}

void MyDoubleVector::pop_back() 
{// pre:
 //post:Removes the last element in the vector.
	if (used == 0)
		return;
	data[used--] = 0;
}

void MyDoubleVector::push_back(double x) 
{// pre:
 //post:Adds a new element at the end of the vector
	if (used == capa)
		reserve(used * 2);
	data[used++] = x;
}

size_t MyDoubleVector::capacity() const {
	// pre:
	//post:Returns the size of the allocated storage space 
	//     for the elements of the vector container. 
	return capa;
}

size_t MyDoubleVector::size() const {
	// pre:
	//post:Returns the number of elements int the vector container.
	return used;
}

void MyDoubleVector::reserve(size_t n) {
	// pre:n은 capaticy보다 커야 한다.
	//post:Capcity의 크기를 n을 담을수 있을 크기로 바꿔라.
	double *larger_array;
	if (n == capa)
		return;
	if (n < used)
		n = used;

	larger_array = new double[n];
	copy(data, data + used, larger_array);
	delete[] data;
	data = larger_array;
	capa = n;
}

bool MyDoubleVector::empty() const {
	// pre:
	//post:비어있으면 참 리턴
	size_t index = 0;
	if (index != used)
		return false;
	cout << "empty" << endl;
	return true;
}

void MyDoubleVector::clear() {
	// pre:
	//post:remove all elements from the vector container.
	capa = 0;

	delete[] data;
}

MyDoubleVector MyDoubleVector::operator -() {
	// pre:
	//post: Returns an object of which each element is the unary negation
	//      of the corresponding element in the operand object.
	for (size_t i = 0; i < used; i++) {
		data[i] = -data[i];
	}
	return *(this);
}

MyDoubleVector MyDoubleVector::operator -(const MyDoubleVector& v1) {
	// pre:
	//post:Returns an object that is a vector-difference
	assert(used == v1.used);
	MyDoubleVector difference = *this;

	for (size_t i = 0; i < used; i++) {
		difference[i] -= data[i];
	}

	return *(this);
}

MyDoubleVector MyDoubleVector::operator +(const MyDoubleVector& v1) {
	// pre:사이즈가 같아야함.
	//post:Returns an object that is a vector-sum
	assert(used == v1.used);
	MyDoubleVector sum= *this;

	for (size_t index = 0; index < used; index++) {
		sum[index] += data[index];
	}
	return sum;
}

double MyDoubleVector::operator *(const MyDoubleVector& v1) {
	// pre:사이즈 같아야함.
	//post:Returns the scalar product (of dot product) value of the two operand objects.
	assert(used == v1.used);
	MyDoubleVector scalar = *this;
	size_t temp = 0;
	for (size_t i = 0; i < used; i++) {
		temp += scalar[i] * data[i];
	}
	return temp;
}

MyDoubleVector MyDoubleVector::operator +=(const MyDoubleVector& v1) {
	// pre:
	//post:appends RHS object to LHS one
	if (used + v1.used > capa)
		reserve(used + v1.used);
	copy(v1.data, v1.data + v1.used, data + used);
	used += v1.used;

	return *(this);
}

bool MyDoubleVector::operator ==(const MyDoubleVector& v1) {
	// pre:check if their sizes are the same(not capacities).
	//postcondition: two operand vectors가 같으면 return.

	assert(capa == v1.capacity());
	MyDoubleVector same = *this;

	for (size_t i = 0; i < used; i++) {
		if (same[i] != data[i])
			return false;
	}
	return true;
}

MyDoubleVector& MyDoubleVector::operator =(const MyDoubleVector& v1) {
// pre:chaining assignment should be possible
//post:
	this->reserve(v1.capa);
	used = v1.used;
	copy(v1.data, v1.data + used, data);

	return *(this);
}

MyDoubleVector MyDoubleVector::operator ()(double ChangeValue) {
	// pre:ChangeValue는 double type이어야함.
	//post:Makes every element of this object be the value of the real-valued operand.
	
	size_t i;
	for (i = 0; i < used; i++) {
		data[i] = ChangeValue;
	}
	return *(this);
}

double& MyDoubleVector::operator [](double index) {
	// pre:index <= used
	//post:Returns a reference to the element at the requested position
	//     in the vector container.
	double temp;
	for(int i = 0; i <= used; i++) {
		if(i==index)
			temp = data[i];
	}
	return temp;
		
}








