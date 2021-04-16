#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
#include "engine.hpp"
#include "character_functions.hpp"

using namespace std;

Character create_character()
{
  int points = 100;
  string name;
  int strength;
  int health;
  int intellect;
  int defense;
  while (points > 0)
  {
    points = 100;
    strength = 0;
    health = 0;
    intellect = 0;
    defense = 0;
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

Character create_enemy(Character player)
{
  int level = rand() % player.level + 1;
  int points = level * 100;

  int strength = (20 * level) + rand() % 41 + (-15);
  int intellect = (20 * level) + rand() % 41 + (-15);
  int health = (20 * level) + rand() % 41 + (-15);
  int defense = (20 * level) + rand() % 41 + (-15);
  int reknown = (20 * level) + rand() % 41 + (-15);
  int experience = 100 * level + (rand() % 25 + 1);

  return Character("barbarian", strength, intellect, health, defense, reknown, level, experience);
}

Character battlemaster(Character &player, bool &arena)
{
  string enemy_name = "hello";
  string choice;
  Character new_enemy("barb", 0, 0, 0, 0);
  int x = 1;
  cout << "          {}" << endl;
  cout << "         .--." << endl;
  cout << "        /.--.\\" << endl;
  cout << "        |====|" << endl;
  cout << "        |`::`|" << endl;
  cout << "    .-;`\\..../`;-." << endl;
  cout << "   /  |...::...|  \\" << endl;
  cout << "  |   /'''::'''\\   |" << endl;
  cout << "  ;--'\\   ::   /\\--;" << endl;
  cout << "  <__>,>._::_.<,<__>" << endl;
  cout << "  |  |/   ^^   \\|  |" << endl;
  cout << "  \\::/|        |\\::/" << endl;
  cout << "  |||\\|        |/||| " << endl;
  cout << "  ''' |___/\\___| '''" << endl;

  cout << "Get up, meat. It's time for another fight.";
  cin.ignore();
  cout << "Here's the match up: " << endl;
  while (x == 1)
  {
    new_enemy = create_enemy(player);
    player.get_versus_stats(new_enemy);
    cout << "Are you willing to accept this fight?" << endl;
    cout << "1) Accept / 2) Decline / 3) Quit" << endl;
    cin >> choice;
    if (choice == "1")
    {
      break;
    }
    else if (choice == "2")
    {
      player.reknown_adjustment(new_enemy, "sub");
      cout << "Declining a fight loses you reknown, but you take a rest." << endl;
      player.regain_health();
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
  cout << "==========================" << endl;
  cout << "Are you ready to die in glorious combat, " << new_player.get_name() << "?" << endl;
  new_player.get_stats();
  cout << "==========================" << endl;
  cout << "Press Enter to continue";
  cin.ignore();
  cin.ignore();
}

void start_arena(bool &arena)
{
  for (int i = 0; i < 50; i++)
  {
    cout << endl;
  }
  cout << "It is a stormy night on the beach.\nThe sound of thunder rolling across the black sea on a night so silent, you could understand the waves as they crash.\n\nYou float over the open water, face down towards the swell; hovering like a corpse.\nDroplets of the salty mist moisten your face. The ocean water is hot like a bath.\n"
       << endl;
  cout << "Press enter to continue." << endl;
  cin.ignore();
  cout << "You reach a beach head and your feet touch the ground, a graveyard of jagged shells.\nLooking out to the tide, you notice something peculiar..." << endl;
  cout << "The sea is blood." << endl;
  cin.ignore();
  cout << "You wake up in a brown stone room. The walls drip with red sludge, as do the floor boards above your head. A voluminous drop of blood lands between your eyes, and a crowd above screams and thunderously stomps.\n"
       << endl;
  cout << "It's only hell from here..." << endl;
  cout << "Continue..." << endl;
  cin.ignore();
  cout << "Welcome to the..." << endl;
  cout << " _______  _______  _______  _        _______ " << endl;
  cout << "(  ___  )(  ____ )(  ____ \\( (    /|(  ___  )" << endl;
  cout << "| (   ) || (    )|| (    \\/|  \\  ( || (   ) |" << endl;
  cout << "| (___) || (____)|| (__    |   \\ | || (___) |" << endl;
  cout << "|  ___  ||     __)|  __)   | (\\ \\) ||  ___  |" << endl;
  cout << "| (   ) || (\\ (   | (      | | \\   || (   ) |" << endl;
  cout << "| )   ( || ) \\ \\__| (____/\\| )  \\  || )   ( |" << endl;
  cout << "|/     \\||/   \\__/(_______/|/    )_)|/     \\|" << endl;
  cout << "                                             " << endl;
  cin.ignore();
  cout << endl;
  cout << endl;
  cout << "The battlemaster wakes you up.";
  cin.ignore();
  for (int i = 0; i < 20; i++)
  {
    cout << endl;
  }
  arena = true;
}

bool combat(Character &player, Character &enemy)
{
  string choice;
  cout << "Press enter to continue the round.\n";

  //Both opponents have health
  while (player.get_current_health() > 0 && enemy.get_current_health() > 0)
  {
    cin.ignore();
    //Intellect decides who gets the first turn
    if (player.get_intellect() > enemy.get_intellect())
    {
      //Does the attack roll hit?
      if (player.attack(enemy))
      {
        //Did that kill them?
        if (enemy.get_current_health() <= 0)
        {
          cout << "Decapitated." << endl;
          break;
        }
      }
      //Does attack roll hit?
      if (enemy.attack(player))
      {
        if (player.current_health <= 0)
        {
          cout << "Decapitated." << endl;
          break;
        }
      }
    }
    //Enemy goes first in this case
    else if (player.get_intellect() < enemy.get_intellect())
    {
      if (enemy.attack(player))
      {
        if (player.current_health <= 0)
        {
          cout << "Decapitated." << endl;
          break;
        }
      }
      if (player.attack(enemy))
      {
        if (enemy.get_current_health() <= 0)
        {
          cout << "Decapitated." << endl;
          break;
        }
      }
    }
    //The enemies have equal intelligence!?
    else
    {
      //Coin toss decides every round.
      int coin_flip = rand() % 2 + 1;
      if (coin_flip == 1)
      {
        if (player.attack(enemy))
        {
          if (enemy.get_current_health() <= 0)
          {
            cout << "Decapitated." << endl;
            break;
          }
        }
        if (enemy.attack(player))
        {
          if (player.current_health <= 0)
          {
            cout << "Decapitated." << endl;
            break;
          }
        }
      }
      else
      {
        if (enemy.attack(player))
        {
          if (player.current_health <= 0)
          {
            cout << "Decapitated." << endl;
            break;
          }
        }
        if (player.attack(enemy))
        {
          if (enemy.get_current_health() <= 0)
          {
            cout << "Decapitated." << endl;
            break;
          }
        }
      }
    }
  }

  if (player.current_health > enemy.current_health)
  {
    cout << "You have won." << endl;
    cin.ignore();
    return true;
  }
  else
  {
    cout << "You have died." << endl;
    cin.ignore();
    return false;
  }
}

void stat_adjust(Character &player)
{
  int x = 1;
  while (x == 1)
  {
    int strength = 0;
    int intellect = 0;
    int defense = 0;
    int health = 0;
    int points = player.unspent_points;
    player.get_stats();
    cout << "You have " << player.unspent_points << " unspent points remaining" << endl;
    cout << "Add points to strength: " << endl;
    cin >> strength;
    points -= strength;
    cout << "Add points to intellect: " << endl;
    cin >> intellect;
    points -= intellect;
    cout << "Add points to health: " << endl;
    cin >> health;
    points -= health;
    cout << "Add points to defense: " << endl;
    cin >> defense;
    points -= defense;
    if (points < 0)
    {
      cout << "You spent too many points, restarting";
      continue;
    }
    player.spend_points(strength, intellect, health, defense);
    break;
  }
}
bool assess_match(Character &player, Character enemy)
{
  string choice;
  player.experience += abs(enemy.experience);
  player.reknown += abs(enemy.reknown);
  cout << "You absbored " << enemy.experience << " milliters of enemy experience.";
  cin.ignore();
  if (player.experience / 100 > player.level)
  {
    for (int i = 1; i <= (player.experience / 100) - player.level; i++)
    {
      player.level_up();
      player.current_health += 10;
    }
    cout << "Your wounds scar over. You are now level " << player.level << endl;
    cout << "You have " << player.unspent_points << " unspent attribute points." << endl;
    cout << "Spend them?\n1) Yes / 2) No" << endl;
    cin >> choice;
    if (choice == "1")
    {
      stat_adjust(player);
      return true;
    }
    else
      return false;
  }
  return false;
}

void game_over(bool &arena)
{
  string choice;
  cout << "You fought valiantly but your head just ended up on a stick like the rest of us" << endl;
  cout << endl;
  cout << "Press Enter for Main Menu";
  cin.ignore();
  arena = false;
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
      if (combat(new_player, new_enemy))
      {
        assess_match(new_player, new_enemy);
      }
      else
      {
        game_over(arena);
      }
    }
  }
};
