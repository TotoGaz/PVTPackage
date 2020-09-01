#ifndef PVTPACKAGE_PDS_PHASEMODEL_HPP
#define PVTPACKAGE_PDS_PHASEMODEL_HPP

#include "refactor/passiveDataStructures/PVTEnums.hpp"
#include "refactor/passiveDataStructures/ComponentProperties.hpp"

#include <vector>

namespace PVTPackage
{
namespace pds
{

class PhaseModel
{
public:

  PhaseModel() {};

  virtual ~PhaseModel() {};

};

class CubicEoSPhaseModel final : public PhaseModel
{
public:
  pds::ComponentProperties m_ComponentsProperties;
  pds::PHASE_TYPE m_PhaseType;
  //EOS parameters
  pds::EOS_TYPE m_EOSType;
  double m_OmegaA;
  double m_OmegaB;
  double m_Delta1, m_Delta2;
  //Constant Properties
  std::vector<double> m_m;
  double m_BICs;
};

} // end of namespace pds
} // end of namespace PVTPackage

#endif //PVTPACKAGE_PDS_PHASEMODEL_HPP
