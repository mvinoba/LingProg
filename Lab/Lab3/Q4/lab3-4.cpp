#include <iostream>
#include <string>
#include <vector>
#include "lab3-4.h"

using namespace std;

string Cadastro::getName() {
    return name;
};

string Cadastro::getJob() {
    return job;
};

int Cadastro::getAge() {
    return age;
};

void Cadastro::setName(string n) {
    if (n.length() > 10) {
      n = n.substr(0,10);
      cout << "Nome maior que 10 caracteres, foi truncado!\n";
    }
    name = n;
};

void Cadastro::setAge(int a) {
    age = a;
};

void Cadastro::setJob(string j) {
    job = j;
};


void Agenda::appendCad(Cadastro &cad) { // append Cadastro to array
    if (vec.size() > numMax) {
        cout << "Agenda Cheia!\n";
    }
    else {
    vec.push_back(cad);
    };
}

void Agenda::showCadastros () { // show all vector elements
  for (int i = 0; i < numMax; i++) {
    cout << "\nName: " << vec.at(i).getName() << endl
         << "Age: " << vec.at(i).getAge() << endl
         << "Job: " << vec.at(i).getJob() << endl;
  }
}

// main Function
int main() {
    Agenda myAgenda;
    string name, job;
    int age;

    cout << "Entre com " << myAgenda.numMax << " nomes:\n";
    for (int i = 0; i < myAgenda.numMax; i++) {
        Cadastro myCad;

        cout << "Nome " << i << ": ";
        getline(cin, name);
        myCad.setName(name);

        cout << "Idade: ";
        cin >> age;
        cin.ignore();
        myCad.setAge(age);

        cout << "Profissão: ";
        getline(cin, job);
        myCad.setJob(job);

        myAgenda.appendCad(myCad);
    }

    myAgenda.showCadastros();

    return 0;
}
