#include "BSTree.hpp"
#include <iostream>
#include <queue>

template <typename T>
BSTree<T> *BSTree<T>::insert(T data)
{
  if (!this)
    return new BSTree(data);

  if (data > this->data)
    this->right = this->right->insert(data);
  else
    this->left = this->left->insert(data);

  return this;
}

template <typename T>
void BSTree<T>::posOrder()
{
  if (this->left)
    this->left->posOrder();

  if (this->right)
    this->right->posOrder();

  std::cout << this->data << std::endl;
  return;
}

template <typename T>
void BSTree<T>::preOrder()
{
  std::cout << this->data << std::endl;

  if (this->left)
    this->left->preOrder();

  if (this->right)
    this->right->preOrder();

  return;
}

template <typename T>
void BSTree<T>::inLevel()
{
  std::queue<BSTree<T> *> fila;
  BSTree<T> *popped;

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
void BSTree<T>::inOrder()
{
  if (this->left)
    this->left->inOrder();

  std::cout << this->data << std::endl;

  if (this->right)
    this->right->inOrder();

  return;
}

template <typename T>
T BSTree<T>::greater()
{
  T data;

  if (this->right)
    data = this->right->greater();

  else
    return this->data;

  return data;
}

template <typename T>
T BSTree<T>::smaller()
{
  T data;

  if (this->left)
    data = this->left->smaller();

  else
    return this->data;

  return data;
}

template <typename T>
int BSTree<T>::height()
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
BSTree<T> *BSTree<T>::find(T value)
{
  if (!this || this->data == value)
    return this;

  if (value > this->data)
    return this->right->find(value);
  else
    return this->left->find(value);
}

template <typename T>
BSTree<T> *BSTree<T>::remove(T value)
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
    BSTree<T> *aux;

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

template class BSTree<int>;
template class BSTree<float>;
template class BSTree<char>;
