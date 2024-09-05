#include "rombo.h"
#include <cmath>

Rombo::Rombo(float diagonalMayor, float diagonalMenor, string color) : figuras(color, 0, 0) {
    this->diagonalMayor = diagonalMayor;
    this->diagonalMenor = diagonalMenor;
}

float Rombo::getDiagonalMayor() {
    return this->diagonalMayor;
}

void Rombo::setDiagonalMayor(float diagonalMayor) {
    this->diagonalMayor = diagonalMayor;
}

float Rombo::getDiagonalMenor() {
    return this->diagonalMenor;
}

void Rombo::setDiagonalMenor(float diagonalMenor) {
    this->diagonalMenor = diagonalMenor;
}

float Rombo::calcularArea() {
    return (this->diagonalMayor * this->diagonalMenor) / 2.0;
}

float Rombo::calcularPerimetro() {
    float lado = sqrt(pow(this->diagonalMayor / 2.0, 2) + pow(this->diagonalMenor / 2.0, 2));
    return 4 * lado;
}
