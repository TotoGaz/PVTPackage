#include "refactor/serializers/PropertyAndDerivatives.hpp"

#include "refactor/JsonKeys.hpp"

#include "MultiphaseSystem/PropertyAndDerivatives.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {

using json = nlohmann::json;

void to_json( json & j,
              const ScalarPropertyAndDerivatives< double > & s )
{
  using namespace PVTPackage::refactor;

  j = json{ { ScalarVectorPropertyAndDerivativesKeys::VALUE, s.value },
            { ScalarVectorPropertyAndDerivativesKeys::DP,    s.dP },
            { ScalarVectorPropertyAndDerivativesKeys::DT,    s.dT },
            { ScalarVectorPropertyAndDerivativesKeys::DZ,    s.dz } };
}

void to_json( json & j,
              const VectorPropertyAndDerivatives< double > & v )
{
  using namespace PVTPackage::refactor;

  j = json{ { ScalarVectorPropertyAndDerivativesKeys::VALUE, v.value },
            { ScalarVectorPropertyAndDerivativesKeys::DP,    v.dP },
            { ScalarVectorPropertyAndDerivativesKeys::DT,    v.dT },
            { ScalarVectorPropertyAndDerivativesKeys::DZ,    v.dz } };
}

} // end of namespace PVTPackage