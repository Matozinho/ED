#include <iostream>
#include "BSTree.h"

using namespace std;

int main()
{
  BSTree<int> arvore;

  arvore.insert(50);
  arvore.insert(100);
  arvore.insert(30);
  arvore.insert(20);
  arvore.insert(40);
  arvore.insert(35);
  arvore.insert(37);
  arvore.insert(45);

  return 0;
}