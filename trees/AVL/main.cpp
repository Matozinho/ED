#include <iostream>
#include "AVLTree.cpp"

using namespace std;

int main()
{
  AVLTree<int> *tree = new AVLTree<int>(8);

  tree->insert(9);
  tree->insert(10);

  tree->inLevel();
  tree->inOrder();

  delete tree;

  return 0;
}