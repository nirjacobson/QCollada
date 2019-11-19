#include "collada.h"

QCollada::Collada::Collada()
{

}

QCollada::Collada::Collada(const QCollada::Collada& other)
  : _cameras(other._cameras)
  , _lights(other._lights)
  , _effects(other._effects)
  , _materials(other._materials)
  , _geometries(other._geometries)
  , _animations(other._animations)
  , _animationClips(other._animationClips)
  , _controllers(other._controllers)
  , _visualScenes(other._visualScenes)
  , _scene(other._scene)
{

}

QCollada::Collada::~Collada()
{
  for (const Camera* camera : _cameras.values()) {
    delete camera;
  }
  for (const Light* light : _lights.values()) {
    delete light;
  }
  for (const Effect* effect : _effects.values()) {
    delete effect;
  }
  for (const Material* material : _materials.values()) {
    delete material;
  }
  for (const Geometry* geometry : _geometries.values()) {
    delete geometry;
  }
  for (const Animation* animation : _animations.values()) {
    delete animation;
  }
  for (const AnimationClip* animationClip : _animationClips.values()) {
    delete animationClip;
  }
  for (const Controller* controller : _controllers.values()) {
    delete controller;
  }
  for (const VisualScene* visualScene : _visualScenes.values()) {
    delete visualScene;
  }
}

void QCollada::Collada::addCamera(const QString& id, Camera* camera)
{
  _cameras.insert(id, camera);
}

void QCollada::Collada::addLight(const QString& id, Light* light)
{
  _lights.insert(id, light);
}

void QCollada::Collada::addImage(const QString& id, QCollada::Image* image)
{
  _images.insert(id, image);
}

void QCollada::Collada::addEffect(const QString& id, Effect* effect)
{
  _effects.insert(id, effect);
}

void QCollada::Collada::addMaterial(const QString& id, Material* material)
{
  _materials.insert(id, material);
}

void QCollada::Collada::addGeometry(const QString& id, Geometry* geometry)
{
  _geometries.insert(id, geometry);
}

void QCollada::Collada::addAnimation(const QString& id, QCollada::Animation* animation)
{
  _animations.insert(id, animation);
}

void QCollada::Collada::addAnimationClip(const QString& id, QCollada::AnimationClip* animationClip)
{
  _animationClips.insert(id, animationClip);
}

void QCollada::Collada::addController(const QString& id, QCollada::Controller* controller)
{
  _controllers.insert(id, controller);
}

void QCollada::Collada::addVisualScene(const QString& id, VisualScene* visualScene)
{
  _visualScenes.insert(id, visualScene);
}

const QMap<QString, QCollada::Camera*>& QCollada::Collada::cameras() const
{
  return _cameras;
}

const QMap<QString, QCollada::Light*>& QCollada::Collada::lights() const
{
  return _lights;
}

const QMap<QString, QCollada::Image*>& QCollada::Collada::images() const
{
  return _images;
}

const QMap<QString, QCollada::Effect*>& QCollada::Collada::effects() const
{
  return _effects;
}

const QMap<QString, QCollada::Material*>& QCollada::Collada::materials() const
{
  return _materials;
}

const QMap<QString, QCollada::Geometry*>& QCollada::Collada::geometries() const
{
  return _geometries;
}

const QMap<QString, QCollada::Animation*>& QCollada::Collada::animations() const
{
  return _animations;
}

const QMap<QString, QCollada::AnimationClip*>& QCollada::Collada::animationClips() const
{
  return _animationClips;
}

const QMap<QString, QCollada::Controller*>& QCollada::Collada::controllers() const
{
  return _controllers;
}

const QMap<QString, QCollada::VisualScene*>& QCollada::Collada::visualScenes() const
{
  return _visualScenes;
}

const QCollada::Scene* QCollada::Collada::scene() const
{
  return _scene.get();
}

const QCollada::Asset* QCollada::Collada::resolve(const QString& url) const
{
  QString id = url.mid(1);
  for (auto it = _cameras.begin(); it != _cameras.end(); it++) {
    if(it.key() == id) {
      return it.value();
    }
  }
  for (auto it = _lights.begin(); it != _lights.end(); it++) {
    if(it.key() == id) {
      return it.value();
    }
  }
  for (auto it = _images.begin(); it != _images.end(); it++) {
    if(it.key() == id) {
      return it.value();
    }
  }
  for (auto it = _effects.begin(); it != _effects.end(); it++) {
    if(it.key() == id) {
      return it.value();
    }
  }
  for (auto it = _materials.begin(); it != _materials.end(); it++) {
    if(it.key() == id) {
      return it.value();
    }
  }
  for (auto it = _geometries.begin(); it != _geometries.end(); it++) {
    if(it.key() == id) {
      return it.value();
    }
  }
  for (auto it = _animations.begin(); it != _animations.end(); it++) {
    if(it.key() == id) {
      return it.value();
    }
  }
  for (auto it = _animationClips.begin(); it != _animationClips.end(); it++) {
    if(it.key() == id) {
      return it.value();
    }
  }
  for (auto it = _controllers.begin(); it != _controllers.end(); it++) {
    if(it.key() == id) {
      return it.value();
    }
  }
  for (auto it = _visualScenes.begin(); it != _visualScenes.end(); it++) {
    if(it.key() == id) {
      return it.value();
    }
  }

  return nullptr;
}

