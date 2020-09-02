#include "PhaseModels.hpp"

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
  j = json{ { PhaseModelsKeys::EOS,                  model.getEosType() },
            { PhaseModelsKeys::PHASE_TYPE_,          model.getPhaseType() },
            { PhaseModelsKeys::COMPONENT_PROPERTIES, model.get_ComponentsProperties() } };
}

} // namespace PVTPackage
