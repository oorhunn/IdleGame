#include "../../include/BridgePattern/Bridge.h"




std::string ConcreteImplementationA::OperationImplementation() const {
    return "ConcreteImplementationA: Here's the result on the platform A.\n";
}



std::string ConcreteImplementationB::OperationImplementation() const {
    return "ConcreteImplementationB: Here's the result on the platform B.\n";
}


std::string Abstraction::Operation() const {
    return "Abstraction: Base operation with:\n" + this->implementation_->OperationImplementation();
}


std::string ExtendedAbstraction::Operation() const {
    return "ExtendedAbstraction: Extended operation with:\n" + this->implementation_->OperationImplementation();
}

void ClientCode(const Abstraction& abstraction) {
  // ...
  std::cout << abstraction.Operation();
  // ...
}