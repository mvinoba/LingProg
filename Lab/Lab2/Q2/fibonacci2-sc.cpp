#include "fibonacci2-sc.h"

void Fibonacci::calcFib(int ind){
	number = setNum(ind);
};

int Fibonacci::getNum(){
	return number;
};

int Fibonacci::setNum(int ind){
    if (ind < 2){
        return ind;
    }
    int fib;
    int a = 1;
    int b = 0;
    for (int i = 2; i < ind; i++) {
        fib = a + b;
        b = a;
        a = fib;
    }
    return fib;
}
