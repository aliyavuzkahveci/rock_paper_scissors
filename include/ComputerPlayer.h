/// ComputerPlayer
///
/// @brief Class to represent computer player of the rock_paper_scissors game
/// @file ComputerPlayer.h
/// @author Ali Yavuz Kahveci (aliyavuzkahveci@gmail.com)
/// @date 2021
///
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef _COMPUTER_PLAYER_H_
#define _COMPUTER_PLAYER_H_

#include "Player.h"
#include "RandomDecision.h"

namespace rock_paper_scissors {

class ComputerPlayer : public Player {

public:
    /**
     * @brief constructor
     * @param playerName name of the player
     * @param up_controller pointer to the input decision object
     */
    ComputerPlayer(const std::string& playerName = "Computer"s, std::unique_ptr<IDecision> up_controller = std::make_unique<RandomDecision>());

    /**
     * @brief destructor
     */
    ~ComputerPlayer() = default;

};

}

#endif // _COMPUTER_PLAYER_H_
