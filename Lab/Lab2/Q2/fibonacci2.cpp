#include <iostream>
#include "fibonacci2-sc.h"

int main(){
    Fibonacci myFib;
    int index;

    std::cout << "Entre com o índice do elemento da série de Fibonacci: ";
    std::cin >> index;

    myFib.calcFib(index);
    std::cout << "Resultado: " << myFib.getNum() << std::endl;

    return 0;
}
