#pragma once

#include <iostream>
using std::string;

// 节点类
template <typename T>
class Node {
public:
	T data; // 数据
	Node<T>* next; // 指向下一个节点的指针

	// 构造函数
	Node(T data, Node<T>* next = nullptr) {
		this->data = data;
		this->next = next;
	}
};

// 定义一个单向链表类，包含头节点和尾节点的指针，以及链表的长度
template <typename T>
class LinkList {
private:
	Node<T>* head; // 头节点指针
	Node<T>* tail; // 尾节点指针
	int size; // 链表长度
public:
	// 构造函数，初始化头节点和尾节点为nullptr，长度为0
	LinkList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	// 析构函数，释放链表中的所有节点的内存空间
	~LinkList() {
		Node<T>* current = head; // 从头节点开始遍历
		while (current != nullptr) {
			Node<T>* next = current->next; // 保存下一个节点的指针
			delete current; // 删除当前节点
			current = next; // 移动到下一个节点
		}
	}

	// 在链表的末尾插入一个新的节点，包含给定的数据
	void append(T data) {
		Node<T>* newNode = new Node<T>(data); // 创建一个新的节点
		if (head == nullptr) { // 如果链表为空，那么新节点就是头节点和尾节点
			head = newNode;
			tail = newNode;
		}
		else { // 如果链表不为空，那么新节点就是尾节点的下一个节点，并更新尾节点
			tail->next = newNode;
			tail = newNode;
		}
		size++; // 链表长度加一
	}

	// 在链表的指定位置插入一个新的节点，包含给定的数据
	bool insert(int index, T data) {
		if (index < 0 || index > size) { // 如果索引无效，返回false
			return false;
		}
		if (index == 0) { // 如果索引为0，那么新节点就是头节点，并更新头节点
			Node<T>* newNode = new Node<T>(data, head);
			head = newNode;
		}
		else if (index == size) { // 如果索引等于长度，那么新节点就是尾节点，并更新尾节点
			Node<T>* newNode = new Node<T>(data);
			tail->next = newNode;
			tail = newNode;
		}
		else { // 如果索引在中间，那么找到前一个节点和后一个节点，并插入新节点
			Node<T>* prev = head; // 前一个节点
			for (int i = 0; i < index - 1; i++) { // 遍历到前一个节点
				prev = prev->next;
			}
			Node<T>* next = prev->next; // 后一个节点
			Node<T>* newNode = new Node<T>(data, next); // 创建新节点，并指向后一个节点
			prev->next = newNode; // 前一个节点指向新节点
		}
		size++; // 链表长度加一

		return true;
	}

	// 删除链表中指定位置的节点，并返回被删除的数据
	T remove(int index) {
		if (index < 0 || index >= size) { // 如果索引无效，返回空引用
			return nullptr;
		}
		T data; // 被删除的数据
		if (index == 0) { // 如果索引为0，那么删除头节点，并更新头节点
			Node<T>* temp = head; // 临时保存头节点
			head = head->next; // 头节点移动到下一个节点
			data = temp->data; // 获取被删除的数据
			delete temp; // 删除临时保存的头节点
		}
		else { // 如果索引不为0，那么找到前一个节点和当前节点，并删除当前节点
			Node<T>* prev = head; // 前一个节点
			for (int i = 0; i < index - 1; i++) { // 遍历到前一个节点
				prev = prev->next;
			}
			Node<T>* current = prev->next; // 当前要删除的节点
			prev->next = current->next; // 前一个节点指向当前节点的下一个节点
			data = current->data; // 获取被删除的数据
			delete current; // 删除当前要删除的节点

			if (index == size - 1) {
				//如果索引等于长度减一，那么更新尾结点
				tail = prev; //尾结点移动到前一个结点
			}
		}
		size--; //链表长度减一
		return data; //返回被删除的数据
	}

	//获取链表中指定位置的数据
	T get(int index) {
		if (index < 0 || index >= size) {
			//如果索引无效，返回空引用
			return nullptr;
		}
		Node<T>* current = head; //从头结点开始遍历
		for (int i = 0; i < index; i++) {
			//遍历到指定位置
			current = current->next;
		}
		return current->data; //返回该位置的数据
	}

	//修改链表中指定位置的数据
	bool set(int index, T data) {
		if (index < 0 || index >= size) {
			//如果索引无效，返回false
			throw std::out_of_range("Index out of range");
		}
		Node<T>* current = head; //从头结点开始遍历

		for (int i = 0; i < index; i++) {
			//遍历到指定位置
			current = current->next;
		}
		current->data = data; //修改该位置的数据
		return true;
	}

	//判断链表是否为空
	bool isEmpty() {
		return size == 0;
	}

	//获取链表的长度
	int getSize() {
		return size;
	}

	//打印链表中所有元素
	string print() {
		Node<T>* current = head; //从头结点开始遍历
		string result = "";
		while (current != nullptr) {
			result += current->data + " ";//添加当前元素
			current = current->next; //移动到下一元素
		}
		std::cout << std::endl;
	}
};