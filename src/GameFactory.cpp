/// GameFactory
///
/// @brief Factory class to create objects required for the game
/// @file GameFactory.cpp
/// @author Ali Yavuz Kahveci (aliyavuzkahveci@gmail.com)
/// @date 2021
///
//////////////////////////////////////////////////////////////////////////////////////////

#include "GameFactory.h"
#include "Game.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "SmartDecision.h"

namespace rock_paper_scissors {

GameFactory& GameFactory::GetInstance() {
    static GameFactory instance;
    return instance;
}

std::unique_ptr<IGame> GameFactory::CreateGame(const GameConfig& config) {
    return std::make_unique<Game>(config.Mode, config.RoundCount, config.Verbose);
}

std::unique_ptr<Player> GameFactory::CreatePlayer(const bool& isHuman, const std::string& playerName) {
    if(isHuman) {
        return std::make_unique<HumanPlayer>(playerName);
    } else {
        return std::make_unique<ComputerPlayer>(playerName);
    }
}

std::unique_ptr<IDecision> GameFactory::CreateDecision(const GameConfig& config) {
    return std::make_unique<SmartDecision>(config.RoundCount);
}

}
