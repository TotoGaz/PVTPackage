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

#include <vector>
#include "MultiphaseSystem/PhaseModel/PhaseModel.hpp"
#include "PVTWdata.hpp"

namespace PVTPackage
{

class BlackOil_WaterModel final : public PhaseModel
{
public:

  /**
   * @brief Paramter constructor for refactor only
   * FIXME REFACTOR
   */
  BlackOil_WaterModel( const PVTWdata & PVTW,
                       double surfaceMassDensity,
                       double surfaceMoleDensity,
                       double surfaceMolecularWeight )
    :
    m_PVTW( PVTW ),
    m_SurfaceMassDensity( surfaceMassDensity ),
    m_SurfaceMoleDensity( surfaceMoleDensity ),
    m_SurfaceMolecularWeight( surfaceMolecularWeight )
  {
    // Left blank
  }

  BlackOil_WaterModel(std::vector<double> PVTW, double water_surface_mass_density, double water_surface_mw);

  ~BlackOil_WaterModel() override = default;

  //Getter
  double GetSurfaceMassDensity() { return m_SurfaceMassDensity; }
  double GetSurfaceMoleDensity() { return m_SurfaceMoleDensity; }
  double GetSurfaceMolecularWeight() { return m_SurfaceMolecularWeight; }

  //Compute
  void ComputeProperties(double P, PhaseProperties& props_out);



protected:


  //PVT data
  PVTWdata m_PVTW{};


  //
  double m_SurfaceMassDensity;
  double m_SurfaceMoleDensity;
  double m_SurfaceMolecularWeight;

public:
  /**
   * @brief Getter for refactor only
   * FIXME REFACTOR
   */
  double getSurfaceMassDensity() const
  { return m_SurfaceMassDensity; }

  /**
   * @brief Getter for refactor only
   * FIXME REFACTOR
   */
  double getSurfaceMoleDensity() const
  { return m_SurfaceMoleDensity; }

  /**
   * @brief Getter for refactor only
   * FIXME REFACTOR
   */
  double getSurfaceMolecularWeight() const
  { return m_SurfaceMolecularWeight; }

  /**
   * @brief Getter for refactor only
   * FIXME REFACTOR
   */
  PVTWdata const & getPvtw() const
  { return m_PVTW; }
};

}
