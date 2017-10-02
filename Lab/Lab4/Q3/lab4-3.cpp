#include <iostream>
#include <time.h>

using namespace std;

class Relogio {
public:
    Relogio();
    void resetHora();

    Relogio &setSegundos();
    Relogio &setMinutos();
    Relogio &setHoras();

    int getSegundos() const;
    int getMinutos() const;
    int getHoras() const;

private:
    time_t hora;
    struct tm *infoHora;
    int segundos;
    int minutos;
    int horas;
};

Relogio::Relogio() {
    resetHora();
}

void Relogio::resetHora() {
    time(&hora);
    infoHora = localtime(&hora);
}

Relogio & Relogio::setSegundos() {
    segundos = (*infoHora).tm_sec;
    return *this;
}

Relogio & Relogio::setMinutos() {
    segundos = (*infoHora).tm_min;
    return *this;
}

Relogio & Relogio::setHoras() {
    segundos = (*infoHora).tm_hour;
    return *this;
}

int Relogio::getSegundos() const{
    return segundos;
}

int Relogio::getMinutos() const{
    return minutos;
}

int Relogio::getHoras() const{
    return horas;
}

int main() {
    Relogio myRelogio;
    myRelogio.setHoras().setMinutos().setSegundos();

    cout << myRelogio.getHoras() << endl;
    cout << myRelogio.getMinutos() << endl;
    cout << myRelogio.getSegundos() << endl;

    return 0;
}
