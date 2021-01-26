/// GameConfig
///
/// @brief Class to represent configuration details of the game
/// @file GameConfig.h
/// @author Ali Yavuz Kahveci (aliyavuzkahveci@gmail.com)
/// @date 2021
///
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef _GAME_CONFIG_H_
#define _GAME_CONFIG_H_

#include "Utils.h"

namespace rock_paper_scissors {

struct GameConfig {

    std::string Player1Name = "Computer"s;
    std::string Player2Name = "Computer2"s; // would be set as human player name in VS mode
    GameMode Mode = GameMode::AUTO; // by default, computers compete and human watch
    size_t RoundCount = MAX_ROUND; // default number of rounds per game
    bool Verbose = false; // utilized to print round-based results

};

}

#endif // _GAME_CONFIG_H_
