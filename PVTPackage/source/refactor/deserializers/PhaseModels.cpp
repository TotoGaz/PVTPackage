#include "refactor/deserializers/PhaseModels.hpp"

#include "refactor/JsonKeys.hpp"

#include "refactor/passiveDataStructures/PhaseModel.hpp"

#include "refactor/deserializers/PVTEnums.hpp"
#include "refactor/deserializers/ComponentProperties.hpp"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace PVTPackage {
namespace pds {

void from_json( const nlohmann::json & j,
                pds::CubicEoSPhaseModel & model )
{
  j.at( PhaseModelsKeys::COMPONENT_PROPERTIES ).get_to( model.m_ComponentsProperties );
  j.at( PhaseModelsKeys::EOS ).get_to( model.m_EOSType );
  j.at( PhaseModelsKeys::PHASE_TYPE_ ).get_to( model.m_PhaseType );
}

} // end of namespace pds
} // end of namespace PVTPackage
