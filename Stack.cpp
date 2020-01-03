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
	void deleteAtTail();
	void print();
	int getTailData();

 };
 
class Stack {
	node* head;
	LinkedList ll;
public:
	void push(int num);
	void pop();
	void printStack();
	void top();
	void deleteStack();
};

void Stack::push(int num) {
	ll.insertAtTail(num);
}

void Stack::pop() {
	ll.deleteAtTail();
}

void Stack::top(){
	cout << "\n" <<	ll.getTailData();
}

void Stack::printStack() {
	ll.print();
}
