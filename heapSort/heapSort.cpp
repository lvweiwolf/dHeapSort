// heapSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "stdlib.h"
#include "qsort.h"

int main()
{
 	int a[7] = { 2, 5, 1, 3, 10, 11, 8 };

	quickSort(a, 0, 7);

	for (int i = 0; i < 7; ++i)
		std::cout << a[i] << ' ';



	system("pause");
	return 0;
}