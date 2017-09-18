#include <iostream>
#include <string>
#include <vector>
#include "lab3.h"

Agenda::Agenda(int i = 4) { // Constructor
  numMax = i;
}

string Agenda::checkName(string name) { // slice name to limit 10 chars
  if (name.length() > 10) {
    name = name.substr(0,10);
    cout << "Nome maior que 10 caracteres, foi truncado!\n";
  }
  return name;
}

void Agenda::appendName(string name) { // append name to vector
  name = checkName(name);
  if (vec.size() > numMax) {
    cout << "Agenda cheia!\n";
  } else {
    vec.push_back(name);
  };  
}

void Agenda::showNames () { // show all vector elements
  for (int i = 0; i < vec.size (); i++) {
    cout << i << ". " << vec.at (i) << endl;
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
    myAgenda.appendName(name);
  }
  
  myAgenda.showNames();
  
  return 0;
}