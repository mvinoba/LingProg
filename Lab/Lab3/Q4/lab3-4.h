#include <string>
#include <vector>

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
    void appendCad(Cadastro &);
    void showCadastros();
  private:
    vector <Cadastro> vec;
    string checkName(string);
};
