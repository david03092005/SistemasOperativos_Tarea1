#include "triangulo.h"


Triangulo::Triangulo(float base, float altura, string color) : figuras(color, 0, 0) {
    this->base = base;
    this->altura = altura;
}

float Triangulo::getBase() {
    return this->base;
}

void Triangulo::setBase(float base) {
    this->base = base;
}

float Triangulo::getAltura() {
    return this->altura;
}

void Triangulo::setAltura(float altura) {
    this->altura = altura;
}

float Triangulo::calcularArea() {
    return (this->base * this->altura) / 2.0;
}

float Triangulo::calcularPerimetro() {
    return 3 * this->base;
}