QCollada::Collada QCollada::Collada::parse(const QString& filename)
{
  Collada collada;

  QFile file(filename);
  QDomDocument document;

  if (!file.exists() || !file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qDebug() << "Check your file";
    return collada;
  }
  document.setContent(&file);

  parseCollada(document, collada);

  return collada;
}

void QCollada::Collada::parseCollada(QDomDocument& document, Collada& collada)
{
  parseColladaLibraryCameras(document, collada);
  parseColladaLibraryLights(document, collada);
  parseColladaLibraryImages(document, collada);
  parseColladaLibraryEffects(document, collada);
  parseColladaLibraryMaterials(document, collada);
  parseColladaLibraryGeometries(document, collada);
  parseColladaLibraryAnimations(document, collada);
  parseColladaLibraryAnimationClips(document, collada);
  parseColladaLibraryControllers(document, collada);
  parseColladaLibraryVisualScenes(document, collada);
  parseColladaScene(document, collada);

}

void QCollada::Collada::parseColladaLibraryCameras(QDomDocument& document, Collada& collada)
{
  QDomElement libraryCamerasElement = document.elementsByTagName("library_cameras").at(0).toElement();
  QDomNodeList cameraElements = libraryCamerasElement.elementsByTagName("camera");

  for (int i = 0; i < cameraElements.size(); i++) {
    QDomElement cameraElement = cameraElements.at(i).toElement();
    parseColladaLibraryCamera(cameraElement, collada);
  }
}

void QCollada::Collada::parseColladaLibraryLights(QDomDocument& document, Collada& collada)
{
  QDomElement libraryLightsElement = document.elementsByTagName("library_lights").at(0).toElement();
  QDomNodeList lightElements = libraryLightsElement.elementsByTagName("light");

  for (int i = 0; i < lightElements.size(); i++) {
    QDomElement lightElement = lightElements.at(i).toElement();
    parseColladaLibraryLight(lightElement, collada);
  }
}

void QCollada::Collada::parseColladaLibraryImages(QDomDocument& document, QCollada::Collada& collada)
{
  QDomElement libraryImagesElement = document.elementsByTagName("library_images").at(0).toElement();
  QDomNodeList imageElements = libraryImagesElement.elementsByTagName("image");

  for (int i = 0; i < imageElements.size(); i++) {
    QDomElement imageElement = imageElements.at(i).toElement();
    parseColladaLibraryImage(imageElement, collada);
  }
}

void QCollada::Collada::parseColladaLibraryEffects(QDomDocument& document, Collada& collada)
{
  QDomElement libraryEffectsElement = document.elementsByTagName("library_effects").at(0).toElement();
  QDomNodeList effectElements = libraryEffectsElement.elementsByTagName("effect");

  for (int i = 0; i < effectElements.size(); i++) {
    QDomElement effectElement = effectElements.at(i).toElement();
    parseColladaLibraryEffect(effectElement, collada);
  }
}

void QCollada::Collada::parseColladaLibraryMaterials(QDomDocument& document, Collada& collada)
{
  QDomElement libraryMaterialsElement = document.elementsByTagName("library_materials").at(0).toElement();
  QDomNodeList materialElements = libraryMaterialsElement.elementsByTagName("material");

  for (int i = 0; i < materialElements.size(); i++) {
    QDomElement materialElement = materialElements.at(i).toElement();
    parseColladaLibraryMaterial(materialElement, collada);
  }
}

void QCollada::Collada::parseColladaLibraryGeometries(QDomDocument& document, Collada& collada)
{
  QDomElement libraryGeometriesElement = document.elementsByTagName("library_geometries").at(0).toElement();
  QDomNodeList geometryElements = libraryGeometriesElement.elementsByTagName("geometry");

  for (int i = 0; i < geometryElements.size(); i++) {
    QDomElement geometryElement = geometryElements.at(i).toElement();
    parseColladaLibraryGeometry(geometryElement, collada);
  }
}

void QCollada::Collada::parseColladaLibraryAnimations(QDomDocument& document, QCollada::Collada& collada)
{
  QDomElement libraryAnimationsElement = document.elementsByTagName("library_animations").at(0).toElement();
  QDomNodeList animationElements = libraryAnimationsElement.elementsByTagName("animation");

  for (int i = 0; i < animationElements.size(); i++) {
    QDomElement animationElement = animationElements.at(i).toElement();
    parseColladaLibraryAnimation(animationElement, collada);
  }
}

