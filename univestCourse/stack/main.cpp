#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
  char charIn, charDropped;
  Stack<char> stack;

  cout << "Adicione uma string:";
  cin.get(charIn);

  while (charIn != '\n')
  {
    stack.push(charIn);
    cin.get(charIn);
  }

  while (!stack.isEmpty())
  {
    charDropped = stack.pop();
    cout << charDropped;
  }
  cout << endl;

  return 0;
}
