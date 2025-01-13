#ifndef PISTA_H
#define PISTA_H

#include <iostream>
#include <vector>
#include <string>
#include "avion.h"

class Pista {
public:
    bool disponibila;
    Avion avion;

    Pista(const Avion& avion) : avion(avion) {
        if (avion.stare == "libera" || avion.stare == "in_zbor") {
            disponibila = true;
        }
        else {
            disponibila = false;
        }
    }

    void vizualizarePista() const {
        if (avion.stare == "asteapta_decolare" || avion.stare == "in_aterizare")
            std::cout << "Stare: Indisponibila" << " " << "\n";
        else
            std::cout << "Stare: Disponibila" << " " << "\n";
    }
};


#endif
