#include <string>
#include <iostream>
#include "lab4-1.h"

MeuNome::MeuNome(string str1): nome(str1) {};

string MeuNome::getNome() {
    cout << "non-const object!\n";
    return nome;
}

string MeuNome::getNome() const {   // Sobrecarrega metodo pra obj const
    cout << "const object!\n";
    return nome;
}

int main() {
    MeuNome objName("vinicius");
    MeuNome const objConstName("aguiar");
    cout << objName.getNome() << endl;
    cout << objConstName.getNome() << endl;

    return 0;
}
