#include <iostream>
#include "menu.h"

using namespace std;

void Menu::showMenu() {

    cout << "Este é um gerenciador de validações de dados" << endl;
    cout << "Escolha uma das opções digitando um número e pressionando enter:" << endl;
    cout << "1 - Validador de Números de Celulares"  << endl;
    cout << "2 - Validador de CPFs"  << endl;
    cout << "3 - Validador de e-mails" << endl;
    cout << "4 - Validador de CEPs "<< endl;
    cout << "5 - Validador de placas de carro do RJ"  << endl;

    cin >> choice;

    while (choice >= 6 || choice <= 0) {
        cout << "Por favor selecione uma opção válida! " << endl;
        cin >> choice;
    }
}

int Menu::getChoice() {
    return choice;
}
