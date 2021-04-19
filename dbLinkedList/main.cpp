#include <iostream>
#include "dbLinkedList.hpp"

int main()
{
  dbLinkedList<int> *lista1;
  lista1 = new dbLinkedList<int>();

  //lista1->test();

  std::cout << "Esta vazio?\n";
  std::cout << lista1->isEmpty() << "\n";
  lista1->add(1);
  lista1->printList();
  lista1->add(2);
  lista1->printList();
  lista1->add(3);
  lista1->printList();
  lista1->add(4);
  lista1->printList();
  lista1->add(5);
  lista1->printList();

  delete lista1;

  return 0;
}