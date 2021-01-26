/// Player
///
/// @brief Base class to represent player of the rock_paper_scissors game
/// @file Player.cpp
/// @author Ali Yavuz Kahveci (aliyavuzkahveci@gmail.com)
/// @date 2021
///
//////////////////////////////////////////////////////////////////////////////////////////

#include "Player.h"

namespace rock_paper_scissors {

Player::Player(const std::string& playerName, std::unique_ptr<IDecision> up_controller) 
: m_playerName(playerName), m_upController(std::move(up_controller)) {
}

void Player::SetDecision(std::unique_ptr<IDecision> up_controller) {
    m_upController = std::move(up_controller);
}

std::string Player::GetName() const {
    return m_playerName;
}

Options Player::GetNextChoice() {
    if(m_upController) {
        return m_upController->Decide();
    } else {
        return Options::FAUL;
    }
}

void Player::NotifyResult(const RoundResult& result) {
    if(m_upController) {
        m_upController->Result(result);
    }
}

}
