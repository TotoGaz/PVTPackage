#include "refactor/serializers/ComponentProperties.hpp"

#include "refactor/JsonKeys.hpp"

#include "MultiphaseSystem/ComponentProperties.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {

using json = nlohmann::json;

void to_json( nlohmann::json & j,
              const ComponentProperties & p )
{
  using namespace PVTPackage::refactor;

  j = json{ { ComponentPropertiesKeys::N_COMPONENTS, p.NComponents },
            { ComponentPropertiesKeys::LABELS,       p.Label },
            { ComponentPropertiesKeys::MW,           p.Mw },
            { ComponentPropertiesKeys::TC,           p.Tc },
            { ComponentPropertiesKeys::PC,           p.Pc },
            { ComponentPropertiesKeys::OMEGA,        p.Omega },
            { ComponentPropertiesKeys::WATER_INDEX,  p.WaterIndex } };
}

} // namespace PVTPackage
