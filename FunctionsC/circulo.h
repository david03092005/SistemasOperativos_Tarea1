#ifndef CIRCULO_H
#define CIRCULO_H

#include "figuras.h"

class Circulo : public figuras {
    private:
        float radio;

    public:
        Circulo(float radio, string color);

        
        float getRadio();
        void setRadio(float radio);

        
        float calcularArea() override;
        float calcularPerimetro() override;
};

#endif