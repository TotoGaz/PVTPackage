#ifndef GEOSX_REFACTOR_DESERIALIZERS_FLASH_HPP
#define GEOSX_REFACTOR_DESERIALIZERS_FLASH_HPP

#include "refactor/passiveDataStructures/Flash.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage
{
namespace refactor
{
namespace pds
{

void from_json( const nlohmann::json & j,
                pds::BlackOilFlash & flash );

void from_json( const nlohmann::json & j,
                pds::DeadOilFlash & flash );

void from_json( const nlohmann::json & j,
                pds::FreeWaterFlash & flash );

void from_json( const nlohmann::json & j,
                pds::NegativeTwoPhaseFlash & flash );

void from_json( const nlohmann::json & j,
                pds::TrivialFlash & flash );


} // end of namespace pds
} // end of namespace refactor
} // end of namespace PVTPackage



#endif //GEOSX_REFACTOR_DESERIALIZERS_FLASH_HPP
