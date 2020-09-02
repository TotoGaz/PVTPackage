#include "refactor/deserializers/PhaseProperties.hpp"

#include "refactor/JsonKeys.hpp"

#include "refactor/passiveDataStructures/PhaseProperties.hpp"
#include "refactor/passiveDataStructures/PropertyAndDerivatives.hpp"

#include "refactor/deserializers/PropertyAndDerivatives.hpp"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace PVTPackage {
namespace pds {

void from_json( const json & j,
                pds::PhaseProperties & phaseProperties )
{
  j.at(PhasePropertiesHelper::MOLECULAR_WEIGHT).get_to(phaseProperties.MolecularWeight);
  j.at(PhasePropertiesHelper::COMPRESSIBILITY_FACTOR).get_to(phaseProperties.CompressibilityFactor);
  j.at(PhasePropertiesHelper::MOLE_COMPOSITION).get_to(phaseProperties.MoleComposition);
  j.at(PhasePropertiesHelper::LN_FUGACITY_COEFFICIENTS).get_to(phaseProperties.LnFugacityCoefficients);
  j.at(PhasePropertiesHelper::MOLE_DENSITY).get_to(phaseProperties.MoleDensity);
  j.at(PhasePropertiesHelper::MASS_DENSITY).get_to(phaseProperties.MassDensity);
  j.at(PhasePropertiesHelper::VISCOSITY).get_to(phaseProperties.Viscosity);
  j.at(PhasePropertiesHelper::MASS_ENTHALPY).get_to(phaseProperties.MassEnthalpy);
  j.at(PhasePropertiesHelper::COMPRESSIBILITY).get_to(phaseProperties.Compressibility);
}

} // end of namespace pds
} // end of namespace PVTPackage
