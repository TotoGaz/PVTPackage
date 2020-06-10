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
  const char * N_COMPONENTS = "n_components";
  const char * LABELS = "labels";
  const char * MW = "mw";
  const char * TC = "tc";
  const char * PC = "pc";
  const char * OMEGA = "omega";

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
  static const char * VALUE;
  static const char * DP;
  static const char * DT;
  static const char * DZ;
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

const char * ScalarVectorPropertyAndDerivativesHelper::VALUE = "value";
const char * ScalarVectorPropertyAndDerivativesHelper::DP = "dP";
const char * ScalarVectorPropertyAndDerivativesHelper::DT = "dT";
const char * ScalarVectorPropertyAndDerivativesHelper::DZ = "dz";

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

class DebugComponentProperties
{
private:
  static const char * N_COMPONENTS;
  static const char * LABELS;
  static const char * MW;
  static const char * TC;
  static const char * PC;
  static const char * OMEGA;

  const std::size_t n_components;
  const std::vector <std::string> labels;
  const std::vector< double > mw;
  const std::vector< double > tc;
  const std::vector< double > pc;
  const std::vector< double > omega;

public:
  DebugComponentProperties( const ComponentProperties & comp )
    :
    n_components( comp.NComponents ),
    labels( comp.Label ),
    mw( comp.Mw ),
    tc( comp.Tc ),
    pc( comp.Pc ),
    omega( comp.Omega )
  { }

  void print() const
  {
    json output = {
      { N_COMPONENTS, n_components },
      { LABELS,       labels },
      { MW,           mw },
      { TC,           tc },
      { PC,           pc },
      { OMEGA,        omega },
    };

    std::cout << std::setprecision( std::numeric_limits< double >::max_digits10 )
              << output << std::endl;
  }
};

const char * DebugComponentProperties::N_COMPONENTS = "n_components";
const char * DebugComponentProperties::LABELS = "labels";
const char * DebugComponentProperties::MW = "mw";
const char * DebugComponentProperties::TC = "tc";
const char * DebugComponentProperties::PC = "pc";
const char * DebugComponentProperties::OMEGA = "omega";

// FIXME Do functions instead.
class DebugMultiphaseSystemProperties
{
private:
  static const char * PHASE_MOLE_FRACTION;
  static const char * PHASE_MODELS;
  static const char * MASS_DENSITY;
  static const char * MOLE_DENSITY;
  static const char * MOLE_COMPOSITION;
  static const char * MOLECULAR_WEIGHT;

  const MultiphaseSystemProperties & props;
public:
  DebugMultiphaseSystemProperties(const MultiphaseSystemProperties & properties):
    props(properties){}

  void print() const
  {
    json output;
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
          output[PHASE_MODELS][int( phaseType )] = { { "EOS",        phaseModel->getEosType() },
                                                     { "PHASE_TYPE", phaseModel->getPhaseType() },
                                                     { "PROPS",      phaseModel->get_ComponentsProperties() } };
        }
      }
    }

    std::cout << std::setprecision( std::numeric_limits< double >::max_digits10 )
              << output << std::endl;
  }
};

const char * DebugMultiphaseSystemProperties::PHASE_MOLE_FRACTION = "PHASE_MOLE_FRACTION";
const char * DebugMultiphaseSystemProperties::PHASE_MODELS = "PHASE_MODELS";
const char * DebugMultiphaseSystemProperties::MASS_DENSITY = "MASS_DENSITY";
const char * DebugMultiphaseSystemProperties::MOLE_DENSITY = "MOLE_DENSITY";
const char * DebugMultiphaseSystemProperties::MOLE_COMPOSITION = "MOLE_COMPOSITION";
const char * DebugMultiphaseSystemProperties::MOLECULAR_WEIGHT = "MOLECULAR_WEIGHT";

void Dump( const Flash * flash,
           const MultiphaseSystemProperties & multiphaseProperties,
           double pressure,
           double temperature,
           std::vector< double > feed )
{
  if( const CompositionalFlash * f = dynamic_cast<const CompositionalFlash *>( flash ) )
  {
    const DebugComponentProperties dbgComp = DebugComponentProperties( f->getComponentProperties() );
    dbgComp.print();
    const DebugMultiphaseSystemProperties dbgProps = DebugMultiphaseSystemProperties( multiphaseProperties );
    dbgProps.print();
    json output{ { "pressure", pressure },
                 { "temperature", temperature },
                 { "feed", feed } };
    std::cout << output << std::endl ;
  }
}

} // enf of namespace PVTPackage