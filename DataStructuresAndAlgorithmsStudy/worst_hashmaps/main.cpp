#include <iostream>
#include <unordered_map>

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        int h1; int h2;
        if (p.first < p.second){
            int h2 = std::hash<T1>{}(p.first);
            int h1 = std::hash<T2>{}(p.second);
            return h1 ^ h2;
        }
        else {
            int h1 = std::hash<T1>{}(p.first);
            int h2 = std::hash<T2>{}(p.second);
            return h1 ^ h2;
        }
    }
};

int main() {
    // Define an unordered_map with std::pair<int, int> as the key type
    std::unordered_map<std::pair<int, int>, std::string, pair_hash> myMap;

    // Insert elements using std::pair as the key
    myMap[{1, 2}] = "Value1";
    myMap[{2, 1}] = "Valueasdfasdfa";

    myMap[{3, 4}] = "Value2";
    myMap[{5, 6}] = "Value3";

    // Access elements using std::pair as the key
    std::cout << "Value for key {1, 2}: " << myMap[{1, 2}] << std::endl;

    // Iterate over the map
    for (const auto& entry : myMap) {
        std::cout << "Key: {" << entry.first.first << ", " << entry.first.second
                  << "}, Value: " << entry.second << std::endl;
    }

    return 0;
}
