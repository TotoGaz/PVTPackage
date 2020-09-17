#ifndef GEOSX_FLASH_HPP
#define GEOSX_FLASH_HPP

#include "refactor/passiveDataStructures/ComponentProperties.hpp"

namespace PVTPackage
{
namespace refactor
{
namespace pds
{

struct BlackOilFlash
{

};

struct DeadOilFlash
{

};

struct CompositionalFlash
{
  pds::ComponentProperties componentsProperties;
};

struct FreeWaterFlash: public CompositionalFlash
{
  size_t waterIndex;
};

struct NegativeTwoPhaseFlash: public CompositionalFlash
{

};

struct TrivialFlash: public CompositionalFlash
{

};

} // end of namespace pds
} // end of namespace refactor
} // end of namespace PVTPackage

#endif //GEOSX_FLASH_HPP
