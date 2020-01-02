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


void CircularLinkedList::print() {

	node* first;
	first = head;

	node* end;
	end = tail;

	while ( first != end ){
		std::cout << first->data << "  ";
		first = first->next;
	}
	std::cout << first->data;
}

void CircularLinkedList::insertionAtHead(int num) {
	node* current;
	current = head;

	node* temp = new node;
	temp->data = num;
	temp->previous = tail;
	temp->next = current;
	current->previous = temp;
	head = temp;
}



void CircularLinkedList :: insertionAtTail(int num) {

	node* ptr;
	ptr = head;

	node* tptr;
	tptr = tail;

	node* temp = new node;
	temp->data = num;
	temp->next = head;
	temp->previous = tail;

	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	else {
		//temp->previous = tptr;
		//temp->next = head;
		tptr->next = temp;
		ptr->previous = temp;
		tail = temp;
	}
}

void CircularLinkedList::insertionAt(int position, int num) {

	node* current;
	current = head;

	node* last;
	last = tail;

	int i = 0;
	int count = 1;

	while (current->next != head)
	{
		count++;
		current = current->next;
	}

	if (position == 1) {
		insertionAtHead(num);
		return;
	}
	else if (position < count + 2) {
			if (position < count) {
				// code for insertion at particular position.
				for (i = 0; i < position-1; i++) {
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
		else{
			insertionAtTail(num);
		}	
	}
	else
	{
		cout<<"\n" << num << " cannot added at position " << position << endl;
		cout <<"coz your list length is " << count << "\n\n";
	}
}

void CircularLinkedList::search(int num) {
	node* first;
	first = head;

	node* end;
	end = tail;

	int index = 1;
	int i = lenghtof();

	if (num == end->data) {
		print();
		cout <<"\n"<< num << " is found at tail "  << i << endl;
		return;
	}

	while (first->next != head) {
		if (first->data == num) {
			cout << num << " is found at " << index << endl;
			return;
		}
		index++;
		first = first->next;
	}
	cout << num << " number is not found at any index." << endl;
}

int main() {

	CircularLinkedList cl;

	cl.insertionAtHead(1);
	cl.insertionAtHead(2);
	//cl.insertionAtHead(3);
	//cl.insertionAtHead(4);
	cl.print();
	cout << '\n';
	system("pause");
}
