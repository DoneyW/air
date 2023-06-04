#include<iostream>
#include<map>
#include<vector>
#include<forward_list>
#include<algorithm>
#include "Custom.h"

#define MVMAX 500
    //�����Ʊ
bool TicketSystem:: purchaseTicket(Path path, int num_tickets, std::string IDNumber) {
        //����·���ϵ����бߣ�������Ʊ����ȥ�����Ʊ��
        for (int i = 0; i < path.flights.size(); i++) {
            auto& edge = graph.getEdge(path.flights[i].start, path.flights[i].end);
            edge.flight.tickets -= num_tickets;
        }

        int total_prices = 0, total_length = 0;
        //����·���ϵ����бߣ������ܼ۸���ܳ���
        for (int i = 0; i < path.flights.size(); i++) {
            auto& edge = graph.getEdge(path.flights[i].start, path.flights[i].end);
            total_prices += edge.flight.price;
            total_length += edge.flight.length;
        }

        //��¼��Ʊ��Ϣ
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


//��Ʊ
bool TicketSystem:: refundTicket(Path path, int num_tickets, std::string IDNumber) {
        //����·���ϵ����бߣ�������Ʊ��������Ʊ��Ʊ��         
        for (int i = 0; i < path.flights.size(); i++) {
            auto& edge = graph.getEdge(path.flights[i].start, path.flights[i].end);
            edge.flight.tickets += num_tickets;
        }
        
        //���ҹ�Ʊ��¼         
        auto it = std::find_if(purchase_records.begin(), purchase_records.end(), [&](const Purchase_Record& r) {
            return r.IDNumber == IDNumber && r.flight.start == path.flights[0].start && r.flight.end == path.flights[path.flights.size() - 1].end;
        });

        //�����ڹ�Ʊ��¼��ִ���˿������������ʾ�޼�¼         
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




