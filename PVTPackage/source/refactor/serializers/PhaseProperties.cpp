#include "PhaseProperties.hpp"

#include "refactor/passiveDataStructures/PropertyAndDerivatives.hpp"
#include "refactor/serializers/PropertyAndDerivatives.hpp"
#include "refactor/deserializers/PropertyAndDerivatives.hpp"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace PVTPackage
{

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
                         pds::PhaseProperties & phaseProperties )
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

namespace pds
{

void from_json( const json & j,
                pds::PhaseProperties & phaseProperties )
{
  PhasePropertiesHelper::from_json( j, phaseProperties );
}

}

}