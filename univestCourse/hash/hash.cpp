#include "hash.h"
#include <iostream>

using namespace std;

Hash::Hash(int maxItems = 100)
{
  this->maxItems = maxItems;
  this->length = 0;
  structure = new Aluno[maxItems];
}

Hash::~Hash()
{
  delete[] structure;
}

void Hash::get(Aluno &aluno, bool &found)
{
  int location = getHash(aluno);
  Aluno aux = this->structure[location];

  if (aluno.getRa() != aux.getRa())
    found = false;
  else
  {
    found = true;
    aluno = aux;
  }
}

void Hash::insert(Aluno aluno)
{
  int location = this->getHash(aluno);
  this->structure[location] = aluno;
  this->length++;
}

void Hash::remove(Aluno aluno)
{
  int location = this->getHash(aluno);
  structure[location] = Aluno();
  length--;
}

void Hash::print()
{
  for (int i = 0; i < this->maxItems; i++)
  {
    cout << i << ":" << structure[i].getRa() << ", "
         << structure[i].getName() << endl;
  }
}

int Hash::getHash(Aluno aluno)
{
  return aluno.getRa() % this->maxItems;
}