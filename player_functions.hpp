#ifndef PLAYER_FUNCTIONS_H
#define PLAYER_FUNCTIONS_H

#include <string>
#include <vector>
using namespace std;

class Player
{
  string name;
  string player_class;
  vector<string> inventory;
  int level;
  int base_strength;
  int base_intellect;
  int base_total_health;
  int base_defense;

public:
  int current_health;

  Player(string new_name, int new_strength, int new_intellect, int new_health, int new_defense);

  Player create_character();

  string get_name();
  string get_player_class();
  vector<string> get_inventory();
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
