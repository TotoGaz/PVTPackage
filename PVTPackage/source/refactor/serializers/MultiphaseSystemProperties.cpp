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
  output[refactor::MultiphaseSystemPropertiesKeys::TEMPERATURE] = props.Temperature;
  output[refactor::MultiphaseSystemPropertiesKeys::PRESSURE] = props.Pressure;
  output[refactor::MultiphaseSystemPropertiesKeys::FEED] = props.Feed;

  output[refactor::MultiphaseSystemPropertiesKeys::PHASE_STATE] = props.PhaseState;
  output[refactor::MultiphaseSystemPropertiesKeys::PHASE_TYPES] = props.PhaseTypes;

  for( const PHASE_TYPE & pt: props.PhaseTypes )
  {
    // Small hack to put the enum as a key
    std::string const & ptKey = nlohmann::json( pt ).get< std::string >();

    const std::shared_ptr< PhaseModel > & pm = props.PhaseModels.at( pt );
    output[refactor::MultiphaseSystemPropertiesKeys::PHASE_MODELS][ptKey] = pm ;
    output[refactor::MultiphaseSystemPropertiesKeys::PHASE_MOLE_FRACTION][ptKey] = props.PhaseMoleFraction.at( pt ) ;
    output[refactor::MultiphaseSystemPropertiesKeys::PHASE_PROPERTIES][ptKey] = props.PhasesProperties.at( pt ) ;
  }
}

} // end of namespace PVTPackage
