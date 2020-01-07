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

void LinkedList::deleteAtHead() {
	node* temp;
	temp = head;
	head = head->next;
	delete temp;
}

void LinkedList::deleteList(){

	node* temp;
	temp = head;

	while ( temp->next != NULL) {
		deleteAtTail();
	}
	deleteAtHead();
}


void LinkedList::print() {

	node* temp;
	temp = head;

	node* last;
	last = tail;

	if (head == NULL && tail == NULL) {
		cout << "\nyour List is empty\n";
	}
	else {
		while (temp != NULL) {
			cout << temp->data << "  ";
			temp = temp->next;
		}
	}
}

void LinkedList::insertAtTail(int num) {

	node* ptr;
	ptr = head;

	node* temp = new node;
	temp->data = num;
	temp->next = NULL;

	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	tail->next = temp;
	temp->next = NULL;
	tail = temp;
}

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


int main() {

	Queue queue;
	queue.enque(2);
	queue.enque(3);
	queue.enque(6);
	queue.deque();
	queue.print();
	queue.QueueDelete();
	system("pause");
	
}
