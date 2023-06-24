#pragma once
#include<iostream>
#include<map>
#include<vector>
#include<forward_list>
#include "Custom.h"
#include "Graph.h"
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

    dist[start] = 0;//将起点到起点的距离设置为0

    std::map<Path*, bool> PQ;//使用优先队列存储所有路径

    //将起点加入优先队列
    Path* pPath = new Path;
    pPath->city.push_back(departure);
    pPath->total_prices = 0;
    pPath->total_length = 0;
    pPath->tickets = 50;
    PQ[pPath] = true;

    //使用Dijkstra算法计算最便宜路径
    while (!PQ.empty())
    {
        //取出优先队列中票价最小的路径
        auto it = PQ.begin();
        Path* tmpPath = it->first;
        PQ.erase(it);

        if (visited[Map_Vex_To_Index[tmpPath->city.back()]]) {//目标城市已经被访问过，则前面找到的是最优解
            path = *tmpPath;
            break;
        }

        //当前路径访问的最后一个城市标记为已经访问过
        visited[Map_Vex_To_Index[tmpPath->city.back()]] = true;

        //遍历所有邻接节点
        for (auto& edge : List[Map_Vex_To_Index[tmpPath->city.back()]]) {
            //获取邻接节点在顶点数组中的索引
            int v = edge.index;
            //获取边的价格
            int price = edge.flight.price;

            if (!visited[v]) {
                //计算新路径的总价格
                int new_price = tmpPath->total_prices + price;
                //如果当前节点未被访问过，则将该节点加入优先队列
                if (dist[v] == INT_MAX) {
                    Path* pNewPath = new Path;
                    pNewPath->city = tmpPath->city;
                    pNewPath->city.push_back(vex[v]);
                    pNewPath->total_prices = new_price;
                    pNewPath->total_length = tmpPath->total_length + edge.flight.length;
                    pNewPath->tickets = std::min(tmpPath->tickets, edge.flight.tickets);
                    PQ[pNewPath] = true;
                    dist[v] = new_price;
                    prev[v] = Map_Vex_To_Index[tmpPath->city.back()];
                }
                //如果当前节点已被访问过，则更新该节点的路径信息
                else if (new_price < dist[v]) {
                    auto it = PQ.begin();
                    while (it != PQ.end())
                    {
                        if (it->first->city.back() == vex[v])
                        {
                            PQ.erase(it++);
                        }
                        else
                        {
                            ++it;
                        }
                    }

                    Path* pNewPath = new Path;
                    pNewPath->city = tmpPath->city;
                    pNewPath->city.push_back(vex[v]);
                    pNewPath->total_prices = new_price;
                    pNewPath->total_length = tmpPath->total_length + edge.flight.length;
                    pNewPath->tickets = std::min(tmpPath->tickets, edge.flight.tickets);
                    PQ[pNewPath] = true;

                    dist[v] = new_price;
                    prev[v] = Map_Vex_To_Index[tmpPath->city.back()];
                }
            }
        }
        delete tmpPath;
    }

    //若终点未被访问过则说明不存在路径
    if (!visited[end]) {
        std::cout << "No path found!" << std::endl;
    }

    return path;//返回路径
}











