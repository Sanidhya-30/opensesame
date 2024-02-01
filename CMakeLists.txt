cmake_minimum_required(VERSION 3.15)
project( opensesame )
set(CMAKE_CXX_STANDARD 17)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories("/usr/local/include/opencv4/opencv2")

add_executable( DispIm          DispIm.cpp )
add_executable( readFileSize    readFileSize.cpp  )
add_executable( compare         compare.cpp )

target_link_libraries( DispIm           ${OpenCV_LIBS} )
target_link_libraries( readFileSize     ${OpenCV_LIBS} )
target_link_libraries( compare          ${OpenCV_LIBS} )

