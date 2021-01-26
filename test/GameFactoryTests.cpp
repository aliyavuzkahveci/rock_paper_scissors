/// UnitTesting of GameFactory
///
/// @brief UnitTesting of GameFactory
/// @file GameFactoryTests.cpp
/// @author Ali Yavuz Kahveci (aliyavuzkahveci@gmail.com)
/// @date 2021
//////////////////////////////////////////////////////////////////////////////////////////

#include "gmock/gmock.h"

#define protected public
#define private public
#include "GameFactory.h"
#include "Game.h"
#include "SmartDecision.h"
#include "InputDecision.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "RandomDecision.h"
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

class GameFactoryTests : public ::testing::Test {

public:
    GameFactoryTests() {};

    void SetUp() override {
        m_config.Player2Name = "Ali Yavuz Kahveci"s;
        m_config.Mode = GameMode::VS;
        m_config.RoundCount = 34;
        m_config.Verbose = true;
    }

    void TearDown() override {}

    virtual ~GameFactoryTests() = default;

    GameConfig m_config;

};

TEST_F(GameFactoryTests, shouldCreateDecision) {
    auto upDecision = GameFactory::GetInstance().CreateDecision(m_config);

    SmartDecision* decisionPtr = dynamic_cast<SmartDecision*>(upDecision.get());
    InputDecision* inputDecisionPtr = dynamic_cast<InputDecision*>(upDecision.get());
    EXPECT_TRUE(decisionPtr);
    EXPECT_FALSE(inputDecisionPtr);

    // game not started yet!
    EXPECT_EQ(decisionPtr->m_lastChoice, Options::FAUL);
    EXPECT_EQ(decisionPtr->m_opponentHistory.size(), 34);
    EXPECT_EQ(decisionPtr->m_roundNumber, 0);
}

TEST_F(GameFactoryTests, shouldCreatePlayer) {
    auto upPlayer = GameFactory::GetInstance().CreatePlayer(); // with default parameter

    ComputerPlayer* playerPtr = dynamic_cast<ComputerPlayer*>(upPlayer.get());
    HumanPlayer* humanPtr = dynamic_cast<HumanPlayer*>(upPlayer.get());
    EXPECT_TRUE(playerPtr);
    EXPECT_FALSE(humanPtr);

    EXPECT_EQ(upPlayer->GetName(), "Computer");

    //default Decision as RandomDecision
    RandomDecision* randomPtr = dynamic_cast<RandomDecision*>(upPlayer->m_upController.get());
    SmartDecision* smartPtr = dynamic_cast<SmartDecision*>(upPlayer->m_upController.get());
    EXPECT_TRUE(randomPtr);
    EXPECT_FALSE(smartPtr);
}

TEST_F(GameFactoryTests, shouldCreateHumanPlayer) {
    auto upPlayer = GameFactory::GetInstance().CreatePlayer(true, "Ali Yavuz Kahveci"s);

    ComputerPlayer* playerPtr = dynamic_cast<ComputerPlayer*>(upPlayer.get());
    HumanPlayer* humanPtr = dynamic_cast<HumanPlayer*>(upPlayer.get());
    EXPECT_FALSE(playerPtr);
    EXPECT_TRUE(humanPtr);

    EXPECT_EQ(upPlayer->GetName(), "Ali Yavuz Kahveci"s);

    //default Decision as RandomDecision
    InputDecision* inputPtr = dynamic_cast<InputDecision*>(upPlayer->m_upController.get());
    SmartDecision* smartPtr = dynamic_cast<SmartDecision*>(upPlayer->m_upController.get());
    EXPECT_TRUE(inputPtr);
    EXPECT_FALSE(smartPtr);
}

TEST_F(GameFactoryTests, shouldCreateGame) {
    auto upGame = GameFactory::GetInstance().CreateGame(m_config);

    Game* gamePtr = dynamic_cast<Game*>(upGame.get());
    EXPECT_TRUE(gamePtr);
    // game not started yet
    EXPECT_TRUE(gamePtr->m_history.empty());
    EXPECT_EQ(gamePtr->m_winCounts.first, 0);
    EXPECT_EQ(gamePtr->m_winCounts.second, 0);
    EXPECT_EQ(gamePtr->m_verbose, true);

    EXPECT_EQ(upGame->m_mode, GameMode::VS);
    EXPECT_EQ(upGame->m_round, 34);
    
    // players not set 
    EXPECT_EQ(upGame->m_players.first, nullptr);
    EXPECT_EQ(upGame->m_players.second, nullptr);
}
