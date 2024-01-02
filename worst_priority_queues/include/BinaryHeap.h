#ifndef BINARYHEAP_H
#define BINARYHEAP_H


#include <stdexcept>
#include <vector>

template<typename T>
class BinaryHeap { 
public:
    explicit BinaryHeap(int capacity = 100);
    explicit BinaryHeap(const std::vector<T>& items);

    bool isEmpty() const;
    const T& findMin() const;

    void insert(const T& x);
    void insert(T&& x);
    void deleteMin();
    void deleteMin(T& minItem);
    void makeEmpty();


private:
    int currentSize;
    void heapify();
    std::vector<T> array;
    void buildHeap();
    static int getLeftChild(int index);
    static int getRightChild(int index);
    static int getParent(int index);

};



class UnderflowException : public std::runtime_error {
public:
    explicit UnderflowException(const std::string& message)
        : std::runtime_error(message) {}
};



#endif

