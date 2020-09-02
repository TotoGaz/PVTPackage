#ifndef PVTPACKAGE_PROPERTYANDDERIVATIVES_HPP
#define PVTPACKAGE_PROPERTYANDDERIVATIVES_HPP

#include "refactor/passiveDataStructures/PropertyAndDerivatives.hpp"

#include "MultiphaseSystem/PropertyAndDerivatives.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {

void to_json( nlohmann::json & j, const ScalarPropertyAndDerivatives< double > & s );
void to_json( nlohmann::json & j, const VectorPropertyAndDerivatives< double > & v );

} // end of namespace PVTPackage

#endif