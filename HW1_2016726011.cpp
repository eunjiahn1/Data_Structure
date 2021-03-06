// HW1_2016726011.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#pragma warning(disable:4996)
#include <iostream>
#include <cassert>
#include "MyDoubleVector.h"
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()
	{
		MyDoubleVector v1(7);   //capacity=7
		MyDoubleVector v2(4);
		MyDoubleVector v3;      //capacity=0  default

		v1.push_back(3.5);
		v1.push_back(5);
		v1.push_back(8.1);

		cout << "v1 capacity is " << v1.capacity() << endl;			//capacity
		cout << "v1 used is " << v1.size() << endl;					//size
		cout << "v2 capacity is " << v2.capacity() << endl;
		cout << "v2 used is " << v2.size() << endl;
		cout << "v3 capacity is " << v3.capacity() << endl;
		cout << "v3 used is " << v3.size() << endl;

		for (double i = 0; i < v1.size(); i++) {			// operator []
			cout << v1[i] << " ";
		}
		cout << endl;

		v3 = v1;										// operator =
		cout << "v1 capacity is " << v1.capacity() << endl;			
		cout << "v1 used is " << v1.size() << endl;					
		cout << "v3 capacity is " << v3.capacity() << endl;
		cout << "v3 used is " << v3.size() << endl;
		for (double i = 0; i < v3.size(); i++) {			// operator []
			cout << v3[i] << " ";
		}
		cout << endl;

		if (v1 == v3) {									// operator ==
			cout << "v1 and v3, two operand vectors are same." << endl;
		}

		v1(7);											// operator ()
		for (double i = 0; i < v1.size(); i++) {			// operator []
			cout << v1[i] << " ";
		}
		cout << endl;

		v2.push_back(1);
		v2.push_back(2.2);
		v2.push_back(1.4);

		v1 + v2;										// operator +
		for (double i = 0; i < v1.size(); i++) {			// operator []
			cout << v1[i] << " ";
		}
		cout << endl;

		v3 - v2;										// operator -
		for (double i = 0; i < v3.size(); i++) {
			cout << v3[i] << " ";
		}
		cout << endl;

		-(v2);											// operator -()
		for (double i = 0; i < v2.size(); i++) {
			cout << v2[i] << " ";
		}
		cout << endl;

		v1 += v3;										// operator +=
		for (double i = 0; i < v1.size(); i++) {
			cout << v1[i] << " ";
		}
		cout << endl;

		v2.pop_back();
		v2.pop_back();
		v2.pop_back();
		v2.push_back(3);
		v2.push_back(5.4);
		v2.push_back(13.2);

		double scalar = v2 * v3;
		cout << scalar << endl;

		v1.clear();										// clear
		v2.clear();
		v3.clear();

		cout << "v1 is empty? " << v1.empty() << endl;  // empty
		cout << "v2 is empty? " << v2.empty() << endl;
		cout << "v3 is empty? " << v3.empty() << endl;

		return 0;
}




