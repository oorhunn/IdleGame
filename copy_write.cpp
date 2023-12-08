#include <iostream>
#include <memory>


class MyString {

public:
    MyString(const std::string& str)
    : data(std::make_shared<std::string>(str)) {

    }

    MyString(const MyString& other) : data(other.data){
        std::cout << "copied with copywrite";
    }

    void write(const std::string& str){
        if(!data.unique()) {
            data = std::make_shared<std::string>(*data);
        }
        *data = str;
    } 

private:
    std::shared_ptr<std::string> data;
};


int main() {
    std::string inputshit = "hi hi ";
    std::shared_ptr<MyString> str1 = std::make_shared<MyString>(&inputshit);
    // MyString str2 = str1;

    return 0;
}