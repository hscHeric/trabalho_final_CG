#ifndef CAMERA_H
#define CAMERA_H

/**
 * @brief Classe Camera para controle da visualização
 */
class Camera {
private:
  float posX, posY, posZ;           /// Posição atual da câmera (olho)
  float centerX, centerY, centerZ;  /// Ponto para onde a câmera está olhando
  float upX, upY, upZ;              /// Vetor "para cima" da câmera
  float yawAngle;                   /// Ângulo de rotação horizontal (em graus)

public:
  /**
   * @brief Construtor padrão da câmera, com valores iniciais definidos.
   */
  Camera();

  /**
   * @brief Aplica a visualização atual utilizando gluLookAt.
   *
   * Deve ser chamada no início da função display(), após glLoadIdentity().
   */
  void applyView();

  /**
   * @brief Move a câmera para frente, na direção em que ela está olhando.
   * @param delta Distância a ser movida
   */
  void moveForward( float delta );

  /**
   * @brief Move a câmera para trás, na direção oposta à que ela está olhando.
   * @param delta Distância a ser movida
   */
  void moveBackward( float delta );

  /**
   * @brief Move a câmera para a esquerda, perpendicular à direção de visão.
   * @param delta Distância a ser movida
   */
  void moveLeft( float delta );

  /**
   * @brief Move a câmera para a direita, perpendicular à direção de visão.
   * @param delta Distância a ser movida
   */
  void moveRight( float delta );

  /**
   * @brief Rotaciona a câmera horizontalmente (eixo Y).
   * @param angleDelta Variação do ângulo em graus (positivo ou negativo)
   */
  void rotateY( float angleDelta );

  /**
   * @brief Retorna a coordenada X da posição da câmera.
   * @return Valor de X
   */
  float getX() const;

  /**
   * @brief Retorna a coordenada Y da posição da câmera.
   * @return Valor de Y
   */
  float getY() const;

  /**
   * @brief Retorna a coordenada Z da posição da câmera.
   * @return Valor de Z
   */
  float getZ() const;
};

#endif
