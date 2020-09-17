#include "CubicEoSPhaseModel.hpp"

#include "refactor/JsonKeys.hpp"

#include "refactor/serializers/PVTEnums.hpp"
#include "refactor/serializers/ComponentProperties.hpp"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace PVTPackage
{

void to_json( json & j,
              const CubicEoSPhaseModel & model )
{
  using namespace PVTPackage::refactor;

  j = json{ { CubeEoSPhaseModelsKeys::EOS,                  model.getEosType() },
            { CubeEoSPhaseModelsKeys::PHASE_TYPE_,          model.getPhaseType() },
            { CubeEoSPhaseModelsKeys::COMPONENT_PROPERTIES, model.get_ComponentsProperties() } };
}

} // end of namespace PVTPackage
