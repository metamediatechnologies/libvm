##########################################
# Library VM 
##########################################

# CMake compatibility issues: don't modify this, please!
CMAKE_MINIMUM_REQUIRED( VERSION 2.6 )
MARK_AS_ADVANCED(CMAKE_BACKWARDS_COMPATIBILITY)
# allow more human readable "if then else" constructs
SET( CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS TRUE )



project(vm)



INCLUDE(AddFileDependencies)
INCLUDE(CheckIncludeFiles)
INCLUDE(FindPkgConfig)

#-------- find dependencies -----------------------------------------------

CHECK_INCLUDE_FILES(stdint.h      VM_HAVE_STDINT_H)
CHECK_INCLUDE_FILES(stdlib.h      VM_HAVE_HAVE_STDLIB_H)
CHECK_INCLUDE_FILES(pthread.h     VM_HAVE_HAVE_PTHREAD_H)
CHECK_INCLUDE_FILES(semaphore.h   VM_HAVE_HAVE_SEMAPHORE_H)
CHECK_INCLUDE_FILES(unistd.h      VM_HAVE_HAVE_UNISTD_H)
CHECK_INCLUDE_FILES(sys/types.h   VM_HAVE_HAVE_SYS_TYPES_H)
CHECK_INCLUDE_FILES(sys/ipc.h     VM_HAVE_HAVE_SYS_IPC_H)
CHECK_INCLUDE_FILES(sys/shm.h     VM_HAVE_HAVE_SYS_SHM_H)
CHECK_INCLUDE_FILES(sys/time.h    VM_HAVE_HAVE_SYS_TIME_H)
CHECK_INCLUDE_FILES(sys/wait.h    VM_HAVE_HAVE_SYS_WAIT_H)
CHECK_INCLUDE_FILES(sys/select.h  VM_HAVE_HAVE_SYS_SELECT_H)
CHECK_INCLUDE_FILES(stdarg.h      VM_HAVE_HAVE_STDARG_H)
CHECK_INCLUDE_FILES(signal.h      VM_HAVE_HAVE_SIGNAL_H)
CHECK_INCLUDE_FILES(sched.h       VM_HAVE_HAVE_SCHED_H)
CHECK_INCLUDE_FILES(soundcard.h   VM_HAVE_SOUNDCARD_H)
CHECK_INCLUDE_FILES(fcntl.h       VM_HAVE_FCNTL_H)
CHECK_INCLUDE_FILES(sys/ioctl.h   VM_HAVE_SYS_IOCTL_H)
CHECK_INCLUDE_FILES(ctype.h       VM_HAVE_CTYPE_H)
CHECK_INCLUDE_FILES(string.h      VM_HAVE_STRING_H)
CHECK_INCLUDE_FILES(process.h     VM_HAVE_PROCESS_H)
CHECK_INCLUDE_FILES(locale.h      VM_HAVE_LOCALE_H)

#check for libraries
find_package(Threads REQUIRED)


#-------- set environmetns ------------------------------------------------

 

ADD_DEFINITIONS( "-O2 -Wall -fPIC -static" )
ADD_DEFINITIONS(-DUNICODE)	

#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
#SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin/lib)

#  #_DEBUG;WIN32;_WIN32;_WIN32_WINNT=0x500;_WINDOWS;STRICT;CLIPPING_DENORMAL_MODE;_USC_ALL

#----- sources and headers ------------------------------------------------


include_directories( ./include )
include_directories( ./include/sys )
#ipp
include_directories( /opt/intel/ipp/include/ )

IF(WIN32 AND NOT UNIX)
  SET( library_sources 
    "./src/vm_debug_win32.c"
    "./src/vm_event_win32.c"
    "./src/vm_file_win32.c"
    "./src/vm_mmap_win32.c"
    "./src/vm_mutex_win32.c"
    "./src/vm_semaphore_win32.c"
    "./src/vm_shared_object_win32.c"
    "./src/vm_socket_win32.c"
    "./src/vm_sys_info_win32.c"
    "./src/vm_thread_win32.c"
    "./src/vm_time_win32.c"
  )
  ADD_DEFINITIONS( "-DWINDOWS" )
  ADD_DEFINITIONS( "-DWIN32" )
ELSEIF(UNIX)
  SET( library_sources ${library_sources}
    "./src/vm_debug_linux32.c"
    "./src/vm_event_linux32.c"
    "./src/vm_file_unix.c"
    "./src/vm_mmap_linux32.c"
    "./src/vm_mutex_linux32.c"
    "./src/vm_semaphore_linux32.c"
    "./src/vm_shared_object_linux32.c"
    "./src/vm_socket_linux32.c"
    "./src/vm_sys_info_linux32.c"
    "./src/vm_thread_linux32.c"
    "./src/vm_time_linux32.c"
    "./src/vm_atomicops_x86_gcc.c"
  )

  ADD_DEFINITIONS( "-DLINUX32" )
  ADD_DEFINITIONS( "-DLINUX" )
ELSEIF(APPLE)
  SET( library_sources ${library_sources} '')

  ADD_DEFINITIONS( "-DAPPLE" )
  ADD_DEFINITIONS( "-DMACOSX" )
ELSE()
  AUX_SOURCE_DIRECTORY( ./src library_sources)
ENDIF()
#common
SET( library_sources ${library_sources} "./src/vm_file.c")




# display status message for important variables
MESSAGE( STATUS )
MESSAGE( STATUS "-------------------------------------------------------------------------------" )
MESSAGE( STATUS "SOURCES = ${library_sources}" )
MESSAGE( STATUS "-------------------------------------------------------------------------------" )
MESSAGE( STATUS )

add_library( ${PROJECT_NAME} ${library_sources} )

## Link libraries
target_link_libraries( ${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})

target_link_libraries( ${PROJECT_NAME} libpthread.a)
target_link_libraries( ${PROJECT_NAME} libm.a)

#link_directories(/opt/intel/ipp/lib/intel64/)
#target_link_libraries( ${PROJECT_NAME} libippcore_l.a)
#target_link_libraries( ${PROJECT_NAME} libipps_l.a)
#target_link_libraries( ${PROJECT_NAME} libiomp5.a)

INSTALL( TARGETS ${PROJECT_NAME} DESTINATION "/bin" )
