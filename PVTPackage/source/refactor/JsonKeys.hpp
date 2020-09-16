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

  static constexpr auto PHASE_MODEL_TYPE_CUBE_EOS = "PHASE_MODEL_TYPE_CUBE_EOS";
  static constexpr auto PHASE_MODEL_TYPE_BLACK_OIL_GAS = "PHASE_MODEL_TYPE_BLACK_OIL_GAS";
  static constexpr auto PHASE_MODEL_TYPE_BLACK_OIL_OIL = "PHASE_MODEL_TYPE_BLACK_OIL_OIL";
  static constexpr auto PHASE_MODEL_TYPE_BLACK_OIL_WATER = "PHASE_MODEL_TYPE_BLACK_OIL_WATER";
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

struct CubeEoSPhaseModelsKeys
{
  static constexpr auto EOS = "EOS";
  static constexpr auto PHASE_TYPE_ = "PHASE_TYPE";
  static constexpr auto COMPONENT_PROPERTIES = "COMPONENT_PROPERTIES";
};

struct MultiphaseSystemPropertiesKeys
{
  static constexpr auto TEMPERATURE = "TEMPERATURE";
  static constexpr auto PRESSURE = "PRESSURE";
  static constexpr auto FEED = "FEED";

  static constexpr auto PHASE_STATE = "PHASE_STATE";
  static constexpr auto PHASE_TYPES = "PHASE_TYPES";

  static constexpr auto PHASE_MODELS = "PHASE_MODELS";
  static constexpr auto PHASE_MOLE_FRACTION = "PHASE_MOLE_FRACTION";
  static constexpr auto PHASE_PROPERTIES = "PHASE_PROPERTIES";
};

struct PVTGDataKeys
{
  static constexpr auto RV = "RV";
  static constexpr auto DEW_PRESSURE = "DEW_PRESSURE";

  static constexpr auto N_SATURATED_POINTS = "N_SATURATED_POINTS";
  static constexpr auto SATURATED_BG = "SATURATED_BG";
  static constexpr auto SATURATED_VISCOSITY = "SATURATED_VISCOSITY";

  static constexpr auto UNDERSATURATED_RV = "UNDERSATURATED_RV";
  static constexpr auto UNDERSATURATED_BG = "UNDERSATURATED_BG";
  static constexpr auto UNDERSATURATED_VISCOSITY = "UNDERSATURATED_VISCOSITY";

  static constexpr auto MAX_RELATIVE_RV = "MAX_RELATIVE_RV";
  static constexpr auto MIN_RELATIVE_RV = "MIN_RELATIVE_RV";
};

struct PVTODataKeys
{
  static constexpr auto RS = "RS";
  static constexpr auto BUBBLE_PRESSURE = "BUBBLE_PRESSURE";

  static constexpr auto N_SATURATED_POINTS = "N_SATURATED_POINTS";
  static constexpr auto SATURATED_BO = "SATURATED_BO";
  static constexpr auto SATURATED_VISCOSITY = "SATURATED_VISCOSITY";

  static constexpr auto UNDERSATURATED_PRESSURE = "UNDERSATURATED_PRESSURE";
  static constexpr auto UNDERSATURATED_BO = "UNDERSATURATED_BO";
  static constexpr auto UNDERSATURATED_VISCOSITY = "UNDERSATURATED_VISCOSITY";

  static constexpr auto MAX_RELATIVE_PRESSURE = "MAX_RELATIVE_PRESSURE";
  static constexpr auto MIN_RELATIVE_PRESSURE = "MIN_RELATIVE_PRESSURE";
};

struct PVTWDataKeys
{
  static constexpr auto REFERENCE_PRESSURE = "REFERENCE_PRESSURE";
  static constexpr auto BW = "BW";
  static constexpr auto COMPRESSIBILITY = "COMPRESSIBILITY";
  static constexpr auto VISCOSITY = "VISCOSITY";
};

struct BlackOilGasModelKeys
{
  static constexpr auto PVTG_DATA = "PVTG_DATA";

  static constexpr auto MIN_PRESSURE = "MIN_PRESSURE";
  static constexpr auto MAX_PRESSURE = "MAX_PRESSURE";

  static constexpr auto SURFACE_MASS_DENSITY = "SURFACE_MASS_DENSITY";
  static constexpr auto SURFACE_MOLE_DENSITY = "SURFACE_MOLE_DENSITY";
  static constexpr auto SURFACE_MOLECULAR_WEIGHT = "SURFACE_MOLECULAR_WEIGHT";
};


struct BlackOilOilModelKeys
{
  static constexpr auto PVTO_DATA = "PVTO_DATA";

  static constexpr auto MIN_PRESSURE = "MIN_PRESSURE";
  static constexpr auto MAX_PRESSURE = "MAX_PRESSURE";

  static constexpr auto SURFACE_MASS_DENSITY = "SURFACE_MASS_DENSITY";
  static constexpr auto SURFACE_MOLE_DENSITY = "SURFACE_MOLE_DENSITY";
  static constexpr auto SURFACE_MOLECULAR_WEIGHT = "SURFACE_MOLECULAR_WEIGHT";
};

struct BlackOilWaterModelKeys
{
  static constexpr auto PVTW_DATA = "PVTW_DATA";

  static constexpr auto SURFACE_MASS_DENSITY = "SURFACE_MASS_DENSITY";
  static constexpr auto SURFACE_MOLE_DENSITY = "SURFACE_MOLE_DENSITY";
  static constexpr auto SURFACE_MOLECULAR_WEIGHT = "SURFACE_MOLECULAR_WEIGHT";
};

struct PhaseModelKeys
{
  static constexpr auto TYPE = "TYPE";
  static constexpr auto VALUE = "VALUE";
};

} // end of namespace PVTPackage

#endif //GEOSX_JSONKEYS_HPP
