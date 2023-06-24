#pragma once
#include"Custom.h"
#include<fstream>
#include"Graph.h"
// test
//姓名 密码 年龄 账号 手机号
bool addCustom(Custom custom);  //追加写入一个Custom

//城市名（字符串）
bool addCity(string city);//追加写入一个城市


//始发地 目的地 距离 票价 余票
bool addFlight(Flight flight);//追加写入一个航班

//1个账号 1个行帮
void addRecord(Purchase_Record record);

std::vector<Custom> getCustom();//读取所有Custom

std::vector<string> getCity();//读取所有城市

std::vector<Flight> getFlight();//读取所有航班

std::vector<Purchase_Record> getRecord(std::string IDNumber);//读取所有购买记录

std::vector<Purchase_Record> getALLRecord();

void writeGraph(Graph *graph);

void writeCustom(std::vector<Custom>);

void writeRecord(std::vector<Purchase_Record>);

void writeFlight(std::vector<Flight>);