#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "figuras.h"

class Triangulo : public figuras {
    private:
        float base;
        float altura;

    public:
        // Constructor que inicializa la base, altura y pasa el color a la clase base
        Triangulo(float base, float altura, string color);

        // Getters y Setters para la base y la altura
        float getBase();
        void setBase(float base);

        float getAltura();
        void setAltura(float altura);

        // Implementación de métodos heredados
        float calcularArea() override;
        float calcularPerimetro() override;
};

#endif // TRIANGULO_H
