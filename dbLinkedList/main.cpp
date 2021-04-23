#include <iostream>
#include "dbLinkedList.hpp"

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
  lista1->removeSpecific(1);
  lista1->print();
  lista1->removeSpecific(2);
  lista1->print();
  lista1->removeSpecific(3);
  lista1->print();
  /*
  lista2->unshift("Para");
  lista2->add("Corno");
  lista2->print();
  lista2->add("sem");
  lista2->print();
  lista2->add("Mae!");
  lista2->print();
  lista2->unshift("Seu");
  lista2->print();
  */

  delete lista1;
  delete lista2;

  return 0;
}