#include <iostream>
#include "sweetArray.h"
using namespace std;

SweetArray::SweetArray() {
	array = new int[10];
	size = 10;
}
SweetArray::SweetArray(int n) {
	array = new int[n];
	size = n;
}

int& SweetArray::operator[](int i) {
	return array[i];
}

int SweetArray::getArraySize()const {
	return size;
}

void SweetArray::rmDup() {
	// Uses a modified MergeSort to remove duplicated elements
	
}

SweetArray SweetArray::operator+(const SweetArray& B)const {
	// Presuming the case |A| = |B|
	SweetArray C(size);

	for (int idx=0; idx<size; idx++) {
		C[idx] = array[idx] + B.array[idx];
	}

	return C;
}

SweetArray SweetArray::operator&(const SweetArray& B)const {
	int k = 0;
	SweetArray C(size);
	for(int i=0; i<size; i++) {
		for(int j=0; j<size; j++) {
			if(array[i] == B.array[j]) {
				C[k] = array[i];
				k++;
				break;
			}
		}
	}
	C.size = k; // If this value is not changed, the ostream will print garbage
	return C;
}

SweetArray SweetArray::operator|(const SweetArray& B)const {
	int k = 0;
	SweetArray C(size + B.size);
	for (int i=0; i<size; i++) {
		C[k] = array[i];
		C[k+1] = B.array[i];
		k += 2;
	}
	C.size = k;
	C.rmDup();
	return C;
}

ostream& operator<<(ostream& out, SweetArray S) {
	if (S.size == 0) return out;
	out << S.array[0];
	for (int i=1; i<S.size; i++)
		out << ", " << S.array[i];
	return out;
}
