#pragma once

#include "game.hpp"

class game_term_view {
public:
  static void display_game_state( game & game_state );
  static void display_game_menu();
  static void display_game_over( game & game_state );
};
