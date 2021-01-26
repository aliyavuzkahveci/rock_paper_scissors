/// RandomDecision
///
/// @brief Class to select choices randomly for each round
/// @file RandomDecision.h
/// @author Ali Yavuz Kahveci (aliyavuzkahveci@gmail.com)
/// @date 2021
///
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef _RANDOM_DECISION_H_
#define _RANDOM_DECISION_H_

#include <random>

#include "IDecision.h"

namespace rock_paper_scissors {

class RandomDecision : public IDecision {

public:
    /**
     * @brief constructor
     */
    RandomDecision();

    /**
     * @brief destructor
     */
    ~RandomDecision() = default;

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

};

}

#endif // _RANDOM_DECISION_H_