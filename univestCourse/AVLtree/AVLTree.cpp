#include "AVLTree.h"
#include <iostream>

using namespace std;

template <typename T>
AVLTree<T>::AVLTree()
{
  this->root = nullptr;
}

template <typename T>
AVLTree<T>::AVLTree(T value)
{
  this->root = new Node;
  this->root->data = value;
}

template <typename T>
typename AVLTree<T>::Node *AVLTree<T>::deleteNodes(Node *node)
{
  if (node->left)
    node->left = this->deleteNodes(node->left);

  if (node->right)
    node->right = this->deleteNodes(node->right);

  if (!node->left && !node->right)
    delete node;

  return nullptr;
}

template <typename T>
AVLTree<T>::~AVLTree()
{
  deleteNodes(this->root);
  this->root = nullptr;
}

template <typename T>
void AVLTree<T>::defineBalancingFactor(Node *node)
{
  node->balancingFactor = this->nodeHeight(node->right) - this->nodeHeight(node->left);
}

template <typename T>
typename AVLTree<T>::Node *AVLTree<T>::rightRotate(Node *node)
{
  Node *newRoot = node->left;

  node->left = newRoot->right;

  newRoot->right = node;

  this->defineBalancingFactor(newRoot);
  this->defineBalancingFactor(node);

  return newRoot;
}

template <typename T>
typename AVLTree<T>::Node *AVLTree<T>::leftRotate(Node *node)
{
  Node *newRoot = node->right;

  node->right = newRoot->left;

  newRoot->left = node;

  this->defineBalancingFactor(newRoot);
  this->defineBalancingFactor(node);

  return newRoot;
}

template <typename T>
typename AVLTree<T>::Node *AVLTree<T>::doubleLeftRotate(Node *node)
{
  node->right = this->rightRotate(node->right);
  node = this->leftRotate(node);

  return node;
}

template <typename T>
typename AVLTree<T>::Node *AVLTree<T>::doubleRightRotate(Node *node)
{
  node->left = this->leftRotate(node->left);
  node = this->rightRotate(node);

  return node;
}

template <typename T>
typename AVLTree<T>::Node *AVLTree<T>::performRotations(Node *node)
{
  this->defineBalancingFactor(node);

  if (node->balancingFactor < -1)
  {
    if (node->left->balancingFactor == 1)
      node = this->doubleRightRotate(node);
    else
      node = this->rightRotate(node);
  }

  else if (node->balancingFactor > 1)
  {
    if (node->right->balancingFactor == -1)
      node = this->doubleLeftRotate(node);
    else
      node = this->leftRotate(node);
  }

  return node;
}

template <typename T>
typename AVLTree<T>::Node *AVLTree<T>::insertNode(T value, Node *root)
{
  if (!root)
  {
    root = new Node;
    root->data = value;
  }

  if (root->data < value)
    root->right = this->insertNode(value, root->right);

  if (root->data > value)
    root->left = this->insertNode(value, root->left);

  root = this->performRotations(root);

  return root;
}

template <typename T>
bool AVLTree<T>::isFull() const
{
  Node *aux;

  try
  {
    aux = new Node;
    delete aux;
    return false;
  }
  catch (bad_alloc exception)
  {
    return true;
  }
}

template <typename T>
void AVLTree<T>::nodeInOrder(Node *root) const
{
  if (root->left)
    nodeInOrder(root->left);

  cout << root->data << endl;

  if (root->right)
    nodeInOrder(root->right);
}

template <typename T>
void AVLTree<T>::nodePreOrder(Node *root) const
{
  cout << root->data << endl;

  if (root->left)
    nodeInOrder(root->left);

  if (root->right)
    nodeInOrder(root->right);
}

template <typename T>
void AVLTree<T>::nodePosOrder(Node *root) const
{
  if (root->left)
    nodeInOrder(root->left);

  if (root->right)
    nodeInOrder(root->right);

  cout << root->data << endl;
}

template <typename T>
T AVLTree<T>::greater()
{
  Node *aux;

  aux = this->root;

  while (aux->right)
    aux = aux->right;

  return aux->data;
}

template <typename T>
T AVLTree<T>::smaller()
{
  return this->smallerNode(this->root)->data;
}

template <typename T>
typename AVLTree<T>::Node *AVLTree<T>::findNode(T value, Node *currentNode)
{
  if (currentNode->data < value && currentNode->right)
    return findNode(value, currentNode->right);

  if (currentNode->data > value && currentNode->left)
    return findNode(value, currentNode->left);

  if (currentNode->data == value)
    return currentNode;

  else
    return nullptr;
}

template <typename T>
typename AVLTree<T>::Node *AVLTree<T>::smallerNode(Node *node)
{
  if (!node->left)
    return node;

  else
    return this->smallerNode(node->left);
}

template <typename T>
typename AVLTree<T>::Node *AVLTree<T>::find(T value)
{
  return this->findNode(value, this->root);
}

template <typename T>
typename AVLTree<T>::Node *AVLTree<T>::removeNode(T value, Node *node)
{
  if (!node)
  {
    cout << "Valor não encontrado" << endl;
    return nullptr;
  }

  if (value < node->data)
    node->left = this->removeNode(value, node->left);

  if (value > node->data)
    node->right = this->removeNode(value, node->right);

  else if (node->data == value)
  {
    Node *aux;

    if (!node->left)
    {
      aux = node->right;
      delete node;

      return aux;
    }

    if (!node->right)
    {
      aux = node->left;
      delete node;

      return aux;
    }

    T removed = this->smallerNode(node->right)->data;
    this->removeNode(removed, node);
    node->data = removed;
  };

  node = this->performRotations(node);

  return node;
}

template <typename T>
void AVLTree<T>::remove(T value)
{
  this->root = this->removeNode(value, this->root);
}

template <typename T>
int AVLTree<T>::nodeHeight(Node *node)
{
  if (!node)
    return 0;

  else
  {
    int heightLeft = this->nodeHeight(node->left);
    int heightRight = this->nodeHeight(node->right);

    if (heightLeft < heightRight)
      return (heightRight + 1);
    else
      return (heightLeft + 1);
  }
}

template <typename T>
void AVLTree<T>::graphicNodePrint(Node *node, int depth, char *path, int direita, int space) const
{
  if (!node)
    return;

  depth++;

  this->graphicNodePrint(node->right, depth, path, 1, space);

  path[depth - 2] = 0;

  if (direita)
    path[depth - 2] = 1;

  if (node->left)
    path[depth - 1] = 1;

  // print root after spacing
  cout << endl;

  for (int i = 0; i < depth - 1; i++)
  {
    if (i == depth - 2)
      cout << "+";
    else if (path[i])
      cout << "|";
    else
      cout << " ";

    for (int j = 1; j < space; j++)
      if (i < depth - 2)
        cout << " ";
      else
        cout << "-";
  }

  cout << node->data << endl;

  // vertical espacors below
  for (int i = 0; i < depth; i++)
  {
    if (path[i])
      cout << "|";
    else
      cout << " ";

    for (int j = 1; j < space; j++)
      cout << " ";
  }

  this->graphicNodePrint(node->left, depth, path, 0, space);
}

template <typename T>
void AVLTree<T>::graphicPrint() const
{
  char path[255] = {};

  this->graphicNodePrint(this->root, 0, path, 0, 8);
  cout << endl;
}