#include<iostream>
#include<map>
#include<vector>
#include<forward_list>
#include<algorithm>
#include "Custom.h"

#define MVMAX 500
    //购买机票
bool TicketSystem:: purchaseTicket(Path path, int num_tickets, std::string IDNumber) {
        //遍历路径上的所有边，将可售票数减去购买的票数
        for (int i = 0; i < path.flights.size(); i++) {
            auto& edge = graph.getEdge(path.flights[i].start, path.flights[i].end);
            edge.flight.tickets -= num_tickets;
        }

        int total_prices = 0, total_length = 0;
        //遍历路径上的所有边，计算总价格和总长度
        for (int i = 0; i < path.flights.size(); i++) {
            auto& edge = graph.getEdge(path.flights[i].start, path.flights[i].end);
            total_prices += edge.flight.price;
            total_length += edge.flight.length;
        }

        //记录购票信息
        Purchase_Record record;
        record.IDNumber = IDNumber;
        record.flight.start = path.flights[0].start;
        record.flight.end = path.flights[path.flights.size() - 1].end;
        record.flight.tickets = num_tickets;
        record.flight.price = total_prices;
        record.flight.length = total_length;
        purchase_records.push_back(record);

        std::cout << "Purchase success! Total price: " << total_prices << std::endl;
        return true;
    }


//退票
bool TicketSystem:: refundTicket(Path path, int num_tickets, std::string IDNumber) {
        //遍历路径上的所有边，将可售票数加上退票的票数         
        for (int i = 0; i < path.flights.size(); i++) {
            auto& edge = graph.getEdge(path.flights[i].start, path.flights[i].end);
            edge.flight.tickets += num_tickets;
        }
        
        //查找购票记录         
        auto it = std::find_if(purchase_records.begin(), purchase_records.end(), [&](const Purchase_Record& r) {
            return r.IDNumber == IDNumber && r.flight.start == path.flights[0].start && r.flight.end == path.flights[path.flights.size() - 1].end;
        });

        //若存在购票记录则执行退款操作，否则提示无记录         
        if (it != purchase_records.end()) {
            int refund_price = it->flight.price * num_tickets / it->flight.tickets;
            it->flight.tickets -= num_tickets;
            it->flight.price -= refund_price;
            std::cout << "Refund success! Refund price: " << refund_price << std::endl;
            return true;
        }
        else {
            std::cout << "No record found!" << std::endl;
            return false;
        }
    }




