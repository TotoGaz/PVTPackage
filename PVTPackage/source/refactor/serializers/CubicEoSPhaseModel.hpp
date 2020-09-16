#ifndef PVTPACKAGE_CUBICEOSPHASEMODEL_HPP
#define PVTPACKAGE_CUBICEOSPHASEMODEL_HPP

#include "MultiphaseSystem/PhaseModel/CubicEOS/CubicEoSPhaseModel.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {

void to_json( nlohmann::json & j,
              const CubicEoSPhaseModel & model );

} // end of namespace PVTPackage

#endif //PVTPACKAGE_CUBICEOSPHASEMODEL_HPP
