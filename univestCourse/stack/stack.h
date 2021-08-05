#ifndef STACK_H
#define STACK_H

template <typename T>
struct Node
{
  T info;
  Node *next = nullptr;
};

template <typename T>
class Stack
{
private:
  Node<T> *top;

public:
  Stack();
  ~Stack();

  bool isEmpty() const;
  bool isFull() const;
  void print() const;

  void push(T item);
  T pop();
};

template class Stack<char>;
template class Stack<int>;
template class Stack<float>;

#endif