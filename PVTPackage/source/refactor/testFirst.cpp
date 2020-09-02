#include "refactor/passiveDataStructures/MultiphaseSystemProperties.hpp"

// This include is necessary for nlohmann::json to find the proper serializers
#include "refactor/deserializers/MultiphaseSystemProperties.hpp"

#include "MultiphaseSystem/PhaseModel/CubicEOS/CubicEoSPhaseModel.hpp"
#include "MultiphaseSystem/PhaseSplitModel/NegativeTwoPhaseFlash.hpp"
#include "MultiphaseSystem/MultiphaseSystemProperties.hpp"

#include <gtest/gtest.h>
#include <nlohmann/json.hpp>

#include <algorithm>

using json = nlohmann::json;

PVTPackage::PHASE_STATE convert( const PVTPackage::pds::PHASE_STATE & input ){
  using namespace PVTPackage;

  const std::map< pds::PHASE_STATE, PHASE_STATE > m{
    { pds::PHASE_STATE::UNKNOWN,       PHASE_STATE::UNKNOWN },
    { pds::PHASE_STATE::GAS,           PHASE_STATE::GAS },
    { pds::PHASE_STATE::OIL,           PHASE_STATE::OIL },
    { pds::PHASE_STATE::WATER,         PHASE_STATE::WATER },
    { pds::PHASE_STATE::OIL_GAS,       PHASE_STATE::OIL_GAS },
    { pds::PHASE_STATE::GAS_WATER,     PHASE_STATE::GAS_WATER },
    { pds::PHASE_STATE::OIL_WATER,     PHASE_STATE::OIL_WATER },
    { pds::PHASE_STATE::OIL_GAS_WATER, PHASE_STATE::OIL_GAS_WATER }
  };

  return m.at( input );
}

PVTPackage::PHASE_TYPE convert( const PVTPackage::pds::PHASE_TYPE & input ){
  using namespace PVTPackage;

  const std::map< pds::PHASE_TYPE, PHASE_TYPE > m{
    { pds::PHASE_TYPE::LIQUID_WATER_RICH, PHASE_TYPE::LIQUID_WATER_RICH },
    { pds::PHASE_TYPE::OIL,               PHASE_TYPE::OIL },
    { pds::PHASE_TYPE::GAS,               PHASE_TYPE::GAS },
    { pds::PHASE_TYPE::UNKNOWN,           PHASE_TYPE::UNKNOWN }
  };

  return m.at( input );
}

PVTPackage::EOS_TYPE convert( const PVTPackage::pds::EOS_TYPE & input ){
  using namespace PVTPackage;

  const std::map< pds::EOS_TYPE, EOS_TYPE > m{
    { pds::EOS_TYPE::REDLICH_KWONG_SOAVE, EOS_TYPE::REDLICH_KWONG_SOAVE },
    { pds::EOS_TYPE::PENG_ROBINSON,       EOS_TYPE::PENG_ROBINSON },
    { pds::EOS_TYPE::UNKNOWN,             EOS_TYPE::UNKNOWN }
  };

  return m.at( input );
}

std::vector< PVTPackage::PHASE_TYPE > convert( const std::vector< PVTPackage::pds::PHASE_TYPE > & input )
{
  using namespace PVTPackage;

  // FIXME I cannot give raw function to std::transform
  auto f = []( const pds::PHASE_TYPE & i ) {
    return convert( i );
  };

  std::vector< PHASE_TYPE > output( input.size() );
  std::transform( input.cbegin(), input.cend(), output.begin(), f );

  return output;
}

PVTPackage::ComponentProperties convert( const PVTPackage::pds::ComponentProperties & input )
{
  return PVTPackage::ComponentProperties{ input.NComponents, input.Label, input.Mw, input.Tc, input.Pc, input.Omega };
}

std::shared_ptr< PVTPackage::PhaseModel > convert( const std::shared_ptr< PVTPackage::pds::PhaseModel > input )
{
  using namespace PVTPackage;

  if (auto pm = std::dynamic_pointer_cast< const pds::CubicEoSPhaseModel >( input )){
    auto output = std::make_shared< CubicEoSPhaseModel >(
                                  convert( pm->m_ComponentsProperties ),
                                  convert( pm->m_EOSType ),
                                  convert( pm->m_PhaseType )
                                  );
    // TODO is this enough?
    return output;
  }
  std::cerr << "Not fully implemented | PVTPackage::PhaseModel convert( const PVTPackage::pds::PhaseModel & input )" << std::endl;
  exit(1);
}

template< typename T >
void compare( const PVTPackage::ScalarPropertyAndDerivatives< T > & actual,
              const PVTPackage::pds::ScalarPropertyAndDerivatives< T > & expected, double eps )
{
  ASSERT_NEAR( actual.value, expected.value, eps );
  ASSERT_NEAR( actual.dT, expected.dT, eps );
  ASSERT_NEAR( actual.dP, expected.dP, eps );

  ASSERT_EQ( actual.dz.size(), expected.dz.size() );
  auto f = [eps]( double a, double b )
  {
    return std::abs( a - b ) < eps;
  };
  bool test = std::equal( actual.dz.cbegin(), actual.dz.cend(), expected.dz.cbegin(), expected.dz.cend(), f );
  EXPECT_TRUE( test );
}

template< typename T >
void compare( const PVTPackage::VectorPropertyAndDerivatives< T > & actual,
              const PVTPackage::pds::VectorPropertyAndDerivatives< T > & expected, double eps )
{
  auto f = [eps]( double a, double b )
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

using PdsPhaseType2PhaseModel = std::unordered_map< PVTPackage::pds::PHASE_TYPE, std::shared_ptr< PVTPackage::pds::PhaseModel >, PVTPackage::pds::EnumClassHash >;
using PhaseType2PhaseModel = std::unordered_map< PVTPackage::PHASE_TYPE, std::shared_ptr< PVTPackage::PhaseModel >, PVTPackage::EnumClassHash >;

PhaseType2PhaseModel convert( const PdsPhaseType2PhaseModel & input )
{
  using namespace PVTPackage;

  PhaseType2PhaseModel output;

  for ( const auto & phaseType2PhaseModel: input ) {
    const PHASE_TYPE phaseType = convert( phaseType2PhaseModel.first );
    const std::shared_ptr< PhaseModel > phaseModel = convert( phaseType2PhaseModel.second );
    output.insert( {phaseType, phaseModel} );
  }

  return output;
}

void compare( const PVTPackage::MultiphaseSystemProperties & actual,
              const PVTPackage::pds::MultiphaseSystemProperties & expected )
{
  using namespace PVTPackage;

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
    const ScalarPropertyAndDerivatives< double > & actualPhaseMoleFraction = actual.PhaseMoleFraction.at( convert( pt ) );

    ASSERT_NEAR( expectedPhaseMoleFraction.value, actualPhaseMoleFraction.value, 1.e-10 );
  }
}

TEST( PVTPackageRefactor, first )
{

  json j1 = R"(
{"PROPERTIES":{"FEED":[0.4413081711638635,0.27943529607843004,0.27232239763279725,0.006934135124909191],"PHASE_MODELS":{"GAS":{"COMPONENT_PROPERTIES":{"WATER_INDEX":3,"labels":["N2","C10","C20","H2O"],"mw":[0.028,0.134,0.275,0.018],"n_components":4,"omega":[0.04,0.443,0.816,0.344],"pc":[3400000.0,2530000.0,1460000.0,22050000.0],"tc":[126.2,622.0,782.0,647.0]},"EOS":"PENG_ROBINSON","PHASE_TYPE":"GAS"},"OIL":{"COMPONENT_PROPERTIES":{"WATER_INDEX":3,"labels":["N2","C10","C20","H2O"],"mw":[0.028,0.134,0.275,0.018],"n_components":4,"omega":[0.04,0.443,0.816,0.344],"pc":[3400000.0,2530000.0,1460000.0,22050000.0],"tc":[126.2,622.0,782.0,647.0]},"EOS":"PENG_ROBINSON","PHASE_TYPE":"OIL"}},"PHASE_MOLE_FRACTION":{"GAS":{"dP":-1.0185526175932416e-08,"dT":0.00011601642177278577,"dz":[0.6057264534307888,-0.47498921569391356,-0.48354189898750966,-0.4187787908545724],"value":0.39490059867355526},"OIL":{"dP":1.0185524550351195e-08,"dT":-0.00011601643430951906,"dz":[-0.605726470313731,0.4749892023624191,0.48354189898750966,0.41877825361636956],"value":0.6050994013264448}},"PHASE_PROPERTIES":{"GAS":{"COMPRESSIBILITY":0.0,"COMPRESSIBILITY_FACTOR":{"dP":-1.4679811217568087e-09,"dT":0.0004023412813064798,"dz":[1.1176507735201687e-05,0.00015923136975369163,0.0003742767318250315,-0.02182906265915973],"value":0.9861296916899498},"LN_FUGACITY_COEFFICIENTS":{"dP":[-2.976622093807557e-09,-1.7065627358176433e-07,-3.352299733595403e-07,-6.883826039054153e-08],"dT":[0.00044614812204968644,0.009461193749792445,0.019304269283478163,0.0031572496089093413],"dz":[[-3.060033273421912e-08,-2.6329701545842345e-07,-9.285099843795327e-07,4.7209807077516765e-05],[0.00010362749921248937,0.0010409230869363902,0.00391775810602465,-0.2024270569371459],[0.0002157640012928664,0.002166474500664176,0.008155019404611634,-0.42134517774969954],[2.975618562430963e-05,0.0002992120615163978,0.0011248137527161263,-0.05812863631271962]],"value":[-0.0172257489871612,-0.8521412571232609,-1.68723750202096,-0.32862429946083127]},"MASS_DENSITY":{"dP":1.157447256608439e-05,"dT":-0.19803289328693638,"dz":[0.00011453387987252001,0.04271709448406336,-0.03811231506387666,-0.2318118376815198],"value":52.683197166973336},"MASS_ENTHALPY":0.0,"MOLECULAR_WEIGHT":{"dP":8.139081976630443e-13,"dT":4.023092562212806e-07,"dz":[3.7775583168449816e-07,2.7228744203056396e-05,-9.629657416267658e-06,-0.0007431683215125736],"value":0.028004937477610806},"MOLE_COMPOSITION":{"dP":[7.191571322354379e-11,8.131567235316377e-13,1.5238484655939819e-15,-7.272965317084006e-11],"dT":[-2.039841844859846e-05,5.225268728375441e-06,6.364355576901417e-10,1.5172500616777392e-05],"dz":[[3.705805812502675e-05,0.0007854649902166782,0.0009798772770697006,-0.07249384861935655],[6.476191108836893e-08,0.00016704175076208847,-0.0001675048897706673,-0.00015724710367702398],[4.68999519839517e-12,-1.0844666380608691e-08,1.1302566506620626e-08,-7.158093737057163e-09],[-3.712654615421745e-05,-0.0009524851554145049,-0.0008123830211323028,0.07265120275095681]],"value":[0.9993931678757727,9.486395574952881e-05,6.147805961401386e-09,0.0005119620206717865]},"MOLE_DENSITY":{"dP":0.0004132464677290469,"dT":-7.098381174351941,"dz":[-0.021298979623085985,-0.3037174667299778,-0.7140166951891652,41.64498632451154],"value":1881.2110260589632},"VISCOSITY":0.0},"OIL":{"COMPRESSIBILITY":0.0,"COMPRESSIBILITY_FACTOR":{"dP":9.478087208487739e-08,"dT":-0.001276224430310039,"dz":[0.0003736701596725362,-0.2746866444299045,0.29853223198724876,-0.6784856477438976],"value":0.4649989533023329},"LN_FUGACITY_COEFFICIENTS":{"dP":[-2.0368303168903628e-07,-1.4525400508533775e-07,-7.052848122336623e-08,-1.9910715710033002e-07],"dT":[0.0025469133914015002,0.06435858888093145,0.12263490437806211,0.033500355218654514],"dz":[[-0.00026067262754005143,0.07655306731901125,-0.09071187559040415,0.49426344454932625],[8.968218895678454e-05,-0.03204464658820776,0.03702406716292107,-0.1682716009512545],[-5.6726685785917934e-05,0.02315200652788438,-0.026376222455421577,0.10641614322520081],[0.00039384527559937306,-0.137148335777074,0.15903609298506366,-0.7438299303594125]],"value":[2.5449468400574675,-9.342451945033686,-19.796001971601456,-3.4073581524079706]},"MASS_DENSITY":{"dP":1.7564808238636303e-08,"dT":-0.34421935858838537,"dz":[0.02518880950554893,2.503348353967836,-1.343733137854427,-49.70992026793742],"value":750.0053500173889},"MASS_ENTHALPY":0.0,"MOLECULAR_WEIGHT":{"dP":-2.6936027136715886e-09,"dT":3.0412409975213977e-05,"dz":[0.00015739122864262499,-0.11042552845427862,0.12035673362479646,-0.28676432173885075],"value":0.18799434509979238},"MOLE_COMPOSITION":{"dP":[1.5478023818948e-08,-7.771296663717763e-09,-7.575537670742356e-09,-1.3118879869580224e-10],"dT":[-0.00016352182449888496,8.510141415982033e-05,8.628738912942096e-05,-7.866969387806338e-06],"dz":[[2.291648366626796e-05,-0.005840957660814373,0.0070683207302598165,-0.043693717349259836],[0.00032158628299112045,0.8283314774275885,-0.8305962775569159,-0.781193235654662],[0.00046635751234059853,-0.8033213138712682,0.8429385589379355,-0.7615147375216054],[-0.0008108510461389723,-0.01916917714947107,-0.019410624340800126,1.5864024628054438]],"value":[0.07709016197537805,0.46173873851641745,0.4500457191133626,0.011125380394841866]},"MOLE_DENSITY":{"dP":5.725555530894867e-05,"dT":-2.4764041555986727,"dz":[-3.206049653524391,2356.7045838368717,-2561.290566140595,5821.130687121025],"value":3989.510161166104},"VISCOSITY":0.0}},"PHASE_STATE":"OIL_GAS","PHASE_TYPES":["OIL","GAS"],"PRESSURE":4583333.333333334,"TEMPERATURE":297.15}}
)"_json;
  json const & refProperties = j1["PROPERTIES"];

  // TODO refMsp should be some reimpl of PVTPackage::MultiphaseSystemProperties, not the original impl that will change.
  PVTPackage::pds::MultiphaseSystemProperties refMsp = refProperties.get< PVTPackage::pds::MultiphaseSystemProperties >();

  // TODO Check that all ComponentProperties are the same.
  std::shared_ptr< PVTPackage::pds::CubicEoSPhaseModel > pm = std::dynamic_pointer_cast< PVTPackage::pds::CubicEoSPhaseModel >( refMsp.PhaseModels.at( refMsp.PhaseTypes[0] ) );
//  const PVTPackage::ComponentProperties & componentProperties = pm->get_ComponentsProperties();
  const PVTPackage::pds::ComponentProperties & componentProperties = pm->m_ComponentsProperties;
  componentProperties.Label.size();

  PVTPackage::MultiphaseSystemProperties msp( convert( refMsp.PhaseTypes ), refMsp.Feed.size() );
  msp.Temperature = refMsp.Temperature ;
  msp.Pressure = refMsp.Pressure ;
  msp.Feed = refMsp.Feed ;

  msp.PhaseModels = convert( refMsp.PhaseModels );
  // the PhaseMoleFraction and PhasesProperties seem to be the results, so no need to copy.

  PVTPackage::NegativeTwoPhaseFlash flash( convert( componentProperties ) );
  flash.ComputeEquilibrium( msp );

  compare( msp, refMsp );
}
