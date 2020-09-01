#ifndef PVTPACKAGE_COMPONENTPROPERTIES_HPP
#define PVTPACKAGE_COMPONENTPROPERTIES_HPP

#include "refactor/passiveDataStructures/ComponentProperties.hpp"

#include "MultiphaseSystem/ComponentProperties.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {

class ComponentPropertiesHelper
{
public:
  static void to_json( nlohmann::json & j,
                       const ComponentProperties & properties ) ;
  static void from_json( const nlohmann::json & j, pds::ComponentProperties & properties );

private:
  static constexpr auto N_COMPONENTS = "n_components";
  static constexpr auto LABELS = "labels";
  static constexpr auto MW = "mw";
  static constexpr auto TC = "tc";
  static constexpr auto PC = "pc";
  static constexpr auto OMEGA = "omega";
  static constexpr auto WATER_INDEX = "WATER_INDEX";
};

}

namespace PVTPackage
{

void to_json( nlohmann::json & j,
              const ComponentProperties & p );

namespace pds
{

void from_json( const nlohmann::json & j, pds::ComponentProperties & p );

}

}


#endif //PVTPACKAGE_COMPONENTPROPERTIES_HPP
