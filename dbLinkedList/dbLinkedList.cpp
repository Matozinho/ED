#include "dbLinkedList.hpp"
#include <iostream>

void dbLinkedList::node::setNext(node *ptr)
{
  this->next = ptr;
}

void dbLinkedList::node::setPrev(node *ptr)
{
  this->prev = ptr;
}

void dbLinkedList::node::setData(dataType data)
{
  this->data = data;
}

dataType dbLinkedList::add(dataType data)
{
  node *aux = new node;
  aux->setData(data);

  //verifica se há elementos na lista
  if (size)
  {
    tail->setNext(aux);
    aux->setPrev(tail);
    tail = aux;
  }
  else
  {
    head = aux;
    tail = aux;
  }

  size++;
}
