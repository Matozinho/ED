#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue
{
private:
  struct Node
  {
    T info;
    Node *next = nullptr;
  };

  Node *head;
  Node *tail;

public:
  Queue();
  ~Queue();

  bool isEmpty() const;
  bool isFull() const;
  void print() const;

  void enqueue(T item);
  T dequeue();
};

template class Queue<char>;
template class Queue<int>;
template class Queue<float>;

#endif