#include <iostream>
#include "time.h"

using namespace std;

Time::Time(unsigned int hour = 0, unsigned int minute = 0, unsigned int second = 0)
{
  this->hour = hour;
  this->minute = minute;
  this->second = second;
}

Time::~Time()
{
  this->hour = 0;
  this->minute = 0;
  this->second = 0;
}

// Getters
unsigned Time::getHour() const
{
  return this->hour;
}
unsigned Time::getMinute() const
{
  return this->minute;
}
unsigned Time::getSecond() const
{
  return this->second;
}

// Setters
void Time::setHour(unsigned hour)
{
  this->hour = hour;
}
void Time::setMinute(unsigned minute)
{
  this->minute = minute;
}
void Time::setSecond(unsigned second)
{
  this->second = second;
}

void Time::print() const
{
  cout << hour << ":" << minute << ":" << second << endl;
}

void Time::nextSecond()
{
  this->second += 1;
  if (this->second >= 60)
  {
    this->second = 0;
    this->minute += 1;
  }
  if (this->minute >= 60)
  {
    this->minute = 0;
    this->hour += 1;
  }
  if (this->hour >= 24)
  {
    this->hour = 0;
  }
}