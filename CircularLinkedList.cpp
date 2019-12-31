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


void CircularLinkedList::insert(int position, int num) {

	node* current;
	current = head;
	
	for (int i = 1; i < position - 2; i++) {
		current = current->next;
	}
	node* next;
	next = current->next;
	node* temp = new node;
	temp->data = num;
	temp->previous = current;
	temp->next = next;
	current->next = temp;
	next->previous = temp;
}

void CircularLinkedList::deletion(int num) {

	node* start;
	start = head;

	node* last;
	last = tail;

	if (num == start->data) {
		head = head->next;
		head->previous = tail;
		tail->next = head;
		delete start;
	}
	else if( num == tail->data ){
		tail = tail->previous;
		tail->next = head;
		delete last;
	}
	else{
		while ( start != last )	{
			if (start->data == num) {
				start->previous->next = start->next;
				start->next->previous = start->previous;
			}
			start = start->next;
		}

	}
}
