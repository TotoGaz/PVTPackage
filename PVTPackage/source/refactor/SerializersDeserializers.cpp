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

class PhaseType2StringHelper
{
public:
  static std::string phaseType2string( const PHASE_TYPE & phaseType )
  {
    const std::map< PHASE_TYPE, std::string > value2string{
      { PHASE_TYPE::LIQUID_WATER_RICH, LIQUID_WATER_RICH },
      { PHASE_TYPE::OIL,               OIL },
      { PHASE_TYPE::GAS,               GAS },
      { PHASE_TYPE::UNKNOWN,           UNKNOWN }
    };

    return value2string.at( phaseType );
  }

  static PHASE_TYPE string2phaseType( const std::string & s )
  {
    const std::map< std::string, PHASE_TYPE > string2value{
      { LIQUID_WATER_RICH, PHASE_TYPE::LIQUID_WATER_RICH },
      { OIL,               PHASE_TYPE::OIL },
      { GAS,               PHASE_TYPE::GAS },
      { UNKNOWN,           PHASE_TYPE::UNKNOWN }
    };

    return string2value.at( s );
  }

private:
  static constexpr auto LIQUID_WATER_RICH = "LIQUID_WATER_RICH";
  static constexpr auto OIL = "OIL";
  static constexpr auto GAS = "GAS";
  static constexpr auto UNKNOWN = "UNKNOWN";
};

decltype( PhaseType2StringHelper::LIQUID_WATER_RICH ) PhaseType2StringHelper::LIQUID_WATER_RICH;
decltype( PhaseType2StringHelper::OIL ) PhaseType2StringHelper::OIL;
decltype( PhaseType2StringHelper::GAS ) PhaseType2StringHelper::GAS;
decltype( PhaseType2StringHelper::UNKNOWN ) PhaseType2StringHelper::UNKNOWN;

std::string phaseType2string( const PHASE_TYPE & phaseType )
{
  return PhaseType2StringHelper::phaseType2string( phaseType );
}

PHASE_TYPE string2phaseType( const std::string & s )
{
  return PhaseType2StringHelper::string2phaseType( s );
}

class EoS2StringHelper
{
public:
  static std::string eos2string( const EOS_TYPE & eos )
  {
    const std::map< EOS_TYPE, std::string > value2string{
      { EOS_TYPE::REDLICH_KWONG_SOAVE, REDLICH_KWONG_SOAVE },
      { EOS_TYPE::PENG_ROBINSON,       PENG_ROBINSON },
      { EOS_TYPE::UNKNOWN,             UNKNOWN }
    };

    return value2string.at( eos );
  }

  static EOS_TYPE string2eos( const std::string & s )
  {
    const std::map< std::string, EOS_TYPE > string2value{
      { REDLICH_KWONG_SOAVE, EOS_TYPE::REDLICH_KWONG_SOAVE },
      { PENG_ROBINSON,       EOS_TYPE::PENG_ROBINSON },
      { UNKNOWN,             EOS_TYPE::UNKNOWN }
    };

    return string2value.at( s );
  }

private:
  static constexpr auto REDLICH_KWONG_SOAVE = "REDLICH_KWONG_SOAVE";
  static constexpr auto PENG_ROBINSON = "PENG_ROBINSON";
  static constexpr auto UNKNOWN = "UNKNOWN";
};

decltype( EoS2StringHelper::REDLICH_KWONG_SOAVE ) EoS2StringHelper::REDLICH_KWONG_SOAVE;
decltype( EoS2StringHelper::PENG_ROBINSON ) EoS2StringHelper::PENG_ROBINSON;
decltype( EoS2StringHelper::UNKNOWN ) EoS2StringHelper::UNKNOWN;

std::string eos2string( const EOS_TYPE & eos )
{
  return EoS2StringHelper::eos2string( eos ) ;
}

EOS_TYPE string2eos( const std::string & s )
{
  return EoS2StringHelper::string2eos( s );
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

  static void from_json( const json & j,
                         ScalarPropertyAndDerivatives< double > & s )
  {
    s.value = j[VALUE];
    s.dP = j[DP];
    s.dT = j[DT];
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
  j = json{ { "EOS",                  eos2string( model.getEosType() ) },
            { "PHASE_TYPE",           phaseType2string( model.getPhaseType() ) },
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

class MultiphaseSystemPropertiesHelper {
public:
  static void to_json( json & output,
                       const MultiphaseSystemProperties & props )
 {
    output[TEMPERATURE] = props.Temperature;
    output[PRESSURE] = props.Pressure;
    output[FEED] = props.Feed;

    for( const PHASE_TYPE & pt: props.PhaseTypes )
    {
      const std::string phaseType = phaseType2string( pt );

      const auto phaseModel = std::dynamic_pointer_cast< PVTPackage::CubicEoSPhaseModel >( props.PhaseModels.at( pt ) );
      output[PHASE_MODELS][phaseType] = phaseModel;

      output[PHASE_MOLE_FRACTION][phaseType] = props.PhaseMoleFraction.at( pt );
      output[PHASE_PROPERTIES][phaseType] = props.PhasesProperties.at( pt );
    }
  }
private:
  static constexpr auto PRESSURE = "PRESSURE";
  static constexpr auto TEMPERATURE = "TEMPERATURE";
  static constexpr auto FEED = "FEED";

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

} // end of namespace PVTPackage
