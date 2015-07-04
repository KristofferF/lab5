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

Node* QIterator::getNode() const{
	return node;
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
	Node* tmp = nullptr;
	for(auto it=begin(); it!=end(); it++){
		if(*it == item){
		    if(tmp != nullptr){
		        tmp->next = it.getNode()->next;
		    }
		    else{
		        first = it.getNode()->next;
		    }
		    delete it.getNode();
		}
		else{
			tmp = it.getNode();
		}
	}
	return false;
}

bool QList::isEmpty()const{
	return (first == nullptr);
}

