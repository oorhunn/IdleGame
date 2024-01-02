#include "../include/BinaryHeap.h"
#include <stdexcept>
#include "BinaryHeap.h"



template class BinaryHeap<int>;

template <typename T>
inline BinaryHeap<T>::BinaryHeap(int capacity) {
    array.reserve(capacity);
    currentSize = 0;  
}

template <typename T>
BinaryHeap<T>::BinaryHeap(const std::vector<T> &items)
{
    array = items;
    buildHeap();
}

template <typename T>
bool BinaryHeap<T>::isEmpty() const {
    return currentSize == 0;
}

template <typename T>
const T &BinaryHeap<T>::findMin() const
{
    if (currentSize == 0){
        return NULL;
    }
    return array[0];
}
template <typename T>
void BinaryHeap<T>::insert(const T &x)
{
    array.push_back(x);
    ++currentSize;
    heapify();

}

template <typename T>
void BinaryHeap<T>::insert(T&& x) {
    array.push_back(x);
    ++currentSize;
    heapify();

}

template <typename T>
void BinaryHeap<T>::deleteMin()
{
    array.erase(array.begin());
    heapify();
}
template <typename T>
void BinaryHeap<T>::makeEmpty() {
    array.clear();
    currentSize = 0;
}
template <typename T>
void BinaryHeap<T>::heapify()
{
    for (int i = currentSize - 1; array[getParent(i)] > array[i]; i!=0){
        std::swap(array[getParent(i)], array[i]);
        i = getParent(i);
    }

}
template <typename T>
void BinaryHeap<T>::buildHeap()
{
    currentSize = array.size();
    heapify();
}



template <typename T>
int BinaryHeap<T>::getLeftChild(int index)
{
    return 2 * index + 1;
}

template <typename T>
int BinaryHeap<T>::getRightChild(int index)
{
    return 2 * index + 2;
}
template <typename T>
int BinaryHeap<T>::getParent(int index)
{
    return (index - 1) / 2;
}
