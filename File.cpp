#include"File.h"
#include <fstream>
#include<cassert>
bool addCustom(Custom custom)
{
	std::ofstream ofs("custom.txt",std::ios::app);
	if (!ofs.is_open()) return false;
	ofs << custom.name << std::endl;
	ofs << custom.passWord << std::endl;
	ofs<<custom.age <<std::endl;
	ofs << custom.IDNumber << std::endl;
	ofs << custom.phoneNumber<< std::endl;
	ofs.close();
	return true;
}

bool addCity(string city)
{
	std::ofstream ofs("city.txt", std::ios::app);
	if (!ofs.is_open()) return false;
	ofs << std::endl;
	ofs << city;
	ofs.close();
	return true;
}

bool addFlight(Flight flight)
{
	std::ofstream ofs("flight.txt", std::ios::app);
	if (!ofs.is_open()) return false;
	ofs << flight.start << std::endl;
	ofs << flight.end << std::endl;
	ofs << flight.length << std::endl;
	ofs << flight.price << std::endl;
	ofs << flight.tickets<< std::endl;
	ofs.close();
	return true;
}

void addRecord(Purchase_Record record)
{
	std::ofstream ofs("record.txt", std::ios::out);
	ofs << record.IDNumber << std::endl;
	ofs << record.flight.start << std::endl;
	ofs << record.flight.end << std::endl;
	ofs << record.flight.length << std::endl;
	ofs << record.flight.price << std::endl;
	ofs << record.flight.tickets << std::endl;
	ofs.close();
}

std::vector<Custom> getCustom()
{
	std::vector<Custom> customs;
	std::ifstream ifs("custom.txt", std::ios::in);
	assert(ifs.is_open());
	while (!ifs.eof()) {
		Custom cus;
		ifs>> cus.name;
		ifs >> cus.passWord;
		ifs >> cus.age;
		ifs >> cus.IDNumber;
		ifs >> cus.phoneNumber;
		customs.push_back(cus);
	}
	ifs.close();
	return customs;
}

std::vector<string> getCity()
{
	std::vector<string> citys;
	std::ifstream ifs("city.txt", std::ios::in);
	assert(ifs.is_open());
	while (!ifs.eof()) {
		std::string cit;
		ifs >> cit;
		citys.push_back(cit);
	}
	ifs.close();
	return citys;
}

std::vector<Flight> getFlight()
{
	std::vector<Flight> flights;
	std::ifstream ifs("flight.txt", std::ios::in);
	assert(ifs.is_open());
	while (!ifs.eof()) {
		Flight flight;
		ifs >> flight.start;
		ifs >> flight.end;
		ifs >> flight.length;
		ifs >> flight.price;
		ifs >> flight.tickets;
		flights.push_back(flight);
	}
	ifs.close();
	return flights;
}





