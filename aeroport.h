#ifndef AEROPORT_H
#define AEROPORT_H

#include <iostream>
#include <vector>
#include <string>
#include "avion.h"
#include "pista.h"

class Aeroport {
public:
    std::string stare;
    std::vector<Avion> avioane;
    // pistele, terminal
    std::vector<Pista> piste;

    void vizualizareAeroport() const {
        std::cout << "Bun venit la Aeroportul International UCV Sky! \n" << std::endl
            << "Destinatia unde cerul intalneste ambitia si fiecare calatorie devine o poveste unica. Aici, sunetul motoarelor si privelistea avioanelor decoland reprezinta inceputul unor aventuri de neuitat. Indiferent daca pleci spre noi orizonturi sau te intorci acasa, acest aeroport este poarta ta catre lume."
            << std::endl << std::endl << " Cerul te asteapta. Zbor placut! " << std::endl;
    }

    void vizualizareAvioane() const {
        for (const auto& avion : avioane) {
            avion.vizualizareAvion();
        }
    }

    void vizualizarePiste() const {
        for (const auto& pista : piste) {
			pista.vizualizarePista();
        }
    }
};

#endif
