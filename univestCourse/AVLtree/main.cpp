#include <iostream>
#include "AVLTree.h"

using namespace std;

int main()
{
  AVLTree<int> arvore;

  arvore.insert(20);
  arvore.insert(10);
  arvore.insert(5);
  arvore.insert(4);
  arvore.insert(3);
  arvore.insert(2);

  arvore.graphicPrint();
  cout << endl;

  arvore.remove(2);

  arvore.graphicPrint();
  cout << endl;

  arvore.remove(3);

  arvore.graphicPrint();
  cout << endl;

  return 0;
}
