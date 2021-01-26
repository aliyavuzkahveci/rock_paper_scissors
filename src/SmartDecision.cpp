/// SmartDecision
///
/// @brief Class to decide considering the previous rounds
/// @file SmartDecision.cpp
/// @author Ali Yavuz Kahveci (aliyavuzkahveci@gmail.com)
/// @date 2021
///
//////////////////////////////////////////////////////////////////////////////////////////

#include <chrono>

#include "SmartDecision.h"

namespace rock_paper_scissors {

SmartDecision::SmartDecision(size_t numOfRounds) {
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    m_generator = std::default_random_engine(seed);
    m_distribution = std::uniform_int_distribution<int>(1, 3);
    m_lastChoice = Options::FAUL;
    m_roundNumber = 0;

    // initialize opponent history randomly!
    for(auto i=0; i<numOfRounds; ++i) {
        m_opponentHistory.push_back(Convert(m_distribution(m_generator)));
    }

    // during rounds, use uniform distribution to choose one of the options in the vector
    m_distribution = std::uniform_int_distribution<int>(0, numOfRounds-1);
}

Options SmartDecision::Decide() {
    // randomly select from the vector
    auto choice = m_distribution(m_generator);
    m_lastChoice = m_opponentHistory[choice];
    return m_lastChoice;
}

void SmartDecision::Result(const RoundResult& result) {
    switch(result) {
    case RoundResult::WIN:
        for(auto const &[choice, beat] : BeatMap) {
            if(beat == m_lastChoice) {
                m_opponentHistory[m_roundNumber++] = choice;
                break;
            }
        }
        break;
    case RoundResult::LOSE:
        m_opponentHistory[m_roundNumber++] = BeatMap.at(m_lastChoice);
        break;
    case RoundResult::TIE:
    default:
    m_opponentHistory[m_roundNumber++] = m_lastChoice;
        break;
    }
}

}
