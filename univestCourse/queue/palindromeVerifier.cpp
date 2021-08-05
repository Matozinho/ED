#include "queue.h"
#include "../stack/stack.h"
#include <iostream>

using namespace std;

int main()
{
  Queue<char> queue;
  Stack<char> stack;
  char charIn, dequeuedChar, droppedChar;
  bool isPalindrome = true;

  cout << "Entre com a palavra: ";
  cin.get(charIn);

  while (charIn != '\n' && !queue.isFull())
  {
    queue.enqueue(charIn);
    stack.push(charIn);
    cin.get(charIn);
  }

  while (isPalindrome && !queue.isEmpty())
  {
    dequeuedChar = queue.dequeue();
    droppedChar = stack.pop();

    if (dequeuedChar != droppedChar)
      isPalindrome = false;
  }

  if (!isPalindrome)
    cout << "A palavra não é um palíndrome!\n";
  else
    cout << "A palavra é um palíndrome\n";

  return 0;
}