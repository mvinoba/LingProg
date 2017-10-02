#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class MeuNome {
public:
    MeuNome(string);
    ~MeuNome();
    char * getNome();
    char * getNome() const;
private:
    char * nome;
};

MeuNome::MeuNome(string str1): nome((char *) malloc (str1.length()*sizeof(char))){
    for (unsigned int i = 0; i < str1.length(); i++) {
        nome[i] = str1[i];
    }
}

MeuNome::~MeuNome() {
    free(nome);
}

char * MeuNome::getNome() {
    cout << "non-const object!\n";
    return nome;
}

char * MeuNome::getNome() const {
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
