#include "record.h"

using namespace std;


std::vector<std::string> split(std::string str, char delimiter);


record::record(string instruction) {
	this->instruction = instruction;
}


string record::getInstruction(int pos){
	vector<string> inst = split(instruction, ' ');
	return inst[pos];
}


vector<string> split(string str, char pattern) {
    
    int posInit = 0;
    int posFound = 0;
    string splitted;
    vector<string> results;
    
    while(posFound >= 0){
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        results.push_back(splitted);
    }
    
    return results;
}