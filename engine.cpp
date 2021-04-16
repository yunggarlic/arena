#include <iostream>
#include <string>
#include "engine.hpp"
#include "character_functions.hpp"

using namespace std;

Character create_character()
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

  return Character(name, strength, intellect, health, defense);
}

Character create_enemy()
{
  return Character("barbarian", 25, 25, 25, 25);
}

Character battlemaster(Character &player, bool &arena)
{
  string enemy_name = "hello";
  string choice;
  Character new_enemy("barb", 0, 0, 0, 0);
  int x = 1;
  cout << "Get up. It's time for another fight." << endl;
  cout << "Here's your next opponent: " << endl;
  while (x == 1)
  {
    new_enemy = create_enemy();
    new_enemy.get_stats();
    cout << "Are you willing to accept this fight?" << endl;
    cout << "1) Accept / 2) Decline / 3) Quit" << endl;
    cin >> choice;
    if (choice == "1")
    {

      break;
    }
    else if (choice == "2")
    {
      continue;
    }
    else if (choice == "3")
    {
      arena = false;
      break;
    }
    else
    {
      cout << "Invalid choice, rerolling..." << endl;
      continue;
    }
  }
  return new_enemy;
}

void character_confirmation(Character new_player)
{
  string choice;
  cout << "==========================" << endl;
  cout << "Are you ready to die in glorious combat, " << new_player.get_name() << "?" << endl;
  new_player.get_stats();
  cout << "==========================" << endl;
  cout << "Enter Anything To Continue" << endl;
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

void combat(Character &player, Character &enemy)
{
  string choice;
  while (player.get_current_health() > 0 && enemy.get_current_health() > 0)
  {
    cout << "You did " << player.attack(enemy) << " to the enemy" << endl;
    cout << enemy.get_current_health() << endl;
    if (enemy.get_current_health() <= 0)
    {
      break;
    }
    cout << "They did " << enemy.attack(player) << " to you." << endl;
    cin >> choice;
  }
  if (player.get_current_health() > 0)
  {
    cout << "You won this time." << endl;
  }
  else
  {
    cout << "You lost." << endl;
  }
  cout << "Continue to a new day..." << endl;
  cin >> choice;
}

void play_game()
{
  bool arena = false;
  Character new_player = create_character();
  character_confirmation(new_player);
  start_arena(arena);
  while (arena == true)
  {
    Character new_enemy = battlemaster(new_player, arena);
    if (arena == true)
    {
      combat(new_player, new_enemy);
    }
  }
};
