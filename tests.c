#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mergeSort.h"

int compareInt(const void *ptr_a, const void *ptr_b)
{
	return (*(int *)(ptr_a) >= *(int *)(ptr_b)) ? 1 : 0;
}

int compareFloat(const void *ptr_a, const void *ptr_b)
{
	return (*(float *)(ptr_a) >= *(float *)(ptr_b)) ? 1 : 0;
}

int compareChar(const void *ptr_a, const void *ptr_b)
{
	return (*(char *)(ptr_a) >= *(char *)(ptr_b)) ? 1 : 0;
}

int compareDouble(const void *ptr_a, const void *ptr_b)
{
	return (*(double *)(ptr_a) >= *(double *)(ptr_b)) ? 1 : 0;
}

typedef struct personInfo
{
	char last_name[25];
	char first_name[25];
	char sex;
} INFO;

int compareStruct(const void *ptr_a, const void *ptr_b)
{
	INFO *a = (INFO *)ptr_a;
	INFO *b = (INFO *)ptr_b;

	return strcmp(a->first_name, b->first_name);
}


void testIntSort()
{
	int arr[] = {5, 3, 8, 6, 2, 7, 4, 1};
	int expected[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int length = sizeof(arr) / sizeof(arr[0]);

	mergeSort(arr, length, sizeof(int), compareInt);

	for (int i = 0; i < length; i++)
	{
		if (arr[i] != expected[i])
		{
			printf("testIntSort failed\n");
			return;
		}
	}
	printf("testIntSort passed\n");
}

void testFloatSort()
{
	float arr[] = {5.5, 3.3, 8.8, 6.6, 2.2, 7.7, 4.4, 1.1};
	float expected[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8};
	int length = sizeof(arr) / sizeof(arr[0]);

	mergeSort(arr, length, sizeof(float), compareFloat);

	for (int i = 0; i < length; i++)
	{
		if (arr[i] != expected[i])
		{
			printf("testFloatSort failed\n");
			return;
		}
	}
	printf("testFloatSort passed\n");
}

void testCharSort()
{
	char arr[] = {'e', 'd', 'a', 'c', 'b'};
	char expected[] = {'a', 'b', 'c', 'd', 'e'};
	int length = sizeof(arr) / sizeof(arr[0]);

	mergeSort(arr, length, sizeof(char), compareChar);

	for (int i = 0; i < length; i++)
	{
		if (arr[i] != expected[i])
		{
			printf("testCharSort failed\n");
			return;
		}
	}
	printf("testCharSort passed\n");
}

void testDoubleSort()
{
	double arr[] = {5.5, 3.3, 8.8, 6.6, 2.2, 7.7, 4.4, 1.1};
	double expected[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8};
	int length = sizeof(arr) / sizeof(arr[0]);

	mergeSort(arr, length, sizeof(double), compareDouble);

	for (int i = 0; i < length; i++)
	{
		if (arr[i] != expected[i])
		{
			printf("testDoubleSort failed\n");
			return;
		}
	}
	printf("testDoubleSort passed\n");
}

void testStructSort()
{
	INFO arr[] = {
		{"Smith", "John", 'M'},
		{"Doe", "Jane", 'F'},
		{"Brown", "Alice", 'F'},
		{"Johnson", "Zach", 'M'}};
	INFO expected[] = {
		{"Brown", "Alice", 'F'},
		{"Doe", "Jane", 'F'},
		{"Smith", "John", 'M'},
		{"Johnson", "Zach", 'M'}};
	int length = sizeof(arr) / sizeof(arr[0]);

	mergeSort(arr, length, sizeof(INFO), compareStruct);

	for (int i = 0; i < length; i++)
	{
		if (strcmp(arr[i].first_name, expected[i].first_name) != 0 ||
			strcmp(arr[i].last_name, expected[i].last_name) != 0 ||
			arr[i].sex != expected[i].sex)
		{
			printf("testStructSort failed\n");
			return;
		}
	}
	printf("testStructSort passed\n");
}

int main()
{
	testIntSort();
	testFloatSort();
	testCharSort();
	testDoubleSort();
	testStructSort();

	return 0;
}
