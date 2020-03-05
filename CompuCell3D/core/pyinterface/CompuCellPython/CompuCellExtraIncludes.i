// ************************************************************
// Module Includes
// ************************************************************

// These are copied directly to the .cxx file and are not parsed
// by SWIG.  Include include files or definitions that are required
// for the module to build correctly.


%{


// CompuCell3D Include Files
#include <CompuCell3D/ClassRegistry.h>
#include <CompuCell3D/Simulator.h>
#include <CompuCell3D/PluginManager.h>
#include <CompuCell3D/Steppable.h>
#include <CompuCell3D/Potts3D/Potts3D.h>
//NeighborFinderParams
#include <NeighborFinderParams.h>
#include <Python.h>
#include <Utils/Coordinates3D.h>
#include <CompuCell3D/Field3D/Array3D.h>

// Third Party Libraries

// System Libraries
#include <iostream>
#include <stdlib.h>




//PyObjectAdapetrs

//EnergyFcns
//#include <CompuCell3D/Potts3D/EnergyFunction.h>

#include <PyCompuCellObjAdapter.h>
#include <EnergyFunctionPyWrapper.h>
#include <ChangeWatcherPyWrapper.h>
#include <TypeChangeWatcherPyWrapper.h>
#include <StepperPyWrapper.h>
#include <PyAttributeAdder.h>
#include <CompuCell3D/steppables/PDESolvers/DiffusableVector.h>


#include <CompuCell3D/ParseData.h>
#include <CompuCell3D/ParserStorage.h>

//Plugins

#include <BasicUtils/BasicClassAccessor.h>
#include <BasicUtils/BasicClassGroup.h> //had to include it to avoid problems with template instantiation

#include <CompuCell3D/Automaton/Automaton.h>

//#include <CompuCell3D/plugins/ConnectivityLocalFlex/ConnectivityLocalFlexData.h>
//
//#include <CompuCell3D/plugins/ConnectivityLocalFlex/ConnectivityLocalFlexPlugin.h>
//
//#include <CompuCell3D/plugins/ConnectivityGlobal/ConnectivityGlobalData.h>
//
//#include <CompuCell3D/plugins/ConnectivityGlobal/ConnectivityGlobalPlugin.h>
//
//
//// #include <CompuCell3D/plugins/LengthConstraintLocalFlex/LengthConstraintLocalFlexData.h>
//// #include <CompuCell3D/plugins/LengthConstraintLocalFlex/LengthConstraintLocalFlexPlugin.h>
//
//#include <CompuCell3D/plugins/LengthConstraint/LengthConstraintData.h>
//#include <CompuCell3D/plugins/LengthConstraint/LengthConstraintPlugin.h>
//
//
//#include <CompuCell3D/plugins/ChemotaxisSimple/ChemotaxisSimpleEnergy.h>
//
//#include <CompuCell3D/plugins/Chemotaxis/ChemotaxisData.h>
//#include <CompuCell3D/plugins/Chemotaxis/ChemotaxisPlugin.h>
//
//
//// //plugins
//#include <CompuCell3D/plugins/Mitosis/MitosisPlugin.h>
//
//#include <CompuCell3D/plugins/Mitosis/MitosisSimplePlugin.h>
//
//#include <CompuCell3D/plugins/VolumeTracker/VolumeTrackerPlugin.h>
//
//#include <CompuCell3D/plugins/CenterOfMass/CenterOfMassPlugin.h>
//
//#include <CompuCell3D/plugins/NeighborTracker/NeighborTracker.h>
//#include <CompuCell3D/plugins/NeighborTracker/NeighborTrackerPlugin.h>
//
//#include <CompuCell3D/plugins/PixelTracker/PixelTracker.h>
//#include <CompuCell3D/plugins/PixelTracker/PixelTrackerPlugin.h>
//
//#include <CompuCell3D/plugins/BoundaryPixelTracker/BoundaryPixelTracker.h>
//#include <CompuCell3D/plugins/BoundaryPixelTracker/BoundaryPixelTrackerPlugin.h>
//
//#include <CompuCell3D/plugins/ContactLocalFlex/ContactLocalFlexData.h>
//#include <CompuCell3D/plugins/ContactLocalFlex/ContactLocalFlexPlugin.h>
//
//#include <CompuCell3D/plugins/ContactLocalProduct/ContactLocalProductData.h>
//#include <CompuCell3D/plugins/ContactLocalProduct/ContactLocalProductPlugin.h>
//
//#include <CompuCell3D/plugins/ContactMultiCad/ContactMultiCadData.h>
//#include <CompuCell3D/plugins/ContactMultiCad/ContactMultiCadPlugin.h>
//
//#include <CompuCell3D/plugins/AdhesionFlex/AdhesionFlexData.h>
//#include <CompuCell3D/plugins/AdhesionFlex/AdhesionFlexPlugin.h>
//
//
//// #include <CompuCell3D/plugins/MolecularContact/MolecularContactPlugin.h>
//
//#include <CompuCell3D/plugins/CellOrientation/CellOrientationVector.h>
//#include <CompuCell3D/plugins/CellOrientation/CellOrientationPlugin.h>
//
//#include <CompuCell3D/plugins/PolarizationVector/PolarizationVector.h>
//#include <CompuCell3D/plugins/PolarizationVector/PolarizationVectorPlugin.h>
//
//#include <CompuCell3D/plugins/ElasticityTracker/ElasticityTracker.h>
//#include <CompuCell3D/plugins/ElasticityTracker/ElasticityTrackerPlugin.h>
//
//#include <CompuCell3D/plugins/PlasticityTracker/PlasticityTracker.h>
//#include <CompuCell3D/plugins/PlasticityTracker/PlasticityTrackerPlugin.h>
//
//#include <CompuCell3D/plugins/FocalPointPlasticity/FocalPointPlasticityTracker.h>
//#include <CompuCell3D/plugins/FocalPointPlasticity/FocalPointPlasticityPlugin.h>
//
//#include <CompuCell3D/plugins/MomentOfInertia/MomentOfInertiaPlugin.h>
//
//#include <CompuCell3D/plugins/Secretion/FieldSecretor.h>
//#include <CompuCell3D/plugins/Secretion/SecretionPlugin.h>
//
////Steppables
//#include <CompuCell3D/steppables/Mitosis/MitosisSteppable.h>
//
////AutogeneratedModules - DO NOT REMOVE THIS LINE IT IS USED BY TWEDIT TO LOCATE CODE INSERTION POINT
////BiasVectorSteppable_autogenerated
//
//
//#include <CompuCell3D/steppables/BiasVectorSteppable/BiasVectorSteppable.h>
//
////ImplicitMotility_autogenerated
//
//
//#include <CompuCell3D/plugins/ImplicitMotility/ImplicitMotilityPlugin.h>
//
////CurvatureCalculator_autogenerated
//
//#include <CompuCell3D/plugins/CurvatureCalculator/CurvatureCalculatorPlugin.h>
////OrientedGrowth_autogenerated
//#include <CompuCell3D/plugins/OrientedGrowth/OrientedGrowthData.h>
//#include <CompuCell3D/plugins/OrientedGrowth/OrientedGrowthPlugin.h>
////CleaverMeshDumper_autogenerated
//#include <CompuCell3D/steppables/CleaverMeshDumper/CleaverMeshDumper.h>
//
//// // // //CGALMeshDumper_autogenerated
//// // // #include <CompuCell3D/steppables/CGALMeshDumper/CGALMeshDumper.h>
//
////ContactOrientation_autogenerated
//#include <CompuCell3D/plugins/ContactOrientation/ContactOrientationData.h>
//#include <CompuCell3D/plugins/ContactOrientation/ContactOrientationPlugin.h>
////BoundaryMonitor_autogenerated
//
//
//#include <CompuCell3D/plugins/BoundaryMonitor/BoundaryMonitorPlugin.h>
////CellTypeMonitor_autogenerated
//
//#include <CompuCell3D/plugins/CellTypeMonitor/CellTypeMonitorPlugin.h>
////Polarization23_autogenerated
//#include <CompuCell3D/plugins/Polarization23/Polarization23Data.h>
//#include <CompuCell3D/plugins/Polarization23/Polarization23Plugin.h>
////ClusterSurface_autogenerated
//
//#include <CompuCell3D/plugins/ClusterSurface/ClusterSurfacePlugin.h>
//
////ClusterSurfaceTracker_autogenerated
//#include <CompuCell3D/plugins/ClusterSurfaceTracker/ClusterSurfaceTrackerPlugin.h>
//



// Namespaces
using namespace std;
using namespace CompuCell3D;

#define SWIG_EXPORT_ITERATOR_METHODS

%}



