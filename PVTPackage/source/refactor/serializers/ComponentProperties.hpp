#ifndef PVTPACKAGE_COMPONENTPROPERTIES_HPP
#define PVTPACKAGE_COMPONENTPROPERTIES_HPP

#include "MultiphaseSystem/ComponentProperties.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {

class ComponentPropertiesHelper
{
public:
  static void to_json( nlohmann::json & j,
                       const ComponentProperties & properties ) ;
  static ComponentProperties from_json( const nlohmann::json & j );

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

namespace nlohmann
{

template<>
struct adl_serializer< PVTPackage::ComponentProperties >
{
  static PVTPackage::ComponentProperties from_json( const json & j )
  {
    return PVTPackage::ComponentPropertiesHelper::from_json( j );
  }

  static void to_json( json & j,
                       const PVTPackage::ComponentProperties & p )
  {
    PVTPackage::ComponentPropertiesHelper::to_json( j, p );
  }
};

}

#endif //PVTPACKAGE_COMPONENTPROPERTIES_HPP
