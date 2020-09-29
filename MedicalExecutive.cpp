#include "MedicalExecutive.h"

using namespace std;

void MedicalExecutive::userInterface() {
	//promps the user to interact with the citeis

	//holds user input
	char userInput;

	//loops though until exit program
    while(userInput != '6') {

		//displays options to user
        cout << endl << "Make a selection:" << endl;
        cout << "1) Increase infection level of all cities" << endl;
        cout << "2) Increase infection level of specific city" << endl;
        cout << "3) Print status of a specific city" << endl;
        cout << "4) Create quarantine log" << endl;
        cout << "5) Print all cities above an infection level" << endl;
        cout << "6) Exit" << endl;
        cout << "Choice: ";

		//gets user input
        cin >> userInput;
		cout << endl;

		//preforms action depending on user input
        switch(userInput) {
            case '1': {
                optionOne();
				break;
			}
            case '2': {
                optionTwo();
				break;
			}
            case '3': {
                optionThree();
				break;
			}
            case '4': {
                optionFour();
				break;
			}
            case '5': {
                optionFive();
				break;
			}
            case '6': {
				break;
                // do nothing, will exit loop back to main
			}
            default: {
                cout << "Invalid selection, please try again" << endl;
				break;
			}
        }
    }
    cout << "Program exiting, Goodbye!" << endl;
}

void MedicalExecutive::optionOne() {
	//increases the infection level of all the cities

	cout << "The infection level for all cities has been increased" << endl;

	//keeps track of all the newly added cities and cities that need to be removed
    vector<City> citiesToAdd;
	vector<int> removeIndex;

	//loops though all the cities
    for(int i = 0; i < cityList.size(); i++) {

		//increases infection level of a city
        cityList[i].setInfectionLevel(cityList[i].getInfectionLevel() + 1);
        int infectionLevel = cityList[i].getInfectionLevel();

        switch (infectionLevel) {
            case 1: {
                // decrease population by 10%
                cityList[i].setPopulation(cityList[i].getPopulation() - (int)(cityList[i].getPopulation() * 0.10));
				break;
			}
            case 2: {
                // decrease population by 20%
                cityList[i].setPopulation(cityList[i].getPopulation() - (int)(cityList[i].getPopulation() * 0.20));
				break;
			}
            case 3: {
                // decrease population by 25% and create a 'New' city
                string cityName = "New " + cityList[i].getName();
                int cityPopulation = (int)(cityList[i].getPopulation() * 0.25);
                cityList[i].setPopulation(cityList[i].getPopulation() - (int)(cityList[i].getPopulation() * 0.25));
				City newCity(cityName, cityPopulation, 0);
                citiesToAdd.push_back(newCity);
                cout << cityName << " has been made." << endl;
				break;
			}
			case 4: {
                // move to quarantine list
				// add index for removal from infected cities
				removeIndex.push_back(i);
                City quarantineCity = cityList[i];
                quarantineList.push_back(quarantineCity);
                cout << quarantineCity.getName() << " has been placed in quarantine!" << endl;
				break;
			}
        }
    }

	// removes the cities with infection level higher than 4 at the index
	for (int i = 0; i < removeIndex.size(); i++) {
		cityList.erase(cityList.begin() + removeIndex[i] - i);
	}

	// inserts all the newly created cities and sorts the all cities
    cityList.insert(cityList.end(), citiesToAdd.begin(), citiesToAdd.end());
    sort(cityList.begin(), cityList.end());
	sort(quarantineList.begin(), quarantineList.end());
}

