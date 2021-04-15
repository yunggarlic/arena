#include <iostream>
#include <string>
#include "engine.hpp"
#include "enemy_functions.hpp"
#include "player_functions.hpp"

using namespace std;

Player create_character()
{
  int points = 100;
  string name;
  int strength = 0;
  int health = 0;
  int intellect = 0;
  int defense = 0;
  while (points > 0)
  {
    cout << "==========================" << endl;
    cout << "====Build your Fighter====" << endl;
    cout << "==========================" << endl;
    cout << "==========================" << endl;
    cout << "=====Enter your name======" << endl;
    cout << "======25 chars max========" << endl;
    cin >> name;
    if (name.size() > 25)
    {
      cout << "Name is too long, starting over...";
      continue;
    }
    cout << "======Enter strength======" << endl;
    cout << "===" << points << " points remaining===" << endl;
    cin >> strength;
    if (strength > points)
    {
      cout << "You've over spent points, starting over...";
      continue;
    }
    points = points - strength;
    if (points == 0)
    {
      break;
    }
    cout << "======Enter intellect======" << endl;
    cout << "===" << points << " points remaining===" << endl;
    cin >> intellect;
    if (intellect > points)
    {
      cout << "You've over spent points, starting over...";
      continue;
    }
    else if (points == 0)
    {
      break;
    }
    points = points - intellect;
    cout << "======Enter health======" << endl;
    cout << "===" << points << " points remaining===" << endl;
    cin >> health;
    if (health > points)
    {
      cout << "You've over spent points, starting over...";
      continue;
    }
    else if (points == 0)
    {
      break;
    }
    points = points - health;
    cout << "======Enter defense======" << endl;
    cout << "===" << points << " points remaining===" << endl;
    cin >> defense;
    if (defense > points)
    {
      cout << "You've over spent points, starting over...";
      continue;
    }
    else if (points == 0)
    {
      break;
    }
    points = points - defense;
  }

  return Player(name, strength, intellect, health, defense);
}

Enemy create_enemy()
{
  return Enemy("barbarian", 25, 25, 25, 25);
}

void character_confirmation(Player new_player)
{
  string choice;
  cout << "==========================" << endl;
  cout << "Are you ready to die in glorious combat, " << new_player.get_name() << "?" << endl;
  new_player.get_stats();
  cout << "==========================" << endl;
  cout << "========1) Continue=======" << endl;
  cin >> choice;
}

void start_arena(bool &arena)
{
  for (int i = 0; i < 50; i++)
  {
    cout << endl;
  }
  string move_on;
  cout << "It is a stormy night on the beach.\nThe sound of thunder rolling across the black sea on a night so silent, you could understand the waves as they crash.\n\nYou float over the open water, face down towards the swell; hovering like a corpse.\nDroplets of the salty mist moisten your face. The ocean water is hot like a bath.\n"
       << endl;
  cout << "Enter anything to continue." << endl;
  cin >> move_on;
  cout << "You reach a beach head and your feet touch the ground, a graveyard of jagged shells.\nLooking out to the tide, you notice something peculiar...";
  cout << "The sea is blood.";
  cin >> move_on;
  cout << "You wake up in a brown stone room. The walls drip with red sludge, as do the floor boards above your head. A voluminous drop of blood lands between your eyes, and a crowd above screams and thunderously stomps.\n"
       << endl;
  cout << "It's only hell from here..." << endl;
  cout << "Contine..." << endl;
  cin >> move_on;
  cout << " _______  _______  _______  _        _______ " << endl;
  cout << "(  ___  )(  ____ )(  ____ \\( (    /|(  ___  )" << endl;
  cout << "| (   ) || (    )|| (    \\/|  \\  ( || (   ) |" << endl;
  cout << "| (___) || (____)|| (__    |   \\ | || (___) |" << endl;
  cout << "|  ___  ||     __)|  __)   | (\\ \\) ||  ___  |" << endl;
  cout << "| (   ) || (\\ (   | (      | | \\   || (   ) |" << endl;
  cout << "| )   ( || ) \\ \\__| (____/\\| )  \\  || )   ( |" << endl;
  cout << "|/     \\||/   \\__/(_______/|/    )_)|/     \\|" << endl;
  cout << "                                             " << endl;
  cin >> move_on;
  cout << endl;
  cout << endl;
  cout << "The battlemaster wakes you up.";
  arena = true;
}

void battlemaster(Player &player)
{
  string enemy_name = "hello";
  string choice;
  Enemy new_enemy(enemy_name, 25, 25, 25, 25);
  cout << "Get up. It's time for another fight." << endl;
  cout << "Here's your next opponent: " << endl;
  new_enemy.get_stats();
  cin >> choice;
}

void play_game()
{
  bool arena = false;
  Player new_player = create_character();
  character_confirmation(new_player);
  start_arena(arena);
  while (arena == true)
  {
    battlemaster(new_player);
  }
};
