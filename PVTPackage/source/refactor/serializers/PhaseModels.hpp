#ifndef PVTPACKAGE_PHASEMODELS_HPP
#define PVTPACKAGE_PHASEMODELS_HPP

#include "MultiphaseSystem/PhaseModel/PhaseModel.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {

void to_json( nlohmann::json & j,
              const PhaseModel & model );

} // end of namespace PVTPackage

#endif //PVTPACKAGE_PHASEMODELS_HPP
