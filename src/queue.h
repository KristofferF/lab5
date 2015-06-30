/*
 * queue.h
 *
 *  Created on: 29 jun 2015
 *      Author: Kristoffer
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "person.h"

typedef Person Item;
class Node;
class QIterator
{
private:
    Node *node;
public:
    QIterator(); // Förvald konstruktor
    QIterator(Node *n); // Initieringskonstruktor
    Item &operator*() const;
    QIterator &operator++(); // prefix ++i
    QIterator operator++(int); // postfix i++
    bool operator!=(const QIterator &qi) const;
}; //---------------------------------------------------------------------------

class QList
{
private:
   Node *first, *last;
public:
    QList():first(nullptr),last(nullptr){}; ~QList();
    void enque(Item item);
    bool deque(Item &item);
    bool del(Item item);
    bool isEmpty()const;
    QIterator begin()const {return QIterator(first);}
    QIterator end() const { return QIterator(nullptr);}
};

#endif /* QUEUE_H_ */
