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
		void setRegisters(vector<record> registers);
		
		record getFromMem(int pos);
};


#endif