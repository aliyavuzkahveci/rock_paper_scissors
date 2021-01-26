/// Game
///
/// @brief Class to represent rock_paper_scissors game
/// @file Game.cpp
/// @author Ali Yavuz Kahveci (aliyavuzkahveci@gmail.com)
/// @date 2021
///
//////////////////////////////////////////////////////////////////////////////////////////

#include "Game.h"

namespace rock_paper_scissors {

Game::Game(GameMode mode, size_t numOfRound, bool isVerbose) : IGame(mode, numOfRound), m_verbose(isVerbose) {
}

void Game::Start() {
    // set win counts to 0 before starting!
    m_winCounts = {0, 0};

    for(size_t i=0; i<m_round; ++i) {
        // get choices from players
        auto choice1 = m_players.first->GetNextChoice();
        auto choice2 = m_players.second->GetNextChoice();

        if(m_verbose) {
            std::cout << "Round " << (i+1) << ": " << choice1 << " vs " << choice2 << std::endl;
        }

        std::pair<RoundResult, RoundResult> roundResult;

        // decide which player has won
        if(choice1 == choice2) { // it's a tie!
            roundResult.first = RoundResult::TIE;
            roundResult.second = RoundResult::TIE;
        } else if(choice1 == Options::FAUL) { // player1 committed faul! defeated
            roundResult.first = RoundResult::LOSE;
            roundResult.second = RoundResult::WIN;

            // update win counts
            ++m_winCounts.second;
        } else if(choice2 == Options::FAUL) { // player2 committed faul! defeated
            roundResult.first = RoundResult::WIN;
            roundResult.second = RoundResult::LOSE;

            // update win counts
            ++m_winCounts.first;
        } else if(BeatMap.at(choice1) == choice2) { // player1 has won
            roundResult.first = RoundResult::WIN;
            roundResult.second = RoundResult::LOSE;

            // update win counts
            ++m_winCounts.first;
        } else { // player2 has won
            roundResult.first = RoundResult::LOSE;
            roundResult.second = RoundResult::WIN;

            // update win counts
            ++m_winCounts.second;
        }

        m_history.push_back(roundResult);

        // let players know about the result
        m_players.first->NotifyResult(roundResult.first);
        m_players.second->NotifyResult(roundResult.second);
    }
}

void Game::GetResult() {
    // ToDo: might be provided this detailed info if executed with --verbose (-v) parameter!
    if(m_verbose) {
        std::cout << "Printing the results:" << std::endl;
        std::cout << m_players.first->GetName() << "   " << m_players.second->GetName() << std::endl;

        for(int i=0; i<m_history.size(); ++i) {
            std::cout << m_history[i].first << "          " << m_history[i].second << std::endl;
        }
        std::cout << m_winCounts.first << "          " << m_winCounts.second << std::endl;
    }

    if(m_winCounts.first == m_winCounts.second) {
        std::cout << "It is a TIE!" << std::endl;
    } else {
        std::cout << "Winner is: " << ((m_winCounts.first > m_winCounts.second) ? m_players.first->GetName() : m_players.second->GetName()) << std::endl;
    }
}

} // rock_paper_scissors
