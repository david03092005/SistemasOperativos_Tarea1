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


record memory::getFromMem(record mar) {
	int pos = stoi(mar.getAllIns());
	return this->getRegisters()[pos];
}

int memory::sizeMem() {
	return this->registers.size();
}