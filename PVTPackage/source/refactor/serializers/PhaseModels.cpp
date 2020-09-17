#include "PhaseModels.hpp"

#include "refactor/JsonKeys.hpp"

#include "refactor/serializers/PVTEnums.hpp"

#include "refactor/serializers/BlackOilModels.hpp"
#include "refactor/serializers/CubicEoSPhaseModel.hpp"
#include "refactor/serializers/DeadOilPhaseModel.hpp"

#include "MultiphaseSystem/PhaseModel/BlackOil/BlackOil_GasModel.hpp"
#include "MultiphaseSystem/PhaseModel/BlackOil/BlackOil_OilModel.hpp"
#include "MultiphaseSystem/PhaseModel/BlackOil/BlackOil_WaterModel.hpp"
#include "MultiphaseSystem/PhaseModel/CubicEOS/CubicEoSPhaseModel.hpp"
#include "MultiphaseSystem/PhaseModel/BlackOil/DeadOil_PhaseModel.hpp"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace PVTPackage
{

void to_json( json & j,
              const PhaseModel & model )
{
  if( const auto * m = dynamic_cast<const CubicEoSPhaseModel *>( &model ) )
  {
    j = json{
      { refactor::PhaseModelKeys::TYPE,  PHASE_MODEL_TYPE::CUBE_EOS },
      { refactor::PhaseModelKeys::VALUE, *m }
    };

    return;
  }

  if( const auto * m = dynamic_cast<const BlackOil_GasModel *>( &model ) )
  {
    j = json{
      { refactor::PhaseModelKeys::TYPE,  PHASE_MODEL_TYPE::BLACK_OIL_GAS },
      { refactor::PhaseModelKeys::VALUE, *m }
    };

    return;
  }

  if( const auto * m = dynamic_cast<const BlackOil_OilModel *>( &model ) )
  {
    j = json{
      { refactor::PhaseModelKeys::TYPE,  PHASE_MODEL_TYPE::BLACK_OIL_OIL },
      { refactor::PhaseModelKeys::VALUE, *m }
    };

    return;
  }

  if( const auto * m = dynamic_cast<const BlackOil_WaterModel *>( &model ) )
  {
    j = json{
      { refactor::PhaseModelKeys::TYPE,  PHASE_MODEL_TYPE::BLACK_OIL_WATER },
      { refactor::PhaseModelKeys::VALUE, *m }
    };

    return;
  }

  if( const auto * m = dynamic_cast<const DeadOil_PhaseModel *>( &model ) )
  {
    j = json{
      { refactor::PhaseModelKeys::TYPE,  PHASE_MODEL_TYPE::DEAD_OIL },
      { refactor::PhaseModelKeys::VALUE, *m }
    };

    return;
  }

  std::cerr << "REFACTOR - DeadOil_*Models not implemented, in void void to_json( nlohmann::json & j, const PhaseModel & model )" << std::endl;
}

} // namespace PVTPackage
