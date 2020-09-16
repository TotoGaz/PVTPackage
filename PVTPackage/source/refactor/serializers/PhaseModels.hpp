#ifndef PVTPACKAGE_PHASEMODELS_HPP
#define PVTPACKAGE_PHASEMODELS_HPP

#include "MultiphaseSystem/PhaseModel/PhaseModel.hpp"

#include "MultiphaseSystem/PhaseModel/CubicEOS/CubicEoSPhaseModel.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {

// FIXME separate CubicEoSPhaseModel from PhaseModel

void to_json( nlohmann::json & j,
              const CubicEoSPhaseModel & model );

void to_json( nlohmann::json & j,
              const PhaseModel & model );

} // end of namespace PVTPackage

#endif //PVTPACKAGE_PHASEMODELS_HPP
