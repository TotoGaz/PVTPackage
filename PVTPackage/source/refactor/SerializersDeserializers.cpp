#include "SerializersDeserializers.hpp"

// for convenience
using json = nlohmann::json;

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

namespace PVTPackage {

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

std::string eos2string( const EOS_TYPE & eos )
{
  const std::map< EOS_TYPE, std::string > value2string{
    { EOS_TYPE::REDLICH_KWONG_SOAVE, "REDLICH_KWONG_SOAVE" },
    { EOS_TYPE::PENG_ROBINSON,       "PENG_ROBINSON" },
    { EOS_TYPE::UNKNOWN,             "UNKNOWN" }
  };

  return value2string.at( eos );
}

class ScalarVectorPropertyAndDerivativesHelper {
public:
  static void to_json( json & j,
                       const ScalarPropertyAndDerivatives< double > & s )
  {
    j = json{ { VALUE, s.value },
              { DP,    s.dP },
              { DT,    s.dT },
              { DZ,    s.dz } };
  }

  static void to_json( json & j,
                       const VectorPropertyAndDerivatives< double > & s )
  {
    j = json{ { VALUE, s.value },
              { DP,    s.dP },
              { DT,    s.dT },
              { DZ,    s.dz } };
  }
private:
  static constexpr auto VALUE = "value";
  static constexpr auto DP = "dP";
  static constexpr auto DT = "dT";
  static constexpr auto DZ = "dz";
};

decltype( ScalarVectorPropertyAndDerivativesHelper::VALUE ) ScalarVectorPropertyAndDerivativesHelper::VALUE;
decltype( ScalarVectorPropertyAndDerivativesHelper::DP ) ScalarVectorPropertyAndDerivativesHelper::DP;
decltype( ScalarVectorPropertyAndDerivativesHelper::DT ) ScalarVectorPropertyAndDerivativesHelper::DT;
decltype( ScalarVectorPropertyAndDerivativesHelper::DZ ) ScalarVectorPropertyAndDerivativesHelper::DZ;

void to_json( json & j,
              const ScalarPropertyAndDerivatives< double > & s )
{
  ScalarVectorPropertyAndDerivativesHelper::to_json( j, s );
}

void to_json( json & j,
              const VectorPropertyAndDerivatives< double > & v )
{
  ScalarVectorPropertyAndDerivativesHelper::to_json( j, v );
}

void to_json( json & j,
              const CubicEoSPhaseModel & model )
{
  j = json{ { "EOS",                  eos2string( model.getEosType() ) },
            { "PHASE_TYPE",           phaseType2string( model.getPhaseType() ) },
            { "COMPONENT_PROPERTIES", model.get_ComponentsProperties() } };
}

class MultiphaseSystemPropertiesHelper {
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
  MultiphaseSystemPropertiesHelper::to_json( j, props );
}

} // end of namespace PVTPackage
