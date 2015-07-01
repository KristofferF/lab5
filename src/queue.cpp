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
	// ++
	return *this;
}

QIterator QIterator::operator++(int){
	return *this;
	// ++
}

bool QIterator::operator!=(const QIterator &qi) const{
	//return this == qi;
}

QList::~QList(){

}

void QList::enque(Item item){
	last = new Node(nullptr, item);
	if(first == nullptr){
		first = last;
	}
}

bool QList::deque(Item &item){
//	if(!isEmpty()){
//		item = first->data;
//		if(first == last){
//			last = nullptr;
//		}
//		delete first;
//		first = nullptr;
//	}
//	else{
//		return false;
//	}

}

bool QList::del(Item item){

}

bool QList::isEmpty()const{

}

// Fyll på med funktionsdefinitioner för medlemsfunktionerna i QIterator och // QList nedan!
