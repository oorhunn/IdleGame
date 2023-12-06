#include <iostream>
#include <memory>

class Resource {
public:
    Resource(int id) : id(id) {
        std::cout << "Resource " << id << " created." << std::endl;
    }

    ~Resource() {
        std::cout << "Resource " << id << " destroyed." << std::endl;
    }

    void useResource() const {
        std::cout << "Using resource " << id << "." << std::endl;
    }

private:
    int id;
};

void demonstrateRawPointer() {
    std::cout << "\nDemonstrating Raw Pointer:" << std::endl;

    // Creating a resource using a raw pointer
    Resource* rawPtr = new Resource(1);

    // Using the resource
    rawPtr->useResource();

    // Deleting the resource manually (not recommended)
    delete rawPtr;
}

void demonstrateSmartPointer() {
    std::cout << "\nDemonstrating Smart Pointer:" << std::endl;

    // Creating a resource using std::unique_ptr
    std::unique_ptr<Resource> uniquePtr = std::make_unique<Resource>(2);

    // Using the resource
    uniquePtr->useResource();

    // No need to delete, std::unique_ptr handles it automatically
}

void demonstrateSharedPointer() {
    std::cout << "\nDemonstrating Shared Pointer:" << std::endl;

    // Creating a resource using std::shared_ptr
    std::shared_ptr<Resource> sharedPtr1 = std::make_shared<Resource>(3);
    std::shared_ptr<Resource> sharedPtr2 = sharedPtr1;  // Shared ownership

    // Using the resource
    sharedPtr1->useResource();
    sharedPtr2->useResource();

    // No need to delete, std::shared_ptr handles it automatically
}

int main() {
    demonstrateRawPointer();
    demonstrateSmartPointer();
    demonstrateSharedPointer();

    return 0;
}
