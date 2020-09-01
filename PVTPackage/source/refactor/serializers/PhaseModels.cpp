#include "PhaseModels.hpp"

#include "refactor/passiveDataStructures/PVTEnums.hpp"
#include "refactor/passiveDataStructures/ComponentProperties.hpp"
#include "refactor/passiveDataStructures/PhaseModel.hpp"

#include "refactor/serializers/Enums.hpp"
#include "refactor/serializers/ComponentProperties.hpp"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace PVTPackage
{

void CubicEoSPhaseModelHelper::to_json( json & j,
                                        const CubicEoSPhaseModel & model )
{
  j = json{ { EOS,                  model.getEosType() },
            { PHASE_TYPE_,          model.getPhaseType() },
            { COMPONENT_PROPERTIES, model.get_ComponentsProperties() } };
}

pds::CubicEoSPhaseModel CubicEoSPhaseModelHelper::CubicEoSPhaseModelHelper::from_json( const json & j )
{
  pds::CubicEoSPhaseModel model;

  j.at( COMPONENT_PROPERTIES ).get_to( model.m_ComponentsProperties );
  j.at( EOS ).get_to( model.m_EOSType );
  j.at( PHASE_TYPE_ ).get_to( model.m_PhaseType );

  return model;
}

decltype( CubicEoSPhaseModelHelper::EOS ) CubicEoSPhaseModelHelper::EOS;
decltype( CubicEoSPhaseModelHelper::PHASE_TYPE_ ) CubicEoSPhaseModelHelper::PHASE_TYPE_;
decltype( CubicEoSPhaseModelHelper::COMPONENT_PROPERTIES ) CubicEoSPhaseModelHelper::COMPONENT_PROPERTIES;

} // namespace PVTPackage
