#pragma once

struct Node {
	int value;
	Node* next;
	Node* prev;
	Node(int x);
};

class FrontMiddleBackQueue
{

private:	
	Node* head;
	Node* tail;
	Node* mid;
	int size;
	Node* createNode(int x);

public:
	FrontMiddleBackQueue();
	

	void pushFront(int value);

	void pushMiddle(int value);

	void pushBack(int value);

	int popFront();

	int popMiddle();

	int popBack();
};

