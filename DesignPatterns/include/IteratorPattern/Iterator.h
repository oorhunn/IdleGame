#ifndef ITERATOR_PATTERN_H
#define ITERATOR_PATTERN_H

#include <iostream>
#include <string>
#include <vector>

template <typename T, typename U>
class Iterator {
public:
    typedef typename std::vector<T>::iterator iter_type;

    Iterator(U *p_data, bool reverse = false);
    void First();
    void Next();
    bool IsDone();
    T& Current();

private:
    U *m_p_data_;
    iter_type m_it_;
};

template <class T>
class Container {
friend class Iterator<T, Container<T>>;
public:
    void Add(T a);
    Iterator<T, Container<T>>* CreateIterator();

private:
    std::vector<T> m_data_;
};

class Data {
public:
    Data(int a = 0);
    void set_data(int a);
    int data();

private:
    int m_data_;
};

void ClientCode();
#endif // ITERATOR_PATTERN_H
