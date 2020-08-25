// This include is necessary for nlohmann::json to find the proper serializers
#include "SerializersDeserializers.hpp"

#include "MultiphaseSystem/PhaseModel/CubicEOS/CubicEoSPhaseModel.hpp"

#include "DebugComponentProperties.hpp"

#include <nlohmann/json.hpp>

#include <iostream>
#include <limits>

namespace PVTPackage
{

void Dump( const Flash * flash,
           const MultiphaseSystemProperties & multiphaseProperties )
{
  if( const CompositionalFlash * f = dynamic_cast<const CompositionalFlash *>( flash ) )
  {
    // FIXME the phase models already hold component properties: is it mandatory?
    nlohmann::json compJson{ { "COMP", f->getComponentProperties() } };

    std::cout << std::setprecision( std::numeric_limits< double >::max_digits10 )
              << compJson << std::endl;

    nlohmann::json propsJson{ { "PROPERTIES", multiphaseProperties } };

    std::cout << std::setprecision( std::numeric_limits< double >::max_digits10 )
              << propsJson << std::endl;
  }
}

} // enf of namespace PVTPackage
