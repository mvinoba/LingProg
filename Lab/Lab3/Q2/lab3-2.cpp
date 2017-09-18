#include <iostream>
#include <string>
#include "lab3-2.h"


string Agenda::checkName(string name) { // slice name to limit 10 chars
  if (name.length() > 10) {
    name = name.substr(0,10);
    cout << "Nome maior que 10 caracteres, foi truncado!\n";
  }
  return name;
}

void Agenda::appendName(string name, int i) { // append name to vector
  name = checkName(name);
  arrayNames[i] = name;
}

void Agenda::showNames () { // show all vector elements
  for (int i = 0; i < numMax; i++) {
    cout << i << ". " << arrayNames[i] << endl;
  }
}   

// Main Function

int main(){
  Agenda myAgenda;
  string name;
  
  cout <<  "Entre com " << myAgenda.numMax << " nomes:\n";
  for (int i = 0; i < myAgenda.numMax; i++) {
    cout << "Nome " << i << ": ";
    getline(cin, name);
    myAgenda.appendName(name, i);
  }
  
  myAgenda.showNames();
  
  return 0;
}