#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "figuras.h"

class Rectangulo : public figuras {
    private:
        float ancho;
        float alto;

    public:
        Rectangulo(float ancho, float alto, string color);

        
        float getAncho();
        void setAncho(float ancho);
        
        float getAlto();
        void setAlto(float alto);

       
        float calcularArea() override;
        float calcularPerimetro() override;
};

#endif // RECTANGULO_H