void QCollada::Collada::parseColladaLibraryAnimationClips(QDomDocument& document, QCollada::Collada& collada)
{
  QDomNodeList libraryAnimationClipsNodes = document.elementsByTagName("library_animation_clips");

  if (!libraryAnimationClipsNodes.isEmpty()) {
    QDomElement libraryAnimationClipsElement = libraryAnimationClipsNodes.at(0).toElement();
    QDomNodeList animationClipElements = libraryAnimationClipsElement.elementsByTagName("animation_clip");

    for (int i = 0; i < animationClipElements.size(); i++) {
      QDomElement animationClipElement = animationClipElements.at(i).toElement();
      parseColladaLibraryAnimationClip(animationClipElement, collada);
    }
  }
}

void QCollada::Collada::parseColladaLibraryControllers(QDomDocument& document, QCollada::Collada& collada)
{
  QDomElement libraryControllersElement = document.elementsByTagName("library_controllers").at(0).toElement();
  QDomNodeList controllerElements = libraryControllersElement.elementsByTagName("controller");

  for (int i = 0; i < controllerElements.size(); i++) {
    QDomElement controllerElement = controllerElements.at(i).toElement();
    parseColladaLibraryController(controllerElement, collada);
  }
}

void QCollada::Collada::parseColladaLibraryVisualScenes(QDomDocument& document, Collada& collada)
{
  QDomElement libraryVisualScenesElement = document.elementsByTagName("library_visual_scenes").at(0).toElement();
  QDomNodeList visualSceneElements = libraryVisualScenesElement.elementsByTagName("visual_scene");

  for (int i = 0; i < visualSceneElements.size(); i++) {
    QDomElement visualSceneElement = visualSceneElements.at(i).toElement();
    parseColladaLibraryVisualScene(visualSceneElement, collada);
  }
}

void QCollada::Collada::parseColladaScene(QDomDocument& document, Collada& collada)
{
  QDomElement sceneElement = document.elementsByTagName("scene").at(0).toElement();
  QDomElement instanceVisualSceneElement = sceneElement.elementsByTagName("instance_visual_scene").at(0).toElement();
  InstanceVisualScene instanceVisualScene(instanceVisualSceneElement.attribute("url"));
  collada._scene = std::shared_ptr<Scene>(new Scene(instanceVisualScene));
}

void QCollada::Collada::parseColladaLibraryCamera(QDomElement& cameraElement, Collada& collada)
{
  QString id = cameraElement.attribute("id");

  if (cameraElement.elementsByTagName("perspective").size() > 0) {
    float xfov = cameraElement.elementsByTagName("xfov").at(0).toElement().text().toFloat();
    float aspect = cameraElement.elementsByTagName("aspect_ratio").at(0).toElement().text().toFloat();
    float znear = cameraElement.elementsByTagName("znear").at(0).toElement().text().toFloat();
    float zfar = cameraElement.elementsByTagName("zfar").at(0).toElement().text().toFloat();

    PerspectiveCamera* camera = new PerspectiveCamera(xfov, aspect, znear, zfar);
    collada.addCamera(id, camera);
  }
}

void QCollada::Collada::parseColladaLibraryLight(QDomElement& lightElement, Collada& collada)
{
  QString id = lightElement.attribute("id");

  if (lightElement.elementsByTagName("point").size() > 0) {
    QStringList colorComponents = lightElement.elementsByTagName("color").at(0).toElement().text().split(QRegExp("\\s"));
    QVector3D color;
    color.setX(colorComponents.at(0).toFloat());
    color.setY(colorComponents.at(1).toFloat());
    color.setZ(colorComponents.at(2).toFloat());

    GLfloat constantAttentuation = lightElement.elementsByTagName("constant_attentuation").at(0).toElement().text().toFloat();
    GLfloat linearAttentuation = lightElement.elementsByTagName("linear_attenuation").at(0).toElement().text().toFloat();
    GLfloat quadraticAttentuation = lightElement.elementsByTagName("quadratic_attenuation").at(0).toElement().text().toFloat();

    Light* light = new PointLight(color, constantAttentuation, linearAttentuation, quadraticAttentuation);

    collada.addLight(id, light);
  }
}

void QCollada::Collada::parseColladaLibraryImage(QDomElement& imageElement, QCollada::Collada& collada)
{
  QString id = imageElement.attribute("id");

  QDomElement initFromElement = imageElement.elementsByTagName("init_from").at(0).toElement();

  Image* image = new Image(initFromElement.text());

  collada.addImage(id, image);
}

