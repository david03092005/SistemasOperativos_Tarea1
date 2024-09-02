#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "record.h"
#include "controlU.h"
#include "memory.h"
#include "AluPc.h"

using namespace std;


int cpu(memory memoryA);
string toUpper(string str);


int main(){
	string nameFile; //Archivo con el codigo y los datos
	do {
		cout << "Put the name of the program (file) that you want to execute (without the extension .txt) 0 to exit: ";
		cin >> nameFile;
		nameFile = nameFile + ".txt";
		ifstream file(nameFile.c_str());
		if (!file.is_open()) {
	        std::cerr << "Error: No se pudo abrir el archivo " << nameFile << std::endl;
	        return 404;  // Salir del programa con un código de error
	    }
	    else {
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
			
			cpu(memoryA);
			cout << endl;
		}
	}while(nameFile != "0.txt");
	
	return 0;
}


int cpu(memory memoryA) {
	// Se inicializan todos los registros que contiene la CPU
	// La ALU y el PC se inicializan como registros especiales, 
	// que pueden realizar operaciones aritmeticas.
	AluPc PC; 
	PC.setInstruction("0");
	AluPc ALU;
	record ICR = record();
	record MAR = record();
	record MDR = record();
	record ACC = record();
	controlU ctrlU = controlU();
	
	// Confirmacion para parar la ejecucion del programa
	bool end = false;
	
	while (not end) {
		// Se le pasa al MAR la direccion donde esta la siguiente instruccion en memoria (PC)
		MAR.setInstruction(PC.getAllIns());
		// Se trae de la memoria en la posición MAR la instruccion
		record temp = memoryA.getFromMem(MAR);
		// Se almacena en el MDR
		MDR.setInstruction(temp.getAllIns());
		// Al ser una instruccion se almacena en el ICR
		ICR.setInstruction(MDR.getAllIns());
		// Incrementa el PC
		PC.increase(true);
		// Se le pasa a la unidad de control la Instruccion que va a decodificar.
		ctrlU.setInstructionU(ICR);
		// Se decodifica la instruccion
		vector<string> IDecode = ctrlU.decodeI();
		
		// Se ejecuta la instruccion LOAD
		if (toUpper(IDecode[0]) == "LDR") {
			MAR.setInstruction(IDecode[1]);
			temp = memoryA.getFromMem(MAR);
			MDR.setInstruction(temp.getAllIns());
			ACC.setInstruction(MDR.getAllIns());
		}
		else if (toUpper(IDecode[0]) == "SET") {
			MAR.setInstruction(IDecode[1]);
			MDR.setInstruction(IDecode[2]); 
			memoryA.setInMem(MAR, MDR.getAllIns());
		}
		else if (toUpper(IDecode[0]) == "ADD") {
			MAR.setInstruction(IDecode[1]);
			temp = memoryA.getFromMem(MAR);
			MDR.setInstruction(temp.getAllIns());
			
			if (toUpper(IDecode[2]) == "NULL" and toUpper(IDecode[3]) == "NULL") {
				ALU.setInstruction(MDR.getAllIns());
				ALU.add(ACC);
				ACC.setInstruction(ALU.getAllIns());
			}
			else {
				ACC.setInstruction(MDR.getAllIns());
				MAR.setInstruction(IDecode[2]);
				temp = memoryA.getFromMem(MAR);
				MDR.setInstruction(temp.getAllIns());
				ALU.setInstruction(MDR.getAllIns());
				ALU.add(ACC);
				ACC.setInstruction(ALU.getAllIns());
				
				if (toUpper(IDecode[2]) != "NULL" and toUpper(IDecode[3]) != "NULL") {
					MAR.setInstruction(IDecode[3]);
					MDR.setInstruction(ACC.getAllIns());
					memoryA.setInMem(MAR, MDR.getAllIns());
				}
			}
		}
		else if (toUpper(IDecode[0]) == "INC") {
			MAR.setInstruction(IDecode[1]);
			temp = memoryA.getFromMem(MAR);
			MDR.setInstruction(temp.getAllIns());
			ACC.setInstruction(MDR.getAllIns());
			ALU.setInstruction(ACC.getAllIns());
			ALU.increase(true);
			ACC.setInstruction(ALU.getAllIns());
			MDR.setInstruction(ACC.getAllIns());
			memoryA.setInMem(MAR, MDR.getAllIns());
		}
		else if (toUpper(IDecode[0]) == "DEC") {
			MAR.setInstruction((IDecode[1]));
			temp = memoryA.getFromMem(MAR);
			MDR.setInstruction(temp.getAllIns());
			ACC.setInstruction(MDR.getAllIns());
			ALU.setInstruction(ACC.getAllIns());
			ALU.increase(false);
			ACC.setInstruction(ALU.getAllIns());
			MDR.setInstruction(ALU.getAllIns());
			memoryA.setInMem(MAR, MDR.getAllIns());
		}
		else if (toUpper(IDecode[0]) == "STR") {
			MAR.setInstruction(IDecode[1]);
			MDR.setInstruction(ACC.getAllIns());
			memoryA.setInMem(MAR, MDR.getAllIns());
		}
		else if (toUpper(IDecode[0]) == "SHW") {
			record show;
			if (toUpper(IDecode[1]) == "ACC"){
				show = ACC;
				cout << "ACC: ";
			}
			else if (toUpper(IDecode[1]) == "PC"){
				show = PC;
				cout << "PC: ";
			}
			else if (toUpper(IDecode[1]) == "ICR"){
				show = ICR;
				cout << "ICR: ";
			}
			else if (toUpper(IDecode[1]) == "MAR"){
				show = MAR;
				cout << "MAR: ";
			}
			else if (toUpper(IDecode[1]) == "MDR"){
				show = MDR;
				cout << "MDR: ";
			}
			else if (toUpper(IDecode[1]) == "UC"){
				show = ctrlU.getInstructionU();
				cout << "UC: ";
			}
			else {
				cout << "From Mem: ";
				MAR.setInstruction(IDecode[1]);
				show = memoryA.getFromMem(MAR);
				MDR.setInstruction(show.getAllIns());
			}
			cout << show.getAllIns() << endl;
		}
		else if (toUpper(IDecode[0]) == "PAUSE") {
			cout << "----PAUSE----" << endl;
			cout << "MAR:" << MAR.getAllIns() << endl;
			cout << "MDR:" << MDR.getAllIns() << endl;
			cout << "PC:" << PC.getAllIns() << endl;
			cout << "ICR:" << ICR.getAllIns() << endl;
			cout << "ControlUnity:" << ctrlU.getInstructionU().getAllIns() << endl;
			cout << "ACC:" << ACC.getAllIns() << endl;
		}
		else if (toUpper(IDecode[0]) == "END") {
			end = true;
		}
	}
	return 0;
}


// Función para convertir a mayúsculas
string toUpper(string str) {
    string upperStr = str;  // Copia de la cadena original
    transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
    return upperStr;
}


int main();