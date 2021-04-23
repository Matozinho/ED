#include <iostream>
#include "../dNode/dNode.hpp"

template <typename T>
class dbLinkedList
{
private:
  class sentinel : dNode<T>
  {
  private:
    unsigned long int size;

  public:
    sentinel() : size(0) {}
    ~sentinel()
    {
      size = 0;
    };

    //manipulação de tamanho
    void incrementSize() { this->size++; }
    void decrementSize() { this->size--; }
    unsigned long int getSize() { return this->size; }

    //Manipulação de ponteiros
    void setFirst(dNode<T> *ptr) { this->setPrev(ptr); }
    void setLast(dNode<T> *ptr) { this->setNext(ptr); }
    dNode<T> *getFirst() { return this->getPrev(); }
    dNode<T> *getLast() { return this->getNext(); }
  };
  sentinel *header;

public:
  dbLinkedList() : header(new sentinel()) {}
  ~dbLinkedList();

  void test()
  {
    std::cout << header->getFirst();
    std::cout << header->getLast();
  }

  //Funções de controle
  bool isEmpty() { return (header->getSize() == 0); };

  //Inserções
  T add(T data);
  T addAt(T data, int position);
  T unshift(T data);

  //Retirada
  T remove();
  T shift();
  T removeAt(int index);
  T removeSpecific(T data);

  //printar a lista
  void print();
};
