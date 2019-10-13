#include "../player.hpp"
#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <random>

TEST(Player, OutputFormat) {
  std::string unittest_output = "Player: Bob\n"
                                "Health: 10\n"
                                "Strength: 5\n"
                                "Defense: 2\n"
                                "At position: (10, 10)\n\n"
                                "Player: Mary\n"
                                "Health: 20\n"
                                "Strength: 10\n"
                                "Defense: 6\n"
                                "At position: (0, 0)\n\n"
                                "Bob took 25 damage\n"
                                "Bob is dead\n\n"
                                "Player: Bob\n"
                                "Health: 0\n"
                                "Strength: 5\n"
                                "Defense: 2\n"
                                "At position: (10, 10)\n";
  ASSERT_EXECIO_EQ("main", "", unittest_output);
}

TEST(Player, PublicMethodPresent) {
  std::stringstream s;
  Player your_player1;
  Player your_player2("Name", 1, 1, 1, 1, 1);
  your_player1.getXpos();
  your_player1.getYpos();
  your_player1.getName();
  your_player1.getHealth();
  your_player1.getStrength();
  your_player1.getDefense();
  your_player1.setXpos(1);
  your_player1.setYpos(1);
  your_player1.setName("Name");
  your_player1.setHealth(1);
  your_player1.setStrength(1);
  your_player1.setDefense(1);
  std::string unittest_output = "Player: Name\nHealth: 1\nStrength: 1\n"
                                "Defense: 1\nAt position: (1, 1)\n"
                                "Name took 1 damage\nName is dead\n";
  ASSERT_SIO_EQ("", unittest_output, {
    your_player1.displayStat();
    your_player1.playerMove();
    your_player1.isPlayerDead();
    your_player1.takeDamage(1);
  });
}

TEST(Player, MutatorsAndAccessors) {
  srand(time(NULL));
  Player your_player;
  std::string name = generate_string(10);
  int r = rand() % 10;
  your_player.setXpos(r);
  your_player.setYpos(r);
  your_player.setName(name);
  your_player.setHealth(r);
  your_player.setStrength(r);
  your_player.setDefense(r);
  ASSERT_EQ(your_player.getXpos(), r);
  ASSERT_EQ(your_player.getYpos(), r);
  ASSERT_EQ(your_player.getName(), name);
  ASSERT_EQ(your_player.getHealth(), r);
  ASSERT_EQ(your_player.getStrength(), r);
  ASSERT_EQ(your_player.getDefense(), r);
}

TEST(Player, DefaultConstructor) {
  Player your_player;
  ASSERT_EQ(your_player.getXpos(), 0);
  ASSERT_EQ(your_player.getYpos(), 0);
  ASSERT_EQ(your_player.getName(), "Bob");
  ASSERT_EQ(your_player.getHealth(), 10);
  ASSERT_EQ(your_player.getStrength(), 5);
  ASSERT_EQ(your_player.getDefense(), 2);
}

TEST(Player, NonDefaultConstructor) {
  Player your_player("Buck", 5, 4, 3, 2, 1);
  ASSERT_EQ(your_player.getXpos(), 2);
  ASSERT_EQ(your_player.getYpos(), 1);
  ASSERT_EQ(your_player.getName(), "Buck");
  ASSERT_EQ(your_player.getHealth(), 5);
  ASSERT_EQ(your_player.getStrength(), 4);
  ASSERT_EQ(your_player.getDefense(), 3);
}

TEST(Player, DisplayStat) {
  for (int i = 0; i < 20; i++) {
    Player your_player;
    std::string temp = generate_string(10);
    your_player.setName(temp);
    int r = rand() % 10;
    your_player.setXpos(r);
    your_player.setYpos(r);
    your_player.setHealth(r);
    your_player.setStrength(r);
    your_player.setDefense(r);
    std::string x = std::to_string(r);
    std::string unittest_output = "Player: " + temp + "\nHealth: " + x +
                                  "\nStrength: " + x + "\nDefense: " + x +
                                  "\nAt position: (" + x + ", " + x + ")\n";
    ASSERT_SIO_EQ("", unittest_output, your_player.displayStat());
  }
}

TEST(Player, ChangePosition) {
  for (int i = 0; i < 20; i++) {
    Player your_player;
    int r = rand() % 10;
    your_player.setXpos(r);
    your_player.setYpos(r);
    your_player.playerMove();
    ASSERT_EQ(your_player.getXpos(), r + 1);
    ASSERT_EQ(your_player.getYpos(), r + 1);
  }
}

TEST(Player, IsPlayerDead) {
  for (int i = 0; i < 20; i++) {
    Player your_player;
    int r = rand() % 2;
    your_player.setHealth(r);
    bool x = !(bool)r;
    ASSERT_EQ(your_player.isPlayerDead(), x);
  }
}

TEST(Player, DamagePlayer) {
  for (int i = 0; i < 50; i++) {
    Player your_player;
    std::string temp = generate_string(10);
    int d = rand() % 20;
    int h = rand() % 10;
    your_player.setName(temp);
    your_player.setHealth(h);
    std::string x = std::to_string(d);
    std::string unittest_output = temp + " took " + x + " damage\n";
    if (h - d <= 0) {
      unittest_output += temp + " is dead\n";
    }
    ASSERT_SIO_EQ("", unittest_output, your_player.takeDamage(d));
    if (h - d <= 0) {
      ASSERT_EQ(your_player.getHealth(), 0);
    }
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
