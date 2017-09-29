#include <iostream>
#include <string>
#include "lab3-3.h"

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


void Agenda::appendCad(Cadastro &cad, int i) { // append Cadastro to array

  arrayCads[i] = cad;
}

void Agenda::showCadastros () { // show all vector elements
  for (int i = 0; i < numMax; i++) {
    cout << "\nName: " << arrayCads[i].getName() << endl
         << "Age: " << arrayCads[i].getAge() << endl
         << "Job: " << arrayCads[i].getJob() << endl;
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

        myAgenda.appendCad(myCad, i);
    }

    myAgenda.showCadastros();

    return 0;
}
