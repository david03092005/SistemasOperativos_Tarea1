#ifndef CUADRADO_H
#define CUADRADO_H

#include <iostream>
#include <string.h>

#include "figuras.h"

class Cuadrado : public figuras {
    private:
        float lado;

    public:
        
        Cuadrado() = default;
        Cuadrado(float lado, string color);

        float getLado();

        void setLado(float lado);

        
        float calcularArea() override;
        
    	float calcularPerimetro() override;
};


#endif