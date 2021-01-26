/// Player
///
/// @brief Base class to represent player of the rock_paper_scissors game
/// @file Player.h
/// @author Ali Yavuz Kahveci (aliyavuzkahveci@gmail.com)
/// @date 2021
///
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <memory>

#include "IDecision.h"

namespace rock_paper_scissors {

class Player {

public:
    /**
     * @brief constructor
     * @param playerName name of the player
     * @param up_controller pointer to decision maker object
     */
    Player(const std::string& playerName, std::unique_ptr<IDecision> up_controller);

    /**
     * @brief destructor
     */
    virtual ~Player() = default;

    /**
     * @brief sets decision object after object instantiation
     * @param up_controller pointer to decision object
     */
    void SetDecision(std::unique_ptr<IDecision> up_controller);

    /**
     * @brief returns the name of player
     * @return name of player
     */
    std::string GetName() const;

    /**
     * @brief returns the next selected option (rock, paper, scissors)
     * @return selected option
     */
    virtual Options GetNextChoice();

    /**
     * @brief notifies the player about the result
     * @param result round result as Win, Loose, or Tie
     */
    virtual void NotifyResult(const RoundResult& result);

protected:
    std::unique_ptr<IDecision> m_upController;
    std::string m_playerName;

private:
    /**
     * @brief default constructor
     */
    Player() = delete;

    /**
     * @brief copy constructor
     * @param rhs another object to be copied
     */
    Player(const Player& rhs) = delete;

    /**
     * @brief move constructor
     * @param rhs another object to be copied
     */
    Player(Player&& rhs) = delete;

    /**
     * @brief assignment operator
     * @param rhs anothe object to be copied
     */
    Player& operator=(const Player& rhs) = delete;

    /**
     * @brief move assignment operator  
     * @param rhs anothe object to be copied
     */
    Player& operator=(Player&& rhs) = delete;

};

}

#endif // _PLAYER_H_
