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
/*
// All types allowed
template class dNode<char>;
template class dNode<int>;
template class dNode<short>;
template class dNode<float>;
template class dNode<double>;
template class dNode<std::string>;*/