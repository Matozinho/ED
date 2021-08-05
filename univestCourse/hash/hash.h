#ifndef HASH_H
#define HASH_H

#include "Aluno.cpp"

class Hash
{
private:
  Aluno *structure;
  int getHash(Aluno aluno);
  int maxItems, length;

public:
  Hash(int maxItems);
  ~Hash();

  bool isFull() const;
  int getLength() const;

  void get(Aluno &aluno, bool &found);
  void insert(Aluno aluno);
  void remove(Aluno aluno);
  void print();
};
#endif