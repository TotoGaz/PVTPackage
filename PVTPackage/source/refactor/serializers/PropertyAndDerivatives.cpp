#include "refactor/serializers/PropertyAndDerivatives.hpp"

#include "refactor/JsonKeys.hpp"

#include "MultiphaseSystem/PropertyAndDerivatives.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {

using json = nlohmann::json;

void to_json( json & j,
              const ScalarPropertyAndDerivatives< double > & s )
{
  j = json{ { ScalarVectorPropertyAndDerivativesHelper::VALUE, s.value },
            { ScalarVectorPropertyAndDerivativesHelper::DP,    s.dP },
            { ScalarVectorPropertyAndDerivativesHelper::DT,    s.dT },
            { ScalarVectorPropertyAndDerivativesHelper::DZ,    s.dz } };
}

void to_json( json & j,
              const VectorPropertyAndDerivatives< double > & v )
{
  j = json{ { ScalarVectorPropertyAndDerivativesHelper::VALUE, v.value },
            { ScalarVectorPropertyAndDerivativesHelper::DP,    v.dP },
            { ScalarVectorPropertyAndDerivativesHelper::DT,    v.dT },
            { ScalarVectorPropertyAndDerivativesHelper::DZ,    v.dz } };
}

} // end of namespace PVTPackage