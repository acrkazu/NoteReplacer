#pragma once
#include <string>
#include <vector>

#include "CommonDef.h"

class DrumMapManager {
 public:
  DrumMapManager() { CreateDrumMap(); };
  ~DrumMapManager() {};
  uint8_t ConvertGGDtoGM(uint8_t src_note);
  uint8_t ConvertGMtoGGD(uint8_t src_note);

 private:
  void CreateDrumMap();
  uint8_t Convert(uint8_t src_note, const DrumMap& from, const DrumMap& to) const;

 private:
  DrumMap GGDModernAndMassive_;
  DrumMap GM_;
  DrumMap AddictiveDrums_;
};
