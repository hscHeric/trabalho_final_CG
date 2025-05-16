#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/gl.h>
#include <IL/il.h>

/**
 * @brief Utilitário simples para carregar texturas com DevIL.
 */
class Texture {
public:
  /**
   * @brief Carrega uma textura de imagem (jpg, png, etc.) e retorna o ID OpenGL.
   * @param path Caminho do arquivo
   * @return GLuint ID da textura, ou 0 se falhar
   */
  static GLuint load( const char * path );
};

#endif
