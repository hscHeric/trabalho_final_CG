#pragma once

#include "board.hpp"

#include <string>

class player {
private:
  std::string name;
  board       game_board;

public:
  player( const std::string & name );

  const std::string & get_name() const;
  board &             get_board();
  bool                receive_shot( int row, int col );
  bool                has_lost() const;
};
