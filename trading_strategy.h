#ifndef TRADING_STRATEGY_H
#define TRADING_STRATEGY_H

class TradingStrategy {
public:
    virtual ~TradingStrategy() = default;
    virtual void execute() = 0;
};


#endif //TRADING_STRATEGY_H
