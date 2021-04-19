#include "dbLinkedList.hpp"
#include <iostream>

template <typename T>
T dbLinkedList<T>::add(T data)
{
  dNode<T> *aux = new dNode<T>;
  aux->setData(data);

  if (!isEmpty())
  {
    dNode<T> *cur = header->getLast();
    aux->setPrev(cur);
    cur->setNext(aux);
    header->setLast(aux);
  }

  else
  {
    header->setFirst(aux);
    header->setLast(aux);
  }

  header->incrementSize();

  return data;
}

template <typename T>
void dbLinkedList<T>::printList()
{
  dNode<T> *cur;

  cur = header->getFirst();

  std::cout << "Inicio ->| ";

  while (cur)
  {
    std::cout << cur->getData();
    //Caso tenha próximo, imprime o separador
    if (cur->getNext())
      std::cout << " | ";

    cur = cur->getNext();
  }

  std::cout << " |<- Fim\n";
}

template <typename T>
dbLinkedList<T>::~dbLinkedList()
{
  dNode<T> *aux;

  aux = header->getFirst();

  while (aux)
  {
    aux = header->getFirst()->getNext();
    delete header->getFirst();
    header->setFirst(aux);
  }

  header->setFirst(nullptr);
  header->setLast(nullptr);
}

template class dbLinkedList<int>;