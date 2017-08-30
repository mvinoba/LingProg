#include <iostream>
#include <string>

using namespace std;

class Agenda{
public:
    void setNames();
    void getNames();
private:
    string listNames[3];
    string verifyName(string);
};
