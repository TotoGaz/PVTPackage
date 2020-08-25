#ifndef GEOSX_DEBUGCOMPONENTPROPERTIES_HPP
#define GEOSX_DEBUGCOMPONENTPROPERTIES_HPP

#include "MultiphaseSystem/ComponentProperties.hpp"
#include "MultiphaseSystem/MultiphaseSystemProperties.hpp"

#include <vector>
#include <string>

namespace PVTPackage
{

void Dump( const Flash * flash,
           const MultiphaseSystemProperties & multiphaseProperties );

} // end of namespace PVTPackage

#endif //GEOSX_DEBUGCOMPONENTPROPERTIES_HPP
