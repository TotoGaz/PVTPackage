// This include is necessary for nlohmann::json to find the proper serializers
#include "refactor/serializers/MultiphaseSystemProperties.hpp"
#include "refactor/serializers/Flash.hpp"

#include "DebugComponentProperties.hpp"

#include <nlohmann/json.hpp>

#include <iostream>
#include <limits>

namespace PVTPackage
{
namespace refactor
{

void Dump( const Flash * flash,
           const MultiphaseSystemProperties & multiphaseProperties )
{
  nlohmann::json propsJson{
    { "MULTIPHASE_SYSTEM_PROPERTIES", multiphaseProperties },
    { "FLASH",                        *flash }
  };

  std::cerr << std::setprecision( std::numeric_limits< double >::max_digits10 )
            << propsJson << std::endl;
}

} // enf of namespace refactor
} // enf of namespace PVTPackage
