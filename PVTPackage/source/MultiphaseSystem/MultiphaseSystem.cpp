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

#include "MultiphaseSystem/MultiphaseSystem.hpp"

#include "refactor/DebugComponentProperties.hpp"

namespace PVTPackage
{

void MultiphaseSystem::Update(double pressure, double temperature, std::vector<double> feed)
{
  ASSERT(m_Flash != nullptr, "Flash has not been initialized");

  m_MultiphaseProperties.Temperature = temperature;
  m_MultiphaseProperties.Pressure = pressure;
  m_MultiphaseProperties.Feed = feed;

  //Multiphase Properties
  const bool res = m_Flash->ComputeEquilibriumAndDerivatives(m_MultiphaseProperties);

  // Extracting inputs and outputs of the computation (CompositionalFlash for the moment).
  refactor::Dump( m_Flash, m_MultiphaseProperties );

  m_StateIndicator = res ? State::SUCCESS : State::NOT_CONVERGED;
}

}
