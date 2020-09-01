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
#ifndef PVTPACKAGE_PDS_PVTENUMS_HPP
#define PVTPACKAGE_PDS_PVTENUMS_HPP

#pragma once

#include <nlohmann/json.hpp>

#include <unordered_map>
#include <vector>

namespace PVTPackage
{
namespace pds
{

//enum class PVT_TYPE : int
//{ BLACK_OIL = 0, DEAD = 0, GENERAL = 1, MODIFIED = 2, API_TRACKING = 3, COMPOSITIONAL = 4, UNKNOWN = -1};
//
//enum class COMPOSITIONAL_FLASH_TYPE : int
//{ TRIVIAL = 0, NEGATIVE_OIL_GAS = 1, TABULATED_KVALUES = 2, FREE_WATER = 3, THREE_PHASE = 4, UNKNOWN = -1 };
//
enum class EOS_TYPE : int
{
  REDLICH_KWONG_SOAVE = 1, PENG_ROBINSON = 0, UNKNOWN = -1
};

enum class PHASE_TYPE : int
{
  LIQUID_WATER_RICH = 2, OIL = 1, GAS = 0, UNKNOWN = -1
};

enum class PHASE_STATE : int
{
  GAS = 6, OIL = 5, WATER = 4, OIL_GAS = 3, GAS_WATER = 2, OIL_WATER = 1, OIL_GAS_WATER = 0, UNKNOWN = -1
};

//enum class STATE_VARIABLE : int
//{TEMPERATURE,PRESSURE,FEED};


struct EnumClassHash
{
  template< typename T >
  std::size_t operator()( T t ) const
  {
    return static_cast<int>(t);
  }
};

// TODO This is supposed to be the same as serialisation.
NLOHMANN_JSON_SERIALIZE_ENUM( pds::PHASE_STATE, {
  { pds::PHASE_STATE::UNKNOWN, "UNKNOWN" },
  { pds::PHASE_STATE::GAS, "GAS" },
  { pds::PHASE_STATE::OIL, "OIL" },
  { pds::PHASE_STATE::WATER, "WATER" },
  { pds::PHASE_STATE::OIL_GAS, "OIL_GAS" },
  { pds::PHASE_STATE::GAS_WATER, "GAS_WATER" },
  { pds::PHASE_STATE::OIL_WATER, "OIL_WATER" },
  { pds::PHASE_STATE::OIL_GAS_WATER, "OIL_GAS_WATER" }
} )

NLOHMANN_JSON_SERIALIZE_ENUM( pds::PHASE_TYPE, {
  { pds::PHASE_TYPE::UNKNOWN, "UNKNOWN" },
  { pds::PHASE_TYPE::LIQUID_WATER_RICH, "LIQUID_WATER_RICH" },
  { pds::PHASE_TYPE::OIL, "OIL" },
  { pds::PHASE_TYPE::GAS, "GAS" }
} )

NLOHMANN_JSON_SERIALIZE_ENUM( pds::EOS_TYPE, {
  { pds::EOS_TYPE::UNKNOWN, "UNKNOWN" },
  { pds::EOS_TYPE::REDLICH_KWONG_SOAVE, "REDLICH_KWONG_SOAVE" },
  { pds::EOS_TYPE::PENG_ROBINSON, "PENG_ROBINSON" }
} )


////Phase State
//const std::unordered_map<std::vector<bool>, PHASE_STATE> PhaseStateMap =
//  {
//    { { 1,1,1 } ,PHASE_STATE::OIL_GAS_WATER },
//    { { 1,0,1 } ,PHASE_STATE::OIL_WATER },
//    { { 1,1,0 } ,PHASE_STATE::OIL_GAS },
//    { { 0,1,1 } ,PHASE_STATE::GAS_WATER },
//    { { 0,0,1 } ,PHASE_STATE::WATER },
//    { { 1,0,0 } ,PHASE_STATE::OIL },
//    { { 0,1,0 } ,PHASE_STATE::GAS },
//  };
//}

} // end of namespace pds
} // end of namespace PVTPackage

#endif //PVTPACKAGE_PDS_PVTENUMS_HPP
