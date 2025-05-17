cmake_minimum_required(VERSION 3.14)

project(QCollada LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Gui Xml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Xml)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_OSX_ARCHITECTURES x86_64 arm64)

add_library(QCollada SHARED
  QCollada_global.h
  qcollada.cpp
  qcollada.h
  asset/animation/animation.cpp
  asset/animation/animation.h
  asset/animation/channel.cpp
  asset/animation/channel.h
  asset/animation/sampler.cpp
  asset/animation/sampler.h
  asset/common/accessor.cpp
  asset/common/accessor.h
  asset/common/floatsource.cpp
  asset/common/floatsource.h
  asset/common/namesource.cpp
  asset/common/namesource.h
  asset/common/source.cpp
  asset/common/source.h
  asset/controller/controller.cpp
  asset/controller/controller.h
  asset/controller/joints.cpp
  asset/controller/joints.h
  asset/controller/skin.cpp
  asset/controller/skin.h
  asset/controller/vertexweights.cpp
  asset/controller/vertexweights.h
  asset/effect/effect.cpp
  asset/effect/effect.h
  asset/effect/phong.cpp
  asset/effect/phong.h
  asset/effect/sampler2d.cpp
  asset/effect/sampler2d.h
  asset/geometry/geometry.cpp
  asset/geometry/geometry.h
  asset/geometry/mesh.cpp
  asset/geometry/mesh.h
  asset/geometry/triangles.cpp
  asset/geometry/triangles.h
  asset/geometry/vertices.cpp
  asset/geometry/vertices.h
  asset/visualscene/node.cpp
  asset/visualscene/node.h
  asset/visualscene/nodeitem.cpp
  asset/visualscene/nodeitem.h
  asset/visualscene/visualscene.cpp
  asset/visualscene/visualscene.h
  asset/animationclip.cpp
  asset/animationclip.h
  asset/asset.cpp
  asset/asset.h
  asset/camera.cpp
  asset/camera.h
  asset/image.cpp
  asset/image.h
  asset/light.cpp
  asset/light.h
  asset/material.cpp
  asset/material.h
  asset/perspectivecamera.cpp
  asset/perspectivecamera.h
  asset/pointlight.cpp
  asset/pointlight.h
  collada/collada.cpp
  collada/collada.h
  collada/scene.cpp
  collada/scene.h
  instance/instanceanimation.cpp
  instance/instanceanimation.h
  instance/instancecamera.cpp
  instance/instancecamera.h
  instance/instancecontroller.cpp
  instance/instancecontroller.h
  instance/instanceeffect.cpp
  instance/instanceeffect.h
  instance/instancegeometry.cpp
  instance/instancegeometry.h
  instance/instancelight.cpp
  instance/instancelight.h
  instance/instancematerial.cpp
  instance/instancematerial.h
  instance/instancevisualscene.cpp
  instance/instancevisualscene.h
)

target_link_libraries(QCollada PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Xml)

target_compile_definitions(QCollada PRIVATE QCOLLADA_LIBRARY)

if (LINUX)
  include(GNUInstallDirs)
  install(TARGETS QCollada
      BUNDLE DESTINATION .
      LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
      RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  )
  install(DIRECTORY "" DESTINATION /usr/include/QCollada
    FILES_MATCHING PATTERN "*.h"
    PATTERN ".git" EXCLUDE
    PATTERN "build" EXCLUDE
  )
endif()
