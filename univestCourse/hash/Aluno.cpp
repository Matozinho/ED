#include <iostream>

using namespace std;

class Aluno
{
private:
  int ra;
  string name;

public:
  Aluno() : ra(-1), name(""){};
  Aluno(int ra, string name) : ra(ra), name(name){};
  ~Aluno()
  {
    this->ra = -1;
    this->name = "";
  };

  //getters
  string getName() const { return this->name; };
  int getRa() const { return this->ra; };

  //setters
  void setName(string name) { this->name = name; };
  void setRa(int ra) { this->ra = ra; };
};