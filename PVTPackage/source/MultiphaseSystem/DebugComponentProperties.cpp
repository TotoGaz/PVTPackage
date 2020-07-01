#include "MultiphaseSystem/PhaseModel/CubicEOS/CubicEoSPhaseModel.hpp"

#include "DebugComponentProperties.hpp"

#include <nlohmann/json.hpp>

#include <iostream>
#include <limits>
#include <map>

// for convenience
using json = nlohmann::json;

namespace nlohmann
{

template< typename T >
struct adl_serializer< std::shared_ptr< T > >
{
  static void to_json( json & j, const std::shared_ptr< T > & opt )
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

// FIXME ComponentProperties is not part of PVTPackage namespace...
void to_json( json & j,
              const ComponentProperties & properties )
{
  static constexpr auto N_COMPONENTS = "n_components";
  static constexpr auto LABELS = "labels";
  static constexpr auto MW = "mw";
  static constexpr auto TC = "tc";
  static constexpr auto PC = "pc";
  static constexpr auto OMEGA = "omega";

  j = json{ { N_COMPONENTS, properties.NComponents },
            { LABELS,       properties.Label },
            { MW,           properties.Mw },
            { TC,           properties.Tc },
            { PC,           properties.Pc },
            { OMEGA,        properties.Omega } };
}

namespace PVTPackage
{

std::string phaseType2string( const PHASE_TYPE & phaseType )
{
  const std::map< PHASE_TYPE, std::string > value2string{
    { PHASE_TYPE::LIQUID_WATER_RICH, "LIQUID_WATER_RICH" },
    { PHASE_TYPE::OIL,               "OIL" },
    { PHASE_TYPE::GAS,               "GAS" },
    { PHASE_TYPE::UNKNOWN,           "UNKNOWN" }
  };

  return value2string.at( phaseType );
}

class ScalarVectorPropertyAndDerivativesHelper {
private:
  static constexpr auto VALUE = "value";
  static constexpr auto DP = "dP";
  static constexpr auto DT = "dT";
  static constexpr auto DZ = "dz";
public:
  static void to_json( json & j,
                       const ScalarPropertyAndDerivatives< double > & s ) {
    j = json{ { VALUE, s.value },
              { DP,    s.dP },
              { DT,    s.dT },
              { DZ,    s.dz } };
  }
  static void to_json( json & j,
                       const VectorPropertyAndDerivatives< double > & s ) {
    j = json{ { VALUE, s.value },
              { DP,    s.dP },
              { DT,    s.dT },
              { DZ,    s.dz } };
  }
};

decltype( ScalarVectorPropertyAndDerivativesHelper::VALUE ) ScalarVectorPropertyAndDerivativesHelper::VALUE;
decltype( ScalarVectorPropertyAndDerivativesHelper::DP ) ScalarVectorPropertyAndDerivativesHelper::DP;
decltype( ScalarVectorPropertyAndDerivativesHelper::DT ) ScalarVectorPropertyAndDerivativesHelper::DT;
decltype( ScalarVectorPropertyAndDerivativesHelper::DZ ) ScalarVectorPropertyAndDerivativesHelper::DZ;

void to_json( json & j,
              const ScalarPropertyAndDerivatives< double > & s )
{
  ScalarVectorPropertyAndDerivativesHelper::to_json(j, s);
}

void to_json( json & j,
              const VectorPropertyAndDerivatives< double > & v )
{
  ScalarVectorPropertyAndDerivativesHelper::to_json(j, v);
}

void to_json( json & j, const CubicEoSPhaseModel & model ){
  j = json{ { "EOS", model.getEosType() },
            { "PHASE_TYPE", model.getPhaseType() },
            { "PROPS",      model.get_ComponentsProperties() } };
}

class MultiphaseSystemPropertiesHelper {
private:
  static constexpr auto PRESSURE = "PRESSURE";
  static constexpr auto TEMPERATURE = "TEMPERATURE";
  static constexpr auto FEED = "FEED";

