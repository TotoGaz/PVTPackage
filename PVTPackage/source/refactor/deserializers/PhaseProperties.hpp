#ifndef PVTPACKAGE_DESERIALIZERS_PHASEPROPERTIES_HPP
#define PVTPACKAGE_DESERIALIZERS_PHASEPROPERTIES_HPP

#include "refactor/passiveDataStructures/PhaseProperties.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {
namespace refactor {
namespace pds {

void from_json( const nlohmann::json & j,
                pds::PhaseProperties & phaseProperties );

} // end of namespace refactor
} // end of namespace pds
} // end of namespace PVTPackage

#endif // PVTPACKAGE_DESERIALIZERS_PHASEPROPERTIES_HPP
