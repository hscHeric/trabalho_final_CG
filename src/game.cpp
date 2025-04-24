#include "game.hpp"

#include "player.hpp"

#include <stdexcept>

game::game( const std::string & player_one_name, const std::string & player_two_name )
  : player_one( player_one_name ), player_two( player_two_name ), is_player_one_turn( true ), game_over( false ) {}

void game::start_game() {
  player_one.get_board().place_ships_randomly();
  player_two.get_board().place_ships_randomly();

  is_player_one_turn = true;
  game_over          = false;
}

bool game::make_move( int row, int col ) {
  if ( game_over ) {
    return false;
  }

  auto current  = get_current_player();
  auto opponent = get_opponent();

  bool hit = opponent.receive_shot( row, col );

  if ( opponent.has_lost() ) {
    game_over = true;
    return hit;
  }

  if ( !hit ) {
    is_player_one_turn = !is_player_one_turn;
  }

  return hit;
}

player & game::get_current_player() {
  return is_player_one_turn ? player_one : player_two;
}

player & game::get_opponent() {
  return is_player_one_turn ? player_two : player_one;
}

bool game::is_game_over() {
  return game_over;
}

player & game::get_winner() {
  if ( !game_over ) {
    throw std::runtime_error( "Game is not over yet" );
  }

  return player_one.has_lost() ? player_two : player_one;
}

bool game::is_player_one_playing() const {
  return is_player_one_turn;
}
