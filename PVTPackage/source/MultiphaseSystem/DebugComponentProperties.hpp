#ifndef GEOSX_DEBUGCOMPONENTPROPERTIES_HPP
#define GEOSX_DEBUGCOMPONENTPROPERTIES_HPP

#include "ComponentProperties.hpp"
#include "MultiphaseSystemProperties.hpp"

#include <vector>
#include <string>

namespace PVTPackage
{

class DebugComponentProperties
{
private:
  static const char * N_COMPONENTS;
  static const char * LABELS;
  static const char * MW;
  static const char * TC;
  static const char * PC;
  static const char * OMEGA;

  const std::size_t n_components;
  const std::vector <std::string> labels;
  const std::vector< double > mw;
  const std::vector< double > tc;
  const std::vector< double > pc;
  const std::vector< double > omega;

public:
  DebugComponentProperties( const ComponentProperties & comp )
    :
    n_components( comp.NComponents ),
    labels( comp.Label ),
    mw( comp.Mw ),
    tc( comp.Tc ),
    pc( comp.Pc ),
    omega( comp.Omega )
  { }

  void print() const ;
};

// FIXME Do functions instead.
class DebugMultiphaseSystemProperties
{
private:
  static const char * PHASE_MOLE_FRACTION;
  static const char * MASS_DENSITY;
  static const char * MOLE_DENSITY;
  static const char * MOLE_COMPOSITION;
  static const char * MOLECULAR_WEIGHT;

  const MultiphaseSystemProperties & props;
public:
  DebugMultiphaseSystemProperties(const MultiphaseSystemProperties & properties):
    props(properties){}

  void print() const ;
};


} // end of namespace PVTPackage

#endif //GEOSX_DEBUGCOMPONENTPROPERTIES_HPP
