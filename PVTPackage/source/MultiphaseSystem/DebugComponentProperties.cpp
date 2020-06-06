#include "DebugComponentProperties.hpp"

#include <nlohmann/json.hpp>

#include <iostream>
#include <limits>

// for convenience
using json = nlohmann::json;

namespace PVTPackage
{

const char * DebugComponentProperties::N_COMPONENTS = "n_components";
const char * DebugComponentProperties::LABELS = "labels";
const char * DebugComponentProperties::MW = "mw";
const char * DebugComponentProperties::TC = "tc";
const char * DebugComponentProperties::PC = "pc";
const char * DebugComponentProperties::OMEGA = "omega";

void DebugComponentProperties::print() const
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

void to_json( json & j,
              const ScalarPropertyAndDerivatives< double > & p )
{
  // TODO use constants
  j = json{ { "value", p.value },
            { "dP",    p.dP },
            { "dT",    p.dT },
            { "dz",    p.dz } };
}

void to_json( json & j,
              const VectorPropertyAndDerivatives< double > & p )
{
  // TODO use constants
  j = json{ { "value", p.value },
            { "dP",    p.dP },
            { "dT",    p.dT },
            { "dz",    p.dz } };
}

const char * DebugMultiphaseSystemProperties::PHASE_MOLE_FRACTION = "PHASE_MOLE_FRACTION";
const char * DebugMultiphaseSystemProperties::MASS_DENSITY = "MASS_DENSITY";
const char * DebugMultiphaseSystemProperties::MOLE_DENSITY = "MOLE_DENSITY";
const char * DebugMultiphaseSystemProperties::MOLE_COMPOSITION = "MOLE_COMPOSITION";
const char * DebugMultiphaseSystemProperties::MOLECULAR_WEIGHT = "MOLECULAR_WEIGHT";

void DebugMultiphaseSystemProperties::print() const
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

  std::cout << std::setprecision( std::numeric_limits< double >::max_digits10 )
            << output << std::endl;
}

} // enf of namespace PVTPackage