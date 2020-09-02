#ifndef PVTPACKAGE_DESERIALIZERS_COMPONENTPROPERTIES_HPP
#define PVTPACKAGE_DESERIALIZERS_COMPONENTPROPERTIES_HPP

#include "refactor/passiveDataStructures/ComponentProperties.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage
{
namespace pds
{

void from_json( const nlohmann::json & j, pds::ComponentProperties & p );

} // end of namespace PVTPackage
} // end of namespace PVTPackage

#endif //PVTPACKAGE_DESERIALIZERS_COMPONENTPROPERTIES_HPP
