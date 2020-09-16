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

namespace PVTPackage
{

struct PVTOdata
{
  friend class BlackOil_OilModel;

  //--Data
  //
  std::vector<double> Rs;
  std::vector<double> BubblePressure;
  //Saturated
  std::size_t NSaturatedPoints;
  std::vector<double> SaturatedBo;
  std::vector<double> SaturatedViscosity;
  //Unsaturated
  std::vector<std::vector<double>> UndersaturatedPressure;   // Pressure - Pbub -> always start at 0
  std::vector<std::vector<double>> UndersaturatedBo;
  std::vector<std::vector<double>> UndersaturatedViscosity;

private:
  //Pressure
  double MaxRelativePressure;
  double MinRelativePressure;

public:
  /**
   * @brief Getter for refactor only
   * FIXME REFACTOR
   */
  double getMaxRelativePressure() const
  {
    return MaxRelativePressure;
  }

  /**
   * @brief Getter for refactor only
   * FIXME REFACTOR
   */
  double getMinRelativePressure() const
  {
    return MaxRelativePressure;
  }

  /**
   * @brief Setter for refactor only
   * FIXME REFACTOR
   */
  void setRs( std::vector< double > const & rs )
  {
    Rs = rs;
  }

  /**
   * @brief Setter for refactor only
   * FIXME REFACTOR
   */
  void setBubblePressure( std::vector< double > const & bubblePressure )
  {
    BubblePressure = bubblePressure;
  }

  /**
   * @brief Setter for refactor only
   * FIXME REFACTOR
   */
  void setNSaturatedPoints( size_t nSaturatedPoints )
  {
    NSaturatedPoints = nSaturatedPoints;
  }

  /**
   * @brief Setter for refactor only
   * FIXME REFACTOR
   */
  void setSaturatedBo( std::vector< double > const & saturatedBo )
  {
    SaturatedBo = saturatedBo;
  }

  /**
   * @brief Setter for refactor only
   * FIXME REFACTOR
   */
  void setSaturatedViscosity( std::vector< double > const & saturatedViscosity )
  {
    SaturatedViscosity = saturatedViscosity;
  }

  /**
   * @brief Setter for refactor only
   * FIXME REFACTOR
   */
  void setUndersaturatedPressure( std::vector< std::vector< double>> const & undersaturatedPressure )
  {
    UndersaturatedPressure = undersaturatedPressure;
  }

  /**
   * @brief Setter for refactor only
   * FIXME REFACTOR
   */
  void setUndersaturatedBo( std::vector< std::vector< double>> const & undersaturatedBo )
  {
    UndersaturatedBo = undersaturatedBo;
  }

  /**
   * @brief Setter for refactor only
   * FIXME REFACTOR
   */
  void setUndersaturatedViscosity( std::vector< std::vector< double>> const & undersaturatedViscosity )
  {
    UndersaturatedViscosity = undersaturatedViscosity;
  }

  /**
   * @brief Setter for refactor only
   * FIXME REFACTOR
   */
  void setMaxRelativePressure( double maxRelativePressure )
  {
    MaxRelativePressure = maxRelativePressure;
  }

  /**
   * @brief Setter for refactor only
   * FIXME REFACTOR
   */
  void setMinRelativePressure( double minRelativePressure )
  {
    MinRelativePressure = minRelativePressure;
  }
};

}
