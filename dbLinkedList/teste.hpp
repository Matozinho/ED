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
    sentinel() : size(0){};
    ~sentinel();

    void incrementSize() { this->size++; }
    void decrementSize() { this->size--; }
    unsigned long int getSize() { return this->size; }
  };

  sentinel *sentinela;

public:
  dbLinkedList() : sentinela(new sentinel) {}
  ~dbLinkedList();

  //Validações
  bool isEmpity();

  //Inserções
  T add(T data);
};
