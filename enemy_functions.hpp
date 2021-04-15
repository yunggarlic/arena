#ifndef Enemy_FUNCTIONS_H
#define Enemy_FUNCTIONS_H

#include <string>
#include <vector>
using namespace std;

class Enemy
{
  string name;
  int level;
  int base_strength;
  int base_intellect;
  int base_total_health;
  int base_defense;

public:
  int current_health;

  Enemy(string new_name, int new_strength, int new_intellect, int new_health, int new_defense);

  Enemy create_character();

  string get_name();
  int get_current_health();
  int get_strength();
  int get_intellect();
  int get_total_health();
  int get_defense();
  void level_up();
  void get_stats();
  // void attack(Enemy &enemy);
};

#endif
