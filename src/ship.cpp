#include "ship.hpp"

ship::ship( int size, const std::string & name ) : size( size ), hits( 0 ), sunk( false ), name( name ) {}

bool ship::is_sunk() const {
  return hits >= size;
}

void ship::hit() {
  hits++;
  sunk = is_sunk();
}

void ship::add_position( int row, int col ) {
  positions.push_back( { row, col } );
}

int ship::get_size() const {
  return size;
}

int ship::get_hits() const {
  return hits;
}

bool ship::get_sunk() const {
  return sunk;
}

const std::string & ship::get_name() const {
  return name;
}

const std::vector<std::pair<int, int>> & ship::get_positions() const {
  return positions;
}

bool ship::is_at_position( int row, int col ) const {
  for ( const auto & pos : positions ) {
    if ( pos.first == row && pos.second == col ) {
      return true;
    }
  }
  return false;
}
