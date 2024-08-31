#include "controlU.h"

using namespace std;


controlU::controlU(record instruction) {
	this->instruction = instruction;
};

vector<string> controlU::decodeI() {
	vector<string> decode;
	for (int i = 0; i <= 3; i++){
		decode.push_back(this->getInstructionU().getInstruction(i));
	}
	
	return decode;
};


record controlU::getInstructionU() {
	return this->instruction;	
};