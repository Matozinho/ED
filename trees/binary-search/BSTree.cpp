#include "BSTree.hpp"
#include <iostream>
#include <queue>

template <typename T>
BSTree<T> *BSTree<T>::insert(BSTree<T> *root, T data)
{
  if (!root)
    return new BSTree(data);

  if (data > root->data)
    root->right = insert(root->right, data);
  else
    root->left = insert(root->left, data);

  return root;
}

template <typename T>
void BSTree<T>::posOrder(BSTree<T> *root)
{
  if (root->left)
    posOrder(root->left);

  if (root->right)
    posOrder(root->right);

  std::cout << root->data << std::endl;
  return;
}

template <typename T>
void BSTree<T>::preOrder(BSTree<T> *root)
{
  std::cout << root->data << std::endl;

  if (root->left)
    preOrder(root->left);

  if (root->right)
    preOrder(root->right);

  return;
}

template <typename T>
void BSTree<T>::inOrder(BSTree<T> *root)
{
  if (root->left)
    inOrder(root->left);

  std::cout << root->data << std::endl;

  if (root->right)
    inOrder(root->right);

  return;
}

template <typename T>
void BSTree<T>::inLevel(BSTree<T> *root)
{
  std::queue<BSTree<T> *> fila;
  BSTree<T> *popped;

  fila.push(root);
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
T BSTree<T>::greater(BSTree<T> *root)
{
  T data;

  if (root->right)
    data = greater(root->right);

  else
    return root->data;

  return data;
}

template <typename T>
T BSTree<T>::smaller(BSTree<T> *root)
{
  T data;

  if (root->left)
    data = smaller(root->left);

  else
    return root->data;

  return data;
}

template <typename T>
int BSTree<T>::height(BSTree<T> *root)
{
  if (!root)
    return 0;
  else
  {
    int heightLeft = height(root->left);
    int heightRight = height(root->right);

    if (heightLeft < heightRight)
      return (heightRight + 1);
    else
      return (heightLeft + 1);
  }
}

template <typename T>
BSTree<T> *BSTree<T>::find(BSTree<T> *root, T value)
{
  if (!root || root->data == value)
    return root;

  if (value > root->data)
    return find(root->right, value);
  else
    return find(root->left, value);
}

template <typename T>
BSTree<T> *BSTree<T>::remove(BSTree<T> *root, T value)
{
  BSTree<T> *aux;

  if (!root)
    return root;

  if (value < root->data)
    root->left = remove(root->left, value);

  else if (value > root->data)
    root->right = remove(root->right, value);

  else
  {
    if (!root->left)
    {
      aux = root->right;
      delete root->right;
      return aux->right;
    }

    else if (!root->right)
    {
      aux = root->left;
      delete root->left;
      return aux->left;
    }

    else
    {
      T substitute = smaller(root->right);
      root->data = substitute;
      root->right = remove(root->right, substitute);
    }
  }

  return root;
}

template class BSTree<int>;
template class BSTree<float>;
template class BSTree<char>;
