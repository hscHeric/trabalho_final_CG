#include "board.hpp"
#include "game.hpp"
#include "game_term_view.hpp"

#include <iostream>

void play_game() {
  std::string player_one_name, player_two_name;

  std::cout << "Enter Player 1 name: ";
  std::getline( std::cin, player_one_name );
  if ( player_one_name.empty() )
    player_one_name = "Player 1";

  std::cout << "Enter Player 2 name: ";
  std::getline( std::cin, player_two_name );
  if ( player_two_name.empty() )
    player_two_name = "Player 2";

  game game_state( player_one_name, player_two_name );
  game_state.start_game();

  while ( !game_state.is_game_over() ) {
    game_term_view::display_game_state( game_state );

    int row, col;
    std::cout << "Enter row and column to fire (e.g., 3 4): ";
    std::cin >> row >> col;

    if ( row < 0 || row >= board::get_size() || col < 0 || col >= board::get_size() ) {
      std::cout << "Invalid coordinates. Try again." << std::endl;
      continue;
    }

    bool hit = game_state.make_move( row, col );

    if ( hit ) {
      std::cout << "HIT!" << std::endl;
    } else {
      std::cout << "MISS!" << std::endl;
    }
  }

  game_term_view::display_game_over( game_state );
}

int main() {
  int choice = 0;
  do {
    game_term_view::display_game_menu();
    std::cin >> choice;
    std::cin.ignore();

    switch ( choice ) {
      case 1 : play_game(); break;
      case 2 : std::cout << "Thanks for playing!" << std::endl; break;
      default: std::cout << "Invalid choice. Please try again." << std::endl;
    }
  } while ( choice != 2 );
}
