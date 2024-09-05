#ifndef PENTAGONO_H
#define PENTAGONO_H

#include "figuras.h"

class Pentagono : public figuras {
    private:
        float lado;

    public:

        Pentagono(float lado, string color);


        float getLado();
        void setLado(float lado);


        float calcularArea() override;
        float calcularPerimetro()  override;
};

#endif // PENTAGONO_H
