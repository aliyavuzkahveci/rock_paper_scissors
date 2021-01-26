/// HumanPlayer
///
/// @brief Class to represent human player of the rock_paper_scissors game
/// @file HumanPlayer.h
/// @author Ali Yavuz Kahveci (aliyavuzkahveci@gmail.com)
/// @date 2021
///
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef _HUMAN_PLAYER_H_
#define _HUMAN_PLAYER_H_

#include "Player.h"
#include "InputDecision.h"

namespace rock_paper_scissors {

class HumanPlayer : public Player {

public:
    /**
     * @brief constructor
     * @param playerName name of the human player
     * @param up_controller pointer to the input decision object
     */
    explicit HumanPlayer(const std::string& playerName, std::unique_ptr<IDecision> up_controller = std::make_unique<InputDecision>());

    /**
     * @brief destructor
     */
    ~HumanPlayer() = default;
};

}

#endif // _HUMAN_PLAYER_H_
