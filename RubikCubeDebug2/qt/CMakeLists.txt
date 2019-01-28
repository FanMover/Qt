cmake_minimum_required(VERSION 3.3)
project(RubikCubeDebug)
#下面的是重点 设置本地的Qt库位置，能够让IDE找到

#set (CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "path->/Qt5.5.1/5.5/gcc_64")
set (CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} /home/top/opt/Qt5.11.2/5.11.2/gcc_64)
set(CMAKE_INCLUDE_CURRENT_DIR on)
#QtMOC 以及Form处理
set(CMAKE_AUTOMOC on)
set(CMAKE_AUTOUIC on)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
#这个也是重点，使用到了说明模块就find什么模块
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(OpenCV REQUIRED)


INCLUDE_DIRECTORIES( ${OPENCV_INCLUDE_DIR} )

set(SOURCE_FILES main.cpp widget.h widget.cpp )


add_executable(RubikCubeDebug ${SOURCE_FILES})
#这个也要有，基本上就是与qmake中的
# Qt+=core 类似吧
# 前面的helloworld 要与add_executable()一样吧，，没测试过
qt5_use_modules(RubikCubeDebug Widgets Network)
#TARGET_LINK_LIBRARIES(RubikCubeDebug ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES(RubikCubeDebug Qt5::Widgets ${OpenCV_LIBS})