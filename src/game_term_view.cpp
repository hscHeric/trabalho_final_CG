#include "game_term_view.hpp"

#include "game.hpp"

#include <iostream>

void game_term_view::display_game_state( game & game_state ) {
  player & current_player = game_state.get_current_player();
  player & opponent       = game_state.get_opponent();

  std::cout << "\n=== " << current_player.get_name() << "'s Turn ===\n" << std::endl;

  std::cout << "Your Board:" << std::endl;
  current_player.get_board().display_player_board();

  std::cout << "\nOpponent's Board:" << std::endl;
  opponent.get_board().display_opponent_board();

  std::cout << std::endl;
}

void game_term_view::display_game_menu() {
  std::cout << "=== Battleship Game ===" << std::endl;
  std::cout << "1. New Game" << std::endl;
  std::cout << "2. Exit" << std::endl;
  std::cout << "Enter your choice: ";
}

void game_term_view::display_game_over( game & game_state ) {
  std::cout << "\n=== GAME OVER ===" << std::endl;
  std::cout << game_state.get_winner().get_name() << " wins!" << std::endl;
}
