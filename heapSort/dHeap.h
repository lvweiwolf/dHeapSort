/*!
 * \file dHeap.h
 * \date 2016/03/06 15:21
 *
 * \author lvwei
 * Contact: lvwei@booway.com.cn
 *
 * \brief d叉堆得推演和实现
 *
 * 实现原理: 基于二叉堆得数据接口是完全二叉树，可以猜测到
 *			d叉树所基于的数据接口是完全d叉树。在该数据结
 *		    的基础上，只要有办法能找到完全d 叉树中任意节
 *          点i的父节点PARENT(i)和准确定位孩子节点CHILD
 *          (i, 1~d)，就可按照二叉堆的实现提供d叉树的实
 *          现。
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
	// 调整大根堆
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

	// 创建大根堆
	static void BuildMax(CompleteBinTree &list)
	{
		// DEBUG: 改方法不适用于d叉堆
		IndexType size = list.size();

		for (int i = (int)size / d - 1; i >= 0; --i)
			MaxHeapify(i, list);
	}
};