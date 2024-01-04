
#include "../include/SamePairHashmap.h"

template class SamePairHashmap<int>;
template class SamePairHashmap<float>;
template class SamePairHashmap<double>;


template <typename valueType>
std::size_t SamePairHashmap<valueType>::hashFunction(int id1, int id2) const{
    if (id1 > id2) {
        std::swap(id1, id2);
    }

    // std::hash<int> hasher;
    // return hasher(id1) ^ hasher(id2);

    return id1*10 + id2;
}

template <typename valueType>
void SamePairHashmap<valueType>::insert(int id1, int id2, valueType value){
    std::size_t hashValue = hashFunction(id1, id2);
    hashmap[hashValue] = value;
}

template <typename valueType>
int SamePairHashmap<valueType>::get(int id1, int id2) const {
    std::size_t hashValue = hashFunction(id1, id2);
    auto it = hashmap.find(hashValue);

    if (it != hashmap.end()) {
        return it->second;
    } else {
        return -1;  
    }
}

