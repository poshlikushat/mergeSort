#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mergeSort.h"


const float EPSILON = 0.00001;


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


int testIntSort()
{
	int arr[] = {5, 3, 8, 6, 2, 7, 4, 1};
	int expected[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int length = sizeof(arr) / sizeof(arr[0]);

	mergeSort(arr, length, sizeof(int), compareInt);
	for (int i = 0; i < length; i++)
	{
		if (arr[i] != expected[i])
		{
			return -1;
		}
	}
	return 1;
}

int testFloatSort()
{
	float arr[] = {5.5, 3.3, 8.8, 6.6, 2.2, 7.7, 4.4, 1.1};
	float expected[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8};
	int length = sizeof(arr) / sizeof(arr[0]);

	mergeSort(arr, length, sizeof(float), compareFloat);

	for (int i = 0; i < length; i++)
	{
		if (fabsf(arr[i] - expected[i]) > EPSILON)
		{
			return -1;
		}
	}
	return 1;
}

int testCharSort()
{
	char arr[] = {'e', 'd', 'a', 'c', 'b'};
	char expected[] = {'a', 'b', 'c', 'd', 'e'};
	int length = sizeof(arr) / sizeof(arr[0]);

	mergeSort(arr, length, sizeof(char), compareChar);

	for (int i = 0; i < length; i++)
	{
		if (arr[i] != expected[i])
		{
			return -1;
		}
	}
	return 1;
}

int testDoubleSort()
{
	double arr[] = {5.5, 3.3, 8.8, 6.6, 2.2, 7.7, 4.4, 1.1};
	double expected[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8};
	int length = sizeof(arr) / sizeof(arr[0]);

	mergeSort(arr, length, sizeof(double), compareDouble);

	for (int i = 0; i < length; i++)
	{
		if (arr[i] != expected[i])
		{
			return -1;
		}
	}
	return 1;
}

int testStructSort()
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
			return -1;
		}
	}
	return 1;
}

void PrintTestRes(char* testName, int testRes)
{

	if (testRes != -1) {
		printf("%s passed\n", testName);
		return;
	}
	printf("%s failed\n", testName);
	return;
}

void RunAllTests()
{
	PrintTestRes("testIntSort", testIntSort());
	PrintTestRes("testFloatSort", testFloatSort());
	PrintTestRes("testChatSort", testCharSort());
	PrintTestRes("testDoubleSort", testDoubleSort());
	PrintTestRes("testStructSort", testStructSort());
}
