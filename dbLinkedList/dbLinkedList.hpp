#include <string>
using std::string;

typedef string dataType;

class dbLinkedList
{
private:
  class node
  {
  private:
    node *next;
    node *prev;
    dataType data;

  public:
    //Constructor and Destructor
    node() : next(nullptr), prev(nullptr), data(NULL) {}
    ~node();

    //Manipulação de ponteiros
    void setNext(node *ptr);
    void setPrev(node *ptr);
    node *getNext() { return this->next; }
    node *getPrev() { return this->prev; }

    //Manipulação dos dados
    void setData(dataType data);
    dataType getData() { return this->data; }
  };

  class sentinel : node
  {
  };

  class boduNode : node
  {
  private:
    dataType data;
  };

  node *head, *tail;
  unsigned long int size;

public:
  //Constructor and Destructor
  dbLinkedList() : head(nullptr), tail(nullptr), size(0) {}
  ~dbLinkedList();

  //Insertions
  dataType add(dataType data);
};
