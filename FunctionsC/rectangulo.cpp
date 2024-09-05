#include "rectangulo.h"


Rectangulo::Rectangulo(float ancho, float alto, string color) : figuras(color, 0, 0){
	this->ancho = ancho;
	this->alto = alto;
}


float Rectangulo::getAncho() {
    return this->ancho;
}


void Rectangulo::setAncho(float ancho) {
    this->ancho = ancho;
}


float Rectangulo::getAlto() {
    return this->alto;
}


void Rectangulo::setAlto(float alto) {
    this->alto = alto;
}


float Rectangulo::calcularArea() {
    return this->ancho * this->alto;
}


float Rectangulo::calcularPerimetro() {
    return 2 * (this->ancho + this->alto);
}
