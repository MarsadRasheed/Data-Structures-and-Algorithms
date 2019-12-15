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

// function to get size of the array

int DoubleLinkedList::sizeOfList(){
	node* temp = head;
	int count = 0;
	while (temp != NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

// function to delete element from head

int DoubleLinkedList::deletionAtHead()
{
	int deleted = head->data;
	head = head->next;
	head->previous = NULL;
	return deleted;;
}

// function to delete element from tail

int DoubleLinkedList::deletionAtTail()
{
	int deleted = tail->data;

	node* current = head;
	node* previous = head;

	while (current->next != NULL){
		previous = current;
		current = current->next;
	}
	current->next = NULL;
	current->previous = NULL;
	previous->next = NULL;
	delete current;
	tail = previous;
	return deleted;
}

// deletion by position

int DoubleLinkedList::deleteAt(int position)
{
	node* current = head;
	node* previous = head;

	for (int i = 0; i < position - 1; i++) {
		previous = current;
		current = current->next;
	}
	int deleted = current->data;
	previous->next = current->next;
	current->next->previous = previous;
	delete current;
	return deleted;
}

// deletion by value

int DoubleLinkedList::deleteBy(int num)
{
	node* temp = head;
	int deleted = 0;
	while ( temp != NULL){
		if (temp->data == num) {
			deleted = temp->data;
			temp->previous->next = temp->next;
			temp->next->previous = temp->previous;
			delete temp;
			return deleted;
		}
		temp = temp->next;
	}
	return 0;
}

// function to reverse list

void DoubleLinkedList::reverseList()
{
	node* next = NULL;
	node* first = head;
	node* previous = NULL;
	node* current = head;

	while (current != NULL){
		next = current->next;
		current->next = previous;
		current->previous = next;
		previous = current;
		current = next;
	}
	head = previous;
	tail = first;
}

// function to sort list

void DoubleLinkedList::sortList()
{
	node* current = head->next;
	node* previous = head;
	
	while (current != NULL){
		previous = head;
		while (previous != NULL){
			if (previous->data > current->data) {
				int temp = previous->data;
				previous->data = current->data;
				current->data = temp;
			}
			else{
				previous = previous->next;
			}
		}
		current = current->next;
	}
}

