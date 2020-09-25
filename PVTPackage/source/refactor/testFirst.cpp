#include "refactor/passiveDataStructures/MultiphaseSystemProperties.hpp"
#include "refactor/passiveDataStructures/Flash.hpp"

// This include is necessary for nlohmann::json to find the proper serializers
#include "refactor/deserializers/MultiphaseSystemProperties.hpp"
#include "refactor/deserializers/Flash.hpp"
#include "refactor/deserializers/PVTEnums.hpp"

#include "MultiphaseSystem/PhaseModel/CubicEOS/CubicEoSPhaseModel.hpp"
#include "MultiphaseSystem/PhaseModel/BlackOil/BlackOil_GasModel.hpp"
#include "MultiphaseSystem/PhaseModel/BlackOil/BlackOil_OilModel.hpp"
#include "MultiphaseSystem/PhaseModel/BlackOil/BlackOil_WaterModel.hpp"
#include "MultiphaseSystem/PhaseModel/BlackOil/DeadOil_PhaseModel.hpp"

#include "MultiphaseSystem/PhaseSplitModel/NegativeTwoPhaseFlash.hpp"
#include "MultiphaseSystem/PhaseSplitModel/BlackOilFlash.hpp"
#include "MultiphaseSystem/PhaseSplitModel/DeadOilFlash.hpp"

#include "MultiphaseSystem/MultiphaseSystemProperties.hpp"

#include <gtest/gtest.h>
#include <nlohmann/json.hpp>

#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

using json = nlohmann::json;

