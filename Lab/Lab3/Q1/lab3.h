#include <vector>
#include <string>

using namespace std;

class Agenda {
  public:
    Agenda(int i);
    int numMax;

    void appendName(string);
    void showNames();
  private:
    vector <string> vec;
    string checkName(string); 
};
