#include <iostream>
#include <fstream>
#include <vector>
#include "record.h"
#include "controlU.h"

using namespace std;


int cpu(string archioCo);


int main(){
	string nombreArchivo = "codigo.txt";
	record pc = record("d15 NULL NULL NULL");
	controlU cu = controlU(pc);
	string ins = pc.getInstruction(1);
	vector<string> dec = cu.decodeI();
	for (int i = 0; i <= 3; i++){
		cout << dec[i];
	}
	cout << ins;
	//cpu(nombreArchivo);
	return 0;
}


int cpu(string archivoCo){
	ifstream archivo(archivoCo.c_str());
	string linea;
	//string MDR, ADR, 
	// Obtener línea de archivo, y almacenar contenido en "linea"
	while (getline(archivo, linea)) {
	    // Lo vamos imprimiendo
	    cout << "Una linea: ";
	    cout << linea << endl;
	}
	
	return 0;
}


int main();