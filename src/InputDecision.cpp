/// InputDecision
///
/// @brief Class to decide according to the input from human player
/// @file InputDecision.cpp
/// @author Ali Yavuz Kahveci (aliyavuzkahveci@gmail.com)
/// @date 2021
///
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "InputDecision.h"

namespace rock_paper_scissors {

Options InputDecision::Decide() {
    int choice = 0;
    std::cout << "Please provide your next choice: " << std::endl;
    std::cout << "1. Rock" << std::endl << "2. Paper" << std::endl << "3. Scissors" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;

    return Convert(choice);
}

void InputDecision::Result(const RoundResult& result) {
    switch(result) {
    case RoundResult::WIN:
        std::cout << "`-> You Win!" << std::endl;
        break;
    case RoundResult::LOSE:
        std::cout << "`-> You Loose!" << std::endl;
        break;
    case RoundResult::TIE:
    default:
        std::cout << "`-> Tie!" << std::endl;
        break;
    }
}

}
