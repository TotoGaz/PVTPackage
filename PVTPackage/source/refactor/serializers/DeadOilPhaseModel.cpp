#include "DeadOilPhaseModel.hpp"

#include "refactor/JsonKeys.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage
{

using json = nlohmann::json;

void to_json( json & j,
              const PVDdata & data )
{
  j = json{
    { PVDDataKeys::PRESSURE, data.Pressure },
    { PVDDataKeys::N_POINTS, data.NPoints },
    { PVDDataKeys::B, data.B },
    { PVDDataKeys::VISCOSITY, data.Viscosity }
  };
}

void to_json( json & j,
              const DeadOil_PhaseModel & model )
{
  j = json{
    { DeadOilModelKeys::PHASE_TYPE_,              model.getType() },
    { DeadOilModelKeys::PVD_DATA,                 model.getPvd() },
    { DeadOilModelKeys::MIN_PRESSURE,             model.getMinPressure() },
    { DeadOilModelKeys::MAX_PRESSURE,             model.getMaxPressure() },
    { DeadOilModelKeys::SURFACE_MASS_DENSITY,     model.getSurfaceMassDensity() },
    { DeadOilModelKeys::SURFACE_MOLE_DENSITY,     model.getSurfaceMoleDensity() },
    { DeadOilModelKeys::SURFACE_MOLECULAR_WEIGHT, model.getSurfaceMolecularWeight() }
  };
}

} // end of namespace PVTPackage
