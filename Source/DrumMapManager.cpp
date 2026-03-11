#include "DrumMapManager.h"

void DrumMapManager::CreateDrumMap() {
  DrumMap GGDModernAndMassive;
  GGDModernAndMassive.name = "GGD Modern & Massive";
  GGDModernAndMassive.kick = {36};
  GGDModernAndMassive.snare_side_stick = {40};
  GGDModernAndMassive.snare_open = {41};
  GGDModernAndMassive.snare_rim = {37};
  GGDModernAndMassive.tom_1_open = {42};
  GGDModernAndMassive.tom_2_open = {45};
  GGDModernAndMassive.tom_3_open = {46};
  GGDModernAndMassive.tom_4_open = {46};  // tom3 と同じノート
  GGDModernAndMassive.hh_foot_close = {55};
  GGDModernAndMassive.hh_closed_tip = {57};
  GGDModernAndMassive.hh_closed = {49};
  GGDModernAndMassive.hh_open = {52, 53, 54};  // open 1/2/3 を統合
  GGDModernAndMassive.hh_pedal_chick = {48};
  GGDModernAndMassive.ride_bell = {74};
  GGDModernAndMassive.ride_crash = {76};
  GGDModernAndMassive.ride_tip = {73};
  GGDModernAndMassive.crash_l = {58};
  GGDModernAndMassive.crash_r = {61};
  GGDModernAndMassive.china = {71};
  GGDModernAndMassive_ = GGDModernAndMassive;

  DrumMap GM;
  GM.name = "GM";
  GM.kick = {36, 35};
  GM.snare_open = {};
  GM.snare_rim = {37, 38};
  GM.snare_side_stick = {37};
  GM.tom_1_open = {50};
  GM.tom_2_open = {47};
  GM.tom_3_open = {45};
  GM.tom_4_open = {41};
  GM.hh_closed = {42};
  GM.hh_closed_tip = {42};
  GM.hh_open = {46};
  GM.hh_pedal_chick = {44};
  GM.hh_foot_close = {44};
  GM.ride_tip = {51};
  GM.ride_bell = {53};
  GM.ride_crash = {59};
  GM.crash_l = {49};
  GM.crash_r = {57};
  GM.china = {52};
  GM_ = GM;

  DrumMap AddictiveDrums;
  AddictiveDrums.name = "Addictive Drums";
  AddictiveDrums.kick = {36};
  AddictiveDrums.snare_open = {38, 40, 43};
  AddictiveDrums.snare_rim = {37, 39, 41, 42};
  AddictiveDrums.snare_side_stick = {};
  AddictiveDrums.tom_1_open = {71};
  AddictiveDrums.tom_2_open = {69};
  AddictiveDrums.tom_3_open = {67};
  AddictiveDrums.tom_4_open = {65};
  AddictiveDrums.hh_foot_close = {48};
  AddictiveDrums.hh_pedal_chick = {48};
  AddictiveDrums.hh_closed_tip = {49, 51};
  AddictiveDrums.hh_closed = {50, 52, 53};
  AddictiveDrums.hh_open = {55, 56, 57, 58, 59};
  AddictiveDrums.ride_tip = {60, 84};
  AddictiveDrums.ride_bell = {61, 85};
  AddictiveDrums.ride_crash = {62, 86};
  AddictiveDrums.crash_l = {77, 79, 81};
  AddictiveDrums.crash_r = {89, 91, 93};
  AddictiveDrums.china = {};
  AddictiveDrums_ = AddictiveDrums;
}

uint8_t DrumMapManager::ConvertGGDtoGM(uint8_t src_note) {
  auto contains = [](const std::vector<uint8_t>& v, uint8_t note) {
    return std::find(v.begin(), v.end(), note) != v.end();
  };

  if (contains(GGDModernAndMassive_.kick, src_note)) {
    if (!GM_.kick.empty()) return GM_.kick[0];
  } else if (contains(GGDModernAndMassive_.snare_side_stick, src_note)) {
    if (!GM_.snare_side_stick.empty()) return GM_.snare_side_stick[0];
    if (!GM_.snare_rim.empty()) return GM_.snare_rim[0];
  } else if (contains(GGDModernAndMassive_.snare_open, src_note)) {
    if (!GM_.snare_open.empty()) return GM_.snare_open[0];
  } else if (contains(GGDModernAndMassive_.snare_rim, src_note)) {
    if (!GM_.snare_rim.empty()) return GM_.snare_rim[0];
  } else if (contains(GGDModernAndMassive_.tom_1_open, src_note)) {
    if (!GM_.tom_1_open.empty()) return GM_.tom_1_open[0];
  } else if (contains(GGDModernAndMassive_.tom_2_open, src_note)) {
    if (!GM_.tom_2_open.empty()) return GM_.tom_2_open[0];
  } else if (contains(GGDModernAndMassive_.tom_3_open, src_note)) {
    if (!GM_.tom_3_open.empty()) return GM_.tom_3_open[0];
  } else if (contains(GGDModernAndMassive_.tom_4_open, src_note)) {
    if (!GM_.tom_4_open.empty()) return GM_.tom_4_open[0];
  } else if (contains(GGDModernAndMassive_.hh_foot_close, src_note)) {
    if (!GM_.hh_foot_close.empty()) return GM_.hh_foot_close[0];
    if (!GM_.hh_pedal_chick.empty()) return GM_.hh_pedal_chick[0];
  } else if (contains(GGDModernAndMassive_.hh_closed_tip, src_note) ||
             contains(GGDModernAndMassive_.hh_closed, src_note)) {
    if (!GM_.hh_closed.empty()) return GM_.hh_closed[0];
  } else if (contains(GGDModernAndMassive_.hh_open, src_note)) {
    if (!GM_.hh_open.empty()) return GM_.hh_open[0];
  } else if (contains(GGDModernAndMassive_.hh_pedal_chick, src_note)) {
    if (!GM_.hh_pedal_chick.empty()) return GM_.hh_pedal_chick[0];
  } else if (contains(GGDModernAndMassive_.ride_bell, src_note)) {
    if (!GM_.ride_bell.empty()) return GM_.ride_bell[0];
  } else if (contains(GGDModernAndMassive_.ride_crash, src_note)) {
    if (!GM_.ride_crash.empty()) return GM_.ride_crash[0];
  } else if (contains(GGDModernAndMassive_.ride_tip, src_note)) {
    if (!GM_.ride_tip.empty()) return GM_.ride_tip[0];
  } else if (contains(GGDModernAndMassive_.crash_l, src_note) ||
             contains(GGDModernAndMassive_.crash_r, src_note)) {
    if (!GM_.crash_l.empty()) return GM_.crash_l[0];
  } else if (contains(GGDModernAndMassive_.china, src_note)) {
    if (!GM_.china.empty()) return GM_.china[0];
  }

  return src_note;
}

