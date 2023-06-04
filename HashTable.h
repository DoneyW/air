#pragma once

#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::pair;

// ����һ����ϣ���������ַ���ת��Ϊ����(utf8)
int hash(string x);

class Hashtable {

private:
    vector<vector<string>> table;
public:
    // ��ʼ����
    Hashtable() {
        table.resize(100);  //��ϣ���СΪ100
    }

    // ���뺯��, ��һ��string�����ϣ��(������)
    void insert(string key);

    // ���Һ���
    bool find(string key);

    // ɾ������, �ӹ�ϣ����ɾ��ĳ��stringֵ(�������), �����Ƿ�ɹ�
    bool remove(string key);
};


