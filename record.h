#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <vector>

using namespace std;


class record {
	private:
		string instruction;
		
	public:
		record() = default; //Constructor por defecto
		
		record(string instruction); //Constructor

		string getInstruction(int pos);
		
		void setInstruction(string instruction);
		
		string getAllIns();
		
		void increase();
};


#endif