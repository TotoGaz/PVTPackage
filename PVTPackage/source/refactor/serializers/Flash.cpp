#include "Flash.hpp"

#include "MultiphaseSystem/PhaseSplitModel/BlackOilFlash.hpp"
#include "MultiphaseSystem/PhaseSplitModel/DeadOilFlash.hpp"
#include "MultiphaseSystem/PhaseSplitModel/FreeWaterFlash.hpp"
#include "MultiphaseSystem/PhaseSplitModel/NegativeTwoPhaseFlash.hpp"
#include "MultiphaseSystem/PhaseSplitModel/TrivialFlash.hpp"

#include "refactor/serializers/PVTEnums.hpp"
#include "refactor/serializers/ComponentProperties.hpp"
#include "refactor/JsonKeys.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage
{

using json = nlohmann::json;

void to_json( nlohmann::json & j,
              const BlackOilFlash & flash )
{
  (void) flash;
  j = json{};
}

void to_json( nlohmann::json & j,
              const DeadOilFlash & flash )
{
  (void) flash;
  j = json{};
}

void to_json( nlohmann::json & j,
              const FreeWaterFlash & flash )
{
  j = json{
    { refactor::CompositionalFlashKeys::COMPONENT_PROPERTIES, flash.getComponentProperties() },
    { refactor::FreeWaterFlashKeys::WATER_INDEX,              flash.getWaterIndex() }
  };
}

void to_json( nlohmann::json & j,
              const NegativeTwoPhaseFlash & flash )
{
  j = json{
    { refactor::CompositionalFlashKeys::COMPONENT_PROPERTIES, flash.getComponentProperties() }
  };
}

void to_json( nlohmann::json & j,
              const TrivialFlash & flash )
{
  j = json{
    { refactor::CompositionalFlashKeys::COMPONENT_PROPERTIES, flash.getComponentProperties() }
  };
}

void to_json( nlohmann::json & j,
              const Flash & flash )
{
  if( const BlackOilFlash * f = dynamic_cast<const BlackOilFlash *>( &flash ) )
  {
    j = json{
      { refactor::FlashKeys::TYPE,  FLASH_TYPE::BLACK_OIL },
      { refactor::FlashKeys::VALUE, *f }
    };

    return ;
  }

  if( const DeadOilFlash * f = dynamic_cast<const DeadOilFlash *>( &flash ) )
  {
    j = json{
      { refactor::FlashKeys::TYPE,  FLASH_TYPE::DEAD_OIL },
      { refactor::FlashKeys::VALUE, *f }
    };

    return ;
  }

  if( const FreeWaterFlash * f = dynamic_cast<const FreeWaterFlash *>( &flash ) )
  {
    j = json{
      { refactor::FlashKeys::TYPE,  FLASH_TYPE::FREE_WATER },
      { refactor::FlashKeys::VALUE, *f }
    };

    return ;
  }

  if( const NegativeTwoPhaseFlash * f = dynamic_cast<const NegativeTwoPhaseFlash *>( &flash ) )
  {
    j = json{
      { refactor::FlashKeys::TYPE,  FLASH_TYPE::NEGATIVE_TWO_PHASE },
      { refactor::FlashKeys::VALUE, *f }
    };

    return ;
  }

  if( const TrivialFlash * f = dynamic_cast<const TrivialFlash *>( &flash ) )
  {
    j = json{
      { refactor::FlashKeys::TYPE,  FLASH_TYPE::TRIVIAL },
      { refactor::FlashKeys::VALUE, *f }
    };

    return ;
  }

  std::cerr << "REFACTOR - Not supported Flash, in void to_json( nlohmann::json & j, const Flash & flash )" << std::endl;
}

}