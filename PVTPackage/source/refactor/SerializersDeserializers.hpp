#ifndef GEOSX_PVTPACKAGE_SERIALIZERSDESERIALIZERS_HPP
#define GEOSX_PVTPACKAGE_SERIALIZERSDESERIALIZERS_HPP

#include "MultiphaseSystem/PhaseModel/CubicEOS/CubicEoSPhaseModel.hpp"

#include "MultiphaseSystem/ComponentProperties.hpp"
#include "MultiphaseSystem/MultiphaseSystemProperties.hpp"

#include <nlohmann/json.hpp>

#include <memory>


namespace nlohmann
{

template< typename T >
struct adl_serializer< std::shared_ptr< T > >
{
static void to_json( nlohmann::json & j, const std::shared_ptr< T > & opt )
{
  if( opt.get() )
  {
    j = *opt;
  }
  else
  {
    j = nullptr;
  }
}
};

}

// FIXME ComponentProperties is not part of PVTPackage namespace...
void to_json( nlohmann::json & j, const ComponentProperties & properties );

namespace PVTPackage
{

std::string phaseType2string( const PHASE_TYPE & phaseType );
std::string eos2string( const EOS_TYPE & eos );

void to_json( nlohmann::json & j, const ScalarPropertyAndDerivatives< double > & s );
void to_json( nlohmann::json & j, const VectorPropertyAndDerivatives< double > & v );
void to_json( nlohmann::json & j, const CubicEoSPhaseModel & model );
void to_json( nlohmann::json & j, const MultiphaseSystemProperties & props );

}

#endif //GEOSX_PVTPACKAGE_SERIALIZERSDESERIALIZERS_HPP
