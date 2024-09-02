#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <vector>
#include "record.h"

using namespace std;

class memory {
	private:
		vector<record> registers;
		
	public:
		memory() = default;
		
		memory(vector<record> registers);
		
		vector<record> getRegisters();
		
		void setRegister(record registers);
		
		record getFromMem(record mar);
		
		int sizeMem();
		
		void setInMem(record mar, string value);
};


#endif