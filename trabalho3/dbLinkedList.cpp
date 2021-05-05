#include "dbLinkedList.hpp"
#include <iostream>

//=============Funções de Inserção=============//
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
T dbLinkedList<T>::unshift(T data)
{
  dNode<T> *aux = new dNode<T>;
  aux->setData(data);

  if (!isEmpty())
  {
    dNode<T> *cur = header->getFirst();
    aux->setNext(cur);
    cur->setPrev(aux);
    header->setFirst(aux);
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
T dbLinkedList<T>::addAt(T data, int position)
{
  dNode<T> *aux = new dNode<T>;
  int i = 0; //Contador para adicionar à posição
  aux->setData(data);

  if (position < header->getSize())
  {
    dNode<T> *cur = header->getFirst();
    while (i < position)
    {
      cur = cur->getNext();
      i++;
    }
    if (cur->getPrev())
      cur->getPrev()->setNext(aux);
    aux->setPrev(cur->getPrev());
    cur->setPrev(aux);
    aux->setNext(cur);

    if (!aux->getPrev())
      header->setFirst(aux);
  }
  else
    add(data);

  header->incrementSize();

  return data;
}

//=============Funções de Retirada=============//
template <typename T>
T dbLinkedList<T>::remove()
{
  T removedData;
  if (!isEmpty())
  {
    dNode<T> *cur = header->getLast();
    header->setLast(cur->getPrev());
    if (header->getLast())
      header->getLast()->setNext(nullptr);
    else
      header->setFirst(nullptr);

    header->decrementSize();
    std::cout << header->getSize() << "\n";

    delete cur;
  }

  return removedData;
}

template <typename T>
T dbLinkedList<T>::shift()
{
  T removedData;
  if (!isEmpty())
  {
    dNode<T> *aux = header->getFirst();
    removedData = aux->getData();

    header->setFirst(aux->getNext());
    delete aux;
    aux = header->getFirst();
    if (aux)
      aux->setPrev(nullptr);

    header->decrementSize();
    std::cout << header->getSize() << "\n";
  }

  return removedData;
}

template <typename T>
T dbLinkedList<T>::removeAt(int index)
{
  T removedData;
  dNode<T> *cur = header->getFirst();
  int i = 0;

  if (!isEmpty() && (index < header->getSize()))
  {
    while (i < index)
    {
      cur = cur->getNext();
      i++;
    }

    if (cur->getPrev())
      cur->getPrev()->setNext(cur->getNext());
    else
      header->setFirst(cur->getNext());
    if (cur->getNext())
      cur->getNext()->setPrev(cur->getPrev());
    else
      header->setLast(cur->getPrev());

    removedData = cur->getData();

    header->decrementSize();

    delete cur;
  }

  return removedData;
}

template <typename T>
T dbLinkedList<T>::removeSpecific(T data)
{
  if (!isEmpty())
  {
    dNode<T> *cur = header->getFirst();
    int index = 0;

    do
    {
      if (cur->getData() == data)
        return removeAt(index);
      cur = cur->getNext();
      index++;
    } while (cur);
  }

  return data;
}
//=============Funções de Retorno=============//
template <typename T>
T dbLinkedList<T>::getAt(int index)
{
  T data;

  if (index < header->getSize())
  {
    dNode<T> *cur = header->getFirst();
    int i = 0;

    while (i < index)
    {
      cur = cur->getNext();
      i++;
    }

    data = cur->getData();
  }

  return data;
}

template <typename T>
void dbLinkedList<T>::print()
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

//=============Destrutor=============//
template <typename T>
dbLinkedList<T>::~dbLinkedList()
{
  dNode<T> *aux;

  aux = header->getFirst();

  while (aux)
  {
    aux = header->getFirst()->getNext();
    std::cout << header->getFirst()->getData() << std::endl;
    delete header->getFirst();
    header->setFirst(aux);
  }

  delete header;
}

//=============Templates=============//
template class dbLinkedList<int>;
template class dbLinkedList<std::string>;