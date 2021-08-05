#include "queue.h"
#include <iostream>

using namespace std;

template <typename T>
Queue<T>::Queue()
{
  this->head = nullptr;
  this->tail = nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
  Node *curNode;
  while (this->head != nullptr)
  {
    curNode = this->head;
    this->head = this->head->next;
    delete curNode;
  }
  this->tail = nullptr;
}

template <typename T>
bool Queue<T>::isEmpty() const
{
  return (this->head == nullptr);
}

template <typename T>
bool Queue<T>::isFull() const
{
  Node *aux;

  try
  {
    aux = new Node;
    delete aux;
    return false;
  }
  catch (bad_alloc exception)
  {
    return true;
  }
}

template <typename T>
void Queue<T>::print() const
{
  if (!isEmpty())
  {
    Node *curNode = this->head;

    cout << "head -> ";
    while (curNode != nullptr)
    {
      cout << curNode->info << ' ';
      curNode = curNode->next;
    }
    cout << "<- tail\n";
  }
  else
  {
    throw "Queue is Empty";
  }
}

template <typename T>
void Queue<T>::enqueue(T item)
{
  if (!this->isFull())
  {
    Node *newNode = new Node;
    newNode->info = item;

    if (this->tail == nullptr)
      this->head = newNode;
    else
      this->tail->next = newNode;

    this->tail = newNode;
  }
  else
  {
    throw "Queue is already full";
  }
}

template <typename T>
T Queue<T>::dequeue()
{
  if (!this->isEmpty())
  {
    Node *aux = this->head;
    T info = this->head->info;

    this->head = this->head->next;

    if (this->head == nullptr)
      this->tail = nullptr;

    delete aux;
    return info;
  }
  else
  {
    throw "Queue is already empty!";
  }
}