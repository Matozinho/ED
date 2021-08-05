#include <iostream>
#include "hash.h"

using namespace std;

int main()
{
  Hash alunosHash(10);
  int ras[7] = {12704, 31300, 1234, 49001, 52202, 65606, 91234};

  string names[7] = {"Pedro", "raul", "Paulo", "Carlos", "Lucas", "Maria", "Samanta"};

  for (int i = 0; i < 7; i++)
  {
    Aluno aluno = Aluno(ras[i], names[i]);
    alunosHash.insert(aluno);
  }

  alunosHash.print();

  return 0;
}