namespace PVTPackage
{
namespace refactor
{

PHASE_STATE convert( const pds::PHASE_STATE & input )
{
  const std::map< pds::PHASE_STATE, PHASE_STATE > m{
    { pds::PHASE_STATE::UNKNOWN,       PVTPackage::PHASE_STATE::UNKNOWN },
    { pds::PHASE_STATE::GAS,           PVTPackage::PHASE_STATE::GAS },
    { pds::PHASE_STATE::OIL,           PVTPackage::PHASE_STATE::OIL },
    { pds::PHASE_STATE::WATER,         PVTPackage::PHASE_STATE::WATER },
    { pds::PHASE_STATE::OIL_GAS,       PVTPackage::PHASE_STATE::OIL_GAS },
    { pds::PHASE_STATE::GAS_WATER,     PVTPackage::PHASE_STATE::GAS_WATER },
    { pds::PHASE_STATE::OIL_WATER,     PVTPackage::PHASE_STATE::OIL_WATER },
    { pds::PHASE_STATE::OIL_GAS_WATER, PVTPackage::PHASE_STATE::OIL_GAS_WATER }
  };

  return m.at( input );
}

PVTPackage::PHASE_TYPE convert( const pds::PHASE_TYPE & input )
{
  const std::map< pds::PHASE_TYPE, PHASE_TYPE > m{
    { pds::PHASE_TYPE::LIQUID_WATER_RICH, PVTPackage::PHASE_TYPE::LIQUID_WATER_RICH },
    { pds::PHASE_TYPE::OIL,               PVTPackage::PHASE_TYPE::OIL },
    { pds::PHASE_TYPE::GAS,               PVTPackage::PHASE_TYPE::GAS },
    { pds::PHASE_TYPE::UNKNOWN,           PVTPackage::PHASE_TYPE::UNKNOWN }
  };

  return m.at( input );
}

PVTPackage::EOS_TYPE convert( const pds::EOS_TYPE & input )
{
  const std::map< pds::EOS_TYPE, EOS_TYPE > m{
    { pds::EOS_TYPE::REDLICH_KWONG_SOAVE, PVTPackage::EOS_TYPE::REDLICH_KWONG_SOAVE },
    { pds::EOS_TYPE::PENG_ROBINSON,       PVTPackage::EOS_TYPE::PENG_ROBINSON },
    { pds::EOS_TYPE::UNKNOWN,             PVTPackage::EOS_TYPE::UNKNOWN }
  };

  return m.at( input );
}

std::vector< PVTPackage::PHASE_TYPE > convert( const std::vector< pds::PHASE_TYPE > & input )
{
  // FIXME I cannot give raw function to std::transform
  auto f = []( const pds::PHASE_TYPE & i )
  {
    return convert( i );
  };

  std::vector< PVTPackage::PHASE_TYPE > output( input.size() );
  std::transform( input.cbegin(), input.cend(), output.begin(), f );

  return output;
}

PVTPackage::ComponentProperties convert( const pds::ComponentProperties & input )
{
  return PVTPackage::ComponentProperties{ input.NComponents, input.Label, input.Mw, input.Tc, input.Pc, input.Omega };
}

PVTPackage::PVTGdata convert( const pds::PVTGdata & input )
{
  PVTPackage::PVTGdata output;

  output.Rv = input.Rv;
  output.DewPressure = input.DewPressure;

  output.NSaturatedPoints = input.NSaturatedPoints;
  output.SaturatedBg = input.SaturatedBg;
  output.SaturatedViscosity = input.SaturatedViscosity;

  output.UndersaturatedRv = input.UndersaturatedRv;
  output.UndersaturatedBg = input.UndersaturatedBg;
  output.UndersaturatedViscosity = input.UndersaturatedViscosity;

  output.setMaxRelativeRv( input.MaxRelativeRv );
  output.setMinRelativeRv( input.MinRelativeRv );

  return output;
}

PVTPackage::PVTWdata convert( const pds::PVTWdata & input )
{
  PVTPackage::PVTWdata output;

  output.ReferencePressure = input.ReferencePressure;
  output.Bw = input.Bw;
  output.Compressibility = input.Compressibility;
  output.Viscosity = input.Viscosity;

  return output;
}

PVTPackage::PVTOdata convert( const pds::PVTOdata & input )
{
  PVTPackage::PVTOdata output;

  output.Rs = input.Rs;
  output.BubblePressure = input.BubblePressure;

  output.NSaturatedPoints = input.NSaturatedPoints;
  output.SaturatedBo = input.SaturatedBo;
  output.SaturatedViscosity = input.SaturatedViscosity;

  output.UndersaturatedPressure = input.UndersaturatedPressure;
  output.UndersaturatedBo = input.UndersaturatedBo;
  output.UndersaturatedViscosity = input.UndersaturatedViscosity;

  output.setMaxRelativePressure( input.MaxRelativePressure );
  output.setMinRelativePressure( input.MinRelativePressure );

  return output;
}

PVTPackage::PVDdata convert( const pds::PVDdata & input )
{
  PVTPackage::PVDdata output;

  output.Pressure = input.Pressure;
  output.NPoints = input.NPoints;
  output.B = input.B;
  output.Viscosity = input.Viscosity;

  return output;
}

std::shared_ptr< PVTPackage::PhaseModel > convert( const std::shared_ptr< pds::PhaseModel > input )
{
  using namespace PVTPackage;

  if( auto pm = std::dynamic_pointer_cast< const pds::CubicEoSPhaseModel >( input ) )
  {
    auto output = std::make_shared< PVTPackage::CubicEoSPhaseModel >(
      convert( pm->m_ComponentsProperties ),
      convert( pm->m_EOSType ),
      convert( pm->m_PhaseType )
    );
    return output;
  }

  if( auto pm = std::dynamic_pointer_cast< const pds::BlackOilGasModel >( input ) )
  {
    auto output = std::make_shared< PVTPackage::BlackOil_GasModel >(
      convert( pm->m_PVTG ), pm->min_Pressure, pm->max_Pressure, pm->m_SurfaceMassDensity, pm->m_SurfaceMoleDensity,
      pm->m_SurfaceMolecularWeight
    );

    return output;
  }

  if( auto pm = std::dynamic_pointer_cast< const pds::BlackOilOilModel >( input ) )
  {
    auto output = std::make_shared< PVTPackage::BlackOil_OilModel >(
      convert( pm->m_PVTO ), pm->min_Pressure, pm->max_Pressure, pm->m_SurfaceMassDensity, pm->m_SurfaceMoleDensity,
      pm->m_SurfaceMolecularWeight
    );

    return output;
  }

  if( auto pm = std::dynamic_pointer_cast< const pds::BlackOilWaterModel >( input ) )
  {
    auto output = std::make_shared< PVTPackage::BlackOil_WaterModel >(
      convert( pm->m_PVTW ), pm->m_SurfaceMassDensity, pm->m_SurfaceMoleDensity, pm->m_SurfaceMolecularWeight
    );

    return output;
  }

  if( auto pm = std::dynamic_pointer_cast< const pds::DeadOilPhaseModel >( input ) )
  {
    auto output = std::make_shared< PVTPackage::DeadOil_PhaseModel >(
      convert( pm->m_type ), convert( pm->m_PVD ), pm->min_Pressure, pm->max_Pressure, pm->m_SurfaceMassDensity,
      pm->m_SurfaceMoleDensity, pm->m_SurfaceMolecularWeight
    );

    return output;
  }

  std::cerr
    << "REFACTOR - Not fully implemented | PVTPackage::PhaseModel convert( const PVTPackage::pds::PhaseModel & input )"
    << std::endl;
  exit( 1 );
}

template< typename T >
void compare( const PVTPackage::ScalarPropertyAndDerivatives< T > & actual,
              const pds::ScalarPropertyAndDerivatives< T > & expected,
              double eps )
{
  ASSERT_NEAR( actual.value, expected.value, eps );
  ASSERT_NEAR( actual.dT, expected.dT, eps );
  ASSERT_NEAR( actual.dP, expected.dP, eps );

  ASSERT_EQ( actual.dz.size(), expected.dz.size() );
  auto f = [eps]( double a,
                  double b )
  {
    return std::abs( a - b ) < eps;
  };
  bool test = std::equal( actual.dz.cbegin(), actual.dz.cend(), expected.dz.cbegin(), expected.dz.cend(), f );
  EXPECT_TRUE( test );
}

template< typename T >
void compare( const PVTPackage::VectorPropertyAndDerivatives< T > & actual,
              const pds::VectorPropertyAndDerivatives< T > & expected,
              double eps )
{
  auto f = [eps]( double a,
                  double b )
  {
    return std::abs( a - b ) < eps;
  };

  {
    ASSERT_EQ( actual.value.size(), expected.value.size() );
    bool test = std::equal( actual.value.cbegin(), actual.value.cend(),
                            expected.value.cbegin(), expected.value.cend(), f );
    EXPECT_TRUE( test );
  }
//  {
//    ASSERT_EQ( actual.dP.size(), expected.dP.size() );
//    bool test = std::equal( actual.dP.cbegin(), actual.dP.cend(),
//                            expected.dP.cbegin(), expected.dP.cend(), f );
//    EXPECT_TRUE( test );
//  }
//  {
//    ASSERT_EQ( actual.dT.size(), expected.dT.size() );
//    bool test = std::equal( actual.dT.cbegin(), actual.dT.cend(),
//                            expected.dT.cbegin(), expected.dT.cend(), f );
//    EXPECT_TRUE( test );
//  }
  // FIXME dz
  ASSERT_EQ( actual.dz.size(), expected.dz.size() );
}

using PdsPhaseType2PhaseModel = std::unordered_map< pds::PHASE_TYPE, std::shared_ptr< pds::PhaseModel >, pds::EnumClassHash >;
using PhaseType2PhaseModel = std::unordered_map< PVTPackage::PHASE_TYPE, std::shared_ptr< PVTPackage::PhaseModel >, PVTPackage::EnumClassHash >;

PhaseType2PhaseModel convert( const PdsPhaseType2PhaseModel & input )
{
  using namespace PVTPackage;

  PhaseType2PhaseModel output;

  for( const auto & phaseType2PhaseModel: input )
  {
    const PHASE_TYPE phaseType = convert( phaseType2PhaseModel.first );
    const std::shared_ptr< PhaseModel > phaseModel = convert( phaseType2PhaseModel.second );
    output.insert( { phaseType, phaseModel } );
  }

  return output;
}

void compare( const PVTPackage::MultiphaseSystemProperties & actual,
              const pds::MultiphaseSystemProperties & expected )
{
  ASSERT_NEAR( actual.Temperature, expected.Temperature, 1.e-10 );
  ASSERT_NEAR( actual.Pressure, expected.Pressure, 1.e-10 );
  ASSERT_EQ( actual.PhaseState, convert( expected.PhaseState ) );

  for( const auto & phaseType2PhaseProperties: expected.PhasesProperties )
  {
    const pds::PHASE_TYPE & pt = phaseType2PhaseProperties.first;
    const pds::PhaseProperties & expectedPhaseProps = phaseType2PhaseProperties.second;
    const PhaseProperties & actualPhaseProps = actual.PhasesProperties.at( convert( pt ) );

    ASSERT_NEAR( actualPhaseProps.Compressibility, expectedPhaseProps.Compressibility, 1.e-10 );
    ASSERT_NEAR( actualPhaseProps.Viscosity, expectedPhaseProps.Viscosity, 1.e-10 );
    ASSERT_NEAR( actualPhaseProps.MassEnthalpy, expectedPhaseProps.MassEnthalpy, 1.e-10 );

    compare( actualPhaseProps.MolecularWeight, expectedPhaseProps.MolecularWeight, 1.e10 );
    compare( actualPhaseProps.CompressibilityFactor, expectedPhaseProps.CompressibilityFactor, 1.e10 );
    compare( actualPhaseProps.MoleDensity, expectedPhaseProps.MoleDensity, 1.e10 );
    compare( actualPhaseProps.MoleComposition, expectedPhaseProps.MoleComposition, 1.e-10 );
    compare( actualPhaseProps.LnFugacityCoefficients, expectedPhaseProps.LnFugacityCoefficients, 1.e-10 );
  }

  for( const auto & phaseType2PhaseMoleFraction: expected.PhaseMoleFraction )
  {
    const pds::PHASE_TYPE & pt = phaseType2PhaseMoleFraction.first;
    const pds::ScalarPropertyAndDerivatives< double > & expectedPhaseMoleFraction = phaseType2PhaseMoleFraction.second;
    const PVTPackage::ScalarPropertyAndDerivatives< double >
      & actualPhaseMoleFraction = actual.PhaseMoleFraction.at( convert( pt ) );

    ASSERT_NEAR( expectedPhaseMoleFraction.value, actualPhaseMoleFraction.value, 1.e-10 );
  }
}

void validate( const std::string & json_string )
{
  const json j1 = json::parse( json_string );

  // FIXME TODO REFACTOR Use constants
  json const & jsonProperties = j1["MULTIPHASE_SYSTEM_PROPERTIES"];
  auto const refMsp = jsonProperties.get< pds::MultiphaseSystemProperties >();

  PVTPackage::MultiphaseSystemProperties msp( convert( refMsp.PhaseTypes ), refMsp.Feed.size() );
  msp.Temperature = refMsp.Temperature;
  msp.Pressure = refMsp.Pressure;
  msp.Feed = refMsp.Feed;
  msp.PhaseModels = convert( refMsp.PhaseModels );

  // FIXME TODO REFACTOR Use constants
  json const & jsonFlash = j1["FLASH"];

  const pds::FLASH_TYPE flashType = jsonFlash.at( FlashKeys::TYPE ).get< pds::FLASH_TYPE >();

  if( flashType == pds::FLASH_TYPE::NEGATIVE_TWO_PHASE )
  {
    auto const refFlash = jsonFlash[FlashKeys::VALUE].get< pds::NegativeTwoPhaseFlash >();

    PVTPackage::NegativeTwoPhaseFlash flash( convert( refFlash.componentsProperties ) );
    flash.ComputeEquilibrium( msp );
  }
  else if( flashType == pds::FLASH_TYPE::DEAD_OIL )
  {
    PVTPackage::DeadOilFlash deadOilFlash;
    deadOilFlash.ComputeEquilibrium( msp );
  }
  else if( flashType == pds::FLASH_TYPE::BLACK_OIL )
  {
    PVTPackage::BlackOilFlash blackOilFlash;
    blackOilFlash.ComputeEquilibrium( msp );
  }

  compare( msp, refMsp );
}

TEST( PVTPackageRefactor, final )
{
  // FIXME Is there a simple way to use data providers with gtest?
  const std::vector< std::string > fileNames = {
    "pvt_data.txt",
    "compositional_multiphase_wells_1d.log.err",
    "compositional_multiphase_wells_2d.log.err",
    "deadoil_3ph_staircase_3d-10000.log.err",
    "blackoil_2ph_1d.log.err"
  };

  std::string line;
  for (const std::string & fileName: fileNames)
  {
    std::ifstream dataFile( "data/" + fileName );
    while( std::getline( dataFile, line ) )
    {
      const bool isComment = line.rfind("#", 0) == 0;
      if ( not line.empty() and not isComment )
      {
//      std::cerr << line << std::endl;
        validate(line);
      }
    }
  }
}

int main( int argc, char * * argv )
{
  ::testing::InitGoogleTest( &argc, argv );

  int const result = RUN_ALL_TESTS();

  return result;
}

} // end of namespace refactor
} // end of namespace PVTPackage
