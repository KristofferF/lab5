/*
 * queue.cpp
 *
 *  Created on: 30 jun 2015
 *      Author: Kristoffer
 */

class Node
{
public:
Node *next;
Item data;
Node (Node *n, Item newData) : next(n), data(newData) {}
};
// Fyll på med funktionsdefinitioner för medlemsfunktionerna i QIterator och // QList nedan!
