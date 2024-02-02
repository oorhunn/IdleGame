#include "../../include/StrategyPattern/Strategy.h"




Context::Context(std::unique_ptr<Strategy> &&strategy) : 
    strategy_(std::move(strategy))
{

}

void Context::set_strategy(std::unique_ptr<Strategy> &&strategy) {
    strategy_ = std::move(strategy);
}


void Context::doSomeBusinessLogic() const { 
    if (strategy_) {
        std::cout << "Context: Sorting data using the strategy (not sure how it'll do it)\n";
        std::string result = strategy_->doAlgorithm("aecbd");
        std::cout << result << "\n";
    } else {
        std::cout << "Context: Strategy isn't set\n";
    }
}

std::string ConcreteStrategyA::doAlgorithm(std::string_view data) const { 
    std::string result(data);
    std::sort(std::begin(result), std::end(result));
    return result;
}

std::string ConcreteStrategyB::doAlgorithm(std::string_view data) const { 
    std::string result(data);
    std::sort(std::begin(result), std::end(result), std::greater<>());

    return result;    
}



void clientCode()
{
    Context context(std::make_unique<ConcreteStrategyA>());
    std::cout << "Client: Strategy is set to normal sorting.\n";
    context.doSomeBusinessLogic();
    std::cout << "\n";
    std::cout << "Client: Strategy is set to reverse sorting.\n";
    context.set_strategy(std::make_unique<ConcreteStrategyB>());
    context.doSomeBusinessLogic();
}
