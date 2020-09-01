#ifndef PVTPACKAGE_PROPERTYANDDERIVATIVES_HPP
#define PVTPACKAGE_PROPERTYANDDERIVATIVES_HPP

#include "MultiphaseSystem/PropertyAndDerivatives.hpp"

#include "refactor/passiveDataStructures/PropertyAndDerivatives.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {

void to_json( nlohmann::json & j, const ScalarPropertyAndDerivatives< double > & s );
void to_json( nlohmann::json & j, const VectorPropertyAndDerivatives< double > & v );

namespace pds {

void from_json( const nlohmann::json & j, pds::ScalarPropertyAndDerivatives< double > & s );
void from_json( const nlohmann::json & j, pds::VectorPropertyAndDerivatives< double > & s );

} // end of namespace pds
} // end of namespace PVTPackage

#endif