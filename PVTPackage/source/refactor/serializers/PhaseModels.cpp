#include "PhaseModels.hpp"

#include "refactor/JsonKeys.hpp"

#include "refactor/serializers/PVTEnums.hpp"
#include "refactor/serializers/ComponentProperties.hpp"

#include "refactor/serializers/BlackOilModels.hpp"
#include "refactor/serializers/DeadOilPhaseModel.hpp"

#include "MultiphaseSystem/PhaseModel/CubicEOS/CubicEoSPhaseModel.hpp"
#include "MultiphaseSystem/PhaseModel/BlackOil/BlackOil_GasModel.hpp"
#include "MultiphaseSystem/PhaseModel/BlackOil/BlackOil_OilModel.hpp"
#include "MultiphaseSystem/PhaseModel/BlackOil/BlackOil_WaterModel.hpp"
#include "MultiphaseSystem/PhaseModel/BlackOil/DeadOil_PhaseModel.hpp"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace PVTPackage
{

void to_json( json & j,
              const CubicEoSPhaseModel & model )
{
  j = json{ { CubeEoSPhaseModelsKeys::EOS,                  model.getEosType() },
            { CubeEoSPhaseModelsKeys::PHASE_TYPE_,          model.getPhaseType() },
            { CubeEoSPhaseModelsKeys::COMPONENT_PROPERTIES, model.get_ComponentsProperties() } };
}

void to_json( json & j,
              const PhaseModel & model )
{
  if( const auto * m = dynamic_cast<const CubicEoSPhaseModel *>( &model ) )
  {
    j = json{
      { PhaseModelKeys::TYPE,  PHASE_MODEL_TYPE::CUBE_EOS },
      { PhaseModelKeys::VALUE, *m }
    };

    return;
  }

  if( const auto * m = dynamic_cast<const BlackOil_GasModel *>( &model ) )
  {
    j = json{
      { PhaseModelKeys::TYPE,  PHASE_MODEL_TYPE::BLACK_OIL_GAS },
      { PhaseModelKeys::VALUE, *m }
    };

    return;
  }

  if( const auto * m = dynamic_cast<const BlackOil_OilModel *>( &model ) )
  {
    j = json{
      { PhaseModelKeys::TYPE,  PHASE_MODEL_TYPE::BLACK_OIL_OIL },
      { PhaseModelKeys::VALUE, *m }
    };

    return;
  }

  if( const auto * m = dynamic_cast<const BlackOil_WaterModel *>( &model ) )
  {
    j = json{
      { PhaseModelKeys::TYPE,  PHASE_MODEL_TYPE::BLACK_OIL_WATER },
      { PhaseModelKeys::VALUE, *m }
    };

    return;
  }

  if( const auto * m = dynamic_cast<const DeadOil_PhaseModel *>( &model ) )
  {
    j = json{
      { PhaseModelKeys::TYPE,  PHASE_MODEL_TYPE::DEAD_OIL },
      { PhaseModelKeys::VALUE, *m }
    };

    return;
  }

  std::cerr << "REFACTOR - DeadOil_*Models not implemented, in void void to_json( nlohmann::json & j, const PhaseModel & model )" << std::endl;
}

} // namespace PVTPackage
