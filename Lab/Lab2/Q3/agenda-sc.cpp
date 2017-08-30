#include "agenda-sc.h"
#include <string>

using namespace std;

void Agenda::setNames(){
    string name;
    for(int i = 0; i < 3; i++){
        cout << "Entre com um nome para a agenda: ";
        getline(cin, name);
        listNames[i] = verifyName(name);
    }
}

void Agenda::getNames(){
    for(int i = 0; i < 3; i++){
        cout << to_string(i) + " " + listNames[i] << "\n";
    }
}

string Agenda::verifyName(string name){
    if(name.length() > 10){
        cout << "Nome tem mais que 10 caracteres, será truncado\n";
        name = name.substr(0,10);
    }
    return name;
}
