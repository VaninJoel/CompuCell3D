FIND_PACKAGE(CUDA)
# LINK_LIBRARIES("c:/ProgramData/NVIDIA Corporation/NVIDIA GPU Computing SDK 4.1/C/common/lib/Win32/cutil32.lib")

#Include FindCUDA script
INCLUDE(FindCUDA)

IF(MSVC)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4251")
ENDIF(MSVC)

ADD_DEFINITIONS(-DPDESOLVERSGPU_EXPORT_COMPILER_DEFINITION)

INCLUDE_DIRECTORIES(${CUDA_TOOLKIT_INCLUDE})
#INCLUDE_DIRECTORIES(${CUDA_SDK_ROOT_DIR}/common/inc)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
# INCLUDE_DIRECTORIES("c:/ProgramData/NVIDIA Corporation/NVIDIA GPU Computing SDK 4.1/C/common/inc" ${CMAKE_CURRENT_SOURCE_DIR})

CUDA_ADD_LIBRARY(FlexibleDiffusionSolverFE_CUDA SHARED 
	FlexibleDiffusionSolverFE_GPU_CUDA.h 
	#FlexibleDiffusionSolverFE_CUDA.cu 
	FlexibleDiffusionSolverFE_GPU_CUDA.cu)

INSTALL_TARGETS(/lib/CompuCell3DSteppables RUNTIME_DIRECTORY /lib/CompuCell3DSteppables FlexibleDiffusionSolverFE_CUDA)



