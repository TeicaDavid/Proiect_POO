#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "header.h"

void afisareMeniu() {
    std::cout << "Meniu Simulator Aeroport:\n";
    std::cout << "1. Vizualizare Avioane\n";
    std::cout << "2. Vizualizare Aeroport\n";
    std::cout << "3. Vizualizare Turn de Control\n";
    std::cout << "4. Vizualizare Piste\n";
    std::cout << "5. Vizualizare Piloti\n";
    std::cout << "6. Iesire\n";
}

void incarcaDate(std::vector<Avion>& avioane, std::vector<Pilot>& piloti, std::vector<Pista>& piste) {
    std::ifstream fisier("planes.txt");
    if (!fisier) {
        std::cerr << "Nu se poate deschide fisierul planes.txt\n";
        return;
    }

    std::string id, pilot, stare;
    while (fisier >> std::ws && std::getline(fisier, id, ' ') && std::getline(fisier, pilot, ' ') && std::getline(fisier, stare)) {
        Avion avion{ id, pilot, stare };
        avioane.push_back(avion);

        Pilot p{ pilot, avion };
        piloti.push_back(p);

        Pista pista{ true, avion }; // Presupunem ca toate pistele sunt initial disponibile
        piste.push_back(pista);
    }

    fisier.close();
}

int main() {
    int alegere;
    Aeroport aeroport;
    TurnDeControl turnDeControl;
    std::vector<Avion> avioane;
    std::vector<Pista> piste;
    std::vector<Pilot> piloti;

    // Incarca date din fisier
    incarcaDate(avioane, piloti, piste);
    aeroport.avioane = avioane;

    do {
        afisareMeniu();
        std::cout << "Introduceti alegerea: ";
        std::cin >> alegere;

        switch (alegere) {
        case 1:
            for (const auto& avion : avioane) {
                std::cout << "ID Avion: " << avion.id << ", Stare: " << avion.stare << "\n";
            }
            break;
        case 2:
            aeroport.vizualizareAeroport();
            break;
        case 3:
            turnDeControl.vizualizareTurnDeControl();
            break;
        case 4:
            for (auto& pista : piste) {
                pista.vizualizarePista();
            }
            break;
        case 5:
            for (const auto& pilot : piloti) {
                std::cout << "Nume Pilot: " << pilot.nume << "\n";
            }
            break;
        case 6:
            std::cout << "Iesire...\n";
            break;
        default:
            std::cout << "Alegere invalida. Va rugam sa incercati din nou.\n";
        }
    } while (alegere != 6);
    return 0;
}
