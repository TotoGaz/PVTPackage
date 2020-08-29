#ifndef PVTPACKAGE_PROPERTYANDDERIVATIVES_HPP
#define PVTPACKAGE_PROPERTYANDDERIVATIVES_HPP

#include "MultiphaseSystem/PropertyAndDerivatives.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {

void to_json( nlohmann::json & j, const ScalarPropertyAndDerivatives< double > & s );
void to_json( nlohmann::json & j, const VectorPropertyAndDerivatives< double > & v );

void from_json( const nlohmann::json & j, ScalarPropertyAndDerivatives< double > & s );
void from_json( const nlohmann::json & j, VectorPropertyAndDerivatives< double > & s );

}

#endif