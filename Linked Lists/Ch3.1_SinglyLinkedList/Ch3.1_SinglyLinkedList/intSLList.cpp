#include <iostream>

#include "intSLList.h"

using namespace std;

intSLList::~intSLList() {
	for (intSLLNode* p; !isEmpty(); ) {
		p = head->next;
		delete head;
		head = p;
	}
}

void intSLList::addToHead(int el) {
	head = new intSLLNode(el, head);

	if (tail == nullptr) {
		tail = head;
	}
}

void intSLList::addToTail(int el) {

	// If the list is not empty
	if (tail != nullptr) {
		tail->next = new intSLLNode(el);
		tail = tail->next;
	}
	else {
		head = tail = new intSLLNode(el);
	}
}

int intSLList::deleteFromHead() {
	int el = head->info;
	intSLLNode* tmp = head;

	// If there is only one node in the list
	if (head == tail) {
		head = tail = nullptr;
	}
	else {
		head = head->next;
	}

	delete tmp;
	return el;
}

int intSLList::deleteFromTail() {
	int el = tail->info;

	// If there is only one node in the list
	if (head == tail) {
		delete head;
		head = tail = nullptr;
	}
	else {
		// If there is more than one node in the list, find the predecessor of the tail

		intSLLNode* tmp;

		for (tmp = head; tmp->next != tail; tmp = tmp->next);

		delete tail;

		// The predecessor of the tail becomes the tail
		tail = tmp;
		tail->next = nullptr;
	}

	return el;
}

void intSLList::deleteNode(int el) {

	// If the list is not empty
	if (head != nullptr) {

		// If there is only one node in the list
		if (head == tail && el == head->info) {
			delete head;
			head = tail = nullptr;
		}
		else if (el == head->info) {
			// If there is more than one node in the list

			intSLLNode* tmp = head;
			head = head->next;

			// The old head is deleted
			delete tmp;
		}
		else {
			// If there is more than one node in the list, and a nonhead node is deleted

			intSLLNode *pred, *tmp;

			for (pred = head, tmp = head->next; tmp != nullptr && !(tmp->info == el); pred = pred->next, tmp = tmp->next);

			if (tmp != nullptr) {
				pred->next = tmp->next;

				if (tmp == tail) {
					tail = pred;
				}

				delete tmp;
			}
		}
	}
}

bool intSLList::isInList(int el) const {
	intSLLNode* tmp;

	for (tmp = head; tmp != nullptr && !(tmp->info == el); tmp = tmp->next);

	return tmp != nullptr;
}
