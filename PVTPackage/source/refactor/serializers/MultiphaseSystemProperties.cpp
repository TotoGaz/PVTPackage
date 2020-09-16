#include "refactor/serializers/MultiphaseSystemProperties.hpp"

#include "refactor/serializers/PVTEnums.hpp"
#include "refactor/serializers/PropertyAndDerivatives.hpp"
#include "refactor/serializers/PhaseProperties.hpp"
#include "refactor/serializers/PhaseModels.hpp"

#include "MultiphaseSystem/MultiphaseSystemProperties.hpp"

#include <nlohmann/json.hpp>

namespace nlohmann
{

template< typename T >
struct adl_serializer< std::shared_ptr< T > >
{
  static void to_json( nlohmann::json & j, const std::shared_ptr< T > & opt )
  {
    if( opt.get() )
    {
      j = *opt;
    }
    else
    {
      j = nullptr;
    }
  }
};

}

namespace PVTPackage
{

void to_json( nlohmann::json & output,
              const MultiphaseSystemProperties & props )
{
  output[MultiphaseSystemPropertiesKeys::TEMPERATURE] = props.Temperature;
  output[MultiphaseSystemPropertiesKeys::PRESSURE] = props.Pressure;
  output[MultiphaseSystemPropertiesKeys::FEED] = props.Feed;

  output[MultiphaseSystemPropertiesKeys::PHASE_STATE] = props.PhaseState;
  output[MultiphaseSystemPropertiesKeys::PHASE_TYPES] = props.PhaseTypes;

  for( const PHASE_TYPE & pt: props.PhaseTypes )
  {
    // Small hack to put the enum as a key
    std::string const & ptKey = nlohmann::json( pt ).get< std::string >();

    const std::shared_ptr< PhaseModel > & pm = props.PhaseModels.at( pt );
    output[MultiphaseSystemPropertiesKeys::PHASE_MODELS][ptKey] = pm ;
    output[MultiphaseSystemPropertiesKeys::PHASE_MOLE_FRACTION][ptKey] = props.PhaseMoleFraction.at( pt ) ;
    output[MultiphaseSystemPropertiesKeys::PHASE_PROPERTIES][ptKey] = props.PhasesProperties.at( pt ) ;
  }
}

} // end of namespace PVTPackage
