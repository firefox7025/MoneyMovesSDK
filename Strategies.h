#ifndef STRATEGIES_H
#define STRATEGIES_H
#include <iostream>
#include <numeric>

#include "trading_strategy.h"


class BuyAndHoldStrategy : public TradingStrategy {
private:
    std::string stockSymbol;
    int numShares;
    double buyPrice;
    double currentPrice;  // Assuming you have a way to get this from the market
    double targetProfitPercentage;

public:
    BuyAndHoldStrategy(const std::string& symbol, int shares, double price, double targetProfit = 0.2)
        : stockSymbol(symbol), numShares(shares), buyPrice(price), currentPrice(price), targetProfitPercentage(targetProfit) {}

    void execute() override {
        std::cout << "Executing Buy and Hold strategy for " << stockSymbol << "\n";
        std::cout << "Bought " << numShares << " shares at $" << buyPrice << " each.\n";
        double targetSellPrice = buyPrice * (1 + targetProfitPercentage);
        std::cout << "Target sell price: $" << targetSellPrice << "\n";

        if (currentPrice >= targetSellPrice) {
            std::cout << "Price target reached! Selling the stock.\n";
        } else {
            std::cout << "Holding the stock for now...\n";
        }
    }

    // A method to update the stock's current price
    void updatePrice(double newPrice) {
        currentPrice = newPrice;
    }

    double getBuyPrice() const {
        return buyPrice;
    }

    double getCurrentPrice() const {
        return currentPrice;
    }
};

class MomentumStrategy : public TradingStrategy {
private:
    std::string stockSymbol;
    std::vector<double> priceHistory;  // Track recent prices for momentum calculation
    double currentPrice;
    int movingAveragePeriod;

public:
    MomentumStrategy(const std::string& symbol, int period)
        : stockSymbol(symbol), movingAveragePeriod(period), currentPrice(0.0) {}

    // Update the price history and the current price
    void updatePrice(double newPrice) {
        if (priceHistory.size() >= movingAveragePeriod) {
            priceHistory.erase(priceHistory.begin());  // Remove the oldest price
        }
        priceHistory.push_back(newPrice);
        currentPrice = newPrice;
    }

    // Calculate the simple moving average (SMA)
    double calculateSMA() {
        if (priceHistory.size() < movingAveragePeriod) {
            return -1.0;  // Not enough data yet
        }

        double sum = std::accumulate(priceHistory.begin(), priceHistory.end(), 0.0);
        return sum / movingAveragePeriod;
    }

    void execute() override {
        std::cout << "Executing Momentum strategy for " << stockSymbol << "\n";
        double sma = calculateSMA();

        if (sma == -1.0) {
            std::cout << "Not enough data to calculate moving average.\n";
            return;
        }

        std::cout << "Current Price: $" << currentPrice << " | Moving Average: $" << sma << "\n";

        if (currentPrice > sma) {
            std::cout << "Momentum is positive. Buying stock.\n";
            // Implement the buying logic here (e.g., record the trade)
        } else if (currentPrice < sma) {
            std::cout << "Momentum is negative. Selling stock.\n";
            // Implement the selling logic here (e.g., record the trade)
        } else {
            std::cout << "Momentum is neutral. No action taken.\n";
        }
    }
};




#endif //STRATEGIES_H
