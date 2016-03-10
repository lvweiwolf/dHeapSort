/*!
 * \file heap.h
 * \date 2016/03/06 15:15
 *
 * \author lvwei
 * Contact: lvwei@booway.com.cn
 *
 * \brief 堆排序实现
 *
 * TODO: long description
 *
 * \note
*/
#pragma once

#include <vector>

#define LEFT(i)  ((i << 1) + 1)
#define RIGHT(i) ((i << 1) + 2)
#define PARENT(i) ((i - 1) >> 2)

template<typename T>
class BinHeap {
public:
    typedef T Type;
    typedef typename std::vector<T> CompleteBinTree;
    typedef typename std::vector<T>::size_type SizeType;

    
    /*
     * \method   MaxHeapSort
     * \author	 lvwei
     * \param	 CompleteBinTree & in 输入无序数组
     * \param	 CompleteBinTree & out 输出排序后数组
     * \return   void
     * \ brief	 大根堆排序
     */
    static void MaxHeapSort(CompleteBinTree &in, CompleteBinTree& out);

    /*
     * \method   MinHeapSort
     * \author	 lvwei
     * \param	 CompleteBinTree & in 输入无序数组
     * \param	 CompleteBinTree & out输出排序后数组
     * \ brief	 小根堆排序
     */
    static void MinHeapSort(CompleteBinTree &in, CompleteBinTree& out);

    /*
     * \method   ExtractMax
     * \author	 lvwei
     * \param	 CompleteBinTree & in 输入大/小根堆
     * \return   Type	出列元素最大/小值
     * \ brief	 优先队列出列（最大）
     */
    static Type ExtractMax(CompleteBinTree &in)
    {
        if (in.empty())
            throw std::exception();

        Type max = *(in.begin());

        *(in.begin()) = *(in.end() - 1);
        in.pop_back();

        MaxHeapify(0, in);

        return max;
    }

    /*
     * \method   IncreaseKey
     * \author	 lvwei
     * \param	 CompleteBinTree & in 大根堆
     * \param	 SizeType index	大根堆中指定位置
     * \param	 Type val		更新后的值
     * \ brief	 更新大根堆指定元素值
     */
    static void IncreaseKey(CompleteBinTree &in, SizeType index, Type val)
    {
        if (index >= in.size())
            throw std::exception();

        in.at(index) = val;
        SizeType parent = PARENT(index);

        while (parent < in.size() && in.at(parent) < in.at(index))
        {
            Type tmp = in.at(parent);
            in.at(parent) = in.at(index);
            in.at(index) = tmp;

            index = parent;
            parent = PARENT(parent);
        }
    }

private:
    // 调整大根堆
    static void MaxHeapify(SizeType index, CompleteBinTree &binTree);

    // 调整小根堆
    static void MinHeapify(SizeType index, CompleteBinTree &binTree);

    // 创建大根堆
    static void BuildMax(CompleteBinTree &list);

    // 创建小根堆
    static void BuildMin(CompleteBinTree &list);
};


template<typename T>
void BinHeap<T>::MaxHeapify(SizeType index,
                            CompleteBinTree &binTree) {
    if (index >= binTree.size())
        return;

    BinHeap<T>::SizeType final = index;
    BinHeap<T>::SizeType l = LEFT(index);
    BinHeap<T>::SizeType r = RIGHT(index);

    if (l < binTree.size() && binTree.at(l) > binTree.at(index))
        final = l;

    if (r < binTree.size() && binTree.at(r) > binTree.at(final))
        final = r;

    if (final != index){
        BinHeap<T>::Type tmp = binTree.at(index);
        binTree.at(index) = binTree.at(final);
        binTree.at(final) = tmp;

        BinHeap<T>::MaxHeapify(final, binTree);
    }
}

template<typename T>
void BinHeap<T>::MinHeapify(SizeType index,
                            CompleteBinTree &binTree) {

}

template<typename T>
void BinHeap<T>::MaxHeapSort(CompleteBinTree &in,
                             CompleteBinTree &out) {

    if (in.empty())
        return;

    // build the heap
    BuildMax(in);

    while (!in.empty())
    {
        typename BinHeap<T>::CompleteBinTree::iterator iter = in.end() - 1;

        // swap the first and the last
        BinHeap<T>::Type t = *(in.begin());
        *(in.begin()) = *iter;
        *iter = t;

        // take the root node because root is largest
        out.push_back(*iter);

        in.erase(iter);

        MaxHeapify(0, in);
    }
}

template<typename T>
void BinHeap<T>::MinHeapSort(CompleteBinTree &in,
                             CompleteBinTree &out) {

}

template<typename T>
void BinHeap<T>::BuildMax(CompleteBinTree &list) {
    BinHeap<T>::SizeType size = list.size();

    for (int i = (int)size / 2 - 1; i >= 0; --i) {
        MaxHeapify(i, list);
    }
}

template<typename T>
void BinHeap<T>::BuildMin(CompleteBinTree &list)
{
	//TODO： 构建小根堆
}
