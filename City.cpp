#include "City.h"

using namespace std;
	
	City::City(string name, int population, int infectionLevel) {
		this->name = name;
		this->population = population;
		this->infectionLevel = infectionLevel;
	}

	string City::getName() {
		return name;
	}

	int City::getPopulation() {
		return population;
	}

	int City::getInfectionLevel() {
		return infectionLevel;
	}

	void City::setName(string name) {
		this->name = name;
	}

	void City::setPopulation(int population) {
		this->population = population;
	}

	void City::setInfectionLevel(int infectionLevel) {
		this->infectionLevel = infectionLevel;
	}
	
	bool City::operator<(City c) const {
		if (!(c.population == this->population)) {
			return c.population < this->population;
		}
		if (!(c.infectionLevel == this->infectionLevel)) {
			return c.infectionLevel < this->infectionLevel;
		}
		return c.name.compare(this->name) < 0;
	}
	
	bool City::operator==(City c) const {
		return (c.getName().compare(this->name) == 0);
	}
