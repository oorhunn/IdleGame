#ifndef SAMEPAIRHASHMAP_H
#define SAMEPAIRHASHMAP_H

#include <unordered_map>
#include <functional>

template <typename valueType>
class SamePairHashmap {
public:

    std::size_t hashFunction(int id1, int id2) const;

    void insert(int id1, int id2, valueType value);

    int get(int id1, int id2) const;

private:
    std::unordered_map<std::size_t, valueType> hashmap;
};
#endif