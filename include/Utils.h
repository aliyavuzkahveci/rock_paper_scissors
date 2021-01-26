/// Utils
///
/// @brief Utility header file containing project specific constants and definitions 
/// @file Utils.h
/// @author Ali Yavuz Kahveci (aliyavuzkahveci@gmail.com)
/// @date 2021
///
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef _UTILS_H_
#define _UTILS_H_

#include <unordered_map>
#include <iostream>
#include <string>

using namespace std::string_literals;

namespace rock_paper_scissors {

enum class Options {
    ROCK,
    PAPER,
    SCISSORS,
    FAUL // if committed, then acted as defeated!
};

static Options Convert(int option) {
    switch(option) {
    case 1:
        return Options::ROCK;
    case 2:
        return Options::PAPER;
    case 3:
        return Options::SCISSORS;
    default:
        return Options::FAUL;
    }
}

const std::unordered_map<Options, Options> BeatMap = { {Options::ROCK, Options::SCISSORS}, 
                                                       {Options::PAPER, Options::ROCK}, 
                                                       {Options::SCISSORS, Options::PAPER} };

constexpr size_t MAX_ROUND = 100;

inline std::ostream& operator<<(std::ostream& out, const Options &option) {
    switch(option) {
    case Options::ROCK:
        out << "Rock";
        break;
    case Options::PAPER:
        out << "Paper";
        break;
    case Options::SCISSORS:
        out << "Scissors";
        break;
    case Options::FAUL:
    default:
        out << "Faul";
        break;
    }

    return out;
}

enum class RoundResult {
    WIN,
    LOSE,
    TIE
};

inline std::ostream& operator<<(std::ostream& out, const RoundResult &result) {
    switch(result) {
    case RoundResult::WIN:
        out << "+";
        break;
    case RoundResult::LOSE:
        out << "-";
        break;
    case RoundResult::TIE:
        out << "o";
        break;
    }

    return out;
}

enum class GameMode {
    VS, // computer vs player
    AUTO, // computer vs computer
    UNDEFINED // not an allowed option
};

inline std::ostream& operator<<(std::ostream& out, const GameMode &mode) {
    switch(mode) {
    case GameMode::VS:
        out << "vs";
        break;
    case GameMode::AUTO:
        out << "auto";
        break;
    default:
        out << "-";
        break;
    }

    return out;
}

inline bool iCompare(const std::string& s1, const std::string& s2) {
    auto lambda = [](const char& ch1, const char& ch2){
        return std::tolower(ch1) == std::tolower(ch2);
    };

    if(s1.size() != s2.size()) {
        return false;
    } else {
        return std::equal(s1.begin(), s1.end(), s2.begin(), lambda);
    }
}

static GameMode Convert(const std::string& modeStr) {
    if(iCompare(modeStr, "vs"s)) {
        return GameMode::VS;
    } else if(iCompare(modeStr, "auto"s)) {
        return GameMode::AUTO;
    } else {
        return GameMode::UNDEFINED;
    }
}

}

#endif // _UTILS_H_
