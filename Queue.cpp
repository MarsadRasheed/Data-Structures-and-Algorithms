#include <iostream>
using namespace std;

// node class

class node {
public:
	int data;		// node containing data
	node* next;		// node contaiing address of next node 
};

// LinkedList class

class LinkedList {
private:
	// declaration of node head,tail
	node* head;
	node* tail;
public:
	
	LinkedList() {
		//initilizing values
		head = NULL;
		tail = NULL;
	}
  
	void insertAtTail(int num);
	void deleteAtHead();
	void print();
  void deleteList();
  
 };


class Queue {
	LinkedList L;
public:
	void enque(int num);
	void deque();
	void print();
	void QueueDelete();
};

void Queue::enque(int num) {
	L.insertAtTail(num);
}

void Queue::deque() {
	L.deleteAtHead();
}

void Queue::print() {
	L.print();
}

void Queue::QueueDelete() {
	L.deleteList();
}
