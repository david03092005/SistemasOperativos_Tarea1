#ifndef ALUPC_H
#define ALUPC_H

#include <iostream>
#include <vector>
#include "record.h"

using namespace std;


class AluPc : public record {
	public:
		//AluPc() = default; //Constructor por defecto
		
		//AluPc(string instruction); //Constructor
		
		void increase(bool INCorDEC);

		void add(record acum);
};


#endif