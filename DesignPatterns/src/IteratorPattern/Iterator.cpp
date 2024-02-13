#include "../../include/IteratorPattern/Iterator.h"



template <typename T, typename U>
Iterator<T, U>::Iterator(U *p_data, bool reverse = false) :
    m_p_data_(p_data) 
{
    m_it_ = m_p_data_->m_data_.begin();

}


template <typename T, typename U>
void Iterator<T, U>::First() {
    m_it_ = m_p_data_->m_data_.begin();
}

template <typename T, typename U>
void Iterator<T, U>::Next() {
    m_it_++;
}


template <typename T, typename U>
bool Iterator<T, U>::IsDone() {
    return (m_it_ == m_p_data_->m_data_.end());
}

template <typename T, typename U>
iter_type Iterator<T, U>::Current(){
    return m_it_;
}

