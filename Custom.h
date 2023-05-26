#pragma once
#include<string>
using std::string;
struct Custom {
	string name;
	string passWord;
	int age;
	string IDNumber;
	string phoneNumber;
};
class Custom_Tree {   //红黑树，用于查找用户
public:
	Custom_Tree();
	string get(string IDNumber);//查找节点，查询成功返回密码，查询失败返回空字符串
	void put(); //添加节点
	void deleteCustom();//
private:

	class Node{
	public:
		Node(Custom custum);
	private:
		static const bool RED = true;//
		static const bool BLACK = false;//
		string IDNumber; //键
		string passWord; //值
		Node *left, *right;
		int N;//以该节点为根的节点总数
		bool color;//由父节点指向他的节点的键的颜色
		bool isRed();
	};
	Node* root; //根节点
	void rotateRight(Node h);
	void roateLeft(Node h);
	void flipColors(Node h);
};

//客户类:
//类名称: Custom
//类成员 :
//String name;
//String password;
//int age;
//String IDNumber;
//String phoneNumber;