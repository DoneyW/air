#pragma once
#include<iostream>
#include<map>
#include<vector>
#include<forward_list>
#include "Custom.h"
#include "Graph.h"
#include <algorithm>
#define MVMAX 500
Graph::Graph() {
        vexnum = 0;
        arcnum = 0;
        idx = 0;
    }
    
//添加顶点
void Graph::addVex(std::string city) {
        vex[vexnum++] = city;    //将城市加入到顶点数组中并更新顶点数量
        Map_Vex_To_Index[city] = idx++;    //将城市与索引值对应起来
    }

//添加弧
void Graph::addArc(std::string departure, std::string destination, int length, int price, int tickets) {
        Edge edge;
        edge.index = Map_Vex_To_Index[destination];//将边的终点设置为目的地在顶点数组中的索引
        edge.flight.start = departure;//设置边的起点
        edge.flight.end = destination;//设置边的终点
        edge.flight.length = length;//设置边的长度
        edge.flight.price = price;//设置边的价格
        edge.flight.tickets = tickets;//设置边的剩余票数
        List[Map_Vex_To_Index[departure]].push_front(edge);//将边加入到邻接表中
        arcnum++;//更新边的数量
    }

//获取路径
Path Graph::getPath(std::string departure, std::string destination) {
        Path path;//初始化路径
        path.total_prices = 0;//初始化总价格为0
        path.total_length = 0; //初始化总长度为0
        path.tickets = 50;//初始化剩余票数为50

        int start = Map_Vex_To_Index[departure];//获取起点在顶点数组中的索引
        int end = Map_Vex_To_Index[destination];//获取终点在顶点数组中的索引
        std::vector<bool> visited(vexnum, false);//初始化访问数组
        std::vector<int> dist(vexnum, INT_MAX);//初始化距离数组
        std::vector<int> prev(vexnum, -1);//初始化前驱节点数组
        dist[start] = 0;//将起点到起点的距离设置为0

 //使用Dijkstra算法计算最短路径
        while (!visited[end]) {//初始化最小距离为无穷大
            int min_dist = INT_MAX;//初始化当前节点为-1
            
            int u = -1;
            for (int i = 0; i < vexnum; i++) {
                if (!visited[i] && dist[i] < min_dist) {
                    u = i;//更新当前节点为距离最小的未访问节点
                    min_dist = dist[i];//更新最小距离
                }
            }
            if (u == -1) {  //若所有节点均已访问过则退出循环
                break;
            }
            visited[u] = true;  //将当前节点标记为已访问
            
             //遍历当前节点所有的邻接节点
            for (auto& edge : List[u]) {
                int v = edge.index;//获取邻接节点在顶点数组中的索引
                int len = edge.flight.length;//获取边的长度
                int price = edge.flight.price;//获取边的价格
                
                
                if (!visited[v] && dist[u] + len < dist[v]) {
                    dist[v] = dist[u] + len;//更新起点到该节点的距离
                    prev[v] = u;//更新该节点的前驱节点
                    //购票时将票数减1
                }
            }
        }

//若终点被访问过则说明可以到达，否则说明不存在路径
        if (visited[end]) {
        	//从终点往回遍历前驱节点，得到路径上所有的城市
            for (int i = end; i != start; i = prev[i]) {
                path.city.push_back(vex[i]);
            }
            path.city.push_back(vex[start]);//将起点加入到城市列表中
            std::reverse(path.city.begin(), path.city.end());//因为是从终点往回遍历的，所以需要对城市列表进行逆序操作
            
             //遍历城市列表中相邻的城市，计算总价格、总长度及可售票数
            for (int i = 0; i < path.city.size() - 1; i++) {
                std::string start = path.city[i];
                std::string end = path.city[i + 1];
                for (auto& edge : List[Map_Vex_To_Index[start]]) {
                    if (edge.flight.end == end) {
                        path.total_prices += edge.flight.price;
                        path.total_length += edge.flight.length;
                        path.tickets = std::min(path.tickets, edge.flight.tickets);//取所有边中可售票数的最小值
                        break;
                    }
                }
            }
        }
        else {
            std::cout << "No path found!" << std::endl;//未找到路径
        }
        return path;//返回路径
    }
int Graph::getIdx(std::string place)
{
    return Map_Vex_To_Index[place];
}

Purchase_Record Graph::buyTicket(int start, int end,std::string IDNumber)
{
    std::forward_list<Edge>::iterator i;
    for (i = List[start].begin(); i != List[start].end(); ++i)
    {
        if (end == (*i).index) {
            (*i).flight.tickets--;
            Purchase_Record record = { IDNumber,(*i).flight };
            return record;
        }
    }
}

void Graph::refundTicket(int start, int end)
{
    std::forward_list<Edge>::iterator i;
    for (i = List[start].begin(); i != List[start].end(); ++i)
    {
        if (end == (*i).index) {
            (*i).flight.tickets++;
            return;
        }
    }
}

std::vector<Flight> Graph::getFlight()
{
    std::vector<Flight> fs;
    for (int i = 0; i < vexnum; ++i)
    {
        for (std::forward_list<Edge>::iterator j = List[i].begin(); j != List[i].end(); ++j) {
            Flight f = { (*j).flight.start,(*j).flight.end,(*j).flight.length,(*j).flight.price
            ,(*j).flight.tickets };
            fs.push_back(f);
        }
    }
    return fs;
}

