#pragma once
#include <string>
#include <vector>

struct DrumMap {
  std::string name;
  std::vector<uint8_t> kick;
  std::vector<uint8_t> snare_side_stick;
  std::vector<uint8_t> snare_open;
  std::vector<uint8_t> snare_rim;
  std::vector<uint8_t> tom_1_open;
  std::vector<uint8_t> tom_2_open;
  std::vector<uint8_t> tom_3_open;
  std::vector<uint8_t> tom_4_open;
  std::vector<uint8_t> hh_foot_close;
  std::vector<uint8_t> hh_closed_tip;
  std::vector<uint8_t> hh_closed;
  std::vector<uint8_t> hh_open;
  std::vector<uint8_t> hh_pedal_chick;
  std::vector<uint8_t> ride_bell;
  std::vector<uint8_t> ride_crash;
  std::vector<uint8_t> ride_tip;
  std::vector<uint8_t> crash_l;
  std::vector<uint8_t> crash_r;
  std::vector<uint8_t> china;
};
