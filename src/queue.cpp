/*
 * queue.cpp
 *
 *  Created on: 30 jun 2015
 *      Author: Kristoffer
 */

#include "queue.h"

class Node
{
public:
    Node *next;
    Item data;
    Node (Node *n, Item newData) : next(n), data(newData) {}
};

QIterator::QIterator(){
	node = nullptr;
}

QIterator::QIterator(Node* n){
	node = n;
}

Item &QIterator::operator*() const{
	return node->data;
}

QIterator &QIterator::operator++(){
	node = node->next;
	return *this;
}

QIterator QIterator::operator++(int){
	QIterator tmp = *this;
	node = node->next;
	return tmp;
}

bool QIterator::operator!=(const QIterator &qi) const{
	if(this->node == qi.node){
		return false;
	}
	return true;
}

Node* QIterator::getNode(){
	return node;
}

Node* QIterator::getNext(){
	return node->next;
}

QList::~QList(){
	while(!isEmpty())
	{
		Node *tmp = first;
		first = first->next;
		delete tmp;
	}
}

void QList::enque(Item item){
	Node* tmp = new Node(nullptr, item);
	if(isEmpty()){
		first = tmp;
	}
	else{
		last->next = tmp;
	}
	last = tmp;
}

bool QList::deque(Item &item){
	if(!isEmpty()){
		Node* tmp = first;
		item = tmp->data;
		first = first->next;
		if(isEmpty()){
			first = nullptr;
			last = nullptr;
		}
		delete tmp;
		return true;
	}
	else{
		return false;
	}
}

bool QList::del(Item item){
	cout << "test1" << endl;
	Node* tmp = nullptr;
	for(auto it=begin(); it!=end(); it++){
		if(*it == item){

		}
		else{
			tmp = it.getNode();
		}
		cout << "test2" << endl;
		if(it.getNext()->data == item){
			cout << "test3" << endl;
			Node* tmp = it.getNext()->next;
			delete it.getNext();
			it.getNode()->next = tmp;
			return true;
		}
	}
	return false;
}

bool QList::isEmpty()const{
	return (first == nullptr && last == nullptr);
}

