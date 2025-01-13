#include <memory>

#include "Strategies.h"
#include "account.h"

class TradingStrategy;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // <b>lang</b> variable name to see how CLion can help you rename it.
    Account myAccount;

    // Set and execute BuyAndHoldStrategy
    std::shared_ptr<TradingStrategy> buyAndHold = std::make_shared<BuyAndHoldStrategy>();
    myAccount.setStrategy(buyAndHold);
    myAccount.executeStrategy();

    // Switch to MomentumStrategy
    std::shared_ptr<TradingStrategy> momentum = std::make_shared<MomentumStrategy>();
    myAccount.setStrategy(momentum);
    myAccount.executeStrategy();

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.