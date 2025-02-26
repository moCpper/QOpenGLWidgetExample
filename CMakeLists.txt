cmake_minimum_required (VERSION 3.8)

project ("QOpenGLWidget")

set(qt5base "D:/Qt/5.14.2/5.14.2/msvc2017_64/lib/cmake")		# 可替换路径 
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${qt5base})
set(QT5_DIR ${qt5base}/Qt5)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)		# 设置输出路径

set(source ${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB source CONFIGURE_DEPENDS *.cpp)						# 查找工作目录下*.cpp

find_package(Qt5 REQUIRED COMPONENTS Core Widgets OpenGL)

set(CMAKE_AUTOMOC ON)  # 启用 MOC 处理
set(CMAKE_INCLUDE_CURRENT_DIR ON)  # 包括当前目录，方便头文件包含

add_executable(QOpenGLWidget ${source})

if (CMAKE_VERSION VERSION_GREATER 3.12)						
  set_property(TARGET QOpenGLWidget PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(QOpenGLWidget PRIVATE Qt5::Core Qt5::Widgets Qt5::OpenGL)		# 链接Qt库

target_include_directories(QOpenGLWidget PRIVATE .)			# 设置.h包含目录
