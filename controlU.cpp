#include "controlU.h"

using namespace std;


controlU::controlU(record instruction) {
	this->instruction = instruction;
};


vector<string> controlU::decodeI() {
	vector<string> decode;
	for (int i = 0; i <= 3; i++){
		decode.push_back(this->getInstructionU().getInstruction(i));
		if (decode[i][0] == 'D' and i != 0) {
			decode[i] = decode[i].substr(1);
		}
	}
	return decode;
};


record controlU::getInstructionU() {
	return this->instruction;	
};


void controlU::setInstructionU(record instruction) {
	this->instruction = instruction;
}