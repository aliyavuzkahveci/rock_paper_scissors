/// Game
///
/// @brief Class to represent rock_paper_scissors game
/// @file Game.h
/// @author Ali Yavuz Kahveci (aliyavuzkahveci@gmail.com)
/// @date 2021
///
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef _GAME_H_
#define _GAME_H_

#include <vector>

#include "IGame.h"

namespace rock_paper_scissors {

class Game : public IGame {

public:
    /**
     * @brief constructor
     * @param mode game mode
     * @param numOfRounds repetition count
     * @param isVerbose True if user wants more detail, False otherwise
     */
    Game(GameMode mode = GameMode::VS, size_t numOfRound = MAX_ROUND, bool isVerbose = false);

    /**
     * @brief destructor
     */
    virtual ~Game() = default;

private:
    /**
     * @brief starting the game between players
     */
    void Start();

    /**
     * @brief prints out the overall result as well as each round
     */
    void GetResult();

    // <player1, player2>
    std::vector<std::pair<RoundResult, RoundResult>> m_history;

    // <player1, player2>
    std::pair<size_t, size_t> m_winCounts;

    bool m_verbose;

};

}

#endif // _GAME_H_
