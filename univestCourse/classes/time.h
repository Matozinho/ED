#ifndef TIME_H
#define TIME_H
class Time
{
private:
  unsigned int hour;
  unsigned int minute;
  unsigned int second;

public:
  Time(unsigned int hour, unsigned int minute, unsigned int second);
  // Getters
  unsigned int getHour() const;
  unsigned int getMinute() const;
  unsigned int getSecond() const;

  // Setters
  void setHour(unsigned int hour);
  void setMinute(unsigned int minute);
  void setSecond(unsigned int second);

  void print() const;
  void nextSecond();
  ~Time();
};
#endif