set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# SET SOURCES AND STUFF
file(GLOB_RECURSE CPPs *.cpp)
file(GLOB_RECURSE HPPs *.h)

# FIND LIBRARIES
find_package(OpenCV REQUIRED)

add_executable(fontgen ${CPPs} ${HPPs})

#if(OPENCV_FOUND)
target_link_libraries(fontgen ${OpenCV_LIBS})
	include_directories(${OPENCV_INCLUDE_DIRS})
	#endif(OPENCV_FOUND)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY})