void MedicalExecutive::optionTwo() {
	//increases the level of a specific city

	//holds the added city if a new one is added
    vector<City> citiesToAdd;

	//gets the user input
    string userInput;
	cout << "What city do you want to infect?: ";
	cin.ignore();
	getline(cin, userInput);

	//find the city the user searched a dummy city
	City temp(userInput, 0, 0); // dummy city to search by name
    auto findResult = find(cityList.begin(), cityList.end(), temp);

	//makes sure the city exits
    if (findResult != cityList.end()) {
        int i = distance(cityList.begin(), findResult);

		//applies the infection level
        cityList[i].setInfectionLevel(cityList[i].getInfectionLevel() + 1);
        int infectionLevel = cityList[i].getInfectionLevel();
        switch(infectionLevel) {
            case 1: {
                // decrease population by 10%
                cityList[i].setPopulation(cityList[i].getPopulation() - (int)(cityList[i].getPopulation() * 0.10));
				break;
			}
            case 2: {
                // decrease population by 20%
                cityList[i].setPopulation(cityList[i].getPopulation() - (int)(cityList[i].getPopulation() * 0.20));
				break;
			}
            case 3: {
                // decrease population by 25% and create a 'New' city
                string cityName = ("New " + cityList[i].getName());
                int cityPopulation = (int)(cityList[i].getPopulation() * 0.25);
                cityList[i].setPopulation(cityList[i].getPopulation() - (int)(cityList[i].getPopulation() * 0.25));
                City newCity(cityName, cityPopulation, 0);
				citiesToAdd.push_back(newCity);
                cout << cityName << " has been made." << endl;
				break;
			}
            case 4: {
                // move to quarantine list
                City quarantineCity = cityList[i];
				cityList.erase(cityList.begin() + i);
                quarantineList.push_back(quarantineCity);
                cout << quarantineCity.getName() << " has been placed in quarantine!" << endl;
				break;
			}
        }

		//inserts the new city and sorts the city list
		cityList.insert(cityList.end(), citiesToAdd.begin(), citiesToAdd.end());
        sort(cityList.begin(), cityList.end());
		sort(quarantineList.begin(), quarantineList.end());
        cout << "Infection level for " << userInput << " increased by 1" << endl;
    
	} else {
		//the city doesnt exits
        cout << "That city name does not exist" << endl;
    }
}

void MedicalExecutive::optionThree() {
	//get the status of a city

	//gets the user input
	string userInput;
	cout << "What city do you want the status of?: ";
	cin.ignore();
    getline(cin, userInput);

	//makes a temp city to see if the city exists
	City temp(userInput, 0, 0); // dummy city to search by name
    auto findResult = find(cityList.begin(), cityList.end(), temp);

	//checks to see if the city exits
    if (findResult != cityList.end()) {
        int i = distance(cityList.begin(), findResult);
        cout << "Status: " << cityList[i].getName() << ", " << cityList[i].getPopulation() << ", " << cityList[i].getInfectionLevel() << endl;
    } else {
        cout << "Sorry, " << userInput << " is not a city in the list\n";
    }
}

void MedicalExecutive::optionFour() {
	//makes a file of quarantine cities

	//gets user input
	cout << "What would you like the name of you log to be called?: ";
	string fileName;
	cin >> fileName;

	// makes the file 
	ofstream outfile;
	outfile.open(fileName);
	
	// prints all the quarantined cities to the file
	if(outfile.is_open()) {
		vector<City>::iterator it = quarantineList.begin();
		for (int i = 0; i < quarantineList.size(); i++) {
			outfile << quarantineList[i].getName() << " " << quarantineList[i].getPopulation() << " " << quarantineList[i].getInfectionLevel() << endl;
		}
		outfile.close();
	} else {
		cout << "Error writing log file." << endl;
	}
}

void MedicalExecutive::optionFive() {
	// prints all the infected cities above the given level

	//gets the user input
	int floor;
	cout << "Cities above what level?: ";
	cin >> floor;

	//loops though all the cities
	vector<City>::iterator it = this->cityList.begin();
	for (int i = 0; i < this->cityList.size(); i++) {

		//checks to see if above the level and prints it
		City current = (City)*it;
		if (current.getInfectionLevel() > floor) {
			cout << current.getName() << " " << current.getPopulation() << " " << current.getInfectionLevel() << endl;
		}
		advance(it, 1);
	}
}

void MedicalExecutive::fillList(string filename) {
	// fills the infected list with the with the file passed in

	//opens the file
	ifstream fileIn;
	fileIn.open(filename);

	//checks to see if it is a valid file
    if (!fileIn.good()) {
    	cout << "Unable to open file, exiting program." << endl;
    	exit(1); // terminate with error
    }

	//loops through line by line
    string currentLine;
    while(getline(fileIn, currentLine)) {

		//gets data from the line and creates a city
    	int levelIndex = currentLine.find_last_of(',');
		int infectionLevel = stoi(currentLine.substr(levelIndex + 1));
    	currentLine = currentLine.substr(0, levelIndex);
    	int populationIndex = currentLine.find_last_of(',');
		int population = stoi(currentLine.substr(populationIndex + 1));
		string name = currentLine.substr(0, populationIndex);
		City city(name, population, infectionLevel);

		//adds city to the infected city vector
    	cityList.push_back(city);
    }

	//closes the file and sorts the infected cities
    fileIn.close();
    sort(cityList.begin(), cityList.end());
}