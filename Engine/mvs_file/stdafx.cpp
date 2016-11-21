// stdafx.cpp : source file that includes just the standard includes
// Engine.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need to pre-compile in STDAFX.H
// and not in this file

/*
Pre-compiled headers can greatly speed the up the compilation of the .cpp files in your project. 
By convention, it is stdafx.h that #includes all of the .h files that you want to be precompiled. 
You can name it anything you want but the project template just picks stdafx.h 
But before that can work, there must be one .cpp file that #includes stdafx.h and gets compiled first.
Before all the other .cpp files in your project. Once that's done, the compiler can use the .pch file
that was created and quickly compile all the other .cpp files, no longer having to actually #include the headers anymore.
Stdafx.cpp is that one .cpp file. It has a setting that's different from all the other .cpp files, 
it gets built with /Yc. The "Create precompiled header file" option.
*/

// source : http://stackoverflow.com/questions/17903843/what-is-stdafx-cpp-file-that-is-created-automatically-in-a-new-c-project-in-vi