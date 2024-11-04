#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <string>

class Avion {
public:
    std::string id;
    std::string pilot;
    std::string stare; // aterizat, in aterizare, sau asteapta decolare

    void vizualizareAvion() const {
        std::cout << "ID Avion: " << id << ", Pilot: " << pilot << ", Stare: " << stare << "\n";
    }
};

class Aeroport {
public:
    std::vector<Avion> avioane;

    void vizualizareAvioane() const {
        for (const Avion& avion : avioane) {
            avion.vizualizareAvion();
        }
    }

    void vizualizareAeroport() const {
        std::cout << "Vizualizare Informatii Aeroport\n";
        
    }
};

class TurnDeControl {
public:
    bool pisteDisponibile;

    void vizualizareTurnDeControl() const {
        std::cout << "Turn de Control - Piste Disponibile: " << (pisteDisponibile ? "Da" : "Nu") << "\n";
    }
};

class Pista {
public:
    bool disponibila;
    Avion avion;

    void vizualizarePista() const {
        std::cout << "Pista - Disponibila: " << (disponibila ? "Da" : "Nu") << ", Avion: " << avion.id << "\n";
    }
};

class Pilot {
public:
    std::string nume;
    Avion avion;

    void vizualizarePilot() const {
        std::cout << "Nume Pilot: " << nume << ", ID Avion: " << avion.id << "\n";
    }
};

#endif
