/// ComputerPlayer
///
/// @brief Class to represent human player of the rock_paper_scissors game
/// @file ComputerPlayer.cpp
/// @author Ali Yavuz Kahveci (aliyavuzkahveci@gmail.com)
/// @date 2021
///
//////////////////////////////////////////////////////////////////////////////////////////

#include "ComputerPlayer.h"

namespace rock_paper_scissors {

ComputerPlayer::ComputerPlayer(const std::string& playerName, std::unique_ptr<IDecision> up_controller) : Player(playerName, std::move(up_controller)) {
}

}
