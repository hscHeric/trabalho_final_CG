#include "model.hpp"

Model::Model( const char * path ) {
  scene = importer.ReadFile( path, aiProcess_Triangulate | aiProcess_GenSmoothNormals );
  if ( !scene || !scene->HasMeshes() ) {
    printf( "Erro ao carregar modelo: %s\n", path );
  }
}

void Model::draw() {
  if ( scene )
    drawNode( scene->mRootNode );
}

void Model::drawNode( const aiNode * node ) {
  for ( unsigned int i = 0; i < node->mNumMeshes; ++i ) {
    drawMesh( scene->mMeshes[node->mMeshes[i]] );
  }

  for ( unsigned int i = 0; i < node->mNumChildren; ++i ) {
    drawNode( node->mChildren[i] );
  }
}

void Model::drawMesh( const aiMesh * mesh ) {
  glBegin( GL_TRIANGLES );
  for ( unsigned int i = 0; i < mesh->mNumFaces; ++i ) {
    const aiFace & face = mesh->mFaces[i];
    for ( int j = 0; j < 3; ++j ) {
      int index = face.mIndices[j];
      if ( mesh->HasNormals() ) {
        glNormal3fv( &mesh->mNormals[index].x );
      }
      glVertex3fv( &mesh->mVertices[index].x );
    }
  }
  glEnd();
}
