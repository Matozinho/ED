#include <iostream>

template <typename T>
class BSTree
{
private:
  T data;
  BSTree<T> *left, *right;

public:
  //construction | destruction functions
  BSTree() : left(nullptr), right(nullptr) {}
  BSTree(T data) : data(data), left(nullptr), right(nullptr) {}
  ~BSTree();

  //Manipulação de dados
  T getData() { return this->data; }
  /*void setData(T data) { this->data = data; } */

  //manipulação de ponteiros
  /*   BSTree *getLeft() { return this->left; }
  BSTree *getRight() { return this->right; } */

  //Algoritmos característiscos de árvore
  BSTree *insert(T data);
  void inOrder();
  void inLevel();
  void preOrder();
  void posOrder();

  T greater();
  T smaller();

  int height();
  BSTree *find(T value);
  BSTree *remove(T value);
};

template <typename T>
BSTree<T>::~BSTree()
{
  std::cout << "Vai apagar essa pohha" << std::endl;
}
