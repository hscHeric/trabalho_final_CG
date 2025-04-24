#include "player.hpp"

player::player( const std::string & name ) : name( name ) {}

const std::string & player::get_name() const {
  return name;
}

board & player::get_board() {
  return game_board;
}

bool player::receive_shot( int row, int col ) {
  CellState result = game_board.fire_shot( row, col );
  return result == CellState::HIT;
}

bool player::has_lost() const {
  return game_board.all_ships_sunk();
}
