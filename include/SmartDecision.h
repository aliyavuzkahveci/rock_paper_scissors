/// SmartDecision
///
/// @brief Class to decide considering the previous rounds
/// @file SmartDecision.h
/// @author Ali Yavuz Kahveci (aliyavuzkahveci@gmail.com)
/// @date 2021
///
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef _SMART_DECISION_H_
#define _SMART_DECISION_H_

#include <random>
#include <vector>

#include "IDecision.h"

namespace rock_paper_scissors {

class SmartDecision : public IDecision {

public:
    /**
     * @brief constructor
     */
    SmartDecision(size_t numOfRounds = MAX_ROUND);

    /**
     * @brief destructor
     */
    ~SmartDecision() = default;

private:
    /**
     * @brief decides which option to choose
     * @return choice 
     */
    Options Decide() override;

    /**
     * @brief notification of the round result
     * @param result result of the round
     */
    void Result(const RoundResult& result) override;

    std::default_random_engine m_generator;
    std::uniform_int_distribution<int> m_distribution;

    Options m_lastChoice;
    std::vector<Options> m_opponentHistory;
    size_t m_roundNumber;

};

}

#endif // _SMART_DECISION_H_