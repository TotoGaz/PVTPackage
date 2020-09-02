#include "refactor/JsonKeys.hpp"

#include "refactor/passiveDataStructures/PropertyAndDerivatives.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {
namespace pds {

using json = nlohmann::json;

void from_json( const nlohmann::json & j,
                pds::ScalarPropertyAndDerivatives< double > & s )
{
  s.value = j[ScalarVectorPropertyAndDerivativesHelper::VALUE].get< double >();
  s.dP = j[ScalarVectorPropertyAndDerivativesHelper::DP].get< double >();
  s.dT = j[ScalarVectorPropertyAndDerivativesHelper::DT].get< double >();
  s.dz = j[ScalarVectorPropertyAndDerivativesHelper::DZ].get< std::vector< double > >();
}

void from_json( const nlohmann::json & j,
                pds::VectorPropertyAndDerivatives< double > & v )
{
  v.value = j[ScalarVectorPropertyAndDerivativesHelper::VALUE].get< std::vector< double > >();
  v.dP = j[ScalarVectorPropertyAndDerivativesHelper::DP].get< std::vector< double > >();
  v.dT = j[ScalarVectorPropertyAndDerivativesHelper::DT].get< std::vector< double > >();
  v.dz = j[ScalarVectorPropertyAndDerivativesHelper::DZ].get< std::vector< std::vector< double > > >();
}

} // end of namespace pds
} // end of namespace PVTPackage
