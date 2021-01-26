/// IGame
///
/// @brief Interface class to represent rock_paper_scissors game
/// @file IGame.h
/// @author Ali Yavuz Kahveci (aliyavuzkahveci@gmail.com)
/// @date 2021
///
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef _I_GAME_H_
#define _I_GAME_H_

#include "Player.h"

namespace rock_paper_scissors {

class IGame {

public:
    /**
     * @brief constructor
     * @param mode game mode
     * @param numOfRounds repetition count
     */
    IGame(GameMode mode, size_t numOfRounds): m_mode(mode), m_round(numOfRounds) {}

    /**
     * @brief move constructor
     * @param rhs another object to be copied
     */
    IGame(IGame&& rhs) {
        this->m_players.first = std::move(rhs.m_players.first);
        this->m_players.second = std::move(rhs.m_players.second);
    }

    /**
     * @brief move assignment operator
     * @param rhs anothe object to be copied
     */
    IGame& operator=(IGame&& rhs) {
        if(this == &rhs) {
            return *this;
        }

        this->m_players.first = std::move(rhs.m_players.first);
        this->m_players.second = std::move(rhs.m_players.second);
    }

    /**
     * @brief destructor
     */
    virtual ~IGame() = default;

    /**
     * @brief setting the player objects 
     * @param up_player1 pointer to first player
     * @param up_player2 pointer to second player
     */
    void SetPlayers(std::unique_ptr<Player> up_player1, std::unique_ptr<Player> up_player2) {
        m_players.first = std::move(up_player1);
        m_players.second = std::move(up_player2);
    }

    /**
     * @brief starting the game between players
     */
    virtual void Start() = 0;

    /**
     * @brief prints out the overall result as well as each round
     */
    virtual void GetResult() = 0;

protected:
    std::pair<std::unique_ptr<Player>, std::unique_ptr<Player>> m_players;
    GameMode m_mode;
    size_t m_round;

private:
    /**
     * @brief default constructor
     */
    IGame() = delete;

    /**
     * @brief copy constructor
     * @param rhs another object to be copied
     */
    IGame(const IGame& rhs) = delete;

    /**
     * @brief assignment operator
     * @param rhs anothe object to be copied
     */
    IGame& operator=(const IGame& rhs) = delete;

};

}

#endif // _I_GAME_H_
