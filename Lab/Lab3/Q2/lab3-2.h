#include <string>

using namespace std;

class Agenda {
  public:
    const static int numMax = 4;
    void appendName(string, int);
    void showNames();
  private:
    string arrayNames[numMax];
    string checkName(string); 
};
