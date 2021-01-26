/// RandomDecision
///
/// @brief Class to select choices randomly for each round
/// @file RandomDecision.cpp
/// @author Ali Yavuz Kahveci (aliyavuzkahveci@gmail.com)
/// @date 2021
///
//////////////////////////////////////////////////////////////////////////////////////////

#include <chrono>

#include "RandomDecision.h"

namespace rock_paper_scissors {

RandomDecision::RandomDecision() {
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    m_generator = std::default_random_engine(seed);
    m_distribution = std::uniform_int_distribution<int>(1, 3);
}

Options RandomDecision::Decide() {
    // ToDo
    auto choice = m_distribution(m_generator);
    return Convert(choice);
}

void RandomDecision::Result(const RoundResult& result) {
    // ToDo
}

}
