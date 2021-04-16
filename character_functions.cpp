#include <string>
#include <iostream>
#include <time.h>
#include <vector>
#include "character_functions.hpp"

using namespace std;

//Player constructor
Character::Character(string new_name, int new_strength, int new_intellect, int new_health, int new_defense, int new_reknown, int new_level, int new_experience)
{
  name = new_name;
  base_strength = new_strength;
  base_intellect = new_intellect;
  base_total_health = 10 + new_health; //10 + new health
  current_health = base_total_health;
  base_defense = new_defense;
  level = new_level;
  experience = new_experience;
  reknown = new_reknown;
  unspent_points = 0;
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

void Character::level_up()
{
  level++;
  unspent_points += 100;
}

void Character::spend_points(int new_strength, int new_intellect, int new_health, int new_defense)
{
  unspent_points -= new_strength + new_intellect + new_health + new_defense;
  base_strength += new_strength;
  base_intellect += new_intellect;
  base_total_health += new_health;
  base_defense += new_defense;
  if (current_health + new_health != base_total_health)
    current_health += new_health;
  else
    current_health = base_total_health;
}

void Character::reknown_adjustment(Character enemy, string operation)
{
  if (operation == "add")
    reknown += enemy.reknown;
  else if (operation == "sub")
  {
    reknown -= enemy.reknown;
  }
}

void Character::get_versus_stats(Character enemy)
{
  cout << name << "   VERSUS   " << enemy.name << endl;
  cout << "Level: " << level << "      Level: " << enemy.level << endl;
  cout << "Strength: " << base_strength << "      Strength: " << enemy.base_strength << endl;
  cout << "Intellect: " << base_intellect << "      Intellect: " << enemy.base_intellect << endl;
  cout << "Health: " << current_health << "/" << base_total_health << "      Health: " << enemy.current_health << "/" << enemy.base_total_health << endl;
  cout << "Defense: " << base_defense << "      Defense: " << enemy.base_defense << endl;
  cout << "Reknown: " << reknown << "      Reknown: " << enemy.reknown << endl;
}

vector<string> Character::get_inventory()
{
  return inventory;
}

int Character::damage(Character &enemy)
{
  double mod_roll = ((double)rand() / RAND_MAX);
  mod_roll = 0.1 + mod_roll * (0.5 - 0.1);
  double total_attack = (base_strength * mod_roll) + base_intellect * 0.1;
  int i_total_attack = (int)total_attack;
  enemy.current_health -= i_total_attack;
  return i_total_attack;
}

bool Character::attack(Character &enemy)
{
  int player_to_enemy_damage;
  int roll = rand() % 20 + 1 + (base_intellect * 0.1);
  if (roll > (enemy.get_defense() / 5) + (enemy.get_intellect() / 20))
  {
    //Commit damage
    player_to_enemy_damage = damage(enemy);
    cout << name << " did " << player_to_enemy_damage << " to " << enemy.name << endl;
    return true;
  }
  else
  {
    cout << name << " missed!" << endl;
    return false;
  }
}

void Character::regain_health()
{
  if (base_total_health - current_health > 10)
  {
    current_health += 10;
  }
  else if (base_total_health - current_health <= 10)
  {
    current_health = base_total_health;
  }
}
