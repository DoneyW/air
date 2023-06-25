#include"File.h"
#include <fstream>
#include<cassert>
bool addCustom(Custom custom)
{
	std::ifstream ifs("record.txt", std::ios::in);
	char c, temp = NULL;

	ifs >> c;
	if (ifs.eof())
	{
		temp = '\n';
	}

	ifs.close();
	std::ofstream ofs("custom.txt",std::ios::app);
	if (!ofs.is_open()) return false;
	if (temp != NULL)
		ofs << temp;
	ofs << custom.name << std::endl;
	ofs << custom.passWord << std::endl;
	ofs<<custom.age <<std::endl;
	ofs << custom.IDNumber << std::endl;
	ofs << custom.phoneNumber;
	ofs.close();
	return true;
}

bool addCity(string city)
{
	std::ifstream ifs("record.txt", std::ios::in);
	char c, temp = NULL;

	ifs >> c;
	if (ifs.eof())
	{
		temp = '\n';
	}

	ifs.close();
	std::ofstream ofs("city.txt", std::ios::app);
	if (!ofs.is_open()) return false;
	if (temp != NULL)
		ofs << temp;
	ofs << city;
	ofs.close();
	return true;
}

bool addFlight(Flight flight)
{
	std::ifstream ifs("record.txt", std::ios::in);
	char c, temp = NULL;

	ifs >> c;
	if (ifs.eof())
	{
		temp = '\n';
	}

	ifs.close();
	std::ofstream ofs("flight.txt", std::ios::app);
	if (!ofs.is_open()) return false;
	if (temp != NULL)
		ofs << temp;
	ofs << flight.start << std::endl;
	ofs << flight.end << std::endl;
	ofs << flight.length << std::endl;
	ofs << flight.price << std::endl;
	ofs << flight.tickets;
	ofs.close();
	return true;
}

void addRecord(Purchase_Record record)
{
	std::ifstream ifs("record.txt", std::ios::in);
	char c, temp = NULL;

	ifs >> c;
	if (ifs.eof())
	{
		temp = '\n';
	}

	ifs.close();

	std::ofstream ofs("record.txt", std::ios::out);
	if (temp != NULL)
		ofs << temp;
	ofs << record.IDNumber << std::endl;
	ofs << record.flight.start << std::endl;
	ofs << record.flight.end << std::endl;
	ofs << record.flight.length << std::endl;
	ofs << record.flight.price << std::endl;
	ofs << record.flight.tickets;
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

std::vector<Purchase_Record> getRecord(std::string IDNumber)
{
	std::vector<Purchase_Record> records;
	std::ifstream ifs("record.txt", std::ios::in);
	assert(ifs.is_open());
	while (!ifs.eof()) {
		Purchase_Record record;
		ifs >> record.IDNumber;
		// 判断ID是否一致
		ifs >> record.flight.start;
		ifs >> record.flight.end;
		ifs >> record.flight.length;
		ifs >> record.flight.price;
		if (record.IDNumber == IDNumber) records.push_back(record);
	}
	ifs.close();
	return records;
}

std::vector<Purchase_Record> getALLRecord()
{
	std::vector<Purchase_Record> records;
	std::ifstream ifs1("record.txt", std::ios::in);
	char c, temp = NULL;
	ifs1 >> c;
	if (ifs1.eof())
	{
		return records;
	}
	ifs1.close();
	std::ifstream ifs("record.txt", std::ios::in);
	assert(ifs.is_open());
	while (!ifs.eof()) {
		Purchase_Record record;
		ifs >> record.IDNumber;
		ifs >> record.flight.start;
		ifs >> record.flight.end;
		ifs >> record.flight.length;
		ifs >> record.flight.price;
		records.push_back(record);
	}
	ifs.close();
	return records;
}

void writeGraph(Graph *graph)
{
	std::vector<Flight> fs=graph->getFlight();
	std::ofstream ofs("flight.txt", std::ios::out);
	for (int i = 0; i < fs.size(); ++i)
	{
		ofs << fs[i].start << std::endl;
		ofs<<fs[i].end << std::endl;
		ofs<<fs[i].length << std::endl;
		ofs<<fs[i].price << std::endl;
		if(i!=fs.size()-1) ofs<<fs[i].tickets << std::endl;
		else ofs<< fs[i].tickets;
	}

}

void writeRecord(std::vector<Purchase_Record> source) 
{
	std::ofstream ofs("record.txt", std::ios::out);
	for (int i = 0; i < source.size(); i++)
	{
		ofs << source[i].IDNumber << std::endl;
		ofs << source[i].flight.start << std::endl;
		ofs << source[i].flight.end << std::endl;
		ofs << source[i].flight.length << std::endl;
		if (i != source.size() - 1) ofs << source[i].flight.price << std::endl;
		else ofs << source[i].flight.price;
	}
	
	ofs.close();
}
void writeFlight(std::vector<Flight> source)
{
	std::ofstream ofs("flight.txt", std::ios::out);
	for (int i = 0; i < source.size(); i++)
	{
		ofs << source[i].start << std::endl;
		ofs << source[i].end << std::endl;
		ofs << source[i].length << std::endl;
		ofs << source[i].price << std::endl;
		if (i != source.size() - 1) ofs << source[i].tickets << std::endl;
		else ofs << source[i].tickets;
	}

	ofs.close();
}
void writeCustom(std::vector<Custom> source) {
	std::ofstream ofs("custom.txt", std::ios::out);
	for (int i = 0; i < source.size(); i++)
	{
		ofs << source[i].name << std::endl;
		ofs << source[i].passWord << std::endl;
		ofs << source[i].age << std::endl;
		ofs << source[i].IDNumber << std::endl;
		if (i != source.size() - 1) ofs << source[i].phoneNumber<< std::endl;
		else ofs << source[i].phoneNumber;
	}

	ofs.close();
}