void QCollada::Collada::parseColladaLibraryEffect(QDomElement& effectElement, Collada& collada)
{
  QString id = effectElement.attribute("id");

  QDomElement phongElement = effectElement.elementsByTagName("phong").at(0).toElement();
  QDomElement emissionElement = phongElement.elementsByTagName("emission").at(0).toElement();
  QDomElement ambientElement = phongElement.elementsByTagName("ambient").at(0).toElement();
  QDomElement diffuseElement = phongElement.elementsByTagName("diffuse").at(0).toElement();
  QDomElement specularElement = phongElement.elementsByTagName("specular").at(0).toElement();
  QDomElement shininessElement = phongElement.elementsByTagName("shininess").at(0).toElement();

  QStringList emissionColorComponents = emissionElement.elementsByTagName("color").at(0).toElement().text().split(QRegExp("\\s"));
  QStringList ambientColorComponents = ambientElement.elementsByTagName("color").at(0).toElement().text().split(QRegExp("\\s"));
  QStringList specularColorComponents = specularElement.elementsByTagName("color").at(0).toElement().text().split(QRegExp("\\s"));

  QVector4D emissionColor(
      emissionColorComponents[0].toFloat(),
      emissionColorComponents[1].toFloat(),
      emissionColorComponents[2].toFloat(),
      emissionColorComponents[3].toFloat());
  QVector4D ambientColor(
      ambientColorComponents[0].toFloat(),
      ambientColorComponents[1].toFloat(),
      ambientColorComponents[2].toFloat(),
      ambientColorComponents[3].toFloat());
  QVector4D specularColor(
      specularColorComponents[0].toFloat(),
      specularColorComponents[1].toFloat(),
      specularColorComponents[2].toFloat(),
      specularColorComponents[3].toFloat());
  float shininess = shininessElement.text().toFloat();


//  QStringList diffuseColorComponents = diffuseElement.elementsByTagName("color").at(0).toElement().text().split(QRegExp("\\s"));
//  QVector4D diffuseColor(
//      diffuseColorComponents[0].toFloat(),
//      diffuseColorComponents[1].toFloat(),
//      diffuseColorComponents[2].toFloat(),
//      diffuseColorComponents[3].toFloat());

  QVector4D diffuseColor;

  Effect* effect;
  QDomNodeList textureElements = diffuseElement.elementsByTagName("texture");
  if (textureElements.isEmpty()) {
    QStringList diffuseColorComponents = diffuseElement.elementsByTagName("color").at(0).toElement().text().split(QRegExp("\\s"));
    diffuseColor = QVector4D(
        diffuseColorComponents[0].toFloat(),
        diffuseColorComponents[1].toFloat(),
        diffuseColorComponents[2].toFloat(),
        diffuseColorComponents[3].toFloat());

    Phong phong(emissionColor, ambientColor, diffuseColor, specularColor, shininess);
    effect = new Effect(phong);
  } else {
    QDomNodeList newparamNodes = effectElement.elementsByTagName("newparam");

    QString surfaceSid;
    for (int i = 0; i < newparamNodes.length(); i++) {
      QDomElement newparamNode = newparamNodes.at(i).toElement();
      if (newparamNode.attribute("sid") == textureElements.at(0).toElement().attribute("texture")) {
        surfaceSid = newparamNode.text();
        break;
      }
    }

    QString imageId;
    for (int i = 0; i < newparamNodes.length(); i++) {
      QDomElement newparamNode = newparamNodes.at(i).toElement();
      if (newparamNode.attribute("sid") == surfaceSid) {
        imageId = newparamNode.text();
        break;
      }
    }

    Sampler2D sampler2D(imageId);

    Phong phong(emissionColor, ambientColor, diffuseColor, specularColor, shininess);
    effect = new Effect(phong, sampler2D);
  }

  collada.addEffect(id, effect);
}

void QCollada::Collada::parseColladaLibraryMaterial(QDomElement& materialElement, Collada& collada)
{
  QString id = materialElement.attribute("id");

  QDomElement instanceEffectElement = materialElement.elementsByTagName("instance_effect").at(0).toElement();
  InstanceEffect instanceEffect(instanceEffectElement.attribute("url"));

  Material* material = new Material(instanceEffect);

  collada.addMaterial(id, material);
}

void QCollada::Collada::parseColladaLibraryGeometry(QDomElement& geometryElement, Collada& collada)
{
  QString id = geometryElement.attribute("id");
  QDomElement meshElement = geometryElement.elementsByTagName("mesh").at(0).toElement();
  Mesh mesh = parseColladaLibraryGeometryMesh(meshElement);
  Geometry* geometry = new Geometry(mesh);

  collada.addGeometry(id, geometry);
}

QCollada::Mesh QCollada::Collada::parseColladaLibraryGeometryMesh(QDomElement& meshElement)
{
  QDomNodeList sourceElements = meshElement.elementsByTagName("source");

  QMap<QString, Source*> sources;
  for (int i = 0; i < sourceElements.size(); i++) {
    QDomElement sourceElement = sourceElements.at(i).toElement();
    Source* source = parseColladaLibraryGeometryMeshSource(sourceElement);
    sources.insert(sourceElement.attribute("id"), source);
  }

  QDomElement verticesElement = meshElement.elementsByTagName("vertices").at(0).toElement();
  Vertices vertices = parseColladaLibraryGeometryMeshVertices(verticesElement);

  QList<Triangles> triangles;
  QDomNodeList trianglesElements = meshElement.elementsByTagName("triangles");
  for (int i = 0; i < trianglesElements.size(); i++) {
    QDomElement trianglesElement = trianglesElements.at(i).toElement();
    triangles.append( parseColladaLibraryGeometryMeshTriangles(trianglesElement) );
  }

  return Mesh(sources, vertices, triangles);
}

QCollada::Source* QCollada::Collada::parseColladaLibraryGeometryMeshSource(QDomElement& sourceElement)
{
  QDomElement floatArrayElement = sourceElement.elementsByTagName("float_array").at(0).toElement();
  int floatCount = floatArrayElement.attribute("count").toInt();
  QList<float> data;
  QStringList dataComponents = floatArrayElement.text().split(QRegExp("\\s"));
  for (int i = 0; i < floatCount; i++) {
    data.append(dataComponents[i].toFloat());
  }

  Accessor accessor;

  QDomElement accessorElement = sourceElement.elementsByTagName("accessor").at(0).toElement();
  QDomNodeList accessorParamElements = accessorElement.elementsByTagName("param");

  for (int i = 0; i < accessorParamElements.size(); i++) {
    QDomElement paramElement = accessorParamElements.at(i).toElement();
    Accessor::Param param;
    param.name = paramElement.attribute("name");
    if (paramElement.attribute("type") == "float") {
      param.type = Accessor::Param::Type::FLOAT;
    }
    accessor.addParam(param);
  }

  accessor.setCount(accessorElement.attribute("count").toInt());
  accessor.setStride(accessorElement.attribute("stride").toInt());

  return new FloatSource(data, floatCount, accessor);
}

QCollada::Vertices QCollada::Collada::parseColladaLibraryGeometryMeshVertices(QDomElement& verticesElement)
{
  Vertices vertices;

  QDomNodeList inputElements = verticesElement.elementsByTagName("input");

  for (int i = 0; i < inputElements.size(); i++) {
    QDomElement inputElement = inputElements.at(i).toElement();

    Vertices::Semantic semantic = Vertices::Semantic::POSITION;
    if (inputElement.attribute("semantic") == "POSITION") {
      semantic = Vertices::Semantic::POSITION;
    }
    vertices.addInput(semantic, inputElement.attribute("source"));
  }

  return vertices;
}

QCollada::Triangles QCollada::Collada::parseColladaLibraryGeometryMeshTriangles(QDomElement& trianglesElement)
{
  QDomNodeList inputElements = trianglesElement.elementsByTagName("input");

  QMap<QCollada::Triangles::Semantic, QPair<QString, int>> inputs;
  for (int i = 0; i < inputElements.size(); i++) {
    QDomElement inputElement = inputElements.at(i).toElement();

    Triangles::Semantic semantic = Triangles::Semantic::VERTEX;
    if (inputElement.attribute("semantic") == "VERTEX") {
      semantic = Triangles::Semantic::VERTEX;
    } else if (inputElement.attribute("semantic") == "NORMAL") {
      semantic = Triangles::Semantic::NORMAL;
    } else if (inputElement.attribute("semantic") == "TEXCOORD") {
      semantic = Triangles::Semantic::TEXCOORD;
    }

    inputs.insert(semantic, QPair<QString, int>(inputElement.attribute("source"), inputElement.attribute("offset").toInt()));
  }

  QDomElement pElement = trianglesElement.elementsByTagName("p").at(0).toElement();
  QStringList pElementComponents = pElement.text().split(QRegExp("\\s"));
  QList<int> data;
  std::transform(pElementComponents.begin(), pElementComponents.end(), std::back_inserter(data), [](const QString& str){ return str.toInt(); });

  return Triangles(trianglesElement.attribute("count").toInt(), trianglesElement.attribute("material"), inputs, data);
}

void QCollada::Collada::parseColladaLibraryAnimation(QDomElement& animationElement, QCollada::Collada& collada)
{
  QString id = animationElement.attribute("id");
  QDomNodeList sourceElements = animationElement.elementsByTagName("source");

  QMap<QString, Source*> sources;
  for (int i = 0; i < sourceElements.size(); i++) {
    QDomElement sourceElement = sourceElements.at(i).toElement();
    Source* source = parseColladaLibraryAnimationSource(sourceElement);
    sources.insert(sourceElement.attribute("id"), source);
  }

  QDomElement samplerElement = animationElement.elementsByTagName("sampler").at(0).toElement();
  Sampler sampler = parseColladaLibraryAnimationSampler(samplerElement);

  QDomElement channelElement = animationElement.elementsByTagName("channel").at(0).toElement();
  Channel channel = parseColladaLibrarayAnimationChannel(channelElement);

  Animation* animation = new Animation(sources, sampler, channel);
  collada.addAnimation(id, animation);
}

void QCollada::Collada::parseColladaLibraryAnimationClip(QDomElement& animationClipElement, QCollada::Collada& collada)
{
  QString id = animationClipElement.attribute("id");
  QString name = animationClipElement.attribute("name");
  QDomNodeList instanceAnimationElements = animationClipElement.elementsByTagName("instance_animation");

  QList<InstanceAnimation> instanceAnimations;
  for (int i = 0; i < instanceAnimationElements.size(); i++) {
    QDomElement instanceAnimationElement = instanceAnimationElements.at(i).toElement();

    instanceAnimations.append(InstanceAnimation(instanceAnimationElement.attribute("url")));
  }

  AnimationClip* animationClip = new AnimationClip(name, instanceAnimations);
  collada.addAnimationClip(id, animationClip);
}

QCollada::Source* QCollada::Collada::parseColladaLibraryAnimationSource(QDomElement& sourceElement)
{
  Accessor accessor;

  QDomElement accessorElement = sourceElement.elementsByTagName("accessor").at(0).toElement();
  QDomNodeList accessorParamElements = accessorElement.elementsByTagName("param");

  for (int i = 0; i < accessorParamElements.size(); i++) {
    QDomElement paramElement = accessorParamElements.at(i).toElement();
    Accessor::Param param;
    param.name = paramElement.attribute("name");
    if (paramElement.attribute("type") == "float") {
      param.type = Accessor::Param::Type::FLOAT;
    } else if (paramElement.attribute("type") == "float4x4") {
      param.type = Accessor::Param::Type::FLOAT4X4;
    } else if (paramElement.attribute("type") == "name") {
      param.type = Accessor::Param::Type::NAME;
    }
    accessor.addParam(param);
  }

  accessor.setCount(accessorElement.attribute("count").toInt());
  accessor.setStride(accessorElement.attribute("stride").toInt());

  QDomNodeList floatArrayElements = sourceElement.elementsByTagName("float_array");
  if (floatArrayElements.size() > 0) {
    QDomElement floatArrayElement = floatArrayElements.at(0).toElement();
    int count = floatArrayElement.attribute("count").toInt();
    QList<float> data;
    QStringList dataComponents = floatArrayElement.text().split(QRegExp("\\s"));
    for (int i = 0; i < count; i++) {
      data.append(dataComponents[i].toFloat());
    }

    return new FloatSource(data, count, accessor);
  } else {
    QDomElement nameArrayElement = sourceElement.elementsByTagName("Name_array").at(0).toElement();
    int count = nameArrayElement.attribute("count").toInt();
    QStringList dataComponents = nameArrayElement.text().split(QRegExp("\\s"));

    return new NameSource(dataComponents, count, accessor);
  }
}

QCollada::Sampler QCollada::Collada::parseColladaLibraryAnimationSampler(QDomElement& samplerElement)
{
  QDomNodeList inputElements = samplerElement.elementsByTagName("input");

  QMap<Sampler::Semantic, QString> inputs;
  for (int i = 0; i < inputElements.size(); i++) {
    QDomElement inputElement = inputElements.at(i).toElement();
    Sampler::Semantic semantic = Sampler::Semantic::INPUT;
    if (inputElement.attribute("semantic") == "INPUT") {
      semantic = Sampler::Semantic::INPUT;
    } else if (inputElement.attribute("semantic") == "OUTPUT") {
      semantic = Sampler::Semantic::OUTPUT;
    } else if (inputElement.attribute("semantic") == "INTERPOLATION") {
      semantic = Sampler::Semantic::INTERPOLATION;
    }

    inputs.insert(semantic, inputElement.attribute("source"));
  }

  return Sampler(inputs);
}

QCollada::Channel QCollada::Collada::parseColladaLibrarayAnimationChannel(QDomElement& channelElement)
{
  return Channel(channelElement.attribute("source"), channelElement.attribute("target"));
}

void QCollada::Collada::parseColladaLibraryController(QDomElement& controllerElement, QCollada::Collada& collada)
{
  QDomElement skinElement = controllerElement.elementsByTagName("skin").at(0).toElement();
  Skin skin = parseColladaLibraryControllerSkin(skinElement);

  QCollada::Controller* controller = new QCollada::Controller(skin);

  collada.addController(controllerElement.attribute("id"), controller);
}

QCollada::Skin QCollada::Collada::parseColladaLibraryControllerSkin(QDomElement& skinElement)
{
  QDomElement bindShapeMatrixElement = skinElement.elementsByTagName("bind_shape_matrix").at(0).toElement();
  QStringList bindShapeMatrixElementComponents = bindShapeMatrixElement.text().split(QRegExp("\\s"));
  QMatrix4x4 bindShapeMatrix;
  for (int i = 0; i < 16; i++) {
    QVector4D row = bindShapeMatrix.row(i/4);
    switch (i % 4) {
      case 0:
        row.setX(bindShapeMatrixElementComponents.at(i).toFloat());
        break;
      case 1:
        row.setY(bindShapeMatrixElementComponents.at(i).toFloat());
        break;
      case 2:
        row.setZ(bindShapeMatrixElementComponents.at(i).toFloat());
        break;
      case 3:
        row.setW(bindShapeMatrixElementComponents.at(i).toFloat());
        break;
    }
    bindShapeMatrix.setRow(i/4, row);
  }

  QDomNodeList sourceElements = skinElement.elementsByTagName("source");

  QMap<QString, Source*> sources;
  for (int i = 0; i < sourceElements.size(); i++) {
    QDomElement sourceElement = sourceElements.at(i).toElement();
    Source* source = parseColladaLibraryControllerSkinSource(sourceElement);
    sources.insert(sourceElement.attribute("id"), source);
  }

  QDomElement jointsElement = skinElement.elementsByTagName("joints").at(0).toElement();
  Joints joints = parseColladaLibraryControllerSkinJoints(jointsElement);

  QDomElement vertexWeightsElement = skinElement.elementsByTagName("vertex_weights").at(0).toElement();
  VertexWeights vertexWeights = parseColladaLibraryControllerSkinVertexWeights(vertexWeightsElement);

  return Skin(skinElement.attribute("source"), bindShapeMatrix, sources, joints, vertexWeights);
}

