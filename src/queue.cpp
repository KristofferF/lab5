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

}

QIterator::QIterator(Node* n){

}

Item &QIterator::operator*() const{

}

QIterator &QIterator::operator++(){

}

QIterator QIterator::operator++(int){

}

bool QIterator::operator!=(const QIterator &qi) const{

}

QList::~QList(){

}
void QList::enque(Item item){

}
bool QList::deque(Item &item){

}
bool QList::del(Item item){

}
bool QList::isEmpty()const{

}

// Fyll på med funktionsdefinitioner för medlemsfunktionerna i QIterator och // QList nedan!
