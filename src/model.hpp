#ifndef MODEL_H
#define MODEL_H

#include <GL/glut.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

/**
 * @brief Carregador e renderizador simples de modelos 3D com Assimp.
 */
class Model {
private:
  const aiScene *  scene;
  Assimp::Importer importer;

  void drawNode( const aiNode * node );
  void drawMesh( const aiMesh * mesh );

public:
  /**
   * @brief Constrói e carrega o modelo.
   * @param path Caminho para o arquivo .obj, .3ds, etc.
   */
  Model( const char * path );

  /**
   * @brief Renderiza o modelo.
   */
  void draw();
};

#endif
