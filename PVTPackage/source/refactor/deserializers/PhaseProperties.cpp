#include "refactor/deserializers/PhaseProperties.hpp"

#include "refactor/JsonKeys.hpp"

#include "refactor/passiveDataStructures/PhaseProperties.hpp"
#include "refactor/passiveDataStructures/PropertyAndDerivatives.hpp"

#include "refactor/deserializers/PropertyAndDerivatives.hpp"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace PVTPackage {
namespace refactor {
namespace pds {

void from_json( const json & j,
                pds::PhaseProperties & phaseProperties )
{
  j.at( PhasePropertiesKeys::MOLECULAR_WEIGHT).get_to( phaseProperties.MolecularWeight);
  j.at( PhasePropertiesKeys::COMPRESSIBILITY_FACTOR).get_to( phaseProperties.CompressibilityFactor);
  j.at( PhasePropertiesKeys::MOLE_COMPOSITION).get_to( phaseProperties.MoleComposition);
  j.at( PhasePropertiesKeys::LN_FUGACITY_COEFFICIENTS).get_to( phaseProperties.LnFugacityCoefficients);
  j.at( PhasePropertiesKeys::MOLE_DENSITY).get_to( phaseProperties.MoleDensity);
  j.at( PhasePropertiesKeys::MASS_DENSITY).get_to( phaseProperties.MassDensity);
  j.at( PhasePropertiesKeys::VISCOSITY).get_to( phaseProperties.Viscosity);
  j.at( PhasePropertiesKeys::MASS_ENTHALPY).get_to( phaseProperties.MassEnthalpy);
  j.at( PhasePropertiesKeys::COMPRESSIBILITY).get_to( phaseProperties.Compressibility);
}

} // end of namespace refactor
} // end of namespace pds
} // end of namespace PVTPackage
