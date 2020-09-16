#ifndef PVTPACKAGE_BLACKOILMODELS_HPP
#define PVTPACKAGE_BLACKOILMODELS_HPP

#include "MultiphaseSystem/PhaseModel/BlackOil/BlackOil_GasModel.hpp"
#include "MultiphaseSystem/PhaseModel/BlackOil/BlackOil_OilModel.hpp"
#include "MultiphaseSystem/PhaseModel/BlackOil/BlackOil_WaterModel.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {

void to_json( nlohmann::json & j,
              const BlackOil_GasModel & model );

void to_json( nlohmann::json & j,
              const BlackOil_OilModel & model );

void to_json( nlohmann::json & j,
              const BlackOil_WaterModel & model );

} // end of namespace PVTPackage


#endif //PVTPACKAGE_BLACKOILMODELS_HPP
