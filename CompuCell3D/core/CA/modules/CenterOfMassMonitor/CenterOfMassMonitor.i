// -*-c++-*-


%module ("threads"=1) CenterOfMassMonitor

%include "typemaps.i"

%include stl.i //to ensure stl functionality 

// // // %include "CompuCellExtraIncludes.i"

// C++ std::string handling
%include "std_string.i"

// C++ std::map handling
%include "std_map.i"

// C++ std::map handling
%include "std_set.i"

// C++ std::map handling
%include "std_vector.i"

%include "stl.i"

%import "../../../CAPython/CoreObjects.i"


// ************************************************************
// Module Includes 
// ************************************************************

// These are copied directly to the .cxx file and are not parsed
// by SWIG.  Include include files or definitions that are required
// for the module to build correctly.
//DOCSTRINGS



%include <windows.i>

%{

// #include <CA/ProbabilityFunction.h>
#include <CA/modules/CenterOfMassMonitor/CenterOfMassMonitor.h>


// Namespaces
using namespace std;
using namespace CompuCell3D;



%}




%include stl.i //to ensure stl functionality 

// // // %include "CompuCellExtraIncludes.i"

// C++ std::string handling
%include "std_string.i"

// C++ std::map handling
%include "std_map.i"

// C++ std::map handling
%include "std_set.i"

// C++ std::map handling
%include "std_vector.i"

%include "stl.i"

//enables better handling of STL exceptions
%include "exception.i"

%exception {
  try {
    $action
  } catch (const std::exception& e) {
    SWIG_exception(SWIG_RuntimeError, e.what());
  }
}

// %include "swig_includes/numpy.i"
// // // %include "pyinterface/swig_includes/numpy.i"

// // // %init %{
    // // // import_array();
// // // %}


//C arrays
//%include "carrays.i"

// ******************************
// Third Party Classes
// ******************************
#define CENTEROFMASSMONITOR_EXPORT
// // // %include <CA/ProbabilityFunction.h>
%include <CA/modules/CenterOfMassMonitor/CenterOfMassMonitor.h>
