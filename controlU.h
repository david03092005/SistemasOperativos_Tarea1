#ifndef CONTROLU_H
#define CONTROLU_H

#include <iostream>
#include <vector>
#include "record.h"

using namespace std;


class controlU {
	private:
		record instruction;
		
	public:
		controlU() = default; //Constructor por defecto
		
		controlU(record instruction); //Constructor
		
		void setInstructionU(record instruction);
		
		record getInstructionU();
		
		vector<string> decodeI(); //Decodifica la instruccion
};


#endif