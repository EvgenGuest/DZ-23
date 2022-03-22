#include<iostream>
using namespace std;

template <typename T> void showArray(T array[], int length);
void threeMax(int &aref, int &bref, int &cref) {
	if (aref > bref && aref > bref){
		bref = aref;
		cref = aref;
	}
	if (bref > aref && bref > cref){
		aref = bref;
		cref = bref;
	}
	if (cref > aref && cref > bref) {
		aref = cref;
		bref = cref;
	}	
}
int arr1(int pZ2[], int length);
int& funcNeg(int z2Ref[], int length);
void zero(int arr1[], int length1, int arr2[], int length2);

int main() {
	setlocale(LC_ALL, "Russian");

	//������ 1.
	cout << "������ 1.\n";
	int a = 22, b = 34, c = 12;
	int &aref = a;
	int &bref = b;
	int &cref = c;
	threeMax(a, b, c);	
	cout << a << " " << b << " " << c << "\n\n";

	//������ 2.	
	cout << "������ 2.\n������:\n";
	int z2[10] = { 1, 2, -3, 4, 5, -6, 7, 8, 9, 10 };
	showArray(z2, 10);
	cout << endl;
	cout << funcNeg(z2, 10) << "\n\n";

	// ������ 3
	cout << "������ 3.\n������ 1:\n";
	int z3_1[7] = { 3, 6, 4, 1, 4, 8, 2 };
	int* pz3_1 = z3_1;
	showArray(z3_1, 7);
	cout << "\n������ 2:\n";
	int z3_2[6] = { 5, 3, 1, 5, 10, 8 };
	int* pz3_2 = z3_2;
	showArray(z3_2, 6);
	cout << endl;
	zero(pz3_1, 7, pz3_2, 6);
	cout << "�������� ������� �������:\n";
	showArray(z3_2, 6);
	cout << endl;

	return 0;
}

//������ 1.
int arr1(int pZ2[], int length) {
	for (int i = 0; i < length; i++) {
		if (*(pZ2 + i) < 0)
			return *(pZ2 + i);

	}
}

//������ 2.
int& funcNeg(int z2Ref[], int length) {
	for (int i = 0; i < length; i++) {
		if (z2Ref[i] < 0)
			return z2Ref[i];
	}
	return z2Ref[0];
}

//������ 3.
void zero(int arr1[], int length1, int arr2[], int length2) {
	for (int i = 0; i < length2; i++) {
		for (int j = 0; j < length1; j++) {
			if (*(arr2 + j) == *(arr1 + i))
				*(arr2 + j) = 0;
		}
	}
}

template <typename T> void showArray(T array[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << array[i] << ", ";
	cout << "\b\b]";
}