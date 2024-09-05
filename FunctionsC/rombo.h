#ifndef ROMB_H
#define ROMB_H

#include "figuras.h"

class Rombo : public figuras {
    private:
        float diagonalMayor;
        float diagonalMenor;

    public:
        Rombo(float diagonalMayor, float diagonalMenor, string color);
        
        float getDiagonalMayor();
		void setDiagonalMayor(float diagonalMayor);
        
		float getDiagonalMenor();
        void setDiagonalMenor(float diagonalMenor);
        
		float calcularArea() override;
        float calcularPerimetro() override;
};

#endif // ROMB_H