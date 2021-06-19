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
  BSTree *insert(BSTree *root, T data);
  void inOrder(BSTree *root);
  void inLevel(BSTree *root);
  void preOrder(BSTree<T> *root);
  void posOrder(BSTree<T> *root);

  T greater(BSTree<T> *root);
  T smaller(BSTree<T> *root);

  int height(BSTree<T> *root);
  BSTree *find(BSTree<T> *root, T value);
  BSTree *remove(BSTree<T> *root, T value);
};

template <typename T>
BSTree<T>::~BSTree()
{
  std::cout << "Vai apagar essa pohha" << std::endl;
}