Path Graph::getShortestPath(std::string departure, std::string destination) {
    Path path;//初始化路径
    path.total_prices = 0;//初始化总价格为0
    path.total_length = 0; //初始化总长度为0
    path.tickets = 50;//初始化剩余票数为50

    int start = Map_Vex_To_Index[departure];//获取起点在顶点数组中的索引
    int end = Map_Vex_To_Index[destination];//获取终点在顶点数组中的索引

    std::vector<bool> visited(vexnum, false);//初始化访问数组
    std::vector<int> dist(vexnum, INT_MAX);//初始化距离数组
    std::vector<int> prev(vexnum, -1);//初始化前驱节点数组

    dist[start] = 0;//将起点到起点的距离设置为0

    //使用Dijkstra算法计算最短路径
    while (!visited[end]) {
        int min_dist = INT_MAX;
        int u = -1;

        //找到距离起点最近且未访问过的节点
        for (int i = 0; i < vexnum; i++) {
            if (!visited[i] && dist[i] < min_dist) {
                u = i;
                min_dist = dist[i];
            }
        }

        if (u == -1) {
            break;
        }

        visited[u] = true;

        //遍历当前节点所有的邻接节点
        for (auto& edge : List[u]) {
            int v = edge.index;//获取邻接节点在顶点数组中的索引
            int len = edge.flight.length;//获取边的长度

            if (!visited[v] && dist[u] + len < dist[v]) {
                dist[v] = dist[u] + len;//更新起点到该节点的距离
                prev[v] = u;//更新该节点的前驱节点
            }
        }
    }

    //没找到路径
    if (prev[end] == -1) {
        std::cout << "No path found!" << std::endl;
        return path;
    }

    //从终点往回遍历前驱节点，得到路径上所有的城市
    int p = end;
    while (p != start) {
        path.city.push_back(vex[p]);
        p = prev[p];
    }
    path.city.push_back(departure);
    std::reverse(path.city.begin(), path.city.end());//因为是从终点往回遍历的，所以需要对城市列表进行逆序操作

    //遍历城市列表中相邻的城市，计算总价格、总长度及可售票数
    for (int i = 0; i < path.city.size() - 1; i++) {
        std::string start = path.city[i];
        std::string end = path.city[i + 1];
        for (auto& edge : List[Map_Vex_To_Index[start]]) {
            if (edge.flight.end == end) {
                path.total_prices += edge.flight.price;
                path.total_length += edge.flight.length;
                path.tickets = std::min(path.tickets, edge.flight.tickets);//取所有边中可售票数的最小值
                break;
            }
        }
    }

    return path;//返回路径
}

Path Graph::getCheapestPath(std::string departure, std::string destination) {
    Path path;//初始化路径
    path.total_prices = 0;//初始化总价格为0
    path.total_length = 0; //初始化总长度为0
    path.tickets = 50;//初始化剩余票数为50

    int start = Map_Vex_To_Index[departure];//获取起点在顶点数组中的索引
    int end = Map_Vex_To_Index[destination];//获取终点在顶点数组中的索引
    std::vector<bool> visited(vexnum, false);//初始化访问数组
    std::vector<int> dist(vexnum, INT_MAX);//初始化距离数组
    std::vector<int> prev(vexnum, -1);//初始化前驱节点数组
    std::vector<Path> paths(vexnum);//用于存储起点到每个顶点的最短路径信息

    dist[start] = 0;//将起点到起点的距离设置为0   

//使用Dijkstra算法计算最短路径
    while (!visited[end]) {
        int min_dist = INT_MAX;
        int u = -1;
        for (int i = 0; i < vexnum; i++) {
            if (!visited[i] && dist[i] < min_dist) {
                u = i;
                min_dist = dist[i];
            }
        }
        if (u == -1) {
            break;
        }
        visited[u] = true;

        for (auto& edge : List[u]) {
            int v = edge.index;
            int price = edge.flight.price;

            if (!visited[v] && dist[u] + price < dist[v]) {
                dist[v] = dist[u] + price;
                prev[v] = u;
                paths[v].city.push_back(vex[u]);
                paths[v].total_prices = price;
            }
        }
    }

    //遍历起点到终点的所有路径，找到价格最低的路径
    std::vector<Path> allPaths;//存储所有路径
    for (int i = 0; i < vexnum; i++) {
        if (i == start) {
            continue;
        }
        if (paths[i].city.empty()) {//若该顶点不可达，则跳过
            continue;
        }
        paths[i].city.push_back(vex[i]);
        allPaths.push_back(paths[i]);
    }
    std::sort(allPaths.begin(), allPaths.end(), PathPriceCmp());//按价格排序

    for (auto& p : allPaths) {
        if (p.city.back() == destination && p.total_prices < path.total_prices) {
            path = p;
        }
    }

    if (path.total_prices == INT_MAX) {
        std::cout << "No path found!" << std::endl;
    }
    else {
        //遍历城市列表中相邻的城市，计算总长度及可售票数
        for (int i = 0; i < path.city.size() - 1; i++) {
            std::string start = path.city[i];
            std::string end = path.city[i + 1];
            for (auto& edge : List[Map_Vex_To_Index[start]]) {
                if (edge.flight.end == end) {
                    path.total_length += edge.flight.length;
                    path.tickets = std::min(path.tickets, edge.flight.tickets);
                    break;
                }
            }
        }
    }
    return path;
} //获取最便宜路径





