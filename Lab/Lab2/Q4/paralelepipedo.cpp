#include <iostream>
#include "paralelepipedo.h"

Paralelepipedo::Paralelepipedo(double a, double b, double c){
        setVolume(a, b, c);
}

void Paralelepipedo::setVolume(double a, double b, double c){
    volume = a*b*c;
}

double Paralelepipedo::getVolume(){
    return volume;
}
