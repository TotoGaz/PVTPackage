#ifndef GEOSX_PVTPACKAGE_DEBUGCOMPONENTPROPERTIES_HPP
#define GEOSX_PVTPACKAGE_DEBUGCOMPONENTPROPERTIES_HPP

#include "MultiphaseSystem/MultiphaseSystemProperties.hpp"
#include "MultiphaseSystem/PhaseSplitModel/Flash.hpp"

namespace PVTPackage
{

void Dump( const Flash * flash,
           const MultiphaseSystemProperties & multiphaseProperties );

} // end of namespace PVTPackage

#endif //GEOSX_PVTPACKAGE_DEBUGCOMPONENTPROPERTIES_HPP
