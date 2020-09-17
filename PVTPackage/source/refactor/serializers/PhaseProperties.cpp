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
  using namespace PVTPackage::refactor;

  j = json{
    { PhasePropertiesKeys::MOLECULAR_WEIGHT,         phaseProperties.MolecularWeight },
    { PhasePropertiesKeys::COMPRESSIBILITY_FACTOR,   phaseProperties.CompressibilityFactor },
    { PhasePropertiesKeys::MOLE_COMPOSITION,         phaseProperties.MoleComposition },
    { PhasePropertiesKeys::LN_FUGACITY_COEFFICIENTS, phaseProperties.LnFugacityCoefficients },
    { PhasePropertiesKeys::MOLE_DENSITY,             phaseProperties.MoleDensity },
    { PhasePropertiesKeys::MASS_DENSITY,             phaseProperties.MassDensity },
    { PhasePropertiesKeys::VISCOSITY,                phaseProperties.Viscosity },
    { PhasePropertiesKeys::MASS_ENTHALPY,            phaseProperties.MassEnthalpy },
    { PhasePropertiesKeys::COMPRESSIBILITY,          phaseProperties.Compressibility }
  };
}

} // end of namespace PVTPackage