uint8_t DrumMapManager::ConvertGMtoGGD(uint8_t src_note) {
  auto contains = [](const std::vector<uint8_t>& v, uint8_t note) {
    return std::find(v.begin(), v.end(), note) != v.end();
  };

  if (contains(GM_.kick, src_note)) {
    if (!GGDModernAndMassive_.kick.empty()) return GGDModernAndMassive_.kick[0];
  } else if (contains(GM_.snare_side_stick, src_note)) {
    if (!GGDModernAndMassive_.snare_side_stick.empty())
      return GGDModernAndMassive_.snare_side_stick[0];
    if (!GGDModernAndMassive_.snare_rim.empty())
      return GGDModernAndMassive_.snare_rim[0];
  } else if (contains(GM_.snare_open, src_note)) {
    if (!GGDModernAndMassive_.snare_open.empty())
      return GGDModernAndMassive_.snare_open[0];
  } else if (contains(GM_.snare_rim, src_note)) {
    if (!GGDModernAndMassive_.snare_rim.empty())
      return GGDModernAndMassive_.snare_rim[0];
  } else if (contains(GM_.tom_1_open, src_note)) {
    if (!GGDModernAndMassive_.tom_1_open.empty())
      return GGDModernAndMassive_.tom_1_open[0];
  } else if (contains(GM_.tom_2_open, src_note)) {
    if (!GGDModernAndMassive_.tom_2_open.empty())
      return GGDModernAndMassive_.tom_2_open[0];
  } else if (contains(GM_.tom_3_open, src_note)) {
    if (!GGDModernAndMassive_.tom_3_open.empty())
      return GGDModernAndMassive_.tom_3_open[0];
  } else if (contains(GM_.tom_4_open, src_note)) {
    if (!GGDModernAndMassive_.tom_4_open.empty())
      return GGDModernAndMassive_.tom_4_open[0];
  } else if (contains(GM_.hh_foot_close, src_note)) {
    if (!GGDModernAndMassive_.hh_foot_close.empty())
      return GGDModernAndMassive_.hh_foot_close[0];
    if (!GGDModernAndMassive_.hh_pedal_chick.empty())
      return GGDModernAndMassive_.hh_pedal_chick[0];
  } else if (contains(GM_.hh_closed, src_note) ||
             contains(GM_.hh_closed_tip, src_note)) {
    if (!GGDModernAndMassive_.hh_closed.empty())
      return GGDModernAndMassive_.hh_closed[0];
  } else if (contains(GM_.hh_open, src_note)) {
    if (!GGDModernAndMassive_.hh_open.empty())
      return GGDModernAndMassive_.hh_open[0];
  } else if (contains(GM_.hh_pedal_chick, src_note)) {
    if (!GGDModernAndMassive_.hh_pedal_chick.empty())
      return GGDModernAndMassive_.hh_pedal_chick[0];
  } else if (contains(GM_.ride_bell, src_note)) {
    if (!GGDModernAndMassive_.ride_bell.empty())
      return GGDModernAndMassive_.ride_bell[0];
  } else if (contains(GM_.ride_crash, src_note)) {
    if (!GGDModernAndMassive_.ride_crash.empty())
      return GGDModernAndMassive_.ride_crash[0];
  } else if (contains(GM_.ride_tip, src_note)) {
    if (!GGDModernAndMassive_.ride_tip.empty())
      return GGDModernAndMassive_.ride_tip[0];
  } else if (contains(GM_.crash_l, src_note) ||
             contains(GM_.crash_r, src_note)) {
    if (!GGDModernAndMassive_.crash_l.empty())
      return GGDModernAndMassive_.crash_l[0];
  } else if (contains(GM_.china, src_note)) {
    if (!GGDModernAndMassive_.china.empty())
      return GGDModernAndMassive_.china[0];
  }

  return src_note;
}
