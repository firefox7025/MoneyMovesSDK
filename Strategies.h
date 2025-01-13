#ifndef STRATEGIES_H
#define STRATEGIES_H
#include <iostream>

#include "trading_strategy.h"


class BuyAndHoldStrategy : public TradingStrategy {
public:
    void execute() override {
        std::cout << "Executing Buy and Hold strategy\n";
    }
};

class MomentumStrategy : public TradingStrategy {
public:
    void execute() override {
        std::cout << "Executing Momentum strategy\n";
    }
};




#endif //STRATEGIES_H
