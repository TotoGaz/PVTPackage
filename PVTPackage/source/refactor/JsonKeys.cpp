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

decltype( ComponentPropertiesKeys::N_COMPONENTS ) ComponentPropertiesKeys::N_COMPONENTS;
decltype( ComponentPropertiesKeys::LABELS ) ComponentPropertiesKeys::LABELS;
decltype( ComponentPropertiesKeys::MW ) ComponentPropertiesKeys::MW;
decltype( ComponentPropertiesKeys::TC ) ComponentPropertiesKeys::TC;
decltype( ComponentPropertiesKeys::PC ) ComponentPropertiesKeys::PC;
decltype( ComponentPropertiesKeys::OMEGA ) ComponentPropertiesKeys::OMEGA;
decltype( ComponentPropertiesKeys::WATER_INDEX ) ComponentPropertiesKeys::WATER_INDEX;

decltype( PhaseModelsKeys::EOS ) PhaseModelsKeys::EOS;
decltype( PhaseModelsKeys::PHASE_TYPE_ ) PhaseModelsKeys::PHASE_TYPE_;
decltype( PhaseModelsKeys::COMPONENT_PROPERTIES ) PhaseModelsKeys::COMPONENT_PROPERTIES;

decltype( MultiphaseSystemPropertiesKeys::TEMPERATURE ) MultiphaseSystemPropertiesKeys::TEMPERATURE;
decltype( MultiphaseSystemPropertiesKeys::PRESSURE ) MultiphaseSystemPropertiesKeys::PRESSURE;
decltype( MultiphaseSystemPropertiesKeys::FEED ) MultiphaseSystemPropertiesKeys::FEED;
decltype( MultiphaseSystemPropertiesKeys::PHASE_STATE ) MultiphaseSystemPropertiesKeys::PHASE_STATE;
decltype( MultiphaseSystemPropertiesKeys::PHASE_TYPES ) MultiphaseSystemPropertiesKeys::PHASE_TYPES;
decltype( MultiphaseSystemPropertiesKeys::PHASE_MODELS ) MultiphaseSystemPropertiesKeys::PHASE_MODELS;
decltype( MultiphaseSystemPropertiesKeys::PHASE_MOLE_FRACTION ) MultiphaseSystemPropertiesKeys::PHASE_MOLE_FRACTION;
decltype( MultiphaseSystemPropertiesKeys::PHASE_PROPERTIES ) MultiphaseSystemPropertiesKeys::PHASE_PROPERTIES;

} // end of namespace PVTPackage
