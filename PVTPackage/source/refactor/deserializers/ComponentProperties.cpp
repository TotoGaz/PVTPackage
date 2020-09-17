#include "refactor/JsonKeys.hpp"

#include "refactor/deserializers/ComponentProperties.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage
{
namespace refactor
{
namespace pds
{

void from_json( const nlohmann::json & j, pds::ComponentProperties & p )
{
  j.at( ComponentPropertiesKeys::N_COMPONENTS ).get_to( p.NComponents );
  j.at( ComponentPropertiesKeys::LABELS ).get_to( p.Label );
  j.at( ComponentPropertiesKeys::MW ).get_to( p.Mw );
  j.at( ComponentPropertiesKeys::PC ).get_to( p.Pc );
  j.at( ComponentPropertiesKeys::TC ).get_to( p.Tc );
  j.at( ComponentPropertiesKeys::OMEGA ).get_to( p.Omega );
  j.at( ComponentPropertiesKeys::WATER_INDEX ).get_to( p.WaterIndex );}

} // end of namespace pds
} // end of namespace refactor
} // end of namespace PVTPackage
