// This include is necessary for nlohmann::json to find the proper serializers
#include "refactor/serializers/SerializersDeserializers.hpp"

#include "MultiphaseSystem/PhaseSplitModel/BlackOilFlash.hpp"
#include "MultiphaseSystem/PhaseSplitModel/DeadOilFlash.hpp"
#include "MultiphaseSystem/PhaseModel/CubicEOS/CubicEoSPhaseModel.hpp"

#include "DebugComponentProperties.hpp"

#include <nlohmann/json.hpp>

#include <iostream>
#include <limits>

namespace PVTPackage
{

// TODO REFACTOR REMOVE
/// Used to silence unused variable warnings, cuda doesn't respect casting to void.
template< typename ... ARGS >
inline constexpr
void i_g_n_o_r_e( ARGS const & ... ) {}

/// Mark an unused variable and silence compiler warnings.
#define PVT_UNUSED_VAR( ... ) i_g_n_o_r_e( __VA_ARGS__ );
// TODO REFACTOR END REMOVE

void Dump( const Flash * flash,
           const MultiphaseSystemProperties & multiphaseProperties )
{
  if( const CompositionalFlash * f = dynamic_cast<const CompositionalFlash *>( flash ) )
  {
    std::cerr << "REFACTOR - CompositionalFlash" << std::endl;

    // FIXME the phase models already hold component properties: is it mandatory?
//    nlohmann::json compJson{ { "COMP", f->getComponentProperties() } };

//    std::cout << std::setprecision( std::numeric_limits< double >::max_digits10 )
//              << compJson << std::endl;


    f->getComponentProperties(); // FIXME non used variable.

    nlohmann::json propsJson{ { "PROPERTIES", multiphaseProperties } };

    std::cerr << std::setprecision( std::numeric_limits< double >::max_digits10 )
              << propsJson << std::endl;

    return;
  }

  if( const BlackOilFlash * f = dynamic_cast<const BlackOilFlash *>( flash ) )
  {
    PVT_UNUSED_VAR(f);
    std::cerr << "REFACTOR - BlackOilFlash" << std::endl;

    nlohmann::json propsJson{ { "PROPERTIES", multiphaseProperties } };

    std::cerr << std::setprecision( std::numeric_limits< double >::max_digits10 )
              << propsJson << std::endl;
    return;
  }

  if( const DeadOilFlash * f = dynamic_cast<const DeadOilFlash *>( flash ) )
  {
    PVT_UNUSED_VAR(f);
    std::cerr << "REFACTOR - DeadOilFlash not implemented, in void Dump( const Flash * flash, const MultiphaseSystemProperties & multiphaseProperties )" << std::endl;
    return;
  }

  std::cerr << "REFACTOR - Not a CompositionalFlash, in void Dump( const Flash * flash, const MultiphaseSystemProperties & multiphaseProperties )" << std::endl;
}

} // enf of namespace PVTPackage
