#include "AVLTree.hpp"
#include <iostream>
#include <queue>

template <typename T>
AVLTree<T> *AVLTree<T>::leftRotate()
{
  AVLTree<T> *aux = new AVLTree<T>(this->data);
  this->data = this->right->data;
  this->left = aux;

  if (this->right->left)
  {
    aux->right = this->right->left;
    this->right->left = nullptr;
  }

  this->right = this->right->right;
  return this;
}

template <typename T>
AVLTree<T> *AVLTree<T>::insert(T data)
{
  if (!this)
    return new AVLTree(data);

  if (data > this->data)
    this->right = this->right->insert(data);
  else
    this->left = this->left->insert(data);

  int difference = this->left->height() - this->right->height();
  /* std::cout << "Diferença: " << difference << std::endl; */

  if (difference < -1)
    this->leftRotate();

  return this;
}

template <typename T>
void AVLTree<T>::posOrder()
{
  if (this->left)
    this->left->posOrder();

  if (this->right)
    this->right->posOrder();

  std::cout << this->data << std::endl;
  return;
}

template <typename T>
void AVLTree<T>::preOrder()
{
  std::cout << this->data << std::endl;

  if (this->left)
    this->left->preOrder();

  if (this->right)
    this->right->preOrder();

  return;
}

template <typename T>
void AVLTree<T>::inLevel()
{
  std::queue<AVLTree<T> *> fila;
  AVLTree<T> *popped;

  fila.push(this);
  while (fila.size())
  {
    popped = fila.front();
    fila.pop();

    std::cout << popped->data << " ";

    if (popped->left)
      fila.push(popped->left);
    if (popped->right)
      fila.push(popped->right);
  }

  std::cout << std::endl;
}

template <typename T>
void AVLTree<T>::inOrder()
{
  if (this->left)
    this->left->inOrder();

  std::cout << this->data << std::endl;

  if (this->right)
    this->right->inOrder();

  return;
}

template <typename T>
T AVLTree<T>::greater()
{
  T data;

  if (this->right)
    data = this->right->greater();

  else
    return this->data;

  return data;
}

template <typename T>
T AVLTree<T>::smaller()
{
  T data;

  if (this->left)
    data = this->left->smaller();

  else
    return this->data;

  return data;
}

template <typename T>
int AVLTree<T>::height()
{
  if (!this)
    return 0;
  else
  {
    int heightLeft = this->left->height();
    int heightRight = this->right->height();

    if (heightLeft < heightRight)
      return (heightRight + 1);
    else
      return (heightLeft + 1);
  }
}

template <typename T>
AVLTree<T> *AVLTree<T>::find(T value)
{
  if (!this || this->data == value)
    return this;

  if (value > this->data)
    return this->right->find(value);
  else
    return this->left->find(value);
}

template <typename T>
AVLTree<T> *AVLTree<T>::remove(T value)
{
  if (!this)
  {
    std::cout << "value not found" << std::endl;
    return nullptr;
  }

  if (value < this->data)
    this->left = this->left->remove(value);

  if (value > this->data)
    this->right = this->right->remove(value);

  else
  {
    AVLTree<T> *aux;

    if (!this->left)
    {
      aux = this->right;
      delete this;
      return aux;
    }

    if (!this->right)
    {
      aux = this->left;
      delete this;
      return aux;
    }

    int removed;
    removed = this->right->smaller();
    this->remove(removed);
    this->data = removed;
  }
  return this;
}

template class AVLTree<int>;
template class AVLTree<float>;
template class AVLTree<char>;
