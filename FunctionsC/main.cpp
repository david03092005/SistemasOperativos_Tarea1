#include <iostream>
#include "cuadrado.h"
#include "rectangulo.h"
#include "triangulo.h"
#include "pentagono.h"
#include "circulo.h"
#include "rombo.h"

int main() {

    Cuadrado cuadrado(5.0, "Rojo");
    Rectangulo rectangulo(4.0, 6.0, "Verde");
    Triangulo triangulo(3.0, 4.0, "Azul");
    Circulo circulo(7.0, "Naranja");
	Rombo rombo(8.0, 5.0, "Morado");

    std::cout << "Cuadrado:" << std::endl;
    std::cout << "Color: " << cuadrado.getColor() << std::endl;
    std::cout << "Área: " << cuadrado.calcularArea() << std::endl;
    std::cout << "Perímetro: " << cuadrado.calcularPerimetro() << std::endl << std::endl;


    std::cout << "Rectángulo:" << std::endl;
    std::cout << "Color: " << rectangulo.getColor() << std::endl;
    std::cout << "Área: " << rectangulo.calcularArea() << std::endl;
    std::cout << "Perímetro: " << rectangulo.calcularPerimetro() << std::endl << std::endl;


    std::cout << "Triángulo:" << std::endl;
    std::cout << "Color: " << triangulo.getColor() << std::endl;
    std::cout << "Área: " << triangulo.calcularArea() << std::endl;
    std::cout << "Perímetro: " << triangulo.calcularPerimetro() << std::endl << std::endl;


    std::cout << "Círculo:" << std::endl;
    std::cout << "Color: " << circulo.getColor() << std::endl;
    std::cout << "Área: " << circulo.calcularArea() << std::endl;
    std::cout << "Perímetro: " << circulo.calcularPerimetro() << std::endl << std::endl;
    
    
    std::cout << "Rombo:" << std::endl;
    std::cout << "Color: " << rombo.getColor() << std::endl;
    std::cout << "Área: " << rombo.calcularArea() << std::endl;
    std::cout << "Perímetro: " << rombo.calcularPerimetro() << std::endl << std::endl;


    return 0;
}
