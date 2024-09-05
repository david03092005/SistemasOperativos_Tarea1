#include <iostream>
#include <string.h>
#include <math.h>

#include "figuras.h"
using namespace std;

figuras::figuras(string color, float area, float perimetro) {
	this->color = color;
	this->area = area;
	this->perimetro = perimetro;
}


string figuras::getColor() {
    return this->color;
}

float figuras::getArea() {
    return this->area;
}

float figuras::getPerimetro() {
    return this->perimetro;
}


void figuras::setColor(string color) {
    this->color = color;
}

void figuras::setArea(float area) {
    this->area = area;
}

void figuras::setPerimetro(float perimetro) {
    this->perimetro = perimetro;
}


float figuras::calcularArea() {
    return 0;
}


float figuras::calcularPerimetro() {
    return 0;
}
