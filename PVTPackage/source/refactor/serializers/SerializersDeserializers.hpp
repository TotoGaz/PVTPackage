#ifndef PVTPACKAGE_SERIALIZERSDESERIALIZERS_HPP
#define PVTPACKAGE_SERIALIZERSDESERIALIZERS_HPP

#include "MultiphaseSystem/MultiphaseSystemProperties.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage
{

void to_json( nlohmann::json & j, const MultiphaseSystemProperties & props );
void from_json( const nlohmann::json & j, MultiphaseSystemProperties & props );

}

#endif //PVTPACKAGE_SERIALIZERSDESERIALIZERS_HPP
