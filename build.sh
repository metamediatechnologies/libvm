

#
# Simple script to make less typing,
# and maybe to use in automatic builds
#
trap exit 2

configure=0
build=0
release=0
debug=0
clean=0

while [ "$1" != "" ]; do
    if [ "$1" = "configure" ]; then
        echo "Configuring products"
        configure=1;
    elif [ "$1" = "build" ]; then
        echo "Building products (debug and release version)"
        build=1;
    elif [ "$1" = "release" ]; then

        release=1;
    elif [ "$1" = "debug" ]; then
        debug=1;
    elif [ "$1" = "clean" ]; then
        echo "Cleaning products"
        clean=1;
    fi
    shift
done

echo

if [ $configure -eq 1 ]; then
  rm -fR ./build
  mkdir ./build
  mkdir ./build/debug
  mkdir ./build/release 

  echo
  echo "--     Configuring DEBUG version"
  echo
  cd ./build/debug

  cmake -D CMAKE_BUILD_TYPE=Debug ../../

  echo
  echo "--     Configuring RELEASE version"
  echo
  cd ../release

  cmake ../../

elif [ $build -eq 1 ]; then
  echo
  echo "--     Building DEBUG version"
  echo
  cd ./build/debug
  make

  cd ../release
  echo
  echo "--     Building RELEASE version"
  echo
  make

elif [ $release -eq 1 ]; then
  echo
  echo "--     Building RELEASE version"
  echo
  cd ./build/release
  make

elif [ $debug -eq 1 ]; then
  echo
  echo "--     Building DEBUG version"
  echo
  cd ./build/debug
  make

elif [ $clean -eq 1 ]; then
  rm -fR ./build/*
else
  cd ./build
  cmake ..
  make
fi

echo
echo "--  Done ! "
echo
