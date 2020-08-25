set( PVTPackage_sources
     MultiphaseSystem/PhaseSplitModel/TrivialFlash.cpp
     MultiphaseSystem/PhaseSplitModel/CompositionalFlash.cpp
     MultiphaseSystem/PhaseSplitModel/DeadOilFlash.cpp
     MultiphaseSystem/PhaseSplitModel/BlackOilFlash.cpp
     MultiphaseSystem/PhaseSplitModel/FreeWaterFlash.cpp
     MultiphaseSystem/PhaseSplitModel/Flash.cpp
     MultiphaseSystem/PhaseSplitModel/NegativeTwoPhaseFlash.cpp
     MultiphaseSystem/DeadOilMultiphaseSystem.cpp
     MultiphaseSystem/CompositionalMultiphaseSystem.cpp
     MultiphaseSystem/PhaseModel/PhaseModel.cpp
     MultiphaseSystem/PhaseModel/BlackOil/BlackOil_Utils.cpp
     MultiphaseSystem/PhaseModel/BlackOil/BlackOil_OilModel.cpp
     MultiphaseSystem/PhaseModel/BlackOil/DeadOil_PhaseModel.cpp
     MultiphaseSystem/PhaseModel/BlackOil/BlackOil_WaterModel.cpp
     MultiphaseSystem/PhaseModel/BlackOil/BlackOil_GasModel.cpp
     MultiphaseSystem/PhaseModel/CubicEOS/CubicEoSPhaseModel.cpp
     MultiphaseSystem/MultiphaseSystem.cpp
     MultiphaseSystem/BlackOilMultiphaseSystem.cpp
     Utils/Timer.cpp
     Utils/StringUtils.cpp
     Utils/File.cpp
     Utils/LogMessage.cpp
     Utils/Logger.cpp
     PVTPackage.cpp
)

set( PVTPackage_headers
     MultiphaseSystem/ComponentProperties.hpp
     MultiphaseSystem/MultiphaseSystem.hpp
     MultiphaseSystem/BlackOilMultiphaseSystem.hpp
     MultiphaseSystem/MultiphaseSystemProperties.hpp
     MultiphaseSystem/CompositionalMultiphaseSystem.hpp
     MultiphaseSystem/PhaseSplitModel/NegativeTwoPhaseFlash.hpp
     MultiphaseSystem/PhaseSplitModel/Flash.hpp
     MultiphaseSystem/PhaseSplitModel/FreeWaterFlash.hpp
     MultiphaseSystem/PhaseSplitModel/DeadOilFlash.hpp
     MultiphaseSystem/PhaseSplitModel/BlackOilFlash.hpp
     MultiphaseSystem/PhaseSplitModel/TrivialFlash.hpp
     MultiphaseSystem/PhaseSplitModel/CompositionalFlash.hpp
     MultiphaseSystem/PropertyAndDerivatives.hpp
     MultiphaseSystem/PhaseModel/BlackOil/BlackOil_GasModel.hpp
     MultiphaseSystem/PhaseModel/BlackOil/PVTGdata.hpp
     MultiphaseSystem/PhaseModel/BlackOil/PVTOdata.hpp
     MultiphaseSystem/PhaseModel/BlackOil/DeadOil_PhaseModel.hpp
     MultiphaseSystem/PhaseModel/BlackOil/BlackOil_WaterModel.hpp
     MultiphaseSystem/PhaseModel/BlackOil/BlackOil_Utils.hpp
     MultiphaseSystem/PhaseModel/BlackOil/PVDdata.hpp
     MultiphaseSystem/PhaseModel/BlackOil/PVTWdata.hpp
     MultiphaseSystem/PhaseModel/BlackOil/BlackOil_OilModel.hpp
     MultiphaseSystem/PhaseModel/CubicEOS/CubicEoSPhaseModel.hpp
     MultiphaseSystem/PhaseModel/PhaseProperties.hpp
     MultiphaseSystem/PhaseModel/PhaseModel.hpp
     MultiphaseSystem/PVTEnums.hpp
     MultiphaseSystem/DeadOilMultiphaseSystem.hpp
     MultiphaseSystem/PhaseModelOutputVariables.hpp
     Utils/Logger.hpp
     Utils/macros.hpp
     Utils/File.hpp
     Utils/LogMessage.hpp
     Utils/math.hpp
     Utils/Timer.hpp
     Utils/FileUtils.hpp
     Utils/Assert.hpp
     Utils/StringUtils.hpp
     Utils/utils.hpp
     Utils/Types.hpp
     PVTPackage.hpp
)

# Expose includes
set(PVTPackage_INCLUDE_DIRS ${PROJECT_INC_DIR} CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)

set(PVTPackage_target PVTPackage)

set(PVTPackage_dependencies "")

# FIXME make conditional
add_subdirectory( refactor )
set(PVTPackage_dependencies ${PVTPackage_dependencies} PVTPackageDump)

message("adding PVTPackage library")
blt_add_library(NAME       ${PVTPackage_target}
                SOURCES    ${PVTPackage_sources}
                HEADERS    ${PVTPackage_headers}
                DEPENDS_ON ${PVTPackage_dependencies})

target_include_directories(${PVTPackage_target} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
