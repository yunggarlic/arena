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
  int base_strength;
  int base_intellect;
  int base_total_health;
  int base_defense;

public:
  int current_health;
  int experience;
  int reknown;
  int level;
  int unspent_points;

  Character(string new_name, int new_strength, int new_intellect, int new_health, int new_defense, int new_reknown = 0, int new_level = 1, int new_experience = 0);

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
  void get_versus_stats(Character enemy);
  void spend_points(int new_strength, int new_intellect, int new_health, int new_defense);
  int damage(Character &enemy);
  bool attack(Character &enemy);
  void reknown_adjustment(Character enemy, string operation);
};

#endif
