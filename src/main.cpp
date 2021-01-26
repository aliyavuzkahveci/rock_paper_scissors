
#include <iostream>
#include "CliParser.h"
#include "GameFactory.h"

using namespace rock_paper_scissors;

int main(int argc, const char** argv) {
    try {
        auto config = CliParser::Parse(argc, argv);

        // creating game and player objects from game config
        auto upGame = GameFactory::GetInstance().CreateGame(config);
        auto player1 = GameFactory::GetInstance().CreatePlayer(); // computer
        auto player2 = GameFactory::GetInstance().CreatePlayer(config.Mode == GameMode::VS, config.Player2Name); // human if VS, computer otherwise

        // set first player (computer) smart to harden the game.
        // this can also be parameterized in the command line arguments such as "--level 2"
        player1->SetDecision(GameFactory::GetInstance().CreateDecision(config));

        // setting up the players of game
        upGame->SetPlayers(std::move(player1), std::move(player2));

        // starting the game
        upGame->Start();

        // informing the user about the result
        upGame->GetResult();

    } catch(std::exception& exc) {
        return -1; // exit program!
    }

    return 0;
}
