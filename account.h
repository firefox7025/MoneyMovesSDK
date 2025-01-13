//
// Created by amontgomery on 1/12/25.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <memory>

#include "trading_strategy.h"


class TradingStrategy;

class Account {
std::shared_ptr<TradingStrategy> strategy;

public:
    void setStrategy(std::shared_ptr<TradingStrategy> newStrategy) {
        strategy = newStrategy;
    }

    void executeStrategy() {
        if (strategy) {
            strategy->execute();
        } else {
            std::cout << "No strategy set.\n";
        }
    }
};



#endif //ACCOUNT_H
