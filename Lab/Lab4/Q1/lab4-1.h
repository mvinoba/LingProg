#include <string>

using namespace std;

class MeuNome {
public:
    MeuNome(string);
    string getNome();
    string getNome() const;
private:
    string nome;
};
