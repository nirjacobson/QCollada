QT -= gui
QT += opengl xml

TEMPLATE = lib
DEFINES += QCOLLADA_LIBRARY

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    asset/animation/animation.cpp \
    asset/animation/channel.cpp \
    asset/animation/sampler.cpp \
    asset/animationclip.cpp \
    asset/common/accessor.cpp \
    asset/asset.cpp \
    asset/camera.cpp \
    asset/common/floatsource.cpp \
    asset/common/namesource.cpp \
    asset/controller/controller.cpp \
    asset/controller/joints.cpp \
    asset/controller/skin.cpp \
    asset/controller/vertexweights.cpp \
    asset/image.cpp \
    asset/effect/sampler2d.cpp \
    collada/collada.cpp \
    asset/effect/effect.cpp \
    asset/geometry/geometry.cpp \
    instance/instanceanimation.cpp \
    instance/instancecamera.cpp \
    instance/instancecontroller.cpp \
    instance/instanceeffect.cpp \
    instance/instancegeometry.cpp \
    instance/instancelight.cpp \
    instance/instancematerial.cpp \
    instance/instancevisualscene.cpp \
    asset/light.cpp \
    asset/material.cpp \
    asset/geometry/mesh.cpp \
    asset/visualscene/node.cpp \
    asset/visualscene/nodeitem.cpp \
    asset/perspectivecamera.cpp \
    asset/effect/phong.cpp \
    asset/pointlight.cpp \
    collada/scene.cpp \
    asset/common/source.cpp \
    asset/geometry/triangles.cpp \
    asset/geometry/vertices.cpp \
    asset/visualscene/visualscene.cpp

HEADERS += \
    QCollada_global.h \
    asset/animation/animation.h \
    asset/animation/channel.h \
    asset/animation/sampler.h \
    asset/animationclip.h \
    asset/common/accessor.h \
    asset/asset.h \
    asset/camera.h \
    asset/common/floatsource.h \
    asset/common/namesource.h \
    asset/controller/controller.h \
    asset/controller/joints.h \
    asset/controller/skin.h \
    asset/controller/vertexweights.h \
    asset/image.h \
    asset/effect/sampler2d.h \
    collada/collada.h \
    asset/effect/effect.h \
    asset/geometry/geometry.h \
    instance/instanceanimation.h \
    instance/instancecamera.h \
    instance/instancecontroller.h \
    instance/instanceeffect.h \
    instance/instancegeometry.h \
    instance/instancelight.h \
    instance/instancematerial.h \
    instance/instancevisualscene.h \
    asset/light.h \
    asset/material.h \
    asset/geometry/mesh.h \
    asset/visualscene/node.h \
    asset/visualscene/nodeitem.h \
    asset/perspectivecamera.h \
    asset/effect/phong.h \
    asset/pointlight.h \
    collada/scene.h \
    asset/common/source.h \
    asset/geometry/triangles.h \
    asset/geometry/vertices.h \
    asset/visualscene/visualscene.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
