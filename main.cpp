#include <iostream>
#include <time.h>
#include "menu_functions.hpp"
#include "engine.hpp"

int main()
{
  srand(time(NULL));
  while (main_menu() == 1)
  {
    play_game();
  };
}
