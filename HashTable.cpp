#include "HashTable.h"

// 哈希转换函数
int hash(string x) {
    int h = 0;      // 初始化哈希值
    for (int i = 0; i < x.size(); i++) {
        h = (h * 31 + x[i]) % 100;
    }

    h = abs(h);

    return h;
}

// 插入函数, 将一个string插入哈希表(不查重)
void Hashtable::insert(string key) {
    int h = hash(key);
    table[h].push_back(key);    // 将string加入哈希表中
}

// 查找函数
bool Hashtable::find(string key) {
    int h = hash(key);
    for (auto& p : table[h])
    {
        if (p == key)
            return true;
    }

    return false;
}

// 删除函数, 从哈希表中删除某个string值(如果存在), 返回是否成功
bool Hashtable::remove(string key)
{
    int h = hash(key);
    if (!find(key))
        return false;

    for (int i = 0; i < table[h].size(); i++) {
        if (table[h][i] == key) {
            table[h].erase(table[h].begin() + i);
            return true;
        }
    }

    return false;
}
