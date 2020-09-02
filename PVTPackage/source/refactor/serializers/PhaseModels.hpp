#ifndef PVTPACKAGE_PHASEMODELS_HPP
#define PVTPACKAGE_PHASEMODELS_HPP

#include "refactor/passiveDataStructures/PhaseModel.hpp"

#include "MultiphaseSystem/PhaseModel/CubicEOS/CubicEoSPhaseModel.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {

void to_json( nlohmann::json & j,
              const CubicEoSPhaseModel & model );

} // end of namespace PVTPackage

#endif //PVTPACKAGE_PHASEMODELS_HPP
