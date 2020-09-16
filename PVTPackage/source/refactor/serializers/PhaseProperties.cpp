#include "PhaseProperties.hpp"

#include "refactor/JsonKeys.hpp"

#include "refactor/serializers/PropertyAndDerivatives.hpp"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace PVTPackage
{

void to_json( json & j,
              const PhaseProperties & phaseProperties )
{
  j = json{
    { PhasePropertiesHelper::MOLECULAR_WEIGHT,         phaseProperties.MolecularWeight },
    { PhasePropertiesHelper::COMPRESSIBILITY_FACTOR,   phaseProperties.CompressibilityFactor },
    { PhasePropertiesHelper::MOLE_COMPOSITION,         phaseProperties.MoleComposition },
    { PhasePropertiesHelper::LN_FUGACITY_COEFFICIENTS, phaseProperties.LnFugacityCoefficients },
    { PhasePropertiesHelper::MOLE_DENSITY,             phaseProperties.MoleDensity },
    { PhasePropertiesHelper::MASS_DENSITY,             phaseProperties.MassDensity },
    { PhasePropertiesHelper::VISCOSITY,                phaseProperties.Viscosity },
    { PhasePropertiesHelper::MASS_ENTHALPY,            phaseProperties.MassEnthalpy },
    { PhasePropertiesHelper::COMPRESSIBILITY,          phaseProperties.Compressibility }
  };
}

} // end of namespace PVTPackage
