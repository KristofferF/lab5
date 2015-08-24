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

//------------------------------------------------------------------------------
// F�rvald konstruktor (Default constructor)
//------------------------------------------------------------------------------
QIterator::QIterator(){
	node = nullptr;
}

//------------------------------------------------------------------------------
// Konstruktor f�r initiering av datamedlemmarna
//------------------------------------------------------------------------------
QIterator::QIterator(Node* n){
	node = n;
}

//------------------------------------------------------------------------------
// Överlagrad innehållsoperatorn
//------------------------------------------------------------------------------
Item &QIterator::operator*() const{
	return node->data;
}

//------------------------------------------------------------------------------
// Överlagrad tillväxtsoperator (prefix)
//------------------------------------------------------------------------------
QIterator &QIterator::operator++(){
	node = node->next;
	return *this;
}

//------------------------------------------------------------------------------
// Överlagrad tillväxtsoperator (postfix)
//------------------------------------------------------------------------------
QIterator QIterator::operator++(int){
	QIterator tmp = *this;
	node = node->next;
	return tmp;
}

//------------------------------------------------------------------------------
// Överlagrad olikhetsoperator
//------------------------------------------------------------------------------
bool QIterator::operator!=(const QIterator &qi) const{
	if(this->node == qi.node){
		return false;
	}
	return true;
}

//------------------------------------------------------------------------------
// Dekonstruktor
//------------------------------------------------------------------------------
QList::~QList(){
	while(!isEmpty())
	{
		Node *tmp = first;
		first = first->next;
		delete tmp;
	}
}

//------------------------------------------------------------------------------
// enque
// Lägger till en person sist i kön
//------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------
// deque
// Tar bort en person först i listan
//------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------
// del
// Tar bort en person i listan som motsvarar parametern item
//------------------------------------------------------------------------------
bool QList::del(Item item){
    Node* tmp;
    for(Node* n1 = first; n1 != nullptr; n1=n1->next){
        if(n1->data == item){
            if(n1 == first){
                first = n1->next;
            }
            else{
                tmp->next = n1->next;
                if (n1 == last){
                    last = tmp;
                }
            }
            delete n1;
            return true;
        } else{
            tmp = n1;
        }
    }
	return false;
}

//------------------------------------------------------------------------------
// isEmpty
// Returnerar true om kön är tom
//------------------------------------------------------------------------------
bool QList::isEmpty()const{
	return (first == nullptr);
}

