#include "BSTree.h"
#include <iostream>

using namespace std;

template <typename T>
BSTree<T>::BSTree()
{
  this->root = nullptr;
}

template <typename T>
BSTree<T>::BSTree(T value)
{
  this->root = new Node;
  this->root->data = value;
}

template <typename T>
typename BSTree<T>::Node *BSTree<T>::deleteNodes(Node *node)
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
BSTree<T>::~BSTree()
{
  deleteNodes(this->root);
  this->root = nullptr;
}

template <typename T>
typename BSTree<T>::Node *BSTree<T>::insertNode(T value, Node *root)
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

  return root;
}

template <typename T>
bool BSTree<T>::isFull() const
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
void BSTree<T>::nodeInOrder(Node *root) const
{
  if (root->left)
    nodeInOrder(root->left);

  cout << root->data << endl;

  if (root->right)
    nodeInOrder(root->right);
}

template <typename T>
void BSTree<T>::nodePreOrder(Node *root) const
{
  cout << root->data << endl;

  if (root->left)
    nodeInOrder(root->left);

  if (root->right)
    nodeInOrder(root->right);
}

template <typename T>
void BSTree<T>::nodePosOrder(Node *root) const
{
  if (root->left)
    nodeInOrder(root->left);

  if (root->right)
    nodeInOrder(root->right);

  cout << root->data << endl;
}

template <typename T>
T BSTree<T>::greater()
{
  Node *aux;

  aux = this->root;

  while (aux->right)
    aux = aux->right;

  return aux->data;
}

template <typename T>
T BSTree<T>::smaller()
{
  return this->smallerNode(this->root)->data;
}

template <typename T>
typename BSTree<T>::Node *BSTree<T>::findNode(T value, Node *currentNode)
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
typename BSTree<T>::Node *BSTree<T>::smallerNode(Node *node)
{
  if (!node->left)
    return node;

  else
    return this->smallerNode(node->left);
}

template <typename T>
typename BSTree<T>::Node *BSTree<T>::find(T value)
{
  return this->findNode(value, this->root);
}

template <typename T>
typename BSTree<T>::Node *BSTree<T>::removeNode(T value, Node *node)
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

    cout << "current Node: " << node->data << endl;

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
  }

  return node;
}

template <typename T>
void BSTree<T>::remove(T value)
{
  this->removeNode(value, this->root);
}