#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

#include "City.h"

using namespace std;

class MedicalExecutive {
	private:
		std::vector<City> cityList;
		std::vector<City> quarantineList;
		
		void optionOne();
		void optionTwo();
		void optionThree();
		void optionFour();
		void optionFive();
		
	public:
		void fillList(string filename);
		void userInterface();
};