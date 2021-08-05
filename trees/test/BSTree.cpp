#include "BSTree.hpp"

void BSTree::insert(int data)
{
  if (!this)
    this->root = new node(data);
}