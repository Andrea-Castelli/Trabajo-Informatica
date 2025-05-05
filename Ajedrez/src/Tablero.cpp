#include "Tablero.h"
#include "freeglut.h"
#include "Peon.h"

void ClassTablero::dibuja() {
   
	// Colores para las casillas (pueden personalizarse)
    colorClaro[0] = 0.96f; colorClaro[1] = 0.96f; colorClaro[2] = 0.86f;
    colorOscuro[0] = 0.55f; colorOscuro[1] = 0.27f; colorOscuro[2] = 0.07f;

    glPushMatrix();
	glTranslatef(posX, posY, posZ); // Trasladar el tablero a la posici�n deseada
	// Bucle para dibujar cada casilla del tablero
    for (int i = 0; i < filas_; i++) {
        for (int j = 0; j < columnas_; j++) {
            // Alternar colores de casillas
            bool esClara = (i + j) % 2 == 0;
            float x = j * tamCasilla;
            float z = i * tamCasilla;

            dibujarCasilla(x, z, esClara);
        }
    }
	// Luego de dibujar el tablero, dibujamos y ubicamos el dibujo de las piezas ��Unicamente en el espacio 2D del tablero, pero no en la matriz!!
    UbicaPieza();
    // Dibujar borde del tablero
    glColor3f(0.1f, 0.1f, 0.1f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    glVertex3f(0, 0.01f, 0);
    glVertex3f(filas_ * tamCasilla, 0.01f, 0);
    glVertex3f(filas_ * tamCasilla, 0.01f, filas_ * tamCasilla);
    glVertex3f(0, 0.01f, filas_ * tamCasilla);
    glEnd();

    glPopMatrix();
}
// Dibuja una casilla en la posici�n (x,z) con el color correspondiente
void ClassTablero::dibujarCasilla(float x, float z, bool esClara) {
    if (esClara) {
        glColor3fv(colorClaro);
    }
    else {
        glColor3fv(colorOscuro);
    }

    glBegin(GL_QUADS);
    glVertex3f(x, z, 0);
    glVertex3f(x + tamCasilla, z, 0);
    glVertex3f(x + tamCasilla, z+tamCasilla,0);
    glVertex3f(x, z+tamCasilla,0 );
    glEnd();
}
// Establece la posici�n del tablero en el espacio
void ClassTablero::setPosicion(float x, float y, float z) {
    posX = x;
    posY = y;
    posZ = z;
}
// Dibuja las piezas en el tablero
void ClassTablero::UbicaPieza() {
    for (int i = 0; i < filas_; ++i) {
        for (int j = 0; j < columnas_; ++j) {
            float x = j + 0.8f;
            float z = i + 0.9f;
            if (tablero[i][j] != nullptr)
                tablero[i][j]->dibuja(x, z);  // m�todo que llamar� al sprite seg�n color o tipo
        }
    }
}
// Pone los -1 y 1 o lo numeros que representan una pieza en la matriz del tablero
void ClassTablero::ColocarPiezas() {
    for (int j = 0; j < columnas_; ++j) {
        tablero[1][j] = new ClassPeon(ClassPieza::Color::NEGRO, Vector2D(j, 1));
        tablero[filas_ - 2][j] = new ClassPeon(ClassPieza::Color::BLANCO, Vector2D(j, filas_ - 2));
    }
}
// Anima las piezas en el tablero
void ClassTablero::AnimaPiezas() {
    ObjPieza.AnimaPeon();  // Anima sprites de la pieza
}
void ClassTablero::ImprimirEnPantalla() {
    for (int i = 0; i < filas_; i++) {
        for (int j = 0; j < columnas_; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}
// Metodos para comprobar posiciones
bool ClassTablero::esPosicionValida(const Vector2D& pos) const {
	return pos.x >= 0 && pos.x < columnas_ && pos.y >= 0 && pos.y < filas_; // Comprobar si la posici�n est� dentro de los l�mites del tablero
}
bool ClassTablero::estaOcupada(const Vector2D& pos) const {
    if (!esPosicionValida(pos)) return false;
    return tablero[pos.y][pos.x] != nullptr;
}
