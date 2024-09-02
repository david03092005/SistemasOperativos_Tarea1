#include "AluPc.h"


void AluPc::increase(bool INCorDEC) {
	int sum;
	if (INCorDEC) {
		sum = 1;
	}
	else {
		sum = -1;
	}
	this->instruction = to_string(stoi(this->instruction) + sum);
}

void AluPc::add(record acum) {
	int num1 = stoi(acum.getAllIns());
	int num2 = stoi(this->getAllIns());
	string result = to_string(num1 + num2);
	this->instruction = result;
}