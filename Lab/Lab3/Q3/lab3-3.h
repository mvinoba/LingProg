#include <iostream>
#include <string>

using namespace std;

class Cadastro {
public:
    string getName();
    string getJob();
    int getAge();
    void setName(string);
    void setJob(string);
    void setAge(int);
private:
    string name;
    string job;
    int age;
};

class Agenda {
  public:
    const static int numMax = 4;
    void appendCad(Cadastro &, int);
    void showCadastros();
  private:
    Cadastro arrayCads[numMax];
    string checkName(string);
};
