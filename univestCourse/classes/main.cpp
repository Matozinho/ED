#include <iostream>
#include "time.h"

using namespace std;

int main()
{
  Time t1(23, 59, 59);

  t1.print();
  t1.setHour(12);
  t1.setMinute(30);
  t1.setSecond(15);

  t1.print();
  t1.nextSecond();
  t1.print();

  return 0;
}