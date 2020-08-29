#include "PhaseModels.hpp"

#include "Enums.hpp"
#include "ComponentProperties.hpp"

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

CubicEoSPhaseModel CubicEoSPhaseModelHelper::CubicEoSPhaseModelHelper::from_json( const json & j )
{
  const ComponentProperties componentProperties = j.at( COMPONENT_PROPERTIES ).get< ComponentProperties >();
  const EOS_TYPE eos = j.at( EOS ).get< EOS_TYPE >();
  const PHASE_TYPE phaseType = j.at( PHASE_TYPE_ ).get< PHASE_TYPE >();

  const CubicEoSPhaseModel model( componentProperties, eos, phaseType );
  return model;
}

decltype( CubicEoSPhaseModelHelper::EOS ) CubicEoSPhaseModelHelper::EOS;
decltype( CubicEoSPhaseModelHelper::PHASE_TYPE_ ) CubicEoSPhaseModelHelper::PHASE_TYPE_;
decltype( CubicEoSPhaseModelHelper::COMPONENT_PROPERTIES ) CubicEoSPhaseModelHelper::COMPONENT_PROPERTIES;

} // namespace PVTPackage
