#ifndef PVTPACKAGE_DESERIALIZERS_MULTIPHASESYSTEMPROPERTIES_HPP
#define PVTPACKAGE_DESERIALIZERS_MULTIPHASESYSTEMPROPERTIES_HPP

#include "refactor/passiveDataStructures/MultiphaseSystemProperties.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage
{
namespace pds
{

void from_json( const nlohmann::json & j,
                pds::MultiphaseSystemProperties & props );

} // end of namespace pds
} // end of namespace PVTPackage

#endif // PVTPACKAGE_DESERIALIZERS_MULTIPHASESYSTEMPROPERTIES_HPP
