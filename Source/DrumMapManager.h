#include <map>
#include <string>
#include <vector>

#include "CommonDef.h"

class DrumMapManager {
 public:
  DrumMapManager() { CreateDrumMap(); };
  ~DrumMapManager() {};
  uint8_t ConvertGGDtoGM(uint8_t src);
  uint8_t ConvertGMtoGGD(uint8_t src_note);

 private:
  void CreateDrumMap();

 private:
  DrumMap GGDModernAndMassive_;
  DrumMap GM_;
  DrumMap AddictiveDrums_;

 private:
};
