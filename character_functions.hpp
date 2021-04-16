#ifndef CHARACTER_FUNCTIONS_H
#define CHARACTER_FUNCTIONS_H

#include <string>
#include <vector>
using namespace std;

class Character
{
  string name;
  string character_class;
  vector<string> inventory;
  int level;
  int base_strength;
  int base_intellect;
  int base_total_health;
  int base_defense;

public:
  int current_health;

  Character(string new_name, int new_strength, int new_intellect, int new_health, int new_defense);

  Character create_character();

  string get_name();
  string get_character_class();
  vector<string> get_inventory();
  int get_current_health();
  int get_strength();
  int get_intellect();
  int get_total_health();
  int get_defense();
  void level_up();
  void get_stats();
  int attack(Character &enemy);
};

#endif
