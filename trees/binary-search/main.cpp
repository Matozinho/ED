#include <iostream>
#include "BSTree.cpp"

using namespace std;

int main()
{
  BSTree<int> *tree = new BSTree<int>(8);

  tree->insert(tree, 12);
  tree->insert(tree, 2);
  tree->insert(tree, 1);
  tree->insert(tree, -10);
  tree->insert(tree, 15);
  tree->insert(tree, 10);
  tree->insert(tree, 195);

  /*   
  tree->posOrder(tree);
  tree->preOrder(tree);
  cout << "extremes\n";
  cout << tree->greater(tree) << endl;
  cout << tree->smaller(tree) << endl;
  cout << tree->height(tree) << endl;
  cout << tree->find(tree, -10) << endl;
  cout << tree->find(tree, 195) << endl;
  cout << tree->find(tree, 11) << endl;
 */
  tree->inOrder(tree);
  tree->remove(tree, 2);
  tree->inOrder(tree);

  delete tree;

  return 0;
}