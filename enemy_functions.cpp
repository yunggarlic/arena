#include <string>
#include <iostream>
#include <vector>
#include "enemy_functions.hpp"

using namespace std;

//Enemy constructor
Enemy::Enemy(string new_name, int new_strength, int new_intellect, int new_health, int new_defense)
{
  name = new_name;
  base_strength = new_strength;
  base_intellect = new_intellect;
  base_total_health = 10 + new_health; //10 + new health
  current_health = base_total_health;
  base_defense = new_defense;
}

//GETTERS
string Enemy::get_name()
{
  return name;
}
int Enemy::get_strength()
{
  return base_strength;
}
int Enemy::get_intellect()
{
  return base_intellect;
}
int Enemy::get_defense()
{
  return base_defense;
}
int Enemy::get_current_health()
{
  return current_health;
}
int Enemy::get_total_health()
{
  return base_total_health;
}
void Enemy::get_stats()
{
  cout << "Current Stats:" << endl;
  cout << "Name: " << name << endl;
  cout << "Strength: " << base_strength << endl;
  cout << "Intellect: " << base_intellect << endl;
  cout << "Health: " << base_total_health << endl;
  cout << "Defense: " << base_defense << endl;
}
// void Enemy::attack(Enemy &enemy)
// {
//   enemy.current_health = enemy.current_health - base_strength + (base_intellect * 0.3);
// }
