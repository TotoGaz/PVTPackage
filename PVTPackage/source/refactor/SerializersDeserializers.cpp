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

NLOHMANN_JSON_SERIALIZE_ENUM( PHASE_STATE, {
  { PHASE_STATE::GAS, "GAS" },
  { PHASE_STATE::OIL, "OIL" },
  { PHASE_STATE::WATER, "WATER" },
  { PHASE_STATE::OIL_GAS, "OIL_GAS" },
  { PHASE_STATE::GAS_WATER, "GAS_WATER" },
  { PHASE_STATE::OIL_WATER, "OIL_WATER" },
  { PHASE_STATE::OIL_GAS_WATER, "OIL_GAS_WATER" },
  { PHASE_STATE::UNKNOWN, "UNKNOWN" }
} )

NLOHMANN_JSON_SERIALIZE_ENUM( PHASE_TYPE, {
  { PHASE_TYPE::LIQUID_WATER_RICH, "LIQUID_WATER_RICH" },
  { PHASE_TYPE::OIL, "OIL" },
  { PHASE_TYPE::GAS, "GAS" },
  { PHASE_TYPE::UNKNOWN, "UNKNOWN" }
} )

NLOHMANN_JSON_SERIALIZE_ENUM( EOS_TYPE, {
  { EOS_TYPE::REDLICH_KWONG_SOAVE, "REDLICH_KWONG_SOAVE" },
  { EOS_TYPE::PENG_ROBINSON, "PENG_ROBINSON" },
  { EOS_TYPE::UNKNOWN, "UNKNOWN" }
} )

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

  static void from_json( const json & j,
                         ScalarPropertyAndDerivatives< double > & s )
  {
    s.value = j[VALUE].get< double >();
    s.dP = j[DP].get< double >();
    s.dT = j[DT].get< double >();
    s.dz = j[DZ].get< std::vector< double > >();
  }

  static void to_json( json & j,
                       const VectorPropertyAndDerivatives< double > & s )
  {
    j = json{ { VALUE, s.value },
              { DP,    s.dP },
              { DT,    s.dT },
              { DZ,    s.dz } };
  }

  static void from_json( const json & j,
                         VectorPropertyAndDerivatives< double > & s )
  {
    s.value = j[VALUE].get< std::vector< double > >();
    s.dP = j[DP].get< std::vector< double> >();
    s.dT = j[DT].get< std::vector< double> >();
    s.dz = j[DZ].get< std::vector< std::vector< double > > >();
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

void from_json( const nlohmann::json & j,
                ScalarPropertyAndDerivatives< double > & s )
{
  ScalarVectorPropertyAndDerivativesHelper::from_json( j, s );
}

void to_json( json & j,
              const VectorPropertyAndDerivatives< double > & v )
{
  ScalarVectorPropertyAndDerivativesHelper::to_json( j, v );
}

void from_json( const nlohmann::json & j,
                VectorPropertyAndDerivatives< double > & s )
{
  ScalarVectorPropertyAndDerivativesHelper::from_json( j, s );
}

void to_json( json & j,
              const CubicEoSPhaseModel & model )
{
  j = json{ { "EOS",                  model.getEosType() },
            { "PHASE_TYPE",           model.getPhaseType() },
            { "COMPONENT_PROPERTIES", model.get_ComponentsProperties() } };
}

class PhasePropertiesHelper
{
public:
  static void to_json( json & j,
                       const PhaseProperties & phaseProperties )
  {
    j = json{
      { MOLECULAR_WEIGHT,         phaseProperties.MolecularWeight },
      { COMPRESSIBILITY_FACTOR,   phaseProperties.CompressibilityFactor },
      { MOLE_COMPOSITION,         phaseProperties.MoleComposition },
      { LN_FUGACITY_COEFFICIENTS, phaseProperties.LnFugacityCoefficients },
      { MOLE_DENSITY,             phaseProperties.MoleDensity },
      { MASS_DENSITY,             phaseProperties.MassDensity },
      { VISCOSITY,                phaseProperties.Viscosity },
      { MASS_ENTHALPY,            phaseProperties.MassEnthalpy },
      { COMPRESSIBILITY,          phaseProperties.Compressibility }
    };
  }

  static void from_json( const json & j,
                         PhaseProperties & phaseProperties )
  {
    j.at(MOLECULAR_WEIGHT).get_to(phaseProperties.MolecularWeight);
    j.at(COMPRESSIBILITY_FACTOR).get_to(phaseProperties.CompressibilityFactor);
    j.at(MOLE_COMPOSITION).get_to(phaseProperties.MoleComposition);
    j.at(LN_FUGACITY_COEFFICIENTS).get_to(phaseProperties.LnFugacityCoefficients);
    j.at(MOLE_DENSITY).get_to(phaseProperties.MoleDensity);
    j.at(MASS_DENSITY).get_to(phaseProperties.MassDensity);
    j.at(VISCOSITY).get_to(phaseProperties.Viscosity);
    j.at(MASS_ENTHALPY).get_to(phaseProperties.MassEnthalpy);
    j.at(COMPRESSIBILITY).get_to(phaseProperties.Compressibility);
  }
private:
  static constexpr auto MOLECULAR_WEIGHT = "MOLECULAR_WEIGHT";

  static constexpr auto COMPRESSIBILITY_FACTOR = "COMPRESSIBILITY_FACTOR";
  static constexpr auto MOLE_COMPOSITION = "MOLE_COMPOSITION";
  static constexpr auto LN_FUGACITY_COEFFICIENTS = "LN_FUGACITY_COEFFICIENTS";

  static constexpr auto MOLE_DENSITY = "MOLE_DENSITY";
  static constexpr auto MASS_DENSITY = "MASS_DENSITY";

  static constexpr auto VISCOSITY = "VISCOSITY";
  static constexpr auto MASS_ENTHALPY = "MASS_ENTHALPY";
  static constexpr auto COMPRESSIBILITY = "COMPRESSIBILITY";
};

decltype( PhasePropertiesHelper::MOLECULAR_WEIGHT ) PhasePropertiesHelper::MOLECULAR_WEIGHT;
decltype( PhasePropertiesHelper::COMPRESSIBILITY_FACTOR ) PhasePropertiesHelper::COMPRESSIBILITY_FACTOR;
decltype( PhasePropertiesHelper::MOLE_COMPOSITION ) PhasePropertiesHelper::MOLE_COMPOSITION;
decltype( PhasePropertiesHelper::LN_FUGACITY_COEFFICIENTS ) PhasePropertiesHelper::LN_FUGACITY_COEFFICIENTS;
decltype( PhasePropertiesHelper::MOLE_DENSITY ) PhasePropertiesHelper::MOLE_DENSITY;
decltype( PhasePropertiesHelper::MASS_DENSITY) PhasePropertiesHelper::MASS_DENSITY;
decltype( PhasePropertiesHelper::VISCOSITY ) PhasePropertiesHelper::VISCOSITY;
decltype( PhasePropertiesHelper::MASS_ENTHALPY ) PhasePropertiesHelper::MASS_ENTHALPY;
decltype( PhasePropertiesHelper::COMPRESSIBILITY ) PhasePropertiesHelper::COMPRESSIBILITY;

void to_json( json & j,
              const PhaseProperties & phaseProperties )
{
  PhasePropertiesHelper::to_json( j, phaseProperties );
}

void from_json( const json & j,
                PhaseProperties & phaseProperties )
{
  PhasePropertiesHelper::from_json( j, phaseProperties );
}

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

//      const auto phaseModelAtPt = std::dynamic_pointer_cast< PVTPackage::CubicEoSPhaseModel >( props.PhaseModels.at( pt ) );
//      output[PHASE_MODELS][ptKey] = phaseModelAtPt ;
//      props.PhaseMoleFraction[ pt ] = j[PHASE_MOLE_FRACTION][ptKey].get< ScalarPropertyAndDerivatives< double > >();
      props.PhaseMoleFraction[ pt ] = j[PHASE_MOLE_FRACTION][ptKey];
      props.PhasesProperties[ pt ] = j[PHASE_PROPERTIES][ptKey];
//      output[PHASE_PROPERTIES][ptKey] = props.PhasesProperties.at( pt ) ;
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
