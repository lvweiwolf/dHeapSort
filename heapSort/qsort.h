/*!
 * \file qsort.h
 * \date 2016/03/10 20:58
 *
 * \author lvwei
 * Contact: lvwei@booway.com.cn
 *
 * \brief 快速排序
 *
 * TODO: long description
 *
 * \note
*/
#pragma once
#include <vector>
#include <iostream>

template<typename T>
void swap(T& ref1, T& ref2)
{
	T tmp = ref1;
	ref1 = ref2;
	ref2 = tmp;
}

/*
 * \method   quickSort
 * \author	 lvwei
 * \param	 T * A
 * \param	 int begin
 * \param	 int size
 * \return   void
 * \ brief	 快速排序算法
 */
template<typename T>
void quickSort(T* A, int begin, int size)
{
	if (begin < size)
	{
		int nPos = parttion(A, begin, size);
		quickSort(A, begin, nPos);
		quickSort(A, nPos + 1, size);
	}
}


/*
 * \method   parttion
 * \author	 lvwei
 * \param	 T * A
 * \param	 int begin
 * \param	 int size
 * \return   int
 * \ brief	 确定参考位置，参考位置左边所有元素小于参考值，右边所有元素大于参考值
 */
template<typename T>
int parttion(T* A, int begin, int size)
{
	try
	{
		// 容错
		if (size < 1)
			throw std::exception("invalid 'size' argument");

		if (begin < 0 || begin >= size)
			throw std::exception("invalid 'begin' argument");

		int exchange = begin - 1;
		int last = size - 1;
		T& refBase = A[size - 1];
		
		for (int pos = begin; pos < last; ++pos)
		{
			if (A[pos] > refBase)
				continue;

			exchange = exchange + 1;
			swap(A[exchange], A[pos]);
		}
		
		// 交换参考
		swap(A[exchange + 1], refBase);

		return exchange + 1;
	}
	catch(std::exception &e)
	{ 
		std::cout << e.what() << std::endl;
		return -1;
	}
}

