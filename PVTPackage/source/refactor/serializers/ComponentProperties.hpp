#ifndef PVTPACKAGE_COMPONENTPROPERTIES_HPP
#define PVTPACKAGE_COMPONENTPROPERTIES_HPP

#include "MultiphaseSystem/ComponentProperties.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage
{

void to_json( nlohmann::json & j,
              const ComponentProperties & p );

}


#endif //PVTPACKAGE_COMPONENTPROPERTIES_HPP
