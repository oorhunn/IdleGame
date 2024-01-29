#include "../include/BinaryHeap.h"
#include <stdexcept>



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
    if (currentSize != 0){
        return array[0];
    }
    else {
        return T();
    }
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
    --currentSize;
    percolateDown(0);
}
template <typename T>
void BinaryHeap<T>::makeEmpty() {
    array.clear();
    currentSize = 0;
}
template <typename T>
std::vector<T> BinaryHeap<T>::heapSort()
{
    int swapPos = currentSize;
    for (int i = currentSize; i > 0; --i){
        array.resize(array.size() + 1 );
        std::swap(array[0], array[swapPos]);
        deleteMin();
    }

    
    return array;
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
void BinaryHeap<T>::heapify(int index)
{
    for (; array[getParent(index)] > array[index]; index!=0){
        std::swap(array[getParent(index)], array[index]);
        index = getParent(index);
    }

}

template <typename T>
void BinaryHeap<T>::buildHeap()
{
    currentSize = array.size();
    for (int i = currentSize / 2 - 1; i >= 0; --i) {
        percolateDown(i);
    }
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


template <typename T>
void BinaryHeap<T>::percolateDown(int index) {
    int child;
    T tmp = std::move(array[index]);

    for (; getLeftChild(index) < currentSize; index = child) {
        child = getLeftChild(index);
        if (child != currentSize - 1 && array[child] > array[child + 1]) {
            ++child;
        }

        if (array[child] < tmp) {
            array[index] = std::move(array[child]);
        } else {
            break;
        }
    }

    array[index] = std::move(tmp);
}
