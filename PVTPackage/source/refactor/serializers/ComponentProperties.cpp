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

ComponentProperties ComponentPropertiesHelper::from_json( const json & j )
{
  const size_t NComponents = j.at( N_COMPONENTS );
  const std::vector< std::string > Label = j.at( LABELS ).get< std::vector< std::string > >();
  const std::vector< double > Mw = j.at( MW ).get< std::vector< double > >();
  const std::vector< double > Pc = j.at( PC ).get< std::vector< double > >();
  const std::vector< double > Tc = j.at( TC ).get< std::vector< double > >();
  const std::vector< double > Omega = j.at( OMEGA ).get< std::vector< double > >();
  const size_t WaterIndex = j.at( WATER_INDEX );

  ComponentProperties p( NComponents, Label, Mw, Tc, Pc, Omega );
  p.WaterIndex = WaterIndex;
  return p;
}

decltype( ComponentPropertiesHelper::N_COMPONENTS ) ComponentPropertiesHelper::N_COMPONENTS;
decltype( ComponentPropertiesHelper::LABELS ) ComponentPropertiesHelper::LABELS;
decltype( ComponentPropertiesHelper::MW ) ComponentPropertiesHelper::MW;
decltype( ComponentPropertiesHelper::TC ) ComponentPropertiesHelper::TC;
decltype( ComponentPropertiesHelper::PC ) ComponentPropertiesHelper::PC;
decltype( ComponentPropertiesHelper::OMEGA ) ComponentPropertiesHelper::OMEGA;
decltype( ComponentPropertiesHelper::WATER_INDEX ) ComponentPropertiesHelper::WATER_INDEX;

} // namespace PVTPackage
