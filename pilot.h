#ifndef PILOT_H
#define PILOT_H

#include <iostream>
#include <vector>
#include <string>
#include "avion.h"
#include "pista.h"
class Pilot {
public:
    std::string nume;
    Avion avion;
    // pointer catre avion
    void vizualizarePilot() const {
        std::cout << "Nume Pilot: " << nume << ", ID Avion: " << avion.id << "\n";
    }
};

#endif