
#ifndef OBJECT_H
#define OBJECT_H

#include "macros.h"
#include "mesh.h"
#include "shader.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "camera.h"
#include <memory>
#include "physicsDefinition.h"

class Object
{
public:

    std::weak_ptr<Mesh> meshInstance;
    EObjectType objectType;
    Shader shaderInstance;

    glm::vec3 location;
    glm::quat rotation;

    Object();

    Object(const std::shared_ptr<Mesh>& mesh, EObjectType type, Shader shader = Shader());

    void setTransformation(glm::vec3 location, glm::quat rotation);

#if RENDER_ENABLED
    void Draw(Camera& cam);
#endif

};


#endif //OBJECT_H
