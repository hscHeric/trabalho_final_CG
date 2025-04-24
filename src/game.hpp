#pragma once

#include "player.hpp"

class game {
private:
  player player_one;
  player player_two;
  bool   is_player_one_turn;
  bool   game_over;

public:
  game( const std::string & player_one_name, const std::string & player_two_name );
  void     start_game();
  bool     make_move( int row, int col );
  player & get_current_player();
  player & get_opponent();
  bool     is_game_over();
  player & get_winner();
  bool     is_player_one_playing() const;
};
