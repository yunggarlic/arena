#include <iostream>
#include "menu_functions.hpp"
#include "engine.hpp"

int main()
{
  while (main_menu() == 1)
  {
    play_game();
  };
}
