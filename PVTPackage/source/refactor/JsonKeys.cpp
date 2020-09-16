#include "refactor/JsonKeys.hpp"

namespace PVTPackage
{

decltype( ScalarVectorPropertyAndDerivativesHelper::VALUE ) ScalarVectorPropertyAndDerivativesHelper::VALUE;
decltype( ScalarVectorPropertyAndDerivativesHelper::DP ) ScalarVectorPropertyAndDerivativesHelper::DP;
decltype( ScalarVectorPropertyAndDerivativesHelper::DT ) ScalarVectorPropertyAndDerivativesHelper::DT;
decltype( ScalarVectorPropertyAndDerivativesHelper::DZ ) ScalarVectorPropertyAndDerivativesHelper::DZ;

decltype( PhasePropertiesHelper::MOLECULAR_WEIGHT ) PhasePropertiesHelper::MOLECULAR_WEIGHT;
decltype( PhasePropertiesHelper::COMPRESSIBILITY_FACTOR ) PhasePropertiesHelper::COMPRESSIBILITY_FACTOR;
decltype( PhasePropertiesHelper::MOLE_COMPOSITION ) PhasePropertiesHelper::MOLE_COMPOSITION;
decltype( PhasePropertiesHelper::LN_FUGACITY_COEFFICIENTS ) PhasePropertiesHelper::LN_FUGACITY_COEFFICIENTS;
decltype( PhasePropertiesHelper::MOLE_DENSITY ) PhasePropertiesHelper::MOLE_DENSITY;
decltype( PhasePropertiesHelper::MASS_DENSITY) PhasePropertiesHelper::MASS_DENSITY;
decltype( PhasePropertiesHelper::VISCOSITY ) PhasePropertiesHelper::VISCOSITY;
decltype( PhasePropertiesHelper::MASS_ENTHALPY ) PhasePropertiesHelper::MASS_ENTHALPY;
decltype( PhasePropertiesHelper::COMPRESSIBILITY ) PhasePropertiesHelper::COMPRESSIBILITY;

decltype( EnumKeys::PHASE_STATE_UNKNOWN ) EnumKeys::PHASE_STATE_UNKNOWN;
decltype( EnumKeys::PHASE_STATE_GAS ) EnumKeys::PHASE_STATE_GAS;
decltype( EnumKeys::PHASE_STATE_OIL ) EnumKeys::PHASE_STATE_OIL;
decltype( EnumKeys::PHASE_STATE_WATER ) EnumKeys::PHASE_STATE_WATER;
decltype( EnumKeys::PHASE_STATE_OIL_GAS ) EnumKeys::PHASE_STATE_OIL_GAS;
decltype( EnumKeys::PHASE_STATE_GAS_WATER ) EnumKeys::PHASE_STATE_GAS_WATER;
decltype( EnumKeys::PHASE_STATE_OIL_WATER ) EnumKeys::PHASE_STATE_OIL_WATER;
decltype( EnumKeys::PHASE_STATE_OIL_GAS_WATER ) EnumKeys::PHASE_STATE_OIL_GAS_WATER;

decltype( EnumKeys::PHASE_TYPE_UNKNOWN ) EnumKeys::PHASE_TYPE_UNKNOWN;
decltype( EnumKeys::PHASE_TYPE_LIQUID_WATER_RICH ) EnumKeys::PHASE_TYPE_LIQUID_WATER_RICH;
decltype( EnumKeys::PHASE_TYPE_OIL ) EnumKeys::PHASE_TYPE_OIL;
decltype( EnumKeys::PHASE_TYPE_GAS ) EnumKeys::PHASE_TYPE_GAS;

decltype( EnumKeys::EOS_TYPE_UNKNOWN ) EnumKeys::EOS_TYPE_UNKNOWN;
decltype( EnumKeys::EOS_TYPE_REDLICH_KWONG_SOAVE ) EnumKeys::EOS_TYPE_REDLICH_KWONG_SOAVE;
decltype( EnumKeys::EOS_TYPE_PENG_ROBINSON ) EnumKeys::EOS_TYPE_PENG_ROBINSON;

decltype( EnumKeys::PHASE_MODEL_TYPE_CUBE_EOS ) EnumKeys::PHASE_MODEL_TYPE_CUBE_EOS;
decltype( EnumKeys::PHASE_MODEL_TYPE_BLACK_OIL_GAS ) EnumKeys::PHASE_MODEL_TYPE_BLACK_OIL_GAS;
decltype( EnumKeys::PHASE_MODEL_TYPE_BLACK_OIL_OIL ) EnumKeys::PHASE_MODEL_TYPE_BLACK_OIL_OIL;
decltype( EnumKeys::PHASE_MODEL_TYPE_BLACK_OIL_WATER ) EnumKeys::PHASE_MODEL_TYPE_BLACK_OIL_WATER;

decltype( ComponentPropertiesKeys::N_COMPONENTS ) ComponentPropertiesKeys::N_COMPONENTS;
decltype( ComponentPropertiesKeys::LABELS ) ComponentPropertiesKeys::LABELS;
decltype( ComponentPropertiesKeys::MW ) ComponentPropertiesKeys::MW;
decltype( ComponentPropertiesKeys::TC ) ComponentPropertiesKeys::TC;
decltype( ComponentPropertiesKeys::PC ) ComponentPropertiesKeys::PC;
decltype( ComponentPropertiesKeys::OMEGA ) ComponentPropertiesKeys::OMEGA;
decltype( ComponentPropertiesKeys::WATER_INDEX ) ComponentPropertiesKeys::WATER_INDEX;

decltype( CubeEoSPhaseModelsKeys::EOS ) CubeEoSPhaseModelsKeys::EOS;
decltype( CubeEoSPhaseModelsKeys::PHASE_TYPE_ ) CubeEoSPhaseModelsKeys::PHASE_TYPE_;
decltype( CubeEoSPhaseModelsKeys::COMPONENT_PROPERTIES ) CubeEoSPhaseModelsKeys::COMPONENT_PROPERTIES;

decltype( MultiphaseSystemPropertiesKeys::TEMPERATURE ) MultiphaseSystemPropertiesKeys::TEMPERATURE;
decltype( MultiphaseSystemPropertiesKeys::PRESSURE ) MultiphaseSystemPropertiesKeys::PRESSURE;
decltype( MultiphaseSystemPropertiesKeys::FEED ) MultiphaseSystemPropertiesKeys::FEED;
decltype( MultiphaseSystemPropertiesKeys::PHASE_STATE ) MultiphaseSystemPropertiesKeys::PHASE_STATE;
decltype( MultiphaseSystemPropertiesKeys::PHASE_TYPES ) MultiphaseSystemPropertiesKeys::PHASE_TYPES;
decltype( MultiphaseSystemPropertiesKeys::PHASE_MODELS ) MultiphaseSystemPropertiesKeys::PHASE_MODELS;
decltype( MultiphaseSystemPropertiesKeys::PHASE_MOLE_FRACTION ) MultiphaseSystemPropertiesKeys::PHASE_MOLE_FRACTION;
decltype( MultiphaseSystemPropertiesKeys::PHASE_PROPERTIES ) MultiphaseSystemPropertiesKeys::PHASE_PROPERTIES;

decltype( PVTGDataKeys::RV ) PVTGDataKeys::RV;
decltype( PVTGDataKeys::DEW_PRESSURE ) PVTGDataKeys::DEW_PRESSURE;
decltype( PVTGDataKeys::N_SATURATED_POINTS ) PVTGDataKeys::N_SATURATED_POINTS;
decltype( PVTGDataKeys::SATURATED_BG ) PVTGDataKeys::SATURATED_BG;
decltype( PVTGDataKeys::SATURATED_VISCOSITY ) PVTGDataKeys::SATURATED_VISCOSITY;
decltype( PVTGDataKeys::UNDERSATURATED_RV ) PVTGDataKeys::UNDERSATURATED_RV;
decltype( PVTGDataKeys::UNDERSATURATED_BG ) PVTGDataKeys::UNDERSATURATED_BG;
decltype( PVTGDataKeys::UNDERSATURATED_VISCOSITY ) PVTGDataKeys::UNDERSATURATED_VISCOSITY;
decltype( PVTGDataKeys::MAX_RELATIVE_RV ) PVTGDataKeys::MAX_RELATIVE_RV;
decltype( PVTGDataKeys::MIN_RELATIVE_RV ) PVTGDataKeys::MIN_RELATIVE_RV;

decltype( PVTODataKeys::RS ) PVTODataKeys::RS;
decltype( PVTODataKeys::BUBBLE_PRESSURE ) PVTODataKeys::BUBBLE_PRESSURE;
decltype( PVTODataKeys::N_SATURATED_POINTS ) PVTODataKeys::N_SATURATED_POINTS;
decltype( PVTODataKeys::SATURATED_BO ) PVTODataKeys::SATURATED_BO;
decltype( PVTODataKeys::SATURATED_VISCOSITY ) PVTODataKeys::SATURATED_VISCOSITY;
decltype( PVTODataKeys::UNDERSATURATED_PRESSURE ) PVTODataKeys::UNDERSATURATED_PRESSURE;
decltype( PVTODataKeys::UNDERSATURATED_BO ) PVTODataKeys::UNDERSATURATED_BO;
decltype( PVTODataKeys::UNDERSATURATED_VISCOSITY ) PVTODataKeys::UNDERSATURATED_VISCOSITY;
decltype( PVTODataKeys::MAX_RELATIVE_PRESSURE ) PVTODataKeys::MAX_RELATIVE_PRESSURE;
decltype( PVTODataKeys::MIN_RELATIVE_PRESSURE ) PVTODataKeys::MIN_RELATIVE_PRESSURE;

decltype( PVTWDataKeys::REFERENCE_PRESSURE ) PVTWDataKeys::REFERENCE_PRESSURE;
decltype( PVTWDataKeys::BW ) PVTWDataKeys::BW;
decltype( PVTWDataKeys::COMPRESSIBILITY ) PVTWDataKeys::COMPRESSIBILITY;
decltype( PVTWDataKeys::VISCOSITY ) PVTWDataKeys::VISCOSITY;

decltype( BlackOilGasModelKeys::PVTG_DATA ) BlackOilGasModelKeys::PVTG_DATA;
decltype( BlackOilGasModelKeys::MIN_PRESSURE ) BlackOilGasModelKeys::MIN_PRESSURE;
decltype( BlackOilGasModelKeys::MAX_PRESSURE ) BlackOilGasModelKeys::MAX_PRESSURE;
decltype( BlackOilGasModelKeys::SURFACE_MASS_DENSITY ) BlackOilGasModelKeys::SURFACE_MASS_DENSITY;
decltype( BlackOilGasModelKeys::SURFACE_MOLE_DENSITY ) BlackOilGasModelKeys::SURFACE_MOLE_DENSITY;
decltype( BlackOilGasModelKeys::SURFACE_MOLECULAR_WEIGHT ) BlackOilGasModelKeys::SURFACE_MOLECULAR_WEIGHT;

decltype( BlackOilOilModelKeys::PVTO_DATA ) BlackOilOilModelKeys::PVTO_DATA;
decltype( BlackOilOilModelKeys::MIN_PRESSURE ) BlackOilOilModelKeys::MIN_PRESSURE;
decltype( BlackOilOilModelKeys::MAX_PRESSURE ) BlackOilOilModelKeys::MAX_PRESSURE;
decltype( BlackOilOilModelKeys::SURFACE_MASS_DENSITY ) BlackOilOilModelKeys::SURFACE_MASS_DENSITY;
decltype( BlackOilOilModelKeys::SURFACE_MOLE_DENSITY ) BlackOilOilModelKeys::SURFACE_MOLE_DENSITY;
decltype( BlackOilOilModelKeys::SURFACE_MOLECULAR_WEIGHT ) BlackOilOilModelKeys::SURFACE_MOLECULAR_WEIGHT;

decltype( BlackOilWaterModelKeys::PVTW_DATA ) BlackOilWaterModelKeys::PVTW_DATA;
decltype( BlackOilWaterModelKeys::SURFACE_MASS_DENSITY ) BlackOilWaterModelKeys::SURFACE_MASS_DENSITY;
decltype( BlackOilWaterModelKeys::SURFACE_MOLE_DENSITY ) BlackOilWaterModelKeys::SURFACE_MOLE_DENSITY;
decltype( BlackOilWaterModelKeys::SURFACE_MOLECULAR_WEIGHT ) BlackOilWaterModelKeys::SURFACE_MOLECULAR_WEIGHT;

decltype( PhaseModelKeys::TYPE ) PhaseModelKeys::TYPE;
decltype( PhaseModelKeys::VALUE ) PhaseModelKeys::VALUE;

} // end of namespace PVTPackage
