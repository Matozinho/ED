#include <string>

template <typename T>
class dNode
{
private:
  dNode<T> *next, *prev;
  T data;

public:
  dNode() : next(nullptr), prev(nullptr) {}
  ~dNode();

  //Manipulação de ponteiros
  void setNext(dNode<T> *ptr) { this->next = ptr; }
  void setPrev(dNode<T> *ptr) { this->prev = ptr; }
  dNode<T> *getNext() { return this->next; }
  dNode<T> *getPrev() { return this->prev; }

  //Manipulação de dados
  void setData(T inf) { this->data = inf; }
  T getData() { return this->data; }
};

template <typename T>
dNode<T>::~dNode()
{
  next = nullptr;
  prev = nullptr;
}