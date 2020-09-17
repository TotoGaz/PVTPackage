#ifndef PVTPACKAGE_SERIALIZERS_FLASH_HPP
#define PVTPACKAGE_SERIALIZERS_FLASH_HPP

#include "MultiphaseSystem/PhaseSplitModel/Flash.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage
{

void to_json( nlohmann::json & j,
              const Flash & flash );

}

#endif //PVTPACKAGE_SERIALIZERS_FLASH_HPP
