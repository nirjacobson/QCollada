#ifndef QCOLLADA_COLLADA_H
#define QCOLLADA_COLLADA_H

#include "QCollada_global.h"

#include <QMap>
#include <QString>
#include <QDomDocument>
#include <QFile>
#include <QRegularExpression>

#include "asset/asset.h"
#include "asset/effect/effect.h"
#include "asset/image.h"
#include "asset/camera.h"
#include "asset/light.h"
#include "asset/controller/controller.h"
#include "asset/material.h"
#include "asset/geometry/geometry.h"
#include "asset/animation/animation.h"
#include "asset/animationclip.h"
#include "asset/geometry/triangles.h"
#include "asset/geometry/vertices.h"
#include "asset/visualscene/visualscene.h"
#include "scene.h"

namespace QCollada {
class Camera;
class Image;
class Material;
class AnimationClip;
  class QCOLLADA_EXPORT Collada
  {
    public:
      Collada();
      Collada(const Collada& other);
      ~Collada();

      void addCamera(const QString& id, Camera* camera);
      void addLight(const QString& id, Light* light);
      void addImage(const QString& id, Image* image);
      void addEffect(const QString& id, Effect* effect);
      void addMaterial(const QString& id, Material* material);
      void addGeometry(const QString& id, Geometry* geometry);
      void addAnimation(const QString& id, Animation* animation);
      void addAnimationClip(const QString& id, AnimationClip* animationClip);
      void addController(const QString& id, Controller* controller);
      void addVisualScene(const QString& id, VisualScene* visualScene);

      const QMap<QString, Camera*>& cameras() const;
      const QMap<QString, Light*>& lights() const;
      const QMap<QString, Image*>& images() const;
      const QMap<QString, Effect*>& effects() const;
      const QMap<QString, Material*>& materials() const;
      const QMap<QString, Geometry*>& geometries() const;
      const QMap<QString, Animation*>& animations() const;
      const QMap<QString, AnimationClip*>& animationClips() const;
      const QMap<QString, Controller*>& controllers() const;
      const QMap<QString, VisualScene*>& visualScenes() const;
      const Scene* scene() const;

      const Asset* resolve(const QString& url) const;

      static Collada parse(const QString& filename);

    private:
      QMap<QString, Camera*> _cameras;
      QMap<QString, Light*> _lights;
      QMap<QString, Image*> _images;
      QMap<QString, Effect*> _effects;
      QMap<QString, Material*> _materials;
      QMap<QString, Geometry*> _geometries;
      QMap<QString, Animation*> _animations;
      QMap<QString, AnimationClip*> _animationClips;
      QMap<QString, Controller*> _controllers;
      QMap<QString, VisualScene*> _visualScenes;
      Scene* _scene;

      static void parseCollada(QDomDocument& document, Collada& collada);
      static void parseColladaLibraryCameras(QDomDocument& document, Collada& collada);
      static void parseColladaLibraryLights(QDomDocument& document, Collada& collada);
      static void parseColladaLibraryImages(QDomDocument& document, Collada& collada);
      static void parseColladaLibraryEffects(QDomDocument& document, Collada& collada);
      static void parseColladaLibraryMaterials(QDomDocument& document, Collada& collada);
      static void parseColladaLibraryGeometries(QDomDocument& document, Collada& collada);
      static void parseColladaLibraryAnimations(QDomDocument& document, Collada& collada);
      static void parseColladaLibraryAnimationClips(QDomDocument& document, Collada& collada);
      static void parseColladaLibraryControllers(QDomDocument& document, Collada& collada);
      static void parseColladaLibraryVisualScenes(QDomDocument& document, Collada& collada);
      static void parseColladaScene(QDomDocument& document, Collada& collada);
      static void parseColladaLibraryCamera(QDomElement& cameraElement, Collada& collada);
      static void parseColladaLibraryLight(QDomElement& lightElement, Collada& collada);
      static void parseColladaLibraryImage(QDomElement& imageElement, Collada& collada);
      static void parseColladaLibraryEffect(QDomElement& effectElement, Collada& collada);
      static void parseColladaLibraryMaterial(QDomElement& materialElement, Collada& collada);
      static void parseColladaLibraryGeometry(QDomElement& geometryElement, Collada& collada);
      static Mesh parseColladaLibraryGeometryMesh(QDomElement& meshElement);
      static Source* parseColladaLibraryGeometryMeshSource(QDomElement& sourceElement);
      static Vertices parseColladaLibraryGeometryMeshVertices(QDomElement& verticesElement);
      static Triangles parseColladaLibraryGeometryMeshTriangles(QDomElement& trianglesElement);
      static void parseColladaLibraryAnimation(QDomElement& animationElement, Collada& collada);
      static void parseColladaLibraryAnimationClip(QDomElement& animationClipElement, Collada& collada);
      static Source* parseColladaLibraryAnimationSource(QDomElement& sourceElement);
      static Sampler parseColladaLibraryAnimationSampler(QDomElement& samplerElement);
      static Channel parseColladaLibrarayAnimationChannel(QDomElement& channelElement);
      static void parseColladaLibraryController(QDomElement& controllerElement, Collada& collada);
      static Skin parseColladaLibraryControllerSkin(QDomElement& skinElement);
      static Source* parseColladaLibraryControllerSkinSource(QDomElement& sourceElement);
      static Joints parseColladaLibraryControllerSkinJoints(QDomElement& jointsElement);
      static VertexWeights parseColladaLibraryControllerSkinVertexWeights(QDomElement& vertexWeightsElement);
      static void parseColladaLibraryVisualScene(QDomElement& visualSceneElement, Collada& collada);
      static Node* parseColladaLibraryVisualSceneNode(QDomElement& nodeElement);
      static QList<QDomElement> directDescendentsByTagName(QDomElement& parent, const QString& tagName);
  };
}

#endif // QCOLLADA_COLLADA_H