  static constexpr auto PHASE_MOLE_FRACTION = "PHASE_MOLE_FRACTION";
  static constexpr auto PHASE_MODELS = "PHASE_MODELS";
  static constexpr auto MASS_DENSITY = "MASS_DENSITY";
  static constexpr auto MOLE_DENSITY = "MOLE_DENSITY";
  static constexpr auto MOLE_COMPOSITION = "MOLE_COMPOSITION";
  static constexpr auto MOLECULAR_WEIGHT = "MOLECULAR_WEIGHT";

public:
  static void to_json( json & output,
                       const MultiphaseSystemProperties & props )
  {
    output[PRESSURE] = props.Pressure;
    output[TEMPERATURE] = props.Temperature;
    output[FEED] = props.Feed;

    for( const PHASE_TYPE & pt: props.PhaseTypes )
    {
      const std::string phaseType = phaseType2string( pt );
      const PhaseProperties & phaseProperties = props.PhasesProperties.at( pt );
      const auto phaseModel = std::dynamic_pointer_cast< PVTPackage::CubicEoSPhaseModel >( props.PhaseModels.at( pt ) );

      output[phaseType][MOLE_COMPOSITION] = phaseProperties.MoleComposition;
      output[phaseType][MASS_DENSITY] = phaseProperties.MassDensity;
      output[phaseType][MOLE_DENSITY] = phaseProperties.MoleDensity;
      output[phaseType][MOLECULAR_WEIGHT] = phaseProperties.MolecularWeight;
      output[PHASE_MOLE_FRACTION][phaseType] = props.PhaseMoleFraction.at( pt );
      output[PHASE_MODELS][phaseType] = phaseModel;
    }
  }
};

decltype( MultiphaseSystemPropertiesHelper::PRESSURE ) MultiphaseSystemPropertiesHelper::PRESSURE;
decltype( MultiphaseSystemPropertiesHelper::TEMPERATURE ) MultiphaseSystemPropertiesHelper::TEMPERATURE;
decltype( MultiphaseSystemPropertiesHelper::FEED ) MultiphaseSystemPropertiesHelper::FEED;
decltype( MultiphaseSystemPropertiesHelper::PHASE_MOLE_FRACTION ) MultiphaseSystemPropertiesHelper::PHASE_MOLE_FRACTION;
decltype( MultiphaseSystemPropertiesHelper::PHASE_MODELS ) MultiphaseSystemPropertiesHelper::PHASE_MODELS;
decltype( MultiphaseSystemPropertiesHelper::MASS_DENSITY) MultiphaseSystemPropertiesHelper::MASS_DENSITY;
decltype( MultiphaseSystemPropertiesHelper::MOLE_DENSITY ) MultiphaseSystemPropertiesHelper::MOLE_DENSITY;
decltype( MultiphaseSystemPropertiesHelper::MOLE_COMPOSITION ) MultiphaseSystemPropertiesHelper::MOLE_COMPOSITION;
decltype( MultiphaseSystemPropertiesHelper::MOLECULAR_WEIGHT ) MultiphaseSystemPropertiesHelper::MOLECULAR_WEIGHT;

void to_json( json & j,
              const MultiphaseSystemProperties & props )
{
  MultiphaseSystemPropertiesHelper::to_json(j, props);
}

void Dump( const Flash * flash,
           const MultiphaseSystemProperties & multiphaseProperties )
{
  if( const CompositionalFlash * f = dynamic_cast<const CompositionalFlash *>( flash ) )
  {
    json compJson{ { "COMP", f->getComponentProperties() } };

    std::cout << std::setprecision( std::numeric_limits< double >::max_digits10 )
              << compJson << std::endl;

    json propsJson{ { "PROPERTIES", multiphaseProperties } };

    std::cout << std::setprecision( std::numeric_limits< double >::max_digits10 )
              << propsJson << std::endl;
  }
}

} // enf of namespace PVTPackage