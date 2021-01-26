/// InputDecision
///
/// @brief Class to decide according to the input from human player
/// @file InputDecision.h
/// @author Ali Yavuz Kahveci (aliyavuzkahveci@gmail.com)
/// @date 2021
///
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef _INPUT_DECISION_H_
#define _INPUT_DECISION_H_

#include "IDecision.h"

namespace rock_paper_scissors {

class InputDecision : public IDecision {

public:
    InputDecision() = default;

    ~InputDecision() = default;

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

};

}

#endif // _INPUT_DECISION_H_
