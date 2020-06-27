#include "MultiphaseSystem/PhaseModel/CubicEOS/CubicEoSPhaseModel.hpp"

#include "DebugComponentProperties.hpp"

#include <nlohmann/json.hpp>

#include <iostream>
#include <limits>

// for convenience
using json = nlohmann::json;

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

class MultiphaseSystemPropertiesHelper {
private:
  static constexpr auto PHASE_MOLE_FRACTION = "PHASE_MOLE_FRACTION";
  static constexpr auto PHASE_MODELS = "PHASE_MODELS";
  static constexpr auto MASS_DENSITY = "MASS_DENSITY";
  static constexpr auto MOLE_DENSITY = "MOLE_DENSITY";
  static constexpr auto MOLE_COMPOSITION = "MOLE_COMPOSITION";
  static constexpr auto MOLECULAR_WEIGHT = "MOLECULAR_WEIGHT";

public:
  static void to_json( json & output, const MultiphaseSystemProperties & props ){
    output[PHASE_MOLE_FRACTION] = { { "OIL", props.PhaseMoleFraction.at( PHASE_TYPE::OIL ) },
                                    { "GAS", props.PhaseMoleFraction.at( PHASE_TYPE::GAS ) } };
    output[MOLE_COMPOSITION] = { { "OIL", props.PhasesProperties.at( PHASE_TYPE::OIL ).MoleComposition },
                                 { "GAS", props.PhasesProperties.at( PHASE_TYPE::GAS ).MoleComposition } };
    output[MASS_DENSITY] = { { "OIL", props.PhasesProperties.at( PHASE_TYPE::OIL ).MassDensity },
                             { "GAS", props.PhasesProperties.at( PHASE_TYPE::GAS ).MassDensity } };
    output[MOLE_DENSITY] = { { "OIL", props.PhasesProperties.at( PHASE_TYPE::OIL ).MoleDensity },
                             { "GAS", props.PhasesProperties.at( PHASE_TYPE::GAS ).MoleDensity } };
    output[MOLECULAR_WEIGHT] = { { "OIL", props.PhasesProperties.at( PHASE_TYPE::OIL ).MolecularWeight },
                                 { "GAS", props.PhasesProperties.at( PHASE_TYPE::GAS ).MolecularWeight } };

    for (const PHASE_TYPE phaseType: { PHASE_TYPE::OIL, PHASE_TYPE::GAS, PHASE_TYPE::LIQUID_WATER_RICH})
    {
      if ( props.PhaseModels.count( phaseType ) > 0 )
      {
        const auto phaseModel = std::dynamic_pointer_cast< PVTPackage::CubicEoSPhaseModel >( props.PhaseModels.at( phaseType ) );
        if( phaseModel )
        {
          // FIXME the phaseType is not reproduced in the json.
          output[PHASE_MODELS][int( phaseType )] = { { "EOS",        phaseModel->getEosType() },
                                                     { "PHASE_TYPE", phaseModel->getPhaseType() },
                                                     { "PROPS",      phaseModel->get_ComponentsProperties() } };
        }
      }
    }
  }
};

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
           const MultiphaseSystemProperties & multiphaseProperties,
           double pressure,
           double temperature,
           std::vector< double > feed )
{
  if( const CompositionalFlash * f = dynamic_cast<const CompositionalFlash *>( flash ) )
  {
    json compJson{ { "COMP", f->getComponentProperties() } };

    std::cout << std::setprecision( std::numeric_limits< double >::max_digits10 )
              << compJson << std::endl;

    json propsJson{ { "PROPERTIES", multiphaseProperties } };

    std::cout << std::setprecision( std::numeric_limits< double >::max_digits10 )
              << propsJson << std::endl;

    json output{ { "pressure", pressure },
                 { "temperature", temperature },
                 { "feed", feed } };
    std::cout << output << std::endl ;
  }
}

} // enf of namespace PVTPackage