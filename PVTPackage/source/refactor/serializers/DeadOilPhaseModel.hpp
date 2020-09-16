#ifndef PVTPACKAGE_DEADOILPHASEMODEL_HPP
#define PVTPACKAGE_DEADOILPHASEMODEL_HPP

#include "MultiphaseSystem/PhaseModel/BlackOil/DeadOil_PhaseModel.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {

void to_json( nlohmann::json & j,
              const DeadOil_PhaseModel & model );

} // end of namespace PVTPackage

#endif //PVTPACKAGE_DEADOILPHASEMODEL_HPP
