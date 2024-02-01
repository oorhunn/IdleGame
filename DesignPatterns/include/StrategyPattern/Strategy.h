#ifndef STRATEGY_H
#define STRATEGY_H

#include <string>
#include <memory>
#include <iostream>
#include <algorithm>

class Strategy
{
public:
    virtual ~Strategy() = default;
    virtual std::string doAlgorithm(std::string_view data) const = 0;
};


class Context
{
private:
    std::unique_ptr<Strategy> strategy_;

public:
    explicit Context(std::unique_ptr<Strategy> &&strategy = {});

    void set_strategy(std::unique_ptr<Strategy> &&strategy);
    void doSomeBusinessLogic() const;
};

class ConcreteStrategyA : public Strategy
{
public:
    std::string doAlgorithm(std::string_view data) const override;
};
class ConcreteStrategyB : public Strategy
{
    std::string doAlgorithm(std::string_view data) const override;
};


#endif