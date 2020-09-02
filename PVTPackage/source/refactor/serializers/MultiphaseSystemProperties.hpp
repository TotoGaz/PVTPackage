#ifndef PVTPACKAGE_MULTIPHASESYSTEMPROPERTIES_HPP
#define PVTPACKAGE_MULTIPHASESYSTEMPROPERTIES_HPP

#include "MultiphaseSystem/MultiphaseSystemProperties.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {

void to_json( nlohmann::json & j,
              const MultiphaseSystemProperties & props );

namespace pds {

void from_json( const nlohmann::json & j,
                MultiphaseSystemProperties & props );

} // end of namespace pds
} // end of namespace PVTPackage

#endif //PVTPACKAGE_MULTIPHASESYSTEMPROPERTIES_HPP