#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

#include <iostream>

using namespace std;

class intSLLNode {
public:
	intSLLNode() {
		info = 0;
		next = nullptr;
	}

	intSLLNode(int el, intSLLNode* ptr = nullptr) {
		info = el; next = ptr;
	}

	int info;
	intSLLNode* next;
};

#pragma once
class intSLList {
public:
	intSLList() {
		head = tail = nullptr;
	}

	~intSLList();

	int isEmpty() {
		return head == nullptr;
	}

	void addToHead(int);
	void addToTail(int);

	// Delete the head and return its info
	int deleteFromHead();

	// Delete the tail and return its info
	int deleteFromTail();
	void deleteNode(int);
	bool isInList(int) const;

private:
	intSLLNode* head, * tail;
};

#endif

