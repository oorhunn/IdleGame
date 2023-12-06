

### Data Types

- float 4 bytes 
- double 8 bytes
- char 1 byte
- bool  1 byte 
- **Arrays**: 
``` 
int numbers[5] = {1, 2, 3, 4, 5};
```

- **Pointers**: Pointers are used to store the memory address of a variable.
```
int num = 42;
int* pNum = &num;
```

- **References**: References are an alternative way to share memory locations between variables, allowing you to create an alias for another variable.
```
int num = 42;
int& numRef = num;
```

- **Structures**:
Structures are used to store different data types under a single variable and accessibility of member variables and methos are PUBLIC.

```
struct Person {
	string name;
	int age;
	float height; 
};
Person p1 = {"John Doe", 31, 5.9};
```

- **Classes**:  
Classes are similar to structures, but the accessibility of the member data and function are governed by access specifiers. By default access to members of a class is private.

```
class Person { 
public:
	string name;
	int age;
	void printInfo() {
		cout << name << age << endl;
	};
};

Person p1;
p1.name = "John Doe";
p1.age = 31;
```

- **Unions**:
Unions are used to store different data types in the same memory location.

```
union Data {
	int num;
	char letter;
	float decimal;
};
Data myData;
myData.num = 42;
```





### Pointers 
```
struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

Node *head = nullptr;
Node *tail = nullptr;

void link(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    if (head == nullptr) {
        head = temp;
        tail = temp;        
    }
    else {
        tail->next = temp;
        tail = temp;
    }
    return;
}

  
void print_links() {
    Node *track = head;

    while (track != nullptr){
        cout << track->data<< endl;
        track = track->next;
    }
    return;
}

int main() {
    link(12);
    link(31);

    print_links();
    return 0;
}
```

### Memory Model in C++
The memory model in C++ defines how the program stores and accesses data in computer memory. It consists of different segments, such as the Stack, Heap, Data and Code segments.
#### Stack Memory
Stack memory is used for automatic storage duration variables, such as local variables and function call data. Stack memory is managed by the compiler, and its allocation and deallocation are done automatically. The stack memory is also a LIFO data structure.

#### Heap Memory 
Heap memory is used for dynamic storage duration variables, such as objects created using the `new` keyword. The programmer has control over the allocation and deallocation of heap memory using `new` and `delete` operators. Heap memory is a larger pool of memory than  the stack, but has a slower access time.

#### Data Segment
The Data segment is composed of two parts: the initialized data segment and the uninitialized data segment. The initialized data segment stores global, static and constant variables with initial values, whereas the uninitialized segment stores uninitialized global and static variables.

#### Code Segment 
The Code segment also known as the text segment stores the executable code (machine code) of the program. It usually located in a read-only area of memory to prevent accidental modification.

### Object Lifetime in C++
- **Static Storage Duration:** Objects with static storage duration exist for the entire run of the program. These objects are allocated at the beginning of the programs run and deallocated when the program terminates. Global variables, static data members and static local variables fall into this category.
```
int global_var; // static storage duration
class MyClass {
	static int static_var; // static storage duration
};
void myFunction() {
	static int local_var; // static storage duration
}
```

- **Thread Storage Duration:**  Objects with thread storage duration exist for the lifetime of the thread they belong to. Can be specified using the `thread_local` keyword.
```
thread_local in my_var; // thread storage duration
```

- **Automatic Storage Duration:** Objects with automatic storage duration are created at the point of definition and destroyed when the scope in which the are declared is exited. These objects are also known as local or stack objects.
- **Dynamic Storage Duration:** Objects with dynamic storage are created at runtime, using memory allocation functions such as `new`. Its the programmers responsibility to destroy the objects using `delete` to avoid memory leaks.
```
int *ptr = new int;
delete ptr;
```



