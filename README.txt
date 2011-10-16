//------------------------------
  libvm  - Virtual Machine, a static library
//------------------------------

  Cross platfrom code to OS functions

  Based on sample code from example code for the Intel IPP library



//------------------------------
  Building process
//------------------------------

  To build use


   ./build.sh configure
   ./build.sh build


  it will:
    configure
      create directories ./build/debug and ./build/release
      run cmake with release and debug with CMAKE_BUILD_TYPE
    build
      just run make file for both debug and release

 -- Release --
  You can also run in order to compile only release version

    ./build.sh configure
    ./build.sh release

 --Debug --
  Or run, to compile only debug wersion

    ./build.sh configure
    ./build.sh debug

 -- Clean--
  After the job done, be sure to clean up the mess:

    ./build.sh clean

  (it removes all files and subdirectories from ./build directory)

//------------------------------


 CMAKE is used to bring native compilation envirenments for different platforms

 e.g.: We use QTCreater to debug. It is easy to import cmake project to it.
  Just use "open project" in file menu, select global project's CMakeLists.txt.
  Set arguments -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=./build/debug
  and you are ready.

  For other IDE use cmake-gui
  to generate eg.: VS2010 project.



If
