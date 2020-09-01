#include "PropertyAndDerivatives.hpp"

#include "MultiphaseSystem/PropertyAndDerivatives.hpp"

#include <nlohmann/json.hpp>

namespace PVTPackage {

using json = nlohmann::json;

class ScalarVectorPropertyAndDerivativesHelper
{
public:
  static void to_json( json & j,
                       const ScalarPropertyAndDerivatives< double > & s )
  {
    j = json{ { VALUE, s.value },
              { DP,    s.dP },
              { DT,    s.dT },
              { DZ,    s.dz } };
  }

  static void from_json( const json & j,
                         pds::ScalarPropertyAndDerivatives< double > & s )
  {
    s.value = j[VALUE].get< double >();
    s.dP = j[DP].get< double >();
    s.dT = j[DT].get< double >();
    s.dz = j[DZ].get< std::vector< double > >();
  }

  static void to_json( json & j,
                       const VectorPropertyAndDerivatives< double > & s )
  {
    j = json{ { VALUE, s.value },
              { DP,    s.dP },
              { DT,    s.dT },
              { DZ,    s.dz } };
  }

  static void from_json( const json & j,
                         pds::VectorPropertyAndDerivatives< double > & s )
  {
    s.value = j[VALUE].get< std::vector< double > >();
    s.dP = j[DP].get< std::vector< double > >();
    s.dT = j[DT].get< std::vector< double > >();
    s.dz = j[DZ].get< std::vector< std::vector< double > > >();
  }

private:
  static constexpr auto VALUE = "value";
  static constexpr auto DP = "dP";
  static constexpr auto DT = "dT";
  static constexpr auto DZ = "dz";
};

decltype( ScalarVectorPropertyAndDerivativesHelper::VALUE ) ScalarVectorPropertyAndDerivativesHelper::VALUE;
decltype( ScalarVectorPropertyAndDerivativesHelper::DP ) ScalarVectorPropertyAndDerivativesHelper::DP;
decltype( ScalarVectorPropertyAndDerivativesHelper::DT ) ScalarVectorPropertyAndDerivativesHelper::DT;
decltype( ScalarVectorPropertyAndDerivativesHelper::DZ ) ScalarVectorPropertyAndDerivativesHelper::DZ;

void to_json( json & j,
              const ScalarPropertyAndDerivatives< double > & s )
{
  ScalarVectorPropertyAndDerivativesHelper::to_json( j, s );
}

void to_json( json & j,
              const VectorPropertyAndDerivatives< double > & v )
{
  ScalarVectorPropertyAndDerivativesHelper::to_json( j, v );
}

namespace pds
{

void from_json( const nlohmann::json & j,
                pds::ScalarPropertyAndDerivatives< double > & s )
{
  ScalarVectorPropertyAndDerivativesHelper::from_json( j, s );
}

void from_json( const nlohmann::json & j,
                pds::VectorPropertyAndDerivatives< double > & s )
{
  ScalarVectorPropertyAndDerivativesHelper::from_json( j, s );
}

}

}