QCollada::Source* QCollada::Collada::parseColladaLibraryControllerSkinSource(QDomElement& sourceElement)
{

  Accessor accessor;

  QDomElement accessorElement = sourceElement.elementsByTagName("accessor").at(0).toElement();
  QDomNodeList accessorParamElements = accessorElement.elementsByTagName("param");

  for (int i = 0; i < accessorParamElements.size(); i++) {
    QDomElement paramElement = accessorParamElements.at(i).toElement();
    Accessor::Param param;
    param.name = paramElement.attribute("name");
    if (paramElement.attribute("type") == "float") {
      param.type = Accessor::Param::Type::FLOAT;
    } else if (paramElement.attribute("type") == "float4x4") {
      param.type = Accessor::Param::Type::FLOAT4X4;
    } else if (paramElement.attribute("type") == "name") {
      param.type = Accessor::Param::Type::NAME;
    }
    accessor.addParam(param);
  }

  accessor.setCount(accessorElement.attribute("count").toInt());
  accessor.setStride(accessorElement.attribute("stride").toInt());

  QDomNodeList floatArrayElements = sourceElement.elementsByTagName("float_array");
  if (floatArrayElements.size() > 0) {
    QDomElement floatArrayElement = floatArrayElements.at(0).toElement();
    int count = floatArrayElement.attribute("count").toInt();
    QList<float> data;
    QStringList dataComponents = floatArrayElement.text().split(QRegExp("\\s"));
    for (int i = 0; i < count; i++) {
      data.append(dataComponents[i].toFloat());
    }

    return new FloatSource(data, count, accessor);
  } else {
    QDomElement nameArrayElement = sourceElement.elementsByTagName("Name_array").at(0).toElement();
    int count = nameArrayElement.attribute("count").toInt();
    QStringList dataComponents = nameArrayElement.text().split(QRegExp("\\s"));

    return new NameSource(dataComponents, count, accessor);
  }
}

QCollada::Joints QCollada::Collada::parseColladaLibraryControllerSkinJoints(QDomElement& jointsElement)
{
  Joints joints;

  QDomNodeList inputElements = jointsElement.elementsByTagName("input");

  for (int i = 0; i < inputElements.size(); i++) {
    QDomElement inputElement = inputElements.at(i).toElement();

    Joints::Semantic semantic = Joints::Semantic::JOINT;
    if (inputElement.attribute("semantic") == "JOINT") {
      semantic = Joints::Semantic::JOINT;
    } else if (inputElement.attribute("semantic") == "INV_BIND_MATRIX") {
      semantic = Joints::Semantic::INV_BIND_MATRIX;
    }

    joints.addInput(semantic, inputElement.attribute("source"));
  }

  return joints;

}

QCollada::VertexWeights QCollada::Collada::parseColladaLibraryControllerSkinVertexWeights(QDomElement& vertexWeightsElement)
{
  QDomNodeList inputElements = vertexWeightsElement.elementsByTagName("input");

  QMap<QCollada::VertexWeights::Semantic, QPair<QString, int>> inputs;
  for (int i = 0; i < inputElements.size(); i++) {
    QDomElement inputElement = inputElements.at(i).toElement();

    QCollada::VertexWeights::Semantic semantic = QCollada::VertexWeights::Semantic::JOINT;
    if (inputElement.attribute("semantic") == "JOINT") {
      semantic = QCollada::VertexWeights::Semantic::JOINT;
    } else if (inputElement.attribute("semantic") == "WEIGHT") {
      semantic = QCollada::VertexWeights::Semantic::WEIGHT;
    }

    inputs.insert(semantic, QPair<QString, int>(inputElement.attribute("source"), inputElement.attribute("offset").toInt()));
  }

  QDomElement vcountElement = vertexWeightsElement.elementsByTagName("vcount").at(0).toElement();
  QStringList vcountElementComponents = vcountElement.text().split(QRegExp("\\s"));
  QList<int> vcountData;
  std::transform(vcountElementComponents.begin(), vcountElementComponents.end(), std::back_inserter(vcountData), [](const QString& str){ return str.toInt(); });

  QDomElement vElement = vertexWeightsElement.elementsByTagName("v").at(0).toElement();
  QStringList vElementComponents = vElement.text().split(QRegExp("\\s"));
  QList<int> vData;
  std::transform(vElementComponents.begin(), vElementComponents.end(), std::back_inserter(vData), [](const QString& str){ return str.toInt(); });

  return VertexWeights(vertexWeightsElement.attribute("count").toInt(), vcountData, vData, inputs);

}

