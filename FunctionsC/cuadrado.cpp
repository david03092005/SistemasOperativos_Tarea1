#include <iostream>
#include <string>

#include "cuadrado.h"

Cuadrado::Cuadrado(float lado, std::string color) : figuras(color, 0, 0) {
    this->lado = lado;
}

float Cuadrado::getLado() {
    return this->lado;
}

void Cuadrado::setLado(float lado) {
    this->lado = lado;
}

float Cuadrado::calcularArea() {
    return this->lado * this->lado;
}

float Cuadrado::calcularPerimetro() {
    return 4 * this->lado;
}
