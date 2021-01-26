/// UnitTesting of CliParser
///
/// @brief UnitTesting of CliParser
/// @file CliParserTests.cpp
/// @author Ali Yavuz Kahveci (aliyavuzkahveci@gmail.com)
/// @date 2021
//////////////////////////////////////////////////////////////////////////////////////////

#include "gmock/gmock.h"

#define protected public
#define private public
#include "CliParser.h"
#undef private
#undef protected

using ::testing::_;
using ::testing::Exactly;
using ::testing::Return;
using ::testing::ReturnRef;
using ::testing::DoAll;
using ::testing::SetArgReferee;

using namespace testing;
using namespace rock_paper_scissors;

class CliParserTests : public ::testing::Test {

public:
    CliParserTests() {};

    void SetUp() override {}

    void TearDown() override {}

    virtual ~CliParserTests() = default;

};

TEST_F(CliParserTests, shouldParseArguments) {
    const int argc = 8;
    const char* argv[] = {"rock_paper_scissors", "--mode", "Auto", "--name", "IMC", "-r", "5", "-v"};

    GameConfig config = CliParser::Parse(argc, argv);
    EXPECT_EQ(config.Player1Name, "Computer"s);
    EXPECT_EQ(config.Player2Name, "IMC"s);
    EXPECT_EQ(config.Mode, GameMode::AUTO);
    EXPECT_EQ(config.RoundCount, 5);
    EXPECT_EQ(config.Verbose, true);
}

TEST_F(CliParserTests, shouldReturnDefaultConfig) {
    const int argc = 1;
    const char* argv[] = {"rock_paper_scissors"};

    GameConfig config = CliParser::Parse(argc, argv);
    EXPECT_EQ(config.Player1Name, "Computer"s);
    EXPECT_EQ(config.Player2Name, "Computer2"s);
    EXPECT_EQ(config.Mode, GameMode::AUTO);
    EXPECT_EQ(config.RoundCount, MAX_ROUND);
    EXPECT_EQ(config.Verbose, false);
}

TEST_F(CliParserTests, shouldThrowExceptionForPrintingHelp) {
    const int argc = 2;
    const char* argv[] = {"rock_paper_scissors", "--help"};

    try {
        GameConfig config = CliParser::Parse(argc, argv);
    } catch(std::exception& exc) {
        std::cout << exc.what() << std::endl;
        EXPECT_EQ(std::string(exc.what()), "Only help requested!"s);
    }

    const char* argv2[] = {"rock_paper_scissors", "-h"};
    try {
        GameConfig config = CliParser::Parse(argc, argv2);
    } catch(std::exception& exc) {
        std::cout << exc.what() << std::endl;
        EXPECT_EQ(std::string(exc.what()), "Only help requested!"s);
    }
}

TEST_F(CliParserTests, shouldThrowExceptionForIncorrectGameMode) {
    const int argc = 8;
    const char* argv[] = {"rock_paper_scissors", "--mode", "ThirdOpt", "--name", "IMC", "-r", "5", "-v"};

    try {
        GameConfig config = CliParser::Parse(argc, argv);
    } catch(std::exception& exc) {
        std::cout << exc.what() << std::endl;
        EXPECT_EQ(std::string(exc.what()), "Not valid arguments!"s);
    }

    const char* argv2[] = {"rock_paper_scissors", "-m", "ThirdOpt", "--name", "IMC", "-r", "5", "-v"};
    try {
        GameConfig config = CliParser::Parse(argc, argv2);
    } catch(std::exception& exc) {
        std::cout << exc.what() << std::endl;
        EXPECT_EQ(std::string(exc.what()), "Not valid arguments!"s);
    }
}

