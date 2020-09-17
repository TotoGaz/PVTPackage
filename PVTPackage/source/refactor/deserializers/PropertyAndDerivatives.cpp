#include "refactor/JsonKeys.hpp"

#include "refactor/passiveDataStructures/PropertyAndDerivatives.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {
namespace refactor {
namespace pds {

using json = nlohmann::json;

void from_json( const nlohmann::json & j,
                pds::ScalarPropertyAndDerivatives< double > & s )
{
  s.value = j[ScalarVectorPropertyAndDerivativesKeys::VALUE].get< double >();
  s.dP = j[ScalarVectorPropertyAndDerivativesKeys::DP].get< double >();
  s.dT = j[ScalarVectorPropertyAndDerivativesKeys::DT].get< double >();
  s.dz = j[ScalarVectorPropertyAndDerivativesKeys::DZ].get< std::vector< double > >();
}

void from_json( const nlohmann::json & j,
                pds::VectorPropertyAndDerivatives< double > & v )
{
  v.value = j[ScalarVectorPropertyAndDerivativesKeys::VALUE].get< std::vector< double > >();
  v.dP = j[ScalarVectorPropertyAndDerivativesKeys::DP].get< std::vector< double > >();
  v.dT = j[ScalarVectorPropertyAndDerivativesKeys::DT].get< std::vector< double > >();
  v.dz = j[ScalarVectorPropertyAndDerivativesKeys::DZ].get< std::vector< std::vector< double > > >();
}

} // end of namespace refactor
} // end of namespace pds
} // end of namespace PVTPackage
