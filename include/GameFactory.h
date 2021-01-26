/// GameFactory
///
/// @brief Factory class to create objects required for the game
/// @file GameFactory.h
/// @author Ali Yavuz Kahveci (aliyavuzkahveci@gmail.com)
/// @date 2021
///
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef _GAME_FACTORY_H_
#define _GAME_FACTORY_H_

#include "IGame.h"
#include "Player.h"
#include "GameConfig.h"

namespace rock_paper_scissors {

class GameFactory {
public:
    /**
     * @brief returns instance of game factory object
     * @return static object instantiated privately 
     */
    static GameFactory& GetInstance();

    /**
     * @brief creates game object according to the configuration
     * @param config user-defined game configuration
     * @return pointer to game object
     */
    std::unique_ptr<IGame> CreateGame(const GameConfig& config);

    /**
     * @brief creates player object according to the configuration
     * @param isHuman True if human player shall be created, False otherwise
     * @param playerName name of the player
     * @return pointer to player object
     */
    std::unique_ptr<Player> CreatePlayer(const bool& isHuman = false, const std::string& playerName = "Computer"s);

    /**
     * @brief creates decision object utilized by player object according to the configuration
     * @param config user-defined game configuration
     * @return pointer to decision object
     */
    std::unique_ptr<IDecision> CreateDecision(const GameConfig& config);

    /**
     * @brief destructor
     */
    ~GameFactory() = default;

private:
    /**
     * @brief constructor
     */
    GameFactory() = default;

    

};

}

#endif // _GAME_FACTORY_H_
