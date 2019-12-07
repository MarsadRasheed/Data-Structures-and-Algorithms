#include <iostream>
using namespace std;

// node class

class node
{
public:
	node* next;
	node* previous;
	int data;
};

// double linked list class

class DoubleLinkedList {
private:
	node* head;
	node* tail;
public:
	// constructor for initializing values
	DoubleLinkedList() {
		head = NULL;
		tail = NULL;
	}
	
	// function prototypes for inserting 
	void insertionAtHead(int num);  	// insertion at head 
	void insertionAtTail(int num);		// insertion at tail
	void insertAT(int position, int num);	// insertion at particular
	void insertSort(int num);		// insertion on sorting based. node will be added in sorting order

	//function prototypes for deleting
	
	int deletionAtHead(); 		// deletion at head
	int deletionAtTail(); 		// deletion at tail
	int deleteAt(int position);	// delete at particular position
	int deleteBy(int num);		// delete by value 
	
	void reverseList(); 	// reverse list function prototype 
	void sortList();	// sort list function prototype
	void printList();       // print list function prototype
	int sizeOfList();       // size of list getter function

};

// function to insertion at head

void DoubleLinkedList::insertionAtHead(int num) {
	node* temp = new node;
	temp->data = num;
	temp->next = NULL;
	temp->previous = NULL;

	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	else {
		temp->next = head;
		head->previous = temp;
		temp->previous = NULL;
		head = temp;
	}
}

// function to print double linked list

void DoubleLinkedList::printList() {
	node* temp = head;
	if ( head == NULL){
		return;
	}else{
		while ( temp!= NULL){
			cout << temp->data << "   ";
			temp = temp->next;
		}
		cout << endl;
	}
}

// function for insertion at tail

void DoubleLinkedList::insertionAtTail(int num)
{
	node* temp = new node;
	temp->data = num;
	temp->next = NULL;
	temp->previous = NULL;

	if (head == NULL) {
		head = temp;
		tail = temp;
	}

	tail->next = temp;
	temp->previous = tail;
	temp->next = NULL;
	tail = temp;
}

// function to insert at any position

void DoubleLinkedList::insertAT(int position, int num)
{
	node* current= head;
	node* previous = head;

	node* temp = new node;
	temp->next = NULL;
	temp->previous = NULL;
	temp->data = num;
	
	for (int i = 0; i < position - 1; i++) {
		previous = current;
		current = current->next;
	}
	previous->next = temp;
	temp->next = current;
	current->previous = temp;
	temp->previous = previous;
}

