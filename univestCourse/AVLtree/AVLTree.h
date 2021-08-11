#ifndef AVLTREE_H
#define AVLTREE_H

template <typename T>
class AVLTree
{
private:
  struct Node
  {
    T data;
    int balancingFactor;
    Node *left = nullptr, *right = nullptr;
  };

  Node *root;

  Node *insertNode(T value, Node *root);
  Node *findNode(T value, Node *currentNode);
  Node *removeNode(T value, Node *node);
  Node *smallerNode(Node *node);
  Node *deleteNodes(Node *node);
  int nodeHeight(Node *node);
  void defineBalancingFactor(Node *node);

  Node *performRotations(Node *node);
  Node *leftRotate(Node *node);
  Node *rightRotate(Node *node);
  Node *doubleLeftRotate(Node *node);
  Node *doubleRightRotate(Node *node);

  void nodeInOrder(Node *root) const;
  void nodePreOrder(Node *root) const;
  void nodePosOrder(Node *root) const;

  void graphicNodePrint(Node *node, int depth, char *path, int direita, int space) const;

public:
  AVLTree();
  AVLTree(T value);

  void insert(T value)
  {
    if (!this->isFull())
      this->root = this->insertNode(value, this->root);
  }

  bool isFull() const;
  void inOrder() const { this->nodeInOrder(this->root); };
  void preOrder() const { this->nodePreOrder(this->root); };
  void posOrder() const { this->nodePosOrder(this->root); };
  void graphicPrint() const;

  Node *getRoot() { return this->root; };

  T greater();
  T smaller();

  Node *find(T value);
  void remove(T value);

  ~AVLTree();
};

template class AVLTree<char>;
template class AVLTree<int>;
template class AVLTree<float>;

#endif
