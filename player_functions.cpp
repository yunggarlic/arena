#include <string>
#include <iostream>
#include <vector>
#include "player_functions.hpp"

using namespace std;

//Player constructor
Player::Player(string new_name, int new_strength, int new_intellect, int new_health, int new_defense)
{
  name = new_name;
  base_strength = new_strength;
  base_intellect = new_intellect;
  base_total_health = 10 + new_health; //10 + new health
  current_health = base_total_health;
  base_defense = new_defense;
}

//GETTERS
string Player::get_name()
{
  return name;
}
string Player::get_player_class()
{
  return player_class;
}
int Player::get_strength()
{
  return base_strength;
}
int Player::get_intellect()
{
  return base_intellect;
}
int Player::get_defense()
{
  return base_defense;
}
int Player::get_current_health()
{
  return current_health;
}
int Player::get_total_health()
{
  return base_total_health;
}
void Player::get_stats()
{
  cout << "Current Stats:" << endl;
  cout << "Name: " << name << endl;
  cout << "Strength: " << base_strength << endl;
  cout << "Intellect: " << base_intellect << endl;
  cout << "Health: " << base_total_health << endl;
  cout << "Defense: " << base_defense << endl;
}
vector<string> Player::get_inventory()
{
  return inventory;
}
// void Player::attack(Enemy &enemy)
// {
//   enemy.current_health = enemy.current_health - base_strength + (base_intellect * 0.3);
// }
