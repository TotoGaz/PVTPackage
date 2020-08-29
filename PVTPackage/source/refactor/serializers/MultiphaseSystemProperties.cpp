#include "MultiphaseSystemProperties.hpp"

#include "Enums.hpp"
#include "PropertyAndDerivatives.hpp"
#include "PhaseProperties.hpp"
#include "PhaseModels.hpp"

#include "MultiphaseSystem/MultiphaseSystemProperties.hpp"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

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

class MultiphaseSystemPropertiesHelper {
public:
  static void to_json( json & output,
                       const MultiphaseSystemProperties & props )
  {
    output[TEMPERATURE] = props.Temperature;
    output[PRESSURE] = props.Pressure;
    output[FEED] = props.Feed;

    output[PHASE_STATE] = props.PhaseState;
    output[PHASE_TYPES] = props.PhaseTypes;

    for( const PHASE_TYPE & pt: props.PhaseTypes )
    {
      // Small hack to put the enum as a key
      std::string const & ptKey = json( pt ).get< std::string >();

      const auto phaseModelAtPt = std::dynamic_pointer_cast< PVTPackage::CubicEoSPhaseModel >( props.PhaseModels.at( pt ) );
      output[PHASE_MODELS][ptKey] = phaseModelAtPt ;
      output[PHASE_MOLE_FRACTION][ptKey] = props.PhaseMoleFraction.at( pt ) ;
      output[PHASE_PROPERTIES][ptKey] = props.PhasesProperties.at( pt ) ;
    }
  }

  static void from_json( const json & j,
                         MultiphaseSystemProperties & props )
  {
    j.at(TEMPERATURE).get_to(props.Temperature);
    j.at(PRESSURE).get_to(props.Pressure);
    j.at(FEED).get_to(props.Feed);

    j.at(PHASE_STATE).get_to(props.PhaseState);
    j.at(PHASE_TYPES).get_to(props.PhaseTypes);

    for( const PHASE_TYPE & pt: props.PhaseTypes )
    {

      // Small hack to put the enum as a key
      std::string const & ptKey = json( pt ).get< std::string >();

      CubicEoSPhaseModel phaseModelAtPt = j[PHASE_MODELS][ptKey].get< CubicEoSPhaseModel >();
      props.PhaseModels[ pt ] = std::make_shared< CubicEoSPhaseModel >( phaseModelAtPt );
      props.PhaseMoleFraction[ pt ] = j[PHASE_MOLE_FRACTION][ptKey];
      props.PhasesProperties[ pt ] = j[PHASE_PROPERTIES][ptKey];
    }

  }

private:
  static constexpr auto TEMPERATURE = "TEMPERATURE";
  static constexpr auto PRESSURE = "PRESSURE";
  static constexpr auto FEED = "FEED";

  static constexpr auto PHASE_STATE = "PHASE_STATE";
  static constexpr auto PHASE_TYPES = "PHASE_TYPES";

  static constexpr auto PHASE_MODELS = "PHASE_MODELS";
  static constexpr auto PHASE_MOLE_FRACTION = "PHASE_MOLE_FRACTION";
  static constexpr auto PHASE_PROPERTIES = "PHASE_PROPERTIES";
};

decltype( MultiphaseSystemPropertiesHelper::PRESSURE ) MultiphaseSystemPropertiesHelper::PRESSURE;
decltype( MultiphaseSystemPropertiesHelper::TEMPERATURE ) MultiphaseSystemPropertiesHelper::TEMPERATURE;
decltype( MultiphaseSystemPropertiesHelper::FEED ) MultiphaseSystemPropertiesHelper::FEED;
decltype( MultiphaseSystemPropertiesHelper::PHASE_MOLE_FRACTION ) MultiphaseSystemPropertiesHelper::PHASE_MOLE_FRACTION;
decltype( MultiphaseSystemPropertiesHelper::PHASE_MODELS ) MultiphaseSystemPropertiesHelper::PHASE_MODELS;

void to_json( json & j,
              const MultiphaseSystemProperties & props )
{
  MultiphaseSystemPropertiesHelper::to_json( j, props );
}

void from_json( const json & j,
                MultiphaseSystemProperties & props )
{
  MultiphaseSystemPropertiesHelper::from_json( j, props );
}

} // end of namespace PVTPackage
