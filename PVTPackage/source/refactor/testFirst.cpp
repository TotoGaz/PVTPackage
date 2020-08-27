// This include is necessary for nlohmann::json to find the proper serializers
#include "SerializersDeserializers.hpp"

#include "MultiphaseSystem/MultiphaseSystemProperties.hpp"

#include <gtest/gtest.h>

#include <nlohmann/json.hpp>

using json = nlohmann::json;


TEST( PVTPackageRefactor, first )
{

  json j1 = R"({"PROPERTIES":{"FEED":[0.44130817116386345,0.27943529607843004,0.27232239763279725,0.006934135124909191],"PHASE_MODELS":{"GAS":{"COMPONENT_PROPERTIES":{"labels":["N2","C10","C20","H2O"],"mw":[0.028,0.134,0.275,0.018],"n_components":4,"omega":[0.04,0.443,0.816,0.344],"pc":[3400000.0,2530000.0,1460000.0,22050000.0],"tc":[126.2,622.0,782.0,647.0]},"EOS":"PENG_ROBINSON","PHASE_TYPE":"GAS"},"OIL":{"COMPONENT_PROPERTIES":{"labels":["N2","C10","C20","H2O"],"mw":[0.028,0.134,0.275,0.018],"n_components":4,"omega":[0.04,0.443,0.816,0.344],"pc":[3400000.0,2530000.0,1460000.0,22050000.0],"tc":[126.2,622.0,782.0,647.0]},"EOS":"PENG_ROBINSON","PHASE_TYPE":"OIL"}},"PHASE_MOLE_FRACTION":{"GAS":{"dP":-1.0262333495276263e-08,"dT":8.361594916856232e-05,"dz":[0.5888741959800442,-0.4631806178462396,-0.46874906259239396,-0.40310218009472104],"value":0.41193094837710786},"OIL":{"dP":1.0262333495276263e-08,"dT":-8.361594916856232e-05,"dz":[-0.5888741875385731,0.4631806178462396,0.4687490489126888,0.4031027173329239],"value":0.5880690516228921}},"PHASE_PROPERTIES":{"GAS":{"COMPRESSIBILITY":0.0,"COMPRESSIBILITY_FACTOR":{"dP":-2.5631546974181998e-09,"dT":0.00027213792857307904,"dz":[1.3793363775921117e-05,0.0001628575362450684,0.0003095990860622848,-0.019604896499263065],"value":0.9894822714893305},"LN_FUGACITY_COEFFICIENTS":{"dP":[-3.5405434401971774e-09,-1.8171175462858925e-07,-3.5899995906012217e-07,-7.096741689102955e-08],"dT":[0.0002924888124303021,0.006128785266084262,0.012530039631088292,0.002016395564764874],"dz":[[-4.0096987720700925e-08,-3.3328736133977657e-07,-8.849059243396099e-07,5.3287314247524256e-05],[0.00012383638102372264,0.001176344407595968,0.0030759090535205404,-0.1761120552839917],[0.0002585453768230796,0.002455447974440216,0.006420979984796539,-0.36764499594326694],[3.4761977986072925e-05,0.0003304144242850277,0.0008636887017131251,-0.04944230042955797]],"value":[-0.011796622137078334,-0.558468166997776,-1.1086618270600828,-0.21209013364174698]},"MASS_DENSITY":{"dP":1.154242106846395e-05,"dT":-0.12112889168093544,"dz":[0.000385741463344242,0.032509222506926505,-0.01991940164323536,-0.5520573814616556],"value":33.41059265663952},"MASS_ENTHALPY":0.0,"MOLECULAR_WEIGHT":{"dP":6.822070905140433e-13,"dT":4.164311027310005e-07,"dz":[7.138318998172151e-07,3.185727243366254e-05,-7.93337398255772e-06,-0.00101756273363026],"value":0.028003691919148165},"MOLE_COMPOSITION":{"dP":[1.9228373255048383e-10,-1.0696833591542285e-11,6.375649722453318e-16,-1.8158729903266807e-10],"dT":[-2.7323810214001636e-05,5.944343330903387e-06,4.836772825825614e-10,2.1379002133295137e-05],"dz":[[7.023303954446983e-05,0.0011197388821460204,0.001278477880223092,-0.09980059199501541],[1.0093905553991005e-07,0.00017811233637102532,-0.00017863136609231887,-0.00016872860283838762],[4.445841230845619e-12,-7.684811517123665e-09,8.010752601537555e-09,-5.1987381945506326e-09],[-7.033524399631219e-05,-0.0012978181989830536,-0.0010998144389628333,0.09996911480519259]],"value":[0.9991944209931032,0.00010126370019417044,4.357955679877347e-09,0.0007043109487469755]},"MOLE_DENSITY":{"dP":0.000412145915876114,"dT":-4.343203281709206,"dz":[-0.016631183764130454,-0.19636246140974473,-0.3732856645491814,23.640268855177144],"value":1193.0781395932393},"VISCOSITY":0.0},"OIL":{"COMPRESSIBILITY":0.0,"COMPRESSIBILITY_FACTOR":{"dP":9.943503652300104e-08,"dT":-0.0008457955759238281,"dz":[0.0003301965835121973,-0.180581971425029,0.19602864210741,-0.44240491530234427],"value":0.3032082159643489},"LN_FUGACITY_COEFFICIENTS":{"dP":[-3.2838023390088596e-07,-2.6991389138357844e-07,-1.9525042942591977e-07,-3.2368536676679175e-07],"dT":[0.002556321056359091,0.06469700445652765,0.12337501855186922,0.033563068872989925],"dz":[[-0.0003634559796426314,0.08061085427481748,-0.09484041059277237,0.49884930984905523],[0.00011345337157183588,-0.031235798156719487,0.03586665467292647,-0.1571486211989597],[-8.914193480644248e-05,0.02668602572959793,-0.030409656147861158,0.12481117929159254],[0.0005319477427805662,-0.1406179371975878,0.1622034371875432,-0.737546392338603]],"value":[2.9727896076747435,-9.012027819190541,-19.59006686483733,-2.987251711231303]},"MASS_DENSITY":{"dP":-1.7735072544642768e-09,"dT":-0.3418565442168823,"dz":[0.03443796055940527,2.5622953164516566,-1.4257921074930155,-49.476664333966575],"value":749.9916497475427},"MASS_ENTHALPY":0.0,"MOLECULAR_WEIGHT":{"dP":-2.873328541006346e-09,"dT":2.3115843147179033e-05,"dz":[0.000218612997788811,-0.11406579966678729,0.12417099108195458,-0.2937680275706123],"value":0.19262847545783127},"MOLE_COMPOSITION":{"dP":[1.6420535636799594e-08,-8.281722664833027e-09,-8.081145797456974e-09,-5.767120580588039e-11],"dT":[-0.00011574966516175869,6.337533058193387e-05,6.584358770629867e-05,-1.3469287210717475e-05],"dz":[[2.1794823193975725e-05,-0.004015981055636578,0.004855896892838881,-0.03024187714228336],[0.0004780742742261423,0.8510557562874238,-0.8536727362643877,-0.8006557640301636],[0.0006340051283686239,-0.8278136288570332,0.8682819910169196,-0.780505033516781],[-0.001133894801874546,-0.01922617387096139,-0.019465183707179687,1.6114011301293947]],"value":[0.05051968919138202,0.47510336015019233,0.46307894470231564,0.011298005956110128]},"MOLE_DENSITY":{"dP":5.8067327008928276e-05,"dT":-2.2419178278140746,"dz":[-4.239949148150231,2318.832402722996,-2517.1814465727334,5680.873453918821],"value":3893.4620022558665},"VISCOSITY":0.0}},"PHASE_STATE":"OIL_GAS","PHASE_TYPES":["OIL","GAS"],"PRESSURE":2916666.6666666665,"TEMPERATURE":297.15}})"_json;
  json const & refProperties = j1["PROPERTIES"];

  PVTPackage::MultiphaseSystemProperties msp = refProperties.get< PVTPackage::MultiphaseSystemProperties >();

  j1.size();

  EXPECT_EQ( true, false );

}
