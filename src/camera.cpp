#include "camera.hpp"

#include <GL/glut.h>
#include <cmath>

#define DEG2RAD 0.017453f

Camera::Camera() {
  posX     = 0.0f;
  posY     = 5.0f;
  posZ     = 20.0f;
  yawAngle = 0.0f;
  upX      = 0.0f;
  upY      = 1.0f;
  upZ      = 0.0f;

  centerX = posX + sin( yawAngle * DEG2RAD );
  centerY = posY;
  centerZ = posZ - cos( yawAngle * DEG2RAD );
}

void Camera::applyView() {
  centerX = posX + sin( yawAngle * DEG2RAD );
  centerZ = posZ - cos( yawAngle * DEG2RAD );
  gluLookAt( posX, posY, posZ, centerX, centerY, centerZ, upX, upY, upZ );
}

void Camera::moveForward( float delta ) {
  posX += delta * sin( yawAngle * DEG2RAD );
  posZ -= delta * cos( yawAngle * DEG2RAD );
}

void Camera::moveBackward( float delta ) {
  posX -= delta * sin( yawAngle * DEG2RAD );
  posZ += delta * cos( yawAngle * DEG2RAD );
}

void Camera::moveLeft( float delta ) {
  posX -= delta * cos( yawAngle * DEG2RAD );
  posZ -= delta * sin( yawAngle * DEG2RAD );
}

void Camera::moveRight( float delta ) {
  posX += delta * cos( yawAngle * DEG2RAD );
  posZ += delta * sin( yawAngle * DEG2RAD );
}

void Camera::rotateY( float angleDelta ) {
  yawAngle += angleDelta;
}

float Camera::getX() const {
  return posX;
}

float Camera::getY() const {
  return posY;
}

float Camera::getZ() const {
  return posZ;
}
