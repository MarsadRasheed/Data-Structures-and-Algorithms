#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
	node* previous;
};

class CircularLinkedList {
private:
	node* head;
	node* tail;
public:
	CircularLinkedList() {
		head = NULL;
		tail = NULL;
	}

	void print();
	void insertionAtHead(int num);
	void insertionAt(int position, int num);
	void insertionAtTail(int num);
	void search(int num);
	void deletion(int num);
	void insert(int position, int num);
	int lenghtof();
};

int CircularLinkedList::lenghtof() {
	node* temp;
	temp = head;
	int counter = 0;
	while (temp->next != temp) {
		counter++;
		temp = temp->next;
	}
	return counter;
}
