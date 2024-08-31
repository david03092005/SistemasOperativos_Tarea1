#include "memory.h"


memory::memory(vector<record> registers) {
	this->registers = registers;
}


vector<record> memory::getRegisters() {
	return this->registers;
}


void memory::setRegisters(vector<record> registers) {
	this->registers = registers;
}


record memory::getFromMem(int pos) {
	return this->getRegisters()[pos];
}