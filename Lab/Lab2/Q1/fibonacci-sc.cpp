#include "fibonacci-sc.h"

int fibonacci(int ind){
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
