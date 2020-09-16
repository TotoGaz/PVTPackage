#ifndef PVTPACKAGE_DESERIALIZERS_PHASEMODELS_HPP
#define PVTPACKAGE_DESERIALIZERS_PHASEMODELS_HPP

#include "refactor/passiveDataStructures/PhaseModel.hpp"

#include <nlohmann/json.hpp>

#include <iostream>

namespace PVTPackage {
namespace pds {

void from_json( const nlohmann::json & j,
                pds::CubicEoSPhaseModel & cubicEoSPhaseModel );

void from_json( const nlohmann::json & j,
                pds::BlackOilGasModel & model );

void from_json( const nlohmann::json & j,
                pds::BlackOilOilModel & model );

void from_json( const nlohmann::json & j,
                pds::BlackOilWaterModel & model );

} // end of namespace pds
} // end of namespace PVTPackage

namespace nlohmann {

template<>
struct adl_serializer< std::shared_ptr< PVTPackage::pds::PhaseModel > >
{
  static std::shared_ptr< PVTPackage::pds::PhaseModel > from_json( const json & j )
  {
    using namespace PVTPackage;

    const auto type = j.at( PhaseModelKeys::TYPE ).get< pds::PHASE_MODEL_TYPE >();
    const json value = j.at( PhaseModelKeys::VALUE );

    if( type == pds::PHASE_MODEL_TYPE::CUBE_EOS )
    {
      const auto model = value.get< pds::CubicEoSPhaseModel >();
      return std::make_shared< pds::CubicEoSPhaseModel >(model);
    }
    else if ( type == pds::PHASE_MODEL_TYPE::BLACK_OIL_GAS )
    {
      const auto model = value.get< pds::BlackOilGasModel >();
      return std::make_shared< pds::BlackOilGasModel >(model);
    }
    else if ( type == pds::PHASE_MODEL_TYPE::BLACK_OIL_OIL )
    {
      const auto model = value.get< pds::BlackOilOilModel >();
      return std::make_shared< pds::BlackOilOilModel >(model);
    }
    else if ( type == pds::PHASE_MODEL_TYPE::BLACK_OIL_WATER )
    {
      const auto model = value.get< pds::BlackOilWaterModel >();
      return std::make_shared< pds::BlackOilWaterModel >(model);
    }


    std::cerr << "REFACTOR - Not implemented in adl_serializer< PVTPackage::pds::PhaseModel >" << std::endl;
    std::shared_ptr< pds::PhaseModel> dummy;
    return dummy;
  };
};
}

#endif //PVTPACKAGE_DESERIALIZERS_PHASEMODELS_HPP
