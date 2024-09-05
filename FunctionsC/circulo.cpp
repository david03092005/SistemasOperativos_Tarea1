#include "circulo.h"
#include <cmath> // Para M_PI y funciones matemáticas


Circulo::Circulo(float radio, string color) : figuras(color, 0, 0), radio(radio) {}


float Circulo::getRadio() {
    return this->radio;
}


void Circulo::setRadio(float radio) {
    this->radio = radio;
}


float Circulo::calcularArea() {
    return M_PI * this->radio * this->radio;
}


float Circulo::calcularPerimetro() {
    return 2 * M_PI * this->radio;
}
