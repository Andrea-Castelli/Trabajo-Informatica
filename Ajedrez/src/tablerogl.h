#pragma once
#include "freeglut.h"

class TableroGL {
public:
    // Constructor: tama�o del tablero (normalmente 8x8) y tama�o de cada casilla
    TableroGL(int dimension = 8, float tamCasilla = 1.0f);

    // Dibuja el tablero en la posici�n actual
    void dibuja();

    // Establece la posici�n del tablero
    void setPosicion(float x, float y, float z);

    // Obtiene el tama�o total del tablero
    float getTamanoTotal() const;

private:
    int dimension;          // Dimensi�n del tablero (8 para ajedrez est�ndar)
    float tamCasilla;       // Tama�o de cada casilla
    float posX, posY, posZ; // Posici�n del tablero

    // Colores para las casillas (pueden personalizarse)
    GLfloat colorClaro[3];
    GLfloat colorOscuro[3];

    // Dibuja una casilla individual
    void dibujarCasilla(float x, float z, bool esClara);
};

