#pragma once
#ifndef MyDoubleVector_H
#define MyDoubleVector_H
#include <cstdlib>


class MyDoubleVector
	{
	public:
		MyDoubleVector(size_t init_capacity = Default_Capacity);
		static const size_t Default_Capacity = 100;
		MyDoubleVector(const MyDoubleVector& v);
		~MyDoubleVector();

		void pop_back();
		void push_back(double x);
		size_t capacity() const;
		size_t size() const;
		void reserve(size_t n);
		bool empty() const;
		void clear();

		MyDoubleVector operator-();
		MyDoubleVector operator-(const MyDoubleVector& v1);
		MyDoubleVector operator+(const MyDoubleVector& v1);
		double operator*(const MyDoubleVector& v1);
		MyDoubleVector operator+=(const MyDoubleVector& v1);
		bool operator==(const MyDoubleVector& v1);
		MyDoubleVector& operator=(const MyDoubleVector& v1);
		MyDoubleVector operator()(double ChangeValue);
		double& operator[](double index);

	private:
		double *data;
		size_t used;
		size_t capa;
};

#endif //!MyDoubleVector_H

