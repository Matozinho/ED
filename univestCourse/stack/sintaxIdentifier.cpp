#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
  char charIn, droppedChar;
  bool isMatched = true;
  Stack<char> stack;

  cout << "Adicione uma string:";
  cin.get(charIn);

  while (isMatched && charIn != '\n')
  {
    if (charIn == '[' || charIn == '(' || charIn == '{')
      stack.push(charIn);

    else if (charIn == ']' || charIn == ')' || charIn == '}')
    {
      if (stack.isEmpty())
        isMatched = false;
      else
      {
        droppedChar = stack.pop();
        isMatched = ((charIn == ']' && droppedChar == '[') ||
                     (charIn == ')' && droppedChar == '(') ||
                     (charIn == '}' && droppedChar == '{'));
      }
    }
    cin.get(charIn);
  }

  if (isMatched && stack.isEmpty())
    cout << "Expressão está correta" << endl;

  else
    cout << "Expressão não está correta" << endl;

  return 0;
}