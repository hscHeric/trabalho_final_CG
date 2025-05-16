#include "texture.hpp"

#include <cstdio>

GLuint Texture::load( const char * path ) {
  ILuint imgId;
  ilGenImages( 1, &imgId );
  ilBindImage( imgId );

  if ( !ilLoadImage( path ) ) {
    printf( "Erro ao carregar imagem: %s\n", path );
    ilDeleteImages( 1, &imgId );
    return 0;
  }

  ilConvertImage( IL_RGBA, IL_UNSIGNED_BYTE );

  GLuint texId;
  glGenTextures( 1, &texId );
  glBindTexture( GL_TEXTURE_2D, texId );

  glTexImage2D( GL_TEXTURE_2D,
                0,
                GL_RGBA,
                ilGetInteger( IL_IMAGE_WIDTH ),
                ilGetInteger( IL_IMAGE_HEIGHT ),
                0,
                GL_RGBA,
                GL_UNSIGNED_BYTE,
                ilGetData() );

  glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
  glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

  ilDeleteImages( 1, &imgId );
  return texId;
}
