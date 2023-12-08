#include <iostream>
#include <memory>
// violating rule of three example
class RuleOfThree {
public:
	RuleOfThree(){
		mData = new int(0);
	}

    RuleOfThree(const RuleOfThree& other){
        mData = new int(*other.mData);
    }

    RuleOfThree operator=(const RuleOfThree other) {
        if(this != &other){
            *mData = *other.mData;
        }
    }

	~RuleOfThree(){
		delete mData;
	}
	void setValue(int value) {
		*mData = value;
	}
	int* getValue() {
		return mData;
	}
private:
	int *mData;
};



class MyTryToGetAround {
public:
    MyTryToGetAround() : mData(std::make_unique<int>(0)) {}

	~MyTryToGetAround(){
		// delete mData;
	}
	void setValue(int value) {
		*mData = value;
	}
	int getValue() {
		return *mData;
	}
private:
	std::unique_ptr<int> mData;
};


class MyTryToGetAround2 {
public:
    MyTryToGetAround2() {
        mData = std::make_shared<int>();
    }
    MyTryToGetAround2(const MyTryToGetAround2& other){
        mData = std::make_shared<int>();
        *mData = *(other.mData);
    }
    MyTryToGetAround2 operator=(const MyTryToGetAround2& other){
        mData = std::make_shared<int>();
        *mData = *other.mData;
        return *this;
    }



    MyTryToGetAround2(const std::shared_ptr<MyTryToGetAround2> other){
        *mData = *(other->mData);
    }
	~MyTryToGetAround2(){
		// delete mData;
	}
	void setValue(int value) {
		*mData = value;
	}
	int getValue() {
		return *mData;
	}
private:
	std::shared_ptr<int> mData;
};


int main() {
    int myConde = 2;
    if (!myConde){
        // std::shared_ptr<Gorg> george = std::make_shared<Gorg>();

        RuleOfThree obj1;
        obj1.setValue(42);
        RuleOfThree obj2;
        obj2 = obj1;
        obj1.setValue(10);

        std::cout << obj1.getValue() << "\n";
        std::cout << obj2.getValue() << "\n";
    }
    else if (myConde == 2){
        MyTryToGetAround2 obj1;
        obj1.setValue(42);
        MyTryToGetAround2 obj2 = obj1;
        MyTryToGetAround2 obj3;
        obj3 = obj1;        
        obj1.setValue(10);
        return 0;

    }

    else {
        std::shared_ptr<MyTryToGetAround> obj1 = std::make_shared<MyTryToGetAround>();
        obj1->setValue(42);
        std::shared_ptr<MyTryToGetAround> obj2 = obj1;
        obj1->setValue(10);
        std::cout << obj1->getValue() << "\n";
        std::cout << obj2->getValue() << "\n";
    }


    return 0;
}