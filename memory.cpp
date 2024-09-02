#include "memory.h"


memory::memory(vector<record> registers) {
	this->registers = registers;
}


vector<record> memory::getRegisters() {
	return this->registers;
}


void memory::setRegister(record reg) {
	this->registers.push_back(reg);
}


void memory::setInMem(record mar, string value) {
	record temp = record(value);
	int pos = stoi(mar.getAllIns());
	this->registers[pos] = temp;
} 


record memory::getFromMem(record mar) {
	int pos = stoi(mar.getAllIns());
	return this->getRegisters()[pos];
}

int memory::sizeMem() {
	return this->registers.size();
}