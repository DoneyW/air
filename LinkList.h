#pragma once

#include <iostream>
using std::string;

// �ڵ���
template <typename T>
class Node {
public:
	T data; // ����
	Node<T>* next; // ָ����һ���ڵ��ָ��

	// ���캯��
	Node(T data, Node<T>* next = nullptr) {
		this->data = data;
		this->next = next;
	}
};

// ����һ�����������࣬����ͷ�ڵ��β�ڵ��ָ�룬�Լ�����ĳ���
template <typename T>
class LinkList {
private:
	Node<T>* head; // ͷ�ڵ�ָ��
	Node<T>* tail; // β�ڵ�ָ��
	int size; // ������
public:
	// ���캯������ʼ��ͷ�ڵ��β�ڵ�Ϊnullptr������Ϊ0
	LinkList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	// �����������ͷ������е����нڵ���ڴ�ռ�
	~LinkList() {
		Node<T>* current = head; // ��ͷ�ڵ㿪ʼ����
		while (current != nullptr) {
			Node<T>* next = current->next; // ������һ���ڵ��ָ��
			delete current; // ɾ����ǰ�ڵ�
			current = next; // �ƶ�����һ���ڵ�
		}
	}

	// �������ĩβ����һ���µĽڵ㣬��������������
	void append(T data) {
		Node<T>* newNode = new Node<T>(data); // ����һ���µĽڵ�
		if (head == nullptr) { // �������Ϊ�գ���ô�½ڵ����ͷ�ڵ��β�ڵ�
			head = newNode;
			tail = newNode;
		}
		else { // �������Ϊ�գ���ô�½ڵ����β�ڵ����һ���ڵ㣬������β�ڵ�
			tail->next = newNode;
			tail = newNode;
		}
		size++; // �����ȼ�һ
	}

	// �������ָ��λ�ò���һ���µĽڵ㣬��������������
	bool insert(int index, T data) {
		if (index < 0 || index > size) { // ���������Ч������false
			return false;
		}
		if (index == 0) { // �������Ϊ0����ô�½ڵ����ͷ�ڵ㣬������ͷ�ڵ�
			Node<T>* newNode = new Node<T>(data, head);
			head = newNode;
		}
		else if (index == size) { // ����������ڳ��ȣ���ô�½ڵ����β�ڵ㣬������β�ڵ�
			Node<T>* newNode = new Node<T>(data);
			tail->next = newNode;
			tail = newNode;
		}
		else { // ����������м䣬��ô�ҵ�ǰһ���ڵ�ͺ�һ���ڵ㣬�������½ڵ�
			Node<T>* prev = head; // ǰһ���ڵ�
			for (int i = 0; i < index - 1; i++) { // ������ǰһ���ڵ�
				prev = prev->next;
			}
			Node<T>* next = prev->next; // ��һ���ڵ�
			Node<T>* newNode = new Node<T>(data, next); // �����½ڵ㣬��ָ���һ���ڵ�
			prev->next = newNode; // ǰһ���ڵ�ָ���½ڵ�
		}
		size++; // �����ȼ�һ

		return true;
	}

	// ɾ��������ָ��λ�õĽڵ㣬�����ر�ɾ��������
	T remove(int index) {
		if (index < 0 || index >= size) { // ���������Ч�����ؿ�����
			return nullptr;
		}
		T data; // ��ɾ��������
		if (index == 0) { // �������Ϊ0����ôɾ��ͷ�ڵ㣬������ͷ�ڵ�
			Node<T>* temp = head; // ��ʱ����ͷ�ڵ�
			head = head->next; // ͷ�ڵ��ƶ�����һ���ڵ�
			data = temp->data; // ��ȡ��ɾ��������
			delete temp; // ɾ����ʱ�����ͷ�ڵ�
		}
		else { // ���������Ϊ0����ô�ҵ�ǰһ���ڵ�͵�ǰ�ڵ㣬��ɾ����ǰ�ڵ�
			Node<T>* prev = head; // ǰһ���ڵ�
			for (int i = 0; i < index - 1; i++) { // ������ǰһ���ڵ�
				prev = prev->next;
			}
			Node<T>* current = prev->next; // ��ǰҪɾ���Ľڵ�
			prev->next = current->next; // ǰһ���ڵ�ָ��ǰ�ڵ����һ���ڵ�
			data = current->data; // ��ȡ��ɾ��������
			delete current; // ɾ����ǰҪɾ���Ľڵ�

			if (index == size - 1) {
				//����������ڳ��ȼ�һ����ô����β���
				tail = prev; //β����ƶ���ǰһ�����
			}
		}
		size--; //�����ȼ�һ
		return data; //���ر�ɾ��������
	}

	//��ȡ������ָ��λ�õ�����
	T get(int index) {
		if (index < 0 || index >= size) {
			//���������Ч�����ؿ�����
			return nullptr;
		}
		Node<T>* current = head; //��ͷ��㿪ʼ����
		for (int i = 0; i < index; i++) {
			//������ָ��λ��
			current = current->next;
		}
		return current->data; //���ظ�λ�õ�����
	}

	//�޸�������ָ��λ�õ�����
	bool set(int index, T data) {
		if (index < 0 || index >= size) {
			//���������Ч������false
			throw std::out_of_range("Index out of range");
		}
		Node<T>* current = head; //��ͷ��㿪ʼ����

		for (int i = 0; i < index; i++) {
			//������ָ��λ��
			current = current->next;
		}
		current->data = data; //�޸ĸ�λ�õ�����
		return true;
	}

	//�ж������Ƿ�Ϊ��
	bool isEmpty() {
		return size == 0;
	}

	//��ȡ����ĳ���
	int getSize() {
		return size;
	}

	//��ӡ����������Ԫ��
	string print() {
		Node<T>* current = head; //��ͷ��㿪ʼ����
		string result = "";
		while (current != nullptr) {
			result += current->data + " ";//��ӵ�ǰԪ��
			current = current->next; //�ƶ�����һԪ��
		}
		std::cout << std::endl;
	}
};