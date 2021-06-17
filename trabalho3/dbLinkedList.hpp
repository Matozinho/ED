#include <iostream>
#include "dNode.hpp"

using namespace std;

template <typename T>
class dbLinkedList
{
private:
  class sentinel : dNode<T>
  {
  private:
    unsigned long int size;
    string routeName;

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

    //Manipulação routeName
    void setRoute(string routeName) { this->routeName = routeName; }
    string getRoute() { return this->routeName; }
  };
  sentinel *header;

public:
  dbLinkedList() : header(new sentinel()) {}
  ~dbLinkedList();

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

  //Funções de retorno
  T getAt(int index);
  int size() { return header->getSize(); }
  void print();

  //RouteData
  void setRouteName(string routeName) { header->setRoute(routeName); }
  string getRouteName() { return header->getRoute(); }
};
