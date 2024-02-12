#ifndef ABSTRACT_H
#define ABSTRACT_H

#include <string>
#include <iostream>

class AbstractProductA {
public:
    virtual ~AbstractProductA(){};
    virtual std::string UsefulFunctionA() const = 0;
};

class ConcreteProductA1 : public AbstractProductA {
public:
    std::string UsefulFunctionA() const override;
};

class ConcreteProductA2 : public AbstractProductA {
    std::string UsefulFunctionA() const override;
};


class AbstractProductB {
public:
    virtual ~AbstractProductB(){};
    virtual std::string UsefulFunctionB() const = 0;

    virtual std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const = 0;
};



class ConcreteProductB1 : public AbstractProductB {
public:
    std::string UsefulFunctionB() const override;

    std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override;
};

class ConcreteProductB2 : public AbstractProductB {
 public:
  std::string UsefulFunctionB() const override;

  std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override ;
};



class AbstractFactory {
public:
    virtual AbstractProductA *CreateProductA() const = 0;
    virtual AbstractProductB *CreateProductB() const = 0;
};


class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA *CreateProductA() const override {
        return new ConcreteProductA1();
    }
    AbstractProductB *CreateProductB() const override {
    return new ConcreteProductB1();
    }
};

class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA *CreateProductA() const override {
        return new ConcreteProductA2();
    }
    AbstractProductB *CreateProductB() const override {
        return new ConcreteProductB2();
    }
};


void ClientCode(const AbstractFactory &factory);



#endif