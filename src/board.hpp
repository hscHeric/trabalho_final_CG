#pragma once

#include "cell.hpp"
#include "ship.hpp"

#include <vector>

class board {
private:
  static const int                    SIZE = 10;
  std::vector<std::vector<CellState>> grid;
  std::vector<ship>                   ships;

public:
  board();
  bool                      place_ship( ship & ship, int row, int col, bool horizontal );
  bool                      place_ships_randomly();
  CellState                 fire_shot( int row, int col );
  bool                      check_ship_hit( int row, int col, ship & hitShip );
  bool                      all_ships_sunk() const;
  void                      display_player_board() const;
  void                      display_opponent_board() const;
  static int                get_size();
  static bool               is_valid_position( int row, int col );
  CellState                 get_cell_state( int row, int col ) const;
  const std::vector<ship> & get_ships() const;
};
