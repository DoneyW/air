#include<iostream>
#include<map>
#include<vector>
#include<forward_list>
#include<algorithm>
#include "Custom.h"

#define MVMAX 500
struct Flight {
	string start;
	string end;
	int length;
	int price;
	int tickets;
};

struct Purchase_Record {
	string IDNumber;
	Flight flight;
};

struct Edge { 
    int start;
    int end; 
	Flight flight; 
};

struct Path {   //城市之间的路径
	std::vector<std::string> city;
	int total_prices; //总票价
	int total_length; //总距离
	int tickets; //余票
};

class TicketSystem { 
public:
	 bool purchaseTicket(Path path, int numtickets, std::string IDNumber); 
     bool refundTicket(Path path, int numtickets, std::string IDNumber);

private: Graph& graph; std::vector purchase_records; };
