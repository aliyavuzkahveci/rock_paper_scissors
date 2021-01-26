/// CliParser
///
/// @brief Class to parse command line arguments and set game config
/// @file CliParser.h
/// @author Ali Yavuz Kahveci (aliyavuzkahveci@gmail.com)
/// @date 2021
///
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef _CLI_PARSER_H_
#define _CLI_PARSER_H_

#include "GameConfig.h"

namespace rock_paper_scissors {

class CliParser {

public:
    /**
     * @brief constructor
     */
    CliParser() = default;

    /**
     * @brief destructor
     */
    ~CliParser() = default;

    /**
     * @brief parsing the command line parameters and extracting game config details
     * @param argc argument count
     * @param argv array of char array holding the arguments
     */
    static GameConfig Parse(int argc, const char** argv) {
        if(argc == 1) { // no additional parameter provided
            return GameConfig();
        }

        // prints manual in case user asked help
        std::string secondArg(argv[1]);
        if(secondArg == "-h" || secondArg == "--help") {
            std::cerr << helpText << std::endl;
            throw std::runtime_error("Only help requested!");
        }

        GameConfig config;
        bool parseSuccessful = true;
        // starting from 1 since 0th argument is the program name!
        for(auto i=1; i<argc; i+=2) { // every i+1 argument is expected to be parameter!
            std::string arg(argv[i]);
            
            if(iCompare(arg, "-m"s) || iCompare(arg, "--mode"s)) {
                if(i == argc-1) { // parameter value not provided
                    std::cerr << "You must provide value for the game mode!" << std::endl;
                    parseSuccessful = false;
                    break;
                }

                std::string param(argv[i+1]);
                auto mode = Convert(param);
                if(mode == GameMode::UNDEFINED) {
                    std::cerr << "Please provide a valid game mode:" << std::endl;
                    std::cerr << "1. vs" << std::endl << "2. auto" << std::endl;
                    parseSuccessful = false;
                    break;
                }
                config.Mode = mode;
            } else if(iCompare(arg, "-n"s) || iCompare(arg, "--name"s)) {
                if(i == argc-1 || argv[i+1][0] == '-' ) { // parameter value not provided
                    std::cerr << "You must provide a name for the player!" << std::endl;
                    parseSuccessful = false;
                    break;
                }

                config.Player2Name = std::string(argv[i+1]);
            } else if(iCompare(arg, "-r"s) || iCompare(arg, "--round"s)) {
                try {
                    
                    auto value = std::atoi(argv[i+1]);
                    
                    if(value < 1 || value > 100) {
                        throw std::runtime_error("invalid range for number of round!");
                    }

                    config.RoundCount = value;
                } catch(std::exception&) {
                    std::cerr << "Plase provide a valid integer value (1-100) for Number of Rounds" << std::endl;
                    parseSuccessful = false;
                    break;
                }
            } else if(iCompare(arg, "-v"s) || iCompare(arg, "--verbose"s)) {
                config.Verbose = true;
                --i; // verbose flag might not be given at the end! 
            } else {
                parseSuccessful = false;
                break;
            }
        }

        if(!parseSuccessful) {
            std::cerr << helpText << std::endl;
            throw std::runtime_error("Not valid arguments!");
        }

        return config;
    }

private:
    static const char* helpText;

};

const char* CliParser::helpText = R"(
Summary:
Simple Rock-Paper-Scissors game, allows you to play or to watch the game between computers

Sample Usage:
./rock_paper_scissors -m VS -n IMC -r 31 -v

Options:
  -m / --mode          Game mode (VS | Auto)
  -n / --name          Player Name for VS mode
  -r / --round         Number of rounds per game
  -v / --verbose       Verbose mode
  -h / --help          Display help and exit

)";

}

#endif // _CLI_PARSER_H_
