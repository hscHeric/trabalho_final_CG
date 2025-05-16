#include "camera.hpp"

#include <GL/glut.h>

Camera camera;

void init() {
  glEnable( GL_DEPTH_TEST );
  glClearColor( 0.5f, 0.8f, 1.0f, 1.0f );  // Céu azul claro
}

void drawGrid( float size, int divisions ) {
  float step = size / divisions;
  float half = size / 2.0f;

  glColor3f( 0.7f, 0.7f, 0.7f );  // Cinza claro

  glBegin( GL_LINES );
  for ( int i = 0; i <= divisions; ++i ) {
    float pos = -half + i * step;

    // Linhas paralelas ao eixo Z
    glVertex3f( pos, 0, -half );
    glVertex3f( pos, 0, half );

    // Linhas paralelas ao eixo X
    glVertex3f( -half, 0, pos );
    glVertex3f( half, 0, pos );
  }
  glEnd();
}

void drawCubes() {
  glColor3f( 0.8f, 0.3f, 0.3f );  // Vermelho

  float positions[][3] = {
    { 5, 1, 5 }, { -5, 1, -5 }, { 0, 1, 10 }, { -10, 1, 0 }, { 15, 1, -15 }
  };

  for ( auto & pos : positions ) {
    glPushMatrix();
    glTranslatef( pos[0], pos[1], pos[2] );
    glutSolidCube( 2.0f );
    glPopMatrix();
  }
}

void display() {
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glLoadIdentity();

  camera.applyView();

  drawGrid( 50.0f, 20 );  // chão quadriculado
  drawCubes();            // obstáculos fixos

  glutSwapBuffers();
}

void reshape( int w, int h ) {
  if ( h == 0 )
    h = 1;
  float ratio = (float)w / h;

  glViewport( 0, 0, w, h );
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  gluPerspective( 45.0f, ratio, 1.0f, 500.0f );
  glMatrixMode( GL_MODELVIEW );
}

void keyboard( unsigned char key, int x, int y ) {
  switch ( key ) {
    case 'w': camera.moveForward( 1.0f ); break;
    case 's': camera.moveBackward( 1.0f ); break;
    case 'a': camera.moveLeft( 1.0f ); break;
    case 'd': camera.moveRight( 1.0f ); break;
    case 'q': camera.rotateY( -5.0f ); break;
    case 'e': camera.rotateY( 5.0f ); break;
    case 'r': camera.moveForward( 0.5f ); break;   // Suavização
    case 'f': camera.moveBackward( 0.5f ); break;  // Suavização
    case 27 : exit( 0 );                            // ESC
  }
  glutPostRedisplay();
}

int main( int argc, char ** argv ) {
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
  glutInitWindowSize( 1000, 600 );
  glutCreateWindow( "Cidade Interativa - Movimentação com Câmera" );

  init();

  glutDisplayFunc( display );
  glutReshapeFunc( reshape );
  glutKeyboardFunc( keyboard );

  glutMainLoop();
  return 0;
}
