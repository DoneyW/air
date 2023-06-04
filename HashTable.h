#pragma once

#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::pair;

// 定义一个哈希函数，将字符串转换为整数(utf8)
int hash(string x);

class Hashtable {

private:
    vector<vector<string>> table;
public:
    // 初始化表
    Hashtable() {
        table.resize(100);  //哈希表大小为100
    }

    // 插入函数, 将一个string插入哈希表(不查重)
    void insert(string key);

    // 查找函数
    bool find(string key);

    // 删除函数, 从哈希表中删除某个string值(如果存在), 返回是否成功
    bool remove(string key);
};


