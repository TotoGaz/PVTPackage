/*
 * ------------------------------------------------------------------------------------------------------------
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 * Copyright (c) 2018-2020 Lawrence Livermore National Security LLC
 * Copyright (c) 2018-2020 The Board of Trustees of the Leland Stanford Junior University
 * Copyright (c) 2018-2020 Total, S.A
 * Copyright (c) 2020-     GEOSX Contributors
 * All right reserved
 *
 * See top level LICENSE, COPYRIGHT, CONTRIBUTORS, NOTICE, and ACKNOWLEDGEMENTS files for details.
 * ------------------------------------------------------------------------------------------------------------
 */

#pragma once

#include "Utils/Assert.hpp"
#include "MultiphaseSystem/PVTEnums.hpp"
#include <vector>
#include "MultiphaseSystem/PhaseModel/PhaseModel.hpp"
#include <map>
#include "PVDdata.hpp"


namespace PVTPackage
{

class DeadOil_PhaseModel final : public PhaseModel
{
public:
  /**
   * @brief Parametrized constructof for refactor
   * FIXME REFACTOR
   */
  DeadOil_PhaseModel( PHASE_TYPE type,
                      PVDdata const & pvd,
                      double minPressure,
                      double maxPressure,
                      double surfaceMassDensity,
                      double surfaceMoleDensity,
                      double surfaceMolecularWeight )
    : m_type( type ),
      m_PVD( pvd ),
      min_Pressure( minPressure ),
      max_Pressure( maxPressure ),
      m_SurfaceMassDensity( surfaceMassDensity ),
      m_SurfaceMoleDensity( surfaceMoleDensity ),
      m_SurfaceMolecularWeight( surfaceMolecularWeight )
  { }

  DeadOil_PhaseModel(PHASE_TYPE type, std::vector<std::vector<double>> PVD, double oil_surface_mass_density, double oil_surface_mw);

  ~DeadOil_PhaseModel() override = default;

  //Getter
  double GetSurfaceMassDensity() { return m_SurfaceMassDensity; }
  double GetSurfaceMoleDensity() { return m_SurfaceMoleDensity; }
  double GetSurfaceMolecularWeight() { return m_SurfaceMolecularWeight; }

  //Compute
  void ComputeProperties(double P, PhaseProperties& props_out) const;


protected:


  //Phase type
  PHASE_TYPE m_type;

  //PVT data
  PVDdata m_PVD;

  //
  double min_Pressure{};
  double max_Pressure{};

  //
  double m_SurfaceMassDensity;
  double m_SurfaceMoleDensity;
  double m_SurfaceMolecularWeight;

  //
  void ComputeBandVisc(double P, double& B, double& visc) const;
  double ComputeMoleDensity(double B) const;
  double ComputeMassDensity(double B) const;


  //Functions
  void CreateTable(const std::vector<std::vector<double>>& PVD);
  void CheckTableConsistency();

public:
  /**
   * @brief Getter for refactor only
   * FIXME REFACTOR
   */
  PHASE_TYPE getType() const
  {
    return m_type;
  }

  /**
   * @brief Getter for refactor only
   * FIXME REFACTOR
   */
  PVDdata const & getPvd() const
  {
    return m_PVD;
  }

  /**
   * @brief Getter for refactor only
   * FIXME REFACTOR
   */
  double getMinPressure() const
  {
    return min_Pressure;
  }

  /**
   * @brief Getter for refactor only
   * FIXME REFACTOR
   */
  double getMaxPressure() const
  {
    return max_Pressure;
  }

  /**
   * @brief Getter for refactor only
   * FIXME REFACTOR
   */
  double getSurfaceMassDensity() const
  {
    return m_SurfaceMassDensity;
  }

  /**
   * @brief Getter for refactor only
   * FIXME REFACTOR
   */
  double getSurfaceMoleDensity() const
  {
    return m_SurfaceMoleDensity;
  }

  /**
   * @brief Getter for refactor only
   * FIXME REFACTOR
   */
  double getSurfaceMolecularWeight() const
  {
    return m_SurfaceMolecularWeight;
  }
};

}
