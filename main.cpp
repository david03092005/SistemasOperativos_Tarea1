#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "record.h"
#include "controlU.h"
#include "memory.h"

using namespace std;


int cpu(memory memoryA);
string toUpper(string str);


int main(){
	string nameFile = "codigo.txt"; //Archivo con el codigo y los datos
	ifstream file(nameFile.c_str());
	string line;
	vector<record> A;
	memory memoryA(A);
	// Obtener línea de archivo, y almacenar contenido en "linea"
	int i = 0;
	while (getline(file, line)) {
	    memoryA.setRegister(line);
	    //cout << memoryA.getFromMem(i).getAllIns() << endl;
	    i++;
	}
	cout << memoryA.sizeMem() << endl;
	
	cpu(memoryA);
	return 0;
}


int cpu(memory memoryA){
	
	// Se inicializan todos los registros que contiene la CPU
	record PC = record("0");
	record ICR = record();
	record MAR = record();
	record MDR = record();
	record acu = record();
	record ALU = record();
	controlU ctrlU = controlU();
	
	// Se le pasa al MAR la direccion donde esta la primera instruccion en memoria (PC)
	MAR.setInstruction(PC.getAllIns());
	// Se trae de la memoria en la posición MAR la instruccion
	record temp = memoryA.getFromMem(MAR);
	// Se almacena en el MDR
	MDR.setInstruction(temp.getAllIns());
	// Al ser una instruccion se almacena en el ICR
	ICR.setInstruction(MDR.getAllIns());
	// Incrementa el PC
	PC.increase();
	
	ctrlU.setInstructionU(ICR);
	vector<string> IDecode = ctrlU.decodeI();
	
	// Se ejecuta la instruccion LOAD
	if (toUpper(IDecode[0]) == "LDR") {
		MAR.setInstruction(IDecode[1]);
		temp = memoryA.getFromMem(MAR);
		MDR.setInstruction(temp.getAllIns());
	}
	
//	cout << PC.getAllIns() << endl;
	
	
//	controlU cu = controlU(pc);
//	string ins = pc.getInstruction(1);
//		cout << dec[i];
//	}
//	cout << ins;
	return 0;
}


// Función para convertir a mayúsculas
string toUpper(string str) {
    string upperStr = str;  // Copia de la cadena original
    transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
    return upperStr;
}


int main();