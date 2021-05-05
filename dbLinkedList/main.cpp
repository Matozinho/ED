#include <iostream>
#include "dbLinkedList.cpp"

int main()
{
  dbLinkedList<int> *lista1;
  dbLinkedList<std::string> *lista2;
  lista1 = new dbLinkedList<int>();
  lista2 = new dbLinkedList<std::string>();

  lista1->add(1);
  lista1->add(2);
  lista1->add(3);
  lista1->print();
  std::cout << lista1->getAt(0) << std::endl;
  std::cout << lista1->getAt(1) << std::endl;
  std::cout << lista1->getAt(2) << std::endl;
  std::cout << lista1->getAt(3) << std::endl;

  lista2->unshift("Para");
  lista2->add("Corno");
  lista2->print();
  std::cout << lista2->getAt(0) << std::endl;
  std::cout << lista2->getAt(1) << std::endl;
  std::cout << lista2->getAt(2) << std::endl;

  delete lista1;
  delete lista2;

  return 0;
}