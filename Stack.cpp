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
 
int LinkedList::getTailData() {
	return tail->data;
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

void LinkedList::deleteAtTail() {
	node* temp;
	temp = head;

	node* current;
	current = head;

	while ( temp->next != NULL ){
		current = temp;
		temp = temp->next;
	}
	tail = current;
	current->next = NULL;
	delete temp;
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

int main() {

	Stack stack;
	stack.push(2);
	stack.push(3);
	stack.push(6);
	stack.pop();
	stack.printStack();
	int top = stack.top();
	system("pause");
	
}
