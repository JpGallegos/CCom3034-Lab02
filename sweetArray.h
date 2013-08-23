#ifndef SWEET_H
#define SWEET_H

#include <iostream>
using namespace std;
class SweetArray {
private:	
	int *array;
	int size;
public:
	SweetArray();
	SweetArray(int n);
	int& operator[](int i);

	int getArraySize()const;

	void rmDup();

	SweetArray operator+(const SweetArray& B)const;
	SweetArray operator&(const SweetArray& B)const;
	SweetArray operator|(const SweetArray& B)const;

friend ostream& operator<<(ostream& out, SweetArray S);

};

#endif

