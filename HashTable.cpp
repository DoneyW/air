#include "HashTable.h"

// ��ϣת������
int hash(string x) {
    int h = 0;      // ��ʼ����ϣֵ
    for (int i = 0; i < x.size(); i++) {
        h = (h * 31 + x[i]) % 100;
    }

    h = abs(h);

    return h;
}

// ���뺯��, ��һ��string�����ϣ��(������)
void Hashtable::insert(string key) {
    int h = hash(key);
    table[h].push_back(key);    // ��string�����ϣ����
}

// ���Һ���
bool Hashtable::find(string key) {
    int h = hash(key);
    for (auto& p : table[h])
    {
        if (p == key)
            return true;
    }

    return false;
}

// ɾ������, �ӹ�ϣ����ɾ��ĳ��stringֵ(�������), �����Ƿ�ɹ�
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
