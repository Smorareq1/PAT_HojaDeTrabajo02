#include "Ejercicio04.h"

Node::Node(int x) { //Nodos
    value = x;
    next = prev = nullptr;
}

FrontMiddleBackQueue::FrontMiddleBackQueue() { //constructor
    head = tail = mid = nullptr;
    size = 0;
}


Node* FrontMiddleBackQueue::createNode(int x) {
    return new Node(x);
}

void FrontMiddleBackQueue::pushFront(int value) {

    Node* nodoAux = createNode(value);
    if (size == 0) {
        head = tail = mid = nodoAux;
    }
    else {
        nodoAux->next = head;
        head->prev = nodoAux;
        nodoAux->prev = nullptr;
        head = head->prev;
    }
    size++;
    if (size % 2 == 0) {
        mid = mid->prev;
    }
}

void FrontMiddleBackQueue::pushMiddle(int value) {

    Node* nodoAux = createNode(value);
    if (size == 0) {
        head = tail = mid = nodoAux;
    }
    else {
        if (size % 2 == 0) {
            nodoAux->next = mid->next;
            nodoAux->prev = mid;
            mid->next->prev = nodoAux;
            mid->next = nodoAux;
            mid = mid->next;
        }
        else {
            nodoAux->next = mid;
            nodoAux->prev = mid->prev;
            if (mid->prev) {
				mid->prev->next = nodoAux; 
            } 
            mid->prev = nodoAux;
            mid = mid->prev;
            if (size == 1) {
                head = mid;
            }
        }
    }
    size++;
}

void FrontMiddleBackQueue::pushBack(int value) {
    Node* nodoAux = createNode(value);
    if (size == 0) {
        head = tail = mid = nodoAux;
    }
    else {
        nodoAux->prev = tail;
        nodoAux->next = nullptr;
        tail->next = nodoAux;
        tail = tail->next;
    }
    size++;
    if (size % 2 != 0 && size != 1) mid = mid->next;
}

int FrontMiddleBackQueue::popFront() {
    if (size == 0) return -1;

    int ans = head->value;
    Node* toDel = head;
    if (size == 1) {
        head = mid = tail = nullptr;
    }
    else {
        head->next->prev = nullptr;
        head = head->next;
        if (size % 2 == 0) mid = mid->next;
    }
    delete toDel;
    size--;
    return ans;
}

int FrontMiddleBackQueue::popMiddle() {
    if (size == 0) return -1;

    int ans = mid->value;
    Node* toDel = mid;
    if (size == 1) {
        head = mid = tail = nullptr;
    }
    else {
        mid->next->prev = mid->prev;
        if (mid->prev) {
            mid->prev->next = mid->next;
        } 
        if (size % 2 != 0) {
            mid = mid->prev;
        } 
        else mid = mid->next;
        if (size == 2) {
            head = mid;
        } 
    }
    delete toDel;
    size--;
    return ans;
}

int FrontMiddleBackQueue::popBack() {
    if (size == 0) return -1;

    int ans = tail->value;
    Node* toDel = tail;
    if (size == 1) {
        head = mid = tail = nullptr;
    }
    else {
        tail->prev->next = nullptr;
        tail = tail->prev;
        if (size % 2 != 0) {
            mid = mid->prev;
        }
    }
    delete toDel;
    size--;
    return ans;
}
