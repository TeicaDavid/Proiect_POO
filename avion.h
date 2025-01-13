#ifndef AVION_H
#define AVION_H

#include <iostream>
#include <vector>
#include <string>

class Avion {
public:
    std::string id;
    std::string pilot; // numele pilotului, pointer catre pilot
    std::string stare; // aterizat, in aterizare, sau asteapta decolare

    void vizualizareAvion() const {
        std::cout << "ID Avion: " << id << ", Stare: " << stare << "\n";
    }
};

#endif // AVION_H
