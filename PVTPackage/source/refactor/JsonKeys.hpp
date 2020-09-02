#ifndef GEOSX_JSONKEYS_HPP
#define GEOSX_JSONKEYS_HPP

namespace PVTPackage
{

struct ScalarVectorPropertyAndDerivativesHelper
{
  static constexpr auto VALUE = "value";
  static constexpr auto DP = "dP";
  static constexpr auto DT = "dT";
  static constexpr auto DZ = "dz";
};

} // end of namespace PVTPackage

#endif //GEOSX_JSONKEYS_HPP
