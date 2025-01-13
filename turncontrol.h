#ifndef TURNCONTROL_H
#define TURNCONTROL_H

#include <iostream>
#include <vector>
#include <string>
#include "avion.h"
#include "pista.h"
class TurnDeControl {
public:
    bool pisteDisponibile;
    //pointer aeroport
    void vizualizareTurnDeControl() const {
        std::cout << "Turn de Control - Piste Disponibile: " << (pisteDisponibile ? "Da" : "Nu") << "\n";
    }
};

#endif