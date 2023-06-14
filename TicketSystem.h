#include<iostream>
#include<map>
#include<vector>
#include<forward_list>
#include<algorithm>
#include "Custom.h"
#include "Graph.h"

#define MVMAX 500


class TicketSystem { 
public:
	TicketSystem(std::string IDNumber,Graph *graph);
	 bool purchaseTicket(Path path); 
	 bool refundTicket(std::string st, std::string ed, std::string IDNumber);

private: 
	Graph* graph; 
	std::vector<Purchase_Record> purchase_records;
	std::string IDNumber;
};
