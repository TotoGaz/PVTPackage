#ifndef PVTPACKAGE_PHASEPROPERTIES_HPP
#define PVTPACKAGE_PHASEPROPERTIES_HPP

#include "MultiphaseSystem/PhaseModel/PhaseProperties.hpp"

#include "refactor/passiveDataStructures/PhaseProperties.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {

void to_json( nlohmann::json & j, const PhaseProperties & phaseProperties );

} // end of namespace PVTPackage

#endif //PVTPACKAGE_PHASEPROPERTIES_HPP
