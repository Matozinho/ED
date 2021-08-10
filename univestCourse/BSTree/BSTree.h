#ifndef BSTREE_H
#define BSTREE_H

template <typename T>
class BSTree
{
private:
  struct Node
  {
    T data;
    Node *left = nullptr, *right = nullptr;
  };

  Node *root;

  Node *insertNode(T value, Node *root);
  Node *findNode(T value, Node *currentNode);
  Node *removeNode(T value, Node *node);
  Node *smallerNode(Node *node);
  Node *deleteNodes(Node *node);

  void nodeInOrder(Node *root) const;
  void nodePreOrder(Node *root) const;
  void nodePosOrder(Node *root) const;

public:
  BSTree();
  BSTree(T value);

  void insert(T value)
  {
    if (!this->isFull())
      this->root = this->insertNode(value, this->root);
  }

  bool isFull() const;
  void inOrder() const { this->nodeInOrder(this->root); };
  void preOrder() const { this->nodePreOrder(this->root); };
  void posOrder() const { this->nodePosOrder(this->root); };

  Node *getRoot() { return this->root; };

  T greater();
  T smaller();

  Node *find(T value);
  void remove(T value);

  ~BSTree();
};

template class BSTree<char>;
template class BSTree<int>;
template class BSTree<float>;

#endif