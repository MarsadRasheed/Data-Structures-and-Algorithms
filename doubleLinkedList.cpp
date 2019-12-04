#include <iostream>
using namespace std;

class node
{
public:
	node* next;
	node* previous;
	int data;
};

class DoubleLinkedList {
private:
	node* head;
	node* tail;
public:
	DoubleLinkedList() {
		head = NULL;
		tail = NULL;
	}

	void insertionAtHead(int num);
	void printList();
	void insertionAtTail(int num);
	void insertAT(int position, int num);
	int sizeOfList();
	int deletionAtHead();
	int deletionAtTail();
	int deleteAt(int position);
	int deleteBy(int num);
	void reverseList();
	void sortList();
	void insertSort(int num);

};