void QCollada::Collada::parseColladaLibraryVisualScene(QDomElement& visualSceneElement, Collada& collada)
{
  QString id = visualSceneElement.attribute("id");

  VisualScene* visualScene = new VisualScene;

  QList<QDomElement> childNodeElements = directDescendentsByTagName(visualSceneElement, "node");
  for (int i = 0; i < childNodeElements.size(); i++) {
    QDomElement childElement = childNodeElements.at(i);
    Node* node = parseColladaLibraryVisualSceneNode(childElement);
    visualScene->root()->addChild(node);
  }

  collada.addVisualScene(id, visualScene);
}

QCollada::Node* QCollada::Collada::parseColladaLibraryVisualSceneNode(QDomElement& nodeElement)
{
  QMatrix4x4 matrix;
  QList<QDomElement> matrixElements = directDescendentsByTagName(nodeElement, "matrix");
  if (!matrixElements.isEmpty()) {
    QDomElement matrixElement = matrixElements.at(0).toElement();
    QStringList matrixElementComponents = matrixElement.text().split(QRegExp("\\s"));

    for (int i = 0; i < 16; i += 4) {
      QVector4D row;
      row.setX(matrixElementComponents[i+0].toFloat());
      row.setY(matrixElementComponents[i+1].toFloat());
      row.setZ(matrixElementComponents[i+2].toFloat());
      row.setW(matrixElementComponents[i+3].toFloat());
      matrix.setRow(i / 4, row);
    }
  }

  NodeItem* nodeItem = nullptr;
  QDomElement instanceElement;
  QList<QDomElement> instanceCameraElements = directDescendentsByTagName(nodeElement, "instance_camera");
  if (!instanceCameraElements.isEmpty()) {
    instanceElement = instanceCameraElements.at(0);
    nodeItem = new InstanceCamera(instanceElement.attribute("url"));
  }
  QList<QDomElement> instanceLightElements = directDescendentsByTagName(nodeElement, "instance_light");
  if (!instanceLightElements.isEmpty()) {
    instanceElement = instanceLightElements.at(0);
    nodeItem = new InstanceLight(instanceElement.attribute("url"));
  }
  QList<QDomElement> instanceGeometryElements = directDescendentsByTagName(nodeElement, "instance_geometry");
  if (!instanceGeometryElements.isEmpty()) {
    instanceElement = instanceGeometryElements.at(0);

    QList<InstanceMaterial> instanceMaterials;
    QDomNodeList instanceMaterialElements = instanceElement.elementsByTagName("instance_material");
    for (int i = 0; i < instanceMaterialElements.size(); i++) {
      QDomElement instanceMaterialElement = instanceMaterialElements.at(i).toElement();
      InstanceMaterial instanceMaterial(instanceMaterialElement.attribute("symbol"), instanceMaterialElement.attribute("target"));
      instanceMaterials.append(instanceMaterial);
    }
    nodeItem = new InstanceGeometry(instanceElement.attribute("url"), instanceMaterials);
  }
  QList<QDomElement> instanceControllerElements = directDescendentsByTagName(nodeElement, "instance_controller");
  if (!instanceControllerElements.isEmpty()) {
    instanceElement = instanceControllerElements.at(0);
    QDomElement skeletonElement = instanceElement.elementsByTagName("skeleton").at(0).toElement();

    QList<InstanceMaterial> instanceMaterials;
    QDomNodeList instanceMaterialElements = instanceElement.elementsByTagName("instance_material");
    for (int i = 0; i < instanceMaterialElements.size(); i++) {
      QDomElement instanceMaterialElement = instanceMaterialElements.at(i).toElement();
      InstanceMaterial instanceMaterial(instanceMaterialElement.attribute("symbol"), instanceMaterialElement.attribute("target"));
      instanceMaterials.append(instanceMaterial);
    }
    nodeItem = new InstanceController(instanceElement.attribute("url"), skeletonElement.text(), instanceMaterials);
  }

  Node::Type type = Node::Type::NODE;
  if (nodeElement.attribute("type") == "NODE") {
    type = Node::Type::NODE;
  } else if (nodeElement.attribute("type") == "JOINT") {
    type = Node::Type::JOINT;
  }
  Node* node = new Node(nodeElement.attribute("id"), nodeElement.attribute("sid"), type, nodeItem, matrix);

  QList<QDomElement> childNodeElements = directDescendentsByTagName(nodeElement, "node");
  for (int i = 0; i < childNodeElements.size(); i++) {
    QDomElement childNodeElement = childNodeElements.at(i);
    node->addChild(parseColladaLibraryVisualSceneNode(childNodeElement));
  }

  return node;
}

QList<QDomElement> QCollada::Collada::directDescendentsByTagName(QDomElement& parent, const QString& tagName)
{
  QList<QDomElement> elements;

  for (int i = 0; i < parent.childNodes().size(); i++) {
    QDomElement childElement = parent.childNodes().at(i).toElement();
    if (childElement.tagName() == tagName)
      elements.append(childElement);
  }

  return elements;
}

