#include <iostream>
#include "fibonacci-sc.h"

int main(){
    int index;
    
    std::cout << "Entre com o índice do elemento da série de Fibonacci: ";
    std::cin >> index;

    std::cout << "Resultado: " << fibonacci(index) << std::endl;

    return 0;
}
