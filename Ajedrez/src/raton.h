#pragma once

class raton {
public:
    // Constructor (opcional si quieres inicializar cosas en el futuro)
    raton() {}

    // M�todo para procesar el rat�n
    void click(int button, int state, int x, int y);

    void mouse(int button, int state, int x, int y, int filas, int columnas, int caso);

};