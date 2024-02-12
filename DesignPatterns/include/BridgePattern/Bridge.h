#ifndef BRIDGE_H
#define BRIDGE_H

#include <string>
#include <iostream>

class Implementation {
public:
  virtual ~Implementation() {}
  virtual std::string OperationImplementation() const = 0;
};


class ConcreteImplementationA : public Implementation {
public:
  std::string OperationImplementation() const override;
};


class ConcreteImplementationB : public Implementation {
public:
  std::string OperationImplementation() const override;
};




class Abstraction {
/**
 * @var Implementation
 */
protected:
    Implementation* implementation_;

public:
    Abstraction(Implementation* implementation) : 
    implementation_(implementation) 
    {
    }

  virtual ~Abstraction() {
  }

  virtual std::string Operation() const;
};



class ExtendedAbstraction : public Abstraction {
public:
    ExtendedAbstraction(Implementation* implementation) : 
    Abstraction(implementation) 
    {
    }
    std::string Operation() const override;
};



void ClientCode(const Abstraction& abstraction);
/**
 * The client code should be able to work with any pre-configured abstraction-
 * implementation combination.
 */

// int main() {
//   Implementation* implementation = new ConcreteImplementationA;
//   Abstraction* abstraction = new Abstraction(implementation);
//   ClientCode(*abstraction);
//   std::cout << std::endl;
//   delete implementation;
//   delete abstraction;

//   implementation = new ConcreteImplementationB;
//   abstraction = new ExtendedAbstraction(implementation);
//   ClientCode(*abstraction);

//   delete implementation;
//   delete abstraction;

//   return 0;
// }

#endif