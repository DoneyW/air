#include<iostream>
#include<map>
#include<vector>
#include<forward_list>
#include<algorithm>
#include "Custom.h"
#include "TicketSystem.h"
#include <vector>
#include "File.h"
#define MVMAX 500
TicketSystem::TicketSystem(std::string IDNumber,Graph *graph) :IDNumber(IDNumber),graph(graph)
{
    purchase_records = getRecord(IDNumber);
}
//购买机票
bool TicketSystem:: purchaseTicket(Path path) {
        //遍历路径上的所有边，将可售票数减去购买的票数
    
    for (int i = 0; i <path.city.size()-1; i++)
    {
        int idx1 = graph->getIdx(path.city[i]);
        int idx2 = graph->getIdx(path.city[i + 1]);
        purchase_records.push_back(graph->buyTicket(idx1, idx2,IDNumber));
    }
    writeGraph(*graph);
    writeRecord(purchase_records);
}


//退票
bool TicketSystem:: refundTicket(std::string st,std::string ed,std::string IDNumber) {
        //遍历路径上的所有边，将可售票数加上退票的票数         
    int idx1 = graph->getIdx(st);
    int idx2 = graph->getIdx(ed);
    graph->refundTicket(idx1, idx2);
    for (int i = 0; i < purchase_records.size(); ++i)
    {
        if (purchase_records[i].flight.start == st && purchase_records[i].flight.end == ed) {
            purchase_records.erase(purchase_records.begin()+i);
        }
    }
    writeGraph(*graph);
    writeRecord(purchase_records);
}




