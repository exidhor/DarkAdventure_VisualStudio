#pragma once
//disable warnings on 255 char debug symbols
#pragma warning (disable : 4786)
//disable warnings on extern before template instantiation
#pragma warning (disable : 4231)

#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport) 
#else
#define ENGINE_API __declspec(dllimport) 
#endif


// TO USE ?


/*
 
// Provide the storage class specifier (extern for an .exe file, null
// for DLL) and the __declspec specifier (dllimport for .an .exe file,
// dllexport for DLL).
// You must define EXP_STL when compiling the DLL.
// You can now use this header file in both the .exe file and DLL - a
// much safer means of using common declarations than two different
// header files.
#ifdef STL_EXPORT
#    define EXPIMP_TEMPLATE
#else
#    define EXPIMP_TEMPLATE extern
#endif

#include <vector>
#include <string>

// Instantiate classes vector<int> and vector<char>
// This does not create an object. It only forces the generation of all
// of the members of classes vector<int> and vector<char>. It exports
// them from the DLL and imports them into the .exe file.
EXPIMP_TEMPLATE template class ENGINE_API std::vector<int>;
EXPIMP_TEMPLATE template class ENGINE_API std::vector<char>;


// Declare/Define a class that contains both a static and non-static
// data member of an STL object.
// Note that the two template instantiations above are required for
// the data members to be accessible. If the instantiations above are
// omitted, you may experience an access violation.
// Note that since you are exporting a vector of MyClass, you must
// provide implementations for the operator < and the operator ==.

// Instantiate the class vector<MyClass>
// This does not create an object. It only forces the generation of
// all of the members of the class vector<MyClass>. It exports them
// from the DLL and imports them into the .exe file.

// EXPIMP_TEMPLATE template class ENGINE_API std::vector<MyClass>;

*/