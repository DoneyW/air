#pragma once
#include<iostream>
#include<map>
#include<vector>
#include<forward_list>
#include "Custom.h"
#define MVMAX 500
struct Flight {
	string start;
	string end;
	int length;
	int price;
	int tickets;
};
struct Path {   //城市之间的路径
	std::vector<std::string> city;
	int total_prices; //总票价
	int total_length; //总距离
	int tickets; //余票
};
struct Purchase_Record {
	string IDNumber;
	Flight flight;
};
class Graph {
public:
	Graph();
	void addVex(std::string city);
	void addArc(std::string departure, std::string destination, int length, int price,int tickets);
	Path getPath(std::string departure, std::string destination);
	Path getCheapestPath(std::string departure, std::string destination); //获取最便宜路径
	Path getShortestPath(std::string departure, std::string destination); //获取最短路径
	int getIdx(std::string);
	Purchase_Record buyTicket(int start, int end, std::string IDNumber);
	void refundTicket(int start, int end);
private:
	int vexnum = 0;
	int arcnum = 0;
	int idx = 0;
	std::string vex[MVMAX];   //城市，就是点
	std::map<std::string, int> Map_Vex_To_Index;//哈希表
	struct Edge {   //航班，就是边
		int index;    //指向顶点的索引
		Flight flight;
	};
	std::forward_list<Edge> List[MVMAX];//链表
};