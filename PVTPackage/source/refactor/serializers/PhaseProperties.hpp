#ifndef PVTPACKAGE_PHASEPROPERTIES_HPP
#define PVTPACKAGE_PHASEPROPERTIES_HPP

#include "MultiphaseSystem/PhaseModel/PhaseProperties.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage{

void to_json( nlohmann::json & j, const PhaseProperties & phaseProperties );

void from_json( const nlohmann::json & j,
                PhaseProperties & phaseProperties );

}

#endif //PVTPACKAGE_PHASEPROPERTIES_HPP
