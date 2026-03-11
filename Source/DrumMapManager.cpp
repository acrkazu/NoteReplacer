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

uint8_t DrumMapManager::Convert(uint8_t src_note,
                                const DrumMap& from,
                                const DrumMap& to) const {
  auto contains = [](const std::vector<uint8_t>& v, uint8_t note) {
    return std::find(v.begin(), v.end(), note) != v.end();
  };

  if (contains(from.kick, src_note)) {
    if (!to.kick.empty()) return to.kick[0];
  } else if (contains(from.snare_side_stick, src_note)) {
    if (!to.snare_side_stick.empty()) return to.snare_side_stick[0];
    if (!to.snare_rim.empty()) return to.snare_rim[0];
  } else if (contains(from.snare_open, src_note)) {
    if (!to.snare_open.empty()) return to.snare_open[0];
  } else if (contains(from.snare_rim, src_note)) {
    if (!to.snare_rim.empty()) return to.snare_rim[0];
  } else if (contains(from.tom_1_open, src_note)) {
    if (!to.tom_1_open.empty()) return to.tom_1_open[0];
  } else if (contains(from.tom_2_open, src_note)) {
    if (!to.tom_2_open.empty()) return to.tom_2_open[0];
  } else if (contains(from.tom_3_open, src_note)) {
    if (!to.tom_3_open.empty()) return to.tom_3_open[0];
  } else if (contains(from.tom_4_open, src_note)) {
    if (!to.tom_4_open.empty()) return to.tom_4_open[0];
  } else if (contains(from.hh_foot_close, src_note)) {
    if (!to.hh_foot_close.empty()) return to.hh_foot_close[0];
    if (!to.hh_pedal_chick.empty()) return to.hh_pedal_chick[0];
  } else if (contains(from.hh_closed_tip, src_note) ||
             contains(from.hh_closed, src_note)) {
    if (!to.hh_closed.empty()) return to.hh_closed[0];
  } else if (contains(from.hh_open, src_note)) {
    if (!to.hh_open.empty()) return to.hh_open[0];
  } else if (contains(from.hh_pedal_chick, src_note)) {
    if (!to.hh_pedal_chick.empty()) return to.hh_pedal_chick[0];
  } else if (contains(from.ride_bell, src_note)) {
    if (!to.ride_bell.empty()) return to.ride_bell[0];
  } else if (contains(from.ride_crash, src_note)) {
    if (!to.ride_crash.empty()) return to.ride_crash[0];
  } else if (contains(from.ride_tip, src_note)) {
    if (!to.ride_tip.empty()) return to.ride_tip[0];
  } else if (contains(from.crash_l, src_note) ||
             contains(from.crash_r, src_note)) {
    if (!to.crash_l.empty()) return to.crash_l[0];
  } else if (contains(from.china, src_note)) {
    if (!to.china.empty()) return to.china[0];
  }

  return src_note;
}

uint8_t DrumMapManager::ConvertGGDtoGM(uint8_t src_note) {
  return Convert(src_note, GGDModernAndMassive_, GM_);
}

uint8_t DrumMapManager::ConvertGMtoGGD(uint8_t src_note) {
  return Convert(src_note, GM_, GGDModernAndMassive_);
}