TEST_F(CliParserTests, shouldThrowExceptionForMissingGameMode) {
    const int argc = 7;
    const char* argv[] = {"rock_paper_scissors", "--mode", "--name", "IMC", "-r", "5", "-v"};

    try {
        GameConfig config = CliParser::Parse(argc, argv);
    } catch(std::exception& exc) {
        std::cout << exc.what() << std::endl;
        EXPECT_EQ(std::string(exc.what()), "Not valid arguments!"s);
    }

    const char* argv2[] = {"rock_paper_scissors", "-m", "--name", "IMC", "-r", "5", "-v"};
    try {
        GameConfig config = CliParser::Parse(argc, argv2);
    } catch(std::exception& exc) {
        std::cout << exc.what() << std::endl;
        EXPECT_EQ(std::string(exc.what()), "Not valid arguments!"s);
    }
}

TEST_F(CliParserTests, shouldThrowExceptionForMissingPlayerName) {
    const int argc = 7;
    const char* argv[] = {"rock_paper_scissors", "--mode", "VS", "-n", "-r", "5", "-v"};

    try {
        GameConfig config = CliParser::Parse(argc, argv);
    } catch(std::exception& exc) {
        std::cout << exc.what() << std::endl;
        EXPECT_EQ(std::string(exc.what()), "Not valid arguments!"s);
    }

    const char* argv2[] = {"rock_paper_scissors", "-m", "VS", "-r", "5", "-v", "--name"};
    try {
        GameConfig config = CliParser::Parse(argc, argv2);
    } catch(std::exception& exc) {
        std::cout << exc.what() << std::endl;
        EXPECT_EQ(std::string(exc.what()), "Not valid arguments!"s);
    }
}

TEST_F(CliParserTests, shouldThrowExceptionForMissingRoundNumber) {
    const int argc = 7;
    const char* argv[] = {"rock_paper_scissors", "--mode", "Auto", "--name", "IMC", "-r", "-v"};

    try {
        GameConfig config = CliParser::Parse(argc, argv);
    } catch(std::exception& exc) {
        std::cout << exc.what() << std::endl;
        EXPECT_EQ(std::string(exc.what()), "Not valid arguments!"s);
    }

    const char* argv2[] = {"rock_paper_scissors", "-m", "Auto", "--name", "IMC", "-v", "--round"};
    try {
        GameConfig config = CliParser::Parse(argc, argv2);
    } catch(std::exception& exc) {
        std::cout << exc.what() << std::endl;
        EXPECT_EQ(std::string(exc.what()), "Not valid arguments!"s);
    }
}

TEST_F(CliParserTests, shouldThrowExceptionForInvalidRoundNumber) {
    const int argc = 8;
    const char* argv[] = {"rock_paper_scissors", "--mode", "Auto", "--name", "IMC", "-r", "101", "-v"};

    try {
        GameConfig config = CliParser::Parse(argc, argv);
    } catch(std::exception& exc) {
        std::cout << exc.what() << std::endl;
        EXPECT_EQ(std::string(exc.what()), "Not valid arguments!"s);
    }

    const char* argv2[] = {"rock_paper_scissors", "-m", "Auto", "--name", "IMC", "-v", "--round", "-1"};
    try {
        GameConfig config = CliParser::Parse(argc, argv2);
    } catch(std::exception& exc) {
        std::cout << exc.what() << std::endl;
        EXPECT_EQ(std::string(exc.what()), "Not valid arguments!"s);
    }
}

TEST_F(CliParserTests, shouldThrowExceptionForInvalidParameter) {
    const int argc = 8;
    const char* argv[] = {"rock_paper_scissors", "--mode", "Auto", "--name", "IMC", "-r", "10", "-virbose"};

    try {
        GameConfig config = CliParser::Parse(argc, argv);
    } catch(std::exception& exc) {
        std::cout << exc.what() << std::endl;
        EXPECT_EQ(std::string(exc.what()), "Not valid arguments!"s);
    }

    const char* argv2[] = {"rock_paper_scissors", "-x", "Auto", "--name", "IMC", "-v", "--round", "1"};
    try {
        GameConfig config = CliParser::Parse(argc, argv2);
    } catch(std::exception& exc) {
        std::cout << exc.what() << std::endl;
        EXPECT_EQ(std::string(exc.what()), "Not valid arguments!"s);
    }
}

