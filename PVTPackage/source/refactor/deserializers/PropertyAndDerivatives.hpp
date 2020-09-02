#ifndef PVTPACKAGE_DESERIALIZERS_PROPERTYANDDERIVATIVES_HPP
#define PVTPACKAGE_DESERIALIZERS_PROPERTYANDDERIVATIVES_HPP

#include "refactor/passiveDataStructures/PropertyAndDerivatives.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {
namespace pds {

void from_json( const nlohmann::json & j,
                pds::ScalarPropertyAndDerivatives< double > & s );

void from_json( const nlohmann::json & j,
                pds::VectorPropertyAndDerivatives< double > & v );

} // end of namespace pds
} // end of namespace PVTPackage

#endif // PVTPACKAGE_DESERIALIZERS_PROPERTYANDDERIVATIVES_HPP
