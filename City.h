#include <string>
#include <iostream>

using namespace std;

class City {
	private:
		string name;
		int population;
		int infectionLevel;
	
	public:
		City(string name, int population, int infectionLevel);
		string getName();
		int getPopulation();
		int getInfectionLevel();
		void setName(string name);
		void setPopulation(int population);
		void setInfectionLevel(int infectionLevel);
		bool operator<(City c) const;
		bool operator==(City c) const;
};
