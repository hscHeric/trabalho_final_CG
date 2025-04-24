#include "board.hpp"

#include "ship.hpp"

#include <iostream>
#include <ostream>
#include <random>

board::board() {
  grid.resize( SIZE, std::vector<CellState>( SIZE, CellState::WATER ) );

  ships.push_back( ship( 5, "Carrier" ) );
  ships.push_back( ship( 4, "Battleship" ) );
  ships.push_back( ship( 3, "Cruiser" ) );
  ships.push_back( ship( 3, "Submarine" ) );
  ships.push_back( ship( 2, "Destroyer" ) );
}

bool board::place_ship( ship & ship, int row, int col, bool horizontal ) {
  // Verificação se a posição do navio vai esta dentro dos limites do grid
  if ( horizontal ) {
    if ( col + ship.get_size() > SIZE ) {
      return false;
    }
  } else {
    if ( row + ship.get_size() > SIZE ) {
      return false;
    }
  }

  std::vector<std::pair<int, int>> positions;

  for ( int i = 0; i < ship.get_size(); i++ ) {
    int newRow = horizontal ? row : row + i;
    int newCol = horizontal ? col + i : col;

    if ( grid[newRow][newCol] == CellState::SHIP ) {
      return false;
    }

    positions.push_back( { newRow, newCol } );
  }

  for ( const auto & pos : positions ) {
    grid[pos.first][pos.second] = CellState::SHIP;
    ship.add_position( pos.first, pos.second );
  }

  return true;
}

bool board::place_ships_randomly() {
  std::random_device              rd;
  std::mt19937                    gen( rd() );
  std::uniform_int_distribution<> disPos( 0, SIZE - 1 );
  std::uniform_int_distribution<> disDir( 0, 1 );

  for ( auto & row : grid ) {
    std::fill( row.begin(), row.end(), CellState::WATER );
  }

  for ( auto & s : ships ) {
    s = ship( s.get_size(), s.get_name() );
  }

  for ( auto & ship : ships ) {
    bool      placed       = false;
    int       attempts     = 0;
    const int MAX_ATTEMPTS = 100;

    while ( !placed && attempts < MAX_ATTEMPTS ) {
      int  row        = disPos( gen );
      int  col        = disPos( gen );
      bool horizontal = disDir( gen ) == 0;

      if ( place_ship( ship, row, col, horizontal ) ) {
        placed = true;
      }

      attempts++;
    }

    if ( !placed ) {
      return false;
    }
  }

  return true;
}

CellState board::fire_shot( int row, int col ) {
  if ( !is_valid_position( row, col ) ) {
    return CellState::WATER;
  }

  CellState state = grid[row][col];

  if ( state == CellState::WATER ) {
    grid[row][col] = CellState::MISS;
    return CellState::MISS;
  } else if ( state == CellState::SHIP ) {
    grid[row][col] = CellState::HIT;

    for ( auto & ship : ships ) {
      if ( check_ship_hit( row, col, ship ) ) {
        break;
      }
    }

    return CellState::HIT;
  }

  return state;
}

bool board::check_ship_hit( int row, int col, ship & hitShip ) {
  if ( hitShip.is_at_position( row, col ) ) {
    hitShip.hit();
    return true;
  }
  return false;
}

bool board::all_ships_sunk() const {
  for ( const auto & ship : ships ) {
    if ( !ship.is_sunk() ) {
      return false;
    }
  }
  return true;
}

void board::display_player_board() const {
  std::cout << "  ";
  for ( int i = 0; i < SIZE; i++ ) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  for ( int i = 0; i < SIZE; i++ ) {
    std::cout << i << " ";
    for ( int j = 0; j < SIZE; j++ ) {
      char symbol;
      switch ( grid[i][j] ) {
        case CellState::WATER: symbol = '~'; break;
        case CellState::SHIP : symbol = 'S'; break;
        case CellState::HIT  : symbol = 'X'; break;
        case CellState::MISS : symbol = 'O'; break;
      }
      std::cout << symbol << " ";
    }
    std::cout << std::endl;
  }
}

void board::display_opponent_board() const {
  std::cout << "  ";
  for ( int i = 0; i < SIZE; i++ ) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  for ( int i = 0; i < SIZE; i++ ) {
    std::cout << i << " ";
    for ( int j = 0; j < SIZE; j++ ) {
      char symbol;
      switch ( grid[i][j] ) {
        case CellState::WATER:
        case CellState::SHIP : symbol = '~'; break;
        case CellState::HIT  : symbol = 'X'; break;
        case CellState::MISS : symbol = 'O'; break;
      }
      std::cout << symbol << " ";
    }
    std::cout << std::endl;
  }
}

int board::get_size() {
  return SIZE;
}

bool board::is_valid_position( int row, int col ) {
  return row >= 0 && row < SIZE && col >= 0 && col < SIZE;
}

CellState board::get_cell_state( int row, int col ) const {
  if ( is_valid_position( row, col ) ) {
    return grid[row][col];
  }
  return CellState::WATER;
}

const std::vector<ship> & board::get_ships() const {
  return ships;
}
