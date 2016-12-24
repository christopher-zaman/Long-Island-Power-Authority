#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class City {
public:
	string Name;
	double NumOfOutages;
	double TotalCust;
	double percentageArray;
};

int main()
{
	City data[1000];
	int count = 0;

	ifstream inFile("C:\\Users\\christopherzaman\\Desktop\\lipa.txt");
	if (inFile.good())
	{
		while (!inFile.eof())
		{
			inFile >> data[count].Name;
			inFile >> data[count].NumOfOutages;
			inFile >> data[count].TotalCust;
			count++;
		}
	}
	inFile.close();

	while (true)
	{
		cout << "1- Query City" << endl;
		cout << "2- City with Most outage" << endl;
		cout << "0- Exit" << endl;

		cout << "What you want to do?" << endl;
		int choice;
		cin >> choice;

		//Query City
		if (choice == 1)
		{
			string cityName;
			cout << "Enter City Name: " << endl;
			cin >> cityName;

			for (int i = 0; i < count; i++)
			{
				if (cityName == data[i].Name)
				{
					cout << "City: " << data[i].Name << endl << "# Of Outages: " << data[i].NumOfOutages << endl << "# of Ppl: " << data[i].TotalCust << endl;
					cout << endl;
				}
			}
		}

		//City With Most Outage
		else if (choice == 2)
		{
			double sum = 0;
			double highestPercent = -99999;
			double properPercentage;
			for (int i = 0; i < count; i++)
			{
				double percentageArray = data[i].NumOfOutages / data[i].TotalCust;
				properPercentage = percentageArray * 100;
				if (highestPercent < properPercentage)
				{
					highestPercent = properPercentage;
				}
			}
			cout << "The city with the highest outage has " << highestPercent << endl;
	}

	// Report all to see the contents of the file
	else if (choice == 4)
	{
		for (int i = 0; i < count; i++)
		{
			cout << "City: " << data[i].Name << endl;
			cout << "Outages: " << data[i].NumOfOutages << endl;
			cout << "Total People: " << data[i].TotalCust << endl;
		}
	}
	else if (choice == 5)
	{

	}
	else if (choice == 6)
	{

	}
	//break
	else if (choice == 0)
	{
		break;
	}
}
system("pause");
return 0;
}