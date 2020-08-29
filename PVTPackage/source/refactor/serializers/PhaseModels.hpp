#ifndef PVTPACKAGE_PHASEMODELS_HPP
#define PVTPACKAGE_PHASEMODELS_HPP

#include "MultiphaseSystem/PhaseModel/CubicEOS/CubicEoSPhaseModel.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {

class CubicEoSPhaseModelHelper
{
public:
  static void to_json( nlohmann::json & j,
                       const CubicEoSPhaseModel & model );

  static CubicEoSPhaseModel from_json( const nlohmann::json & j );

private:
  static constexpr auto EOS = "EOS";
  static constexpr auto PHASE_TYPE_ = "PHASE_TYPE";
  static constexpr auto COMPONENT_PROPERTIES = "COMPONENT_PROPERTIES";

};

}

namespace nlohmann
{

template<>
struct adl_serializer< PVTPackage::CubicEoSPhaseModel >
{
  static PVTPackage::CubicEoSPhaseModel from_json( const json & j )
  {
    return PVTPackage::CubicEoSPhaseModelHelper::from_json( j );
  }

  static void to_json( json & j,
                       const PVTPackage::CubicEoSPhaseModel & p )
  {
    PVTPackage::CubicEoSPhaseModelHelper::to_json( j, p );
  }
};

}


#endif //PVTPACKAGE_PHASEMODELS_HPP
