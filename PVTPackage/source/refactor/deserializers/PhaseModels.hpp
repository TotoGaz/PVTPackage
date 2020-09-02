#ifndef PVTPACKAGE_DESERIALIZERS_PHASEMODELS_HPP
#define PVTPACKAGE_DESERIALIZERS_PHASEMODELS_HPP

#include "refactor/passiveDataStructures/PhaseModel.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {
namespace pds {

void from_json( const nlohmann::json & j,
                pds::CubicEoSPhaseModel & cubicEoSPhaseModel );


} // end of namespace pds
} // end of namespace PVTPackage

#endif //PVTPACKAGE_DESERIALIZERS_PHASEMODELS_HPP
