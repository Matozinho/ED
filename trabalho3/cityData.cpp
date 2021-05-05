#include <string>
#include <ostream>

using namespace std;

class cityData
{
private:
  string city;
  string description;

public:
  cityData() : city(""), description("") {}
  ~cityData();

  string getCity() { return this->city; }
  string getDescription() { return this->description; }
  void setCity(string city) { this->city = city; }
  void setDescription(string description) { this->description = description; }
  friend ostream &operator<<(ostream &os, const cityData &F);
};

ostream &operator<<(ostream &os, const cityData &F)
{
  os << "Cidade: " << F.city << " ~ Decrição: " << F.description;
  return (os);
}

cityData::~cityData()
{
  this->city = "";
  this->description = "";
}
