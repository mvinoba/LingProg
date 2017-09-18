#include <iostream>
#include "paralelepipedo.h"

int main(){
    Paralelepipedo myParalelepipedo(3,8,4);
    std::cout << myParalelepipedo.getVolume() << std::endl;
    myParalelepipedo.setVolume(5, 7, 2.6);
    std::cout << myParalelepipedo.getVolume() << std::endl;
    return 0;
}
