#pragma once
#include "freeglut.h"
#include "Mundo.h"
#include "pieza.h"
class ClassTablero {
private:

    float tamCasilla;       // Tama�o de cada casilla
    float posX, posY, posZ; // Posici�n del tablero

    // Colores para las casillas (pueden personalizarse)
    GLfloat colorClaro[3];
    GLfloat colorOscuro[3];

    // Dibuja una casilla individual
    void dibujarCasilla(float x, float z, bool esClara);
public:
    // Constructor: tama�o del tablero (normalmente 8x8) y tama�o de cada casilla
    ClassTablero(float tamCasilla = 1.0f) :
        tamCasilla(tamCasilla), posX(0), posY(0), posZ(0)
    {
        colorClaro[0] = 0.96f; colorClaro[1] = 0.96f; colorClaro[2] = 0.86f;
        colorOscuro[0] = 0.55f; colorOscuro[1] = 0.27f; colorOscuro[2] = 0.07f;
    }

    //TEMPORAL ESTO LUEGO LO CAMBIO
    
    // Dibuja el tablero en la posici�n actual
    void dibuja(int filas, int columnas, float tamCasilla = 1.0f);

    // Establece la posici�n del tablero
    void setPosicion(float x, float y, float z);

    // Obtiene el tama�o total del tablero
    float getTamanoTotal() const;

    /////
    bool esPosicionValida(const Vector2D& posicion) const;

	bool estaOcupada(const Vector2D& posicion) const;
};

