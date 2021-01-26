/// IDecision
///
/// @brief Interface class to decide which option to choose
/// @file IDecision.h
/// @author Ali Yavuz Kahveci (aliyavuzkahveci@gmail.com)
/// @date 2021
///
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef _I_DECISION_H_
#define _I_DECISION_H_

#include "Utils.h"

namespace rock_paper_scissors {

class IDecision {

public:
    /**
     * @brief constructor
     */
    IDecision() = default;

    /**
     * @brief destructor
     */
    virtual ~IDecision() = default;

    /**
     * @brief decides which option to choose
     * @return choice 
     */
    virtual Options Decide() = 0;

    /**
     * @brief notification of the round result
     * @param result result of the round
     */
    virtual void Result(const RoundResult& result) {};

};

}

#endif // _I_DECISION_H_
