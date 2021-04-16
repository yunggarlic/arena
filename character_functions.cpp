#include <string>
#include <iostream>
#include <vector>
#include "character_functions.hpp"

using namespace std;

//Player constructor
Character::Character(string new_name, int new_strength, int new_intellect, int new_health, int new_defense)
{
  name = new_name;
  base_strength = new_strength;
  base_intellect = new_intellect;
  base_total_health = 10 + new_health; //10 + new health
  current_health = base_total_health;
  base_defense = new_defense;
}

//GETTERS
string Character::get_name()
{
  return name;
}
string Character::get_character_class()
{
  return character_class;
}
int Character::get_strength()
{
  return base_strength;
}
int Character::get_intellect()
{
  return base_intellect;
}
int Character::get_defense()
{
  return base_defense;
}
int Character::get_current_health()
{
  return current_health;
}
int Character::get_total_health()
{
  return base_total_health;
}
void Character::get_stats()
{
  cout << "Current Stats:" << endl;
  cout << "Name: " << name << endl;
  cout << "Strength: " << base_strength << endl;
  cout << "Intellect: " << base_intellect << endl;
  cout << "Health: " << base_total_health << endl;
  cout << "Defense: " << base_defense << endl;
}
vector<string> Character::get_inventory()
{
  return inventory;
}
int Character::attack(Character &enemy)
{
  int total_attack = base_strength + (base_intellect * 0.3);
  enemy.current_health = enemy.current_health - base_strength + (base_intellect * 0.3);
  return total_attack;
}
