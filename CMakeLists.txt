cmake_minimum_required(VERSION 3.30)
project(MoneyMovesSDK)

set(CMAKE_CXX_STANDARD 26)

add_executable(MoneyMovesSDK main.cpp
        account.cpp
        account.h
        trading_strategy.cpp
        trading_strategy.h
        Strategies.cpp
        Strategies.h)
