#pragma once
#include<string>
#include<vector>
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
	Custom_Tree(std::vector<Custom> &cus);
	string get(string IDNumber);//查找节点，查询成功返回密码，查询失败返回空字符串

	//void deleteCustom();//
	void put(string IDNumber, string passWord);
private:
	class Node{
	public:
		Node(string IDNumber, string passWord);
		Node* left, * right;
		bool color;//由父节点指向他的节点的键的颜色
		int N; //以本节点位根节点的节点总数
		string getNumber() { return IDNumber; };
		string getpassWord() { return passWord; };
		void chgPassWord(string newPassWord) { passWord = newPassWord; };
	private:
		string IDNumber; //键
		string passWord; //值
	};
	Node* root; //根节点
	Node* rotateRight(Node *h);
	Node* rotateLeft(Node *h);
	void flipColors(Node *h);
	int size(Node* h);
	static const bool RED = true;//
	static const bool BLACK = false;//
	bool isRed(Node *h);
	Node* put(Node* root,string IDnumber, string passWord); //添加节点
	string get(Node* h, string ID);
};

//客户类:
//类名称: Custom
//类成员 :
//String name;
//String password;
//int age;
//String IDNumber;
//String phoneNumber;