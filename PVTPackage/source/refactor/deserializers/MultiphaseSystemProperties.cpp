#include "refactor/deserializers/MultiphaseSystemProperties.hpp"

#include "refactor/JsonKeys.hpp"

#include "refactor/passiveDataStructures/MultiphaseSystemProperties.hpp"

#include "refactor/deserializers/PVTEnums.hpp"
#include "refactor/deserializers/PropertyAndDerivatives.hpp"
#include "refactor/deserializers/PhaseProperties.hpp"
#include "refactor/deserializers/PhaseModels.hpp"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace PVTPackage
{
namespace pds
{

void from_json( const json & j,
                pds::MultiphaseSystemProperties & props )
{
  j.at(MultiphaseSystemPropertiesKeys::TEMPERATURE).get_to(props.Temperature);
  j.at(MultiphaseSystemPropertiesKeys::PRESSURE).get_to(props.Pressure);
  j.at(MultiphaseSystemPropertiesKeys::FEED).get_to(props.Feed);

  j.at(MultiphaseSystemPropertiesKeys::PHASE_STATE).get_to(props.PhaseState);
  j.at(MultiphaseSystemPropertiesKeys::PHASE_TYPES).get_to(props.PhaseTypes);

  for( const pds::PHASE_TYPE & pt: props.PhaseTypes )
  {

    // Small hack to put the enum as a key
    std::string const & ptKey = json( pt ).get< std::string >();

    pds::CubicEoSPhaseModel phaseModelAtPt = j[MultiphaseSystemPropertiesKeys::PHASE_MODELS][ptKey].get< pds::CubicEoSPhaseModel >();
    props.PhaseModels[ pt ] = std::make_shared< pds::CubicEoSPhaseModel >( phaseModelAtPt );
    props.PhaseMoleFraction[ pt ] = j[MultiphaseSystemPropertiesKeys::PHASE_MOLE_FRACTION][ptKey];
    props.PhasesProperties[ pt ] = j[MultiphaseSystemPropertiesKeys::PHASE_PROPERTIES][ptKey];
  }
}

} // end of namespace pds
} // end of namespace PVTPackage