### Diamond Inheritance
Diamond inheritance is a specific scenario in multiple inheritance where a class is derived from two or more classes, which in turn, are derived from a common base class. It creates an ambiguity that arises from duplicating the common base class, which leads to an ambiguous behavior while calling the duplicate members.
To resolve this ambiguity, you can use virtual inheritance. A virtual base class is a class that is shared by multiple classes using `virtual` keyword in C++. This ensures that only one copy of the base class is inherited in the final derived class, and thus, resolves the diamond inheritance problem.
*Example:*
```
#include <iostream>

class Base {
public:
    void print() {
        std::cout << "Base class" << std::endl;
    }
};

class Derived1 : virtual public Base {
public:
    void derived1Print() {
        std::cout << "Derived1 class" << std::endl;
    }
};

class Derived2 : virtual public Base {
public:
    void derived2Print() {
        std::cout << "Derived2 class" << std::endl;
    }
};

class Derived3 : public Derived1, public Derived2 {
public:
    void derived3Print() {
        std::cout << "Derived3 class" << std::endl;
    }
};

int main() {
    Derived3 d3;
    d3.print(); // Now, there is no ambiguity in calling the base class function
    d3.derived1Print();
    d3.derived2Print();
    d3.derived3Print();

    return 0;
}

```

### Object-Oriented Programming in C++
#### Classes 
```
class Dog {
public:
	string name;
	int age;
	void bark() {
		cout << name << "barks" << endl;
	}
} 
```
#### Encapsulation
Encapsulation is the concept of bundling data and functions that operate on that data within a single unit. In C++ you can use access specifiers like `public`, `private`, and `protected` to control the visibility and accessibility of class members.

#### Inheritance
```
class Animal {
public:
	void breathe() {
		cout << " i breathe" << endl;
	}
};

class Dog : public Animal {
public:
	void bark() {
		cout << "dog barks" << endl;
	}
}
```
In this example, the `Dog` class inherits from the `Animal` class so the `Dog` class can access the `breathe` function from the `Animal` class. When you create a `Dog` object, you can use both `breathe` and `bark` functions.

#### Polymorphism
```
class Animal {
public:
    virtual void makeSound() {
        std::cout << "The Animal makes a sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Dog barks!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Cat meows!" << std::endl;
    }
};
```

```
Animal *animals[2] = {new Dog, new Cat};
animals[0]->makeSound(); // Output: Dog barks!
animals[1]->makeSound(); // Output: Cat meows!
```



### Static Polymorphism
Static polymorphism, also known as compile-time polymorphism, is a type of polymorphism that resolves the types and method calls at compile time rather than at runtime. This commonly achieved through the use of function **overloading** and **templates** in C++. 
#### Templates 
```
#include <iostream>

// Template function to print any type
template<typename T>
void print(const T& value) {
    std::cout << "Printing value: " << value << std::endl;
}

int main() {
    print(42);           // int
    print(3.14159);      // double
    print("Hello");      // const char*

    return 0;
}
```

### Dynamic Polymorphism
Dynamic polymorphism is a programming concept in object-oriented languages like C++ where a derived class can override or redefine methods of its base class. This means that a single method call can have different implementations based on the type of object it is called on.

Dynamic polymorphism is achieved through **virtual functions**, which are member functions of a base class marked with the `virtual` keyword.
```
#include <iostream>

// Base class
class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing a shape" << std::endl; 
    }
};

// Derived class 1
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle" << std::endl; 
    }
};

// Derived class 2
class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a rectangle" << std::endl;
    }
};

int main() {
    Shape* shape;
    Circle circle;
    Rectangle rectangle;

    // Storing the address of circle
    shape = &circle;

    // Call circle draw function
    shape->draw();

    // Storing the address of rectangle
    shape = &rectangle;

    // Call rectangle draw function
    shape->draw();

    return 0;
}
```
Output will be like:
```
Drawing a circle
Drawing a rectangle
```

### SOLID Principles
SOLID is an acronym that represents a set of five design principles for writing maintainable and scalable software. 