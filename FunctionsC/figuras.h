#ifndef FIGURAS_H
#define FIGURAS_H

#include <iostream>
#include <string.h>

using namespace std;

class figuras {
	protected:
		string color;
		float area;
		float perimetro;
	
	public:
		figuras() = default;
		
	    figuras(string color, float area, float perimetro);
	    
		string getColor();
		
		float getArea();
		
		float getPerimetro();
		
		void setColor(string color);
		
		void setArea(float area);
		
		void setPerimetro(float perimetro);
			    
		virtual float calcularArea();
		
		virtual float calcularPerimetro();

};
	
#endif 