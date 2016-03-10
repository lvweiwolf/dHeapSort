/*!
 * \file dHeap.h
 * \date 2016/03/06 15:21
 *
 * \author lvwei
 * Contact: lvwei@booway.com.cn
 *
 * \brief d��ѵ����ݺ�ʵ��
 *
 * ʵ��ԭ��: ���ڶ���ѵ����ݽӿ�����ȫ�����������Բ²⵽
 *			d���������ڵ����ݽӿ�����ȫd�������ڸ����ݽ�
 *		    �Ļ����ϣ�ֻҪ�а취���ҵ���ȫd �����������
 *          ��i�ĸ��ڵ�PARENT(i)��׼ȷ��λ���ӽڵ�CHILD
 *          (i, 1~d)���Ϳɰ��ն���ѵ�ʵ���ṩd������ʵ
 *          �֡�
 *
 * \note
*/

#pragma once

#include <vector>


#define CHILD(d, i, index) (d*i + index + 1 )
#define PARENT(d, i) ((i - 1) / d)

template<typename T, int d>
class DHeap
{
public:
	typedef T Type;
	typedef typename std::vector<T> CompleteBinTree;
	typedef typename std::vector<T>::size_type IndexType;

	static void MaxHeapSort(CompleteBinTree &in, CompleteBinTree &out)
	{
		if (in.empty())
			return;

		// build the heap
		BuildMax(in);

		while (!in.empty())
		{
			typename CompleteBinTree::iterator iter = in.end() - 1;

			// swap the first and the last
			Type t = *(in.begin());
			*(in.begin()) = *iter;
			*iter = t;

			// take the root node because root is largest
			out.push_back(*iter);

			in.erase(iter);

			MaxHeapify(0, in);
		}
	}

private:
	// ���������
	static void MaxHeapify(IndexType index, CompleteBinTree &binTree)
	{
		IndexType final = index;
		
		for (IndexType i = 0; i < d; ++i)
		{
			IndexType childIndex = CHILD(d, index, i);

			if (childIndex < binTree.size() 
				&& binTree.at(childIndex) > binTree.at(final))
				final = childIndex;
		}

		if (final != index)
		{
			Type tmp = binTree.at(index);
			binTree.at(index) = binTree.at(final);
			binTree.at(final) = tmp;

			MaxHeapify(final, binTree);
		}
	}

	// ���������
	static void BuildMax(CompleteBinTree &list)
	{
		// DEBUG: �ķ�����������d���
		IndexType size = list.size();

		for (int i = (int)size / d - 1; i >= 0; --i)
			MaxHeapify(i, list);
	}
};