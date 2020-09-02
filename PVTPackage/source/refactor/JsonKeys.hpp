#ifndef GEOSX_JSONKEYS_HPP
#define GEOSX_JSONKEYS_HPP

namespace PVTPackage
{

struct ScalarVectorPropertyAndDerivativesHelper
{
  static constexpr auto VALUE = "value";
  static constexpr auto DP = "dP";
  static constexpr auto DT = "dT";
  static constexpr auto DZ = "dz";
};

struct PhasePropertiesHelper
{
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

struct EnumKeys
{
  static constexpr auto PHASE_STATE_UNKNOWN = "UNKNOWN";
  static constexpr auto PHASE_STATE_GAS = "GAS";
  static constexpr auto PHASE_STATE_OIL = "OIL";
  static constexpr auto PHASE_STATE_WATER = "WATER";
  static constexpr auto PHASE_STATE_OIL_GAS = "OIL_GAS";
  static constexpr auto PHASE_STATE_GAS_WATER = "GAS_WATER";
  static constexpr auto PHASE_STATE_OIL_WATER = "OIL_WATER";
  static constexpr auto PHASE_STATE_OIL_GAS_WATER = "OIL_GAS_WATER";

  static constexpr auto PHASE_TYPE_UNKNOWN = "UNKNOWN";
  static constexpr auto PHASE_TYPE_LIQUID_WATER_RICH = "LIQUID_WATER_RICH";
  static constexpr auto PHASE_TYPE_OIL = "OIL";
  static constexpr auto PHASE_TYPE_GAS = "GAS";

  static constexpr auto EOS_TYPE_UNKNOWN = "UNKNOWN";
  static constexpr auto EOS_TYPE_REDLICH_KWONG_SOAVE = "REDLICH_KWONG_SOAVE";
  static constexpr auto EOS_TYPE_PENG_ROBINSON = "PENG_ROBINSON";
};

struct ComponentPropertiesKeys
{
  static constexpr auto N_COMPONENTS = "n_components";
  static constexpr auto LABELS = "labels";
  static constexpr auto MW = "mw";
  static constexpr auto TC = "tc";
  static constexpr auto PC = "pc";
  static constexpr auto OMEGA = "omega";
  static constexpr auto WATER_INDEX = "WATER_INDEX";
};

} // end of namespace PVTPackage

#endif //GEOSX_JSONKEYS_HPP
