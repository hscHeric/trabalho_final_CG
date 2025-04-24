#pragma once

#include <string>
#include <utility>
#include <vector>

class ship {
private:
  int                              size;
  int                              hits;
  bool                             sunk;
  std::string                      name;
  std::vector<std::pair<int, int>> positions;

public:
  ship( int size, const std::string & name );

  bool is_sunk() const;
  void hit();
  void add_position( int row, int col );

  int                                      get_size() const;
  int                                      get_hits() const;
  bool                                     get_sunk() const;
  const std::string &                      get_name() const;
  const std::vector<std::pair<int, int>> & get_positions() const;

  bool is_at_position( int row, int col ) const;
};
