#include <iostream>
#include "MedicalExecutive.h"

using namespace std;

int main(int argc, char* argv[]) {
	if(argc != 2) {
		cout << "Incorrect number of arguments, exiting program." << endl;
		exit(EXIT_FAILURE);
	} else {

		//runs the medical executive with the file passed in
		MedicalExecutive medExec;
		medExec.fillList(argv[1]);
		medExec.userInterface();
	}
	return 0;
}