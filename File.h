#pragma once
#include"Custom.h"
#include<fstream>
#include"Graph.h"
// test
//���� ���� ���� �˺� �ֻ���
bool addCustom(Custom custom);  //׷��д��һ��Custom

//���������ַ�����
bool addCity(string city);//׷��д��һ������


//ʼ���� Ŀ�ĵ� ���� Ʊ�� ��Ʊ
bool addFlight(Flight flight);//׷��д��һ������

//1���˺� 1���а�
void addRecord(Purchase_Record record);

std::vector<Custom> getCustom();//��ȡ����Custom

std::vector<string> getCity();//��ȡ���г���

std::vector<Flight> getFlight();//��ȡ���к���

std::vector<Purchase_Record> getRecord(std::string IDNumber);//��ȡ���й����¼
void writeGraph(Graph graph);

void writeCustom(std::vector<string>);

void writeRecord(std::vector<Purchase_Record>);