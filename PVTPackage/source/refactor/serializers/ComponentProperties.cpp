#include "ComponentProperties.hpp"

#include "MultiphaseSystem/ComponentProperties.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {

using json = nlohmann::json;

void ComponentPropertiesHelper::to_json( json & j,
                                         const ComponentProperties & properties )
{
  j = json{ { N_COMPONENTS, properties.NComponents },
            { LABELS,       properties.Label },
            { MW,           properties.Mw },
            { TC,           properties.Tc },
            { PC,           properties.Pc },
            { OMEGA,        properties.Omega },
            { WATER_INDEX,  properties.WaterIndex } };
}

void ComponentPropertiesHelper::from_json( const json & j, pds::ComponentProperties & p )
{
  j.at( N_COMPONENTS ).get_to( p.NComponents );
  j.at( LABELS ).get_to( p.Label );
  j.at( MW ).get_to( p.Mw );
  j.at( PC ).get_to( p.Pc );
  j.at( TC ).get_to( p.Tc );
  j.at( OMEGA ).get_to( p.Omega );
  j.at( WATER_INDEX ).get_to( p.WaterIndex );
}

decltype( ComponentPropertiesHelper::N_COMPONENTS ) ComponentPropertiesHelper::N_COMPONENTS;
decltype( ComponentPropertiesHelper::LABELS ) ComponentPropertiesHelper::LABELS;
decltype( ComponentPropertiesHelper::MW ) ComponentPropertiesHelper::MW;
decltype( ComponentPropertiesHelper::TC ) ComponentPropertiesHelper::TC;
decltype( ComponentPropertiesHelper::PC ) ComponentPropertiesHelper::PC;
decltype( ComponentPropertiesHelper::OMEGA ) ComponentPropertiesHelper::OMEGA;
decltype( ComponentPropertiesHelper::WATER_INDEX ) ComponentPropertiesHelper::WATER_INDEX;

void to_json( nlohmann::json & j,
              const ComponentProperties & p )
{
  ComponentPropertiesHelper::to_json( j, p );
}

namespace pds
{

void from_json( const nlohmann::json & j, pds::ComponentProperties & p )
{
  ComponentPropertiesHelper::from_json( j, p );
}

}

} // namespace PVTPackage
