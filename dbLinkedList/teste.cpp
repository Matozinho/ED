#include "teste.hpp"
#include <iostream>

template <typename T>
bool dbLinkedList<T>::isEmpity()
{
  unsigned long int aux;
  aux = sentinela->getSize();
  if (aux)
    return true;
  else
    return false;
}

template <typename T>
T dbLinkedList<T>::add(T data)
{
  dNode<T> *aux;
  aux = new dNode<T>;
  aux->setData(data);

  if (!isEmpity())
  {
    dNode<T> *cur;
    cur = sentinela->getNext();
    aux->setPrev(cur);
    cur->setNext(aux);
    sentinela->setNext(aux);
  }
  else
  {
    sentinela->setPrev(aux);
    sentinela->setNext(aux);
  }

  sentinela->incrementSize();

  return data;
}

// All types allowed
template class dNode<char>;
template class dNode<int>;
template class dNode<short>;
template class dNode<float>;
template class dNode<double>;
template class dNode<std::string>;