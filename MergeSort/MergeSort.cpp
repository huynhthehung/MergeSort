//// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
#include <iostream>
using namespace std;
void NhapMang(int M[], int n);
void XuatMang(int M[], int n);
void MSort(int M[], int temp[], int left, int right);
void Merge(int M[], int temp[], int left, int middle, int right);
int main()
{
	int n = 0;
	cout << "Nhap n: ";
	cin >> n;
	int M[100], temp[100];
	NhapMang(M, n);
	cout << "Mang sau khi nhap: " << "\n";
	XuatMang(M, n);
	MSort(M, temp, 0, n - 1);
	cout << "\nMang sau khi sap xep: " << "\n";
	XuatMang(M, n);
	return 0;
}

void NhapMang(int M[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "M[" << i << "]=";
		cin >> M[i];
	}
}

void XuatMang(int M[], int n)
{
	for (int i = 0; i < n; i++)
		cout << M[i] << "\t";
}

void MSort(int M[], int temp[], int left, int right)
{
	int middle;
	if (right > left)
	{
		middle = (left + right) / 2;
		MSort(M, temp, left, middle);
		MSort(M, temp, middle + 1, right);
		Merge(M, temp, left, middle, right);
	}
}

void Merge(int M[], int temp[], int left, int middle, int right)
{
	int i, leftEnd, rightStart, size, tempPos;
	leftEnd = middle;
	rightStart = middle + 1;
	tempPos = left;
	size = right - left + 1;

	while (left <= leftEnd && rightStart <= right)
		if (M[left] < M[rightStart])
			temp[tempPos++] = M[left++];
		else
			temp[tempPos++] = M[rightStart++];

	while (left <= leftEnd)
		temp[tempPos++] = M[left++];

	while (rightStart <= right)
		temp[tempPos++] = M[rightStart++];

	for (i = 0; i <= size; i++)
	{
		M[right] = temp[right];
		right--;
	}
}

