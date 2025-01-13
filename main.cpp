#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>
#include "avion.h"
#include "pista.h"
#include "aeroport.h"
#include "turncontrol.h"
#include "pilot.h"

void afisareMeniu() {
    std::cout << "Meniu Simulator Aeroport:\n";
    std::cout << "1. Vizualizare Avioane\n";
    std::cout << "2. Vizualizare Aeroport\n";
    std::cout << "3. Vizualizare Turn de Control\n";
    std::cout << "4. Vizualizare Piste\n";
    std::cout << "5. Vizualizare Piloti\n";
    std::cout << "6. Pornire Simulare Automata\n";
    std::cout << "7. Iesire\n";
}

void incarcaDate(std::vector<Avion>& avioane, std::vector<Pilot>& piloti, std::vector<Pista>& piste) {
    std::ifstream fisier("avioane.txt");
    if (!fisier) {
        std::cerr << "Nu se poate deschide fisierul avioane.txt\n";
        return;
    }

    std::string id, pilot, stare;
    while (fisier >> id >> pilot >> stare) {
        Avion avion{ id, pilot, stare };
        avioane.push_back(avion);

        Pilot p{ pilot, avion };
        piloti.push_back(p);

        Pista pista{ avion };
        piste.push_back(pista);
    }

    fisier.close();
}


void actualizeazaStari(std::vector<Avion>& avioane, std::vector<Pista>& piste) {
    for (size_t i = 0; i < avioane.size(); ++i) {
        Avion& avion = avioane[i];
        Pista& pista = piste[i];

        if (avion.stare == "libera") {
            avion.stare = "in_aterizare";
            pista.disponibila = false;
        }
        else if (avion.stare == "in_aterizare") {
            avion.stare = "asteapta_decolare";
            pista.disponibila = false;
        }
        else if (avion.stare == "asteapta_decolare") {
            avion.stare = "in_zbor";
            pista.disponibila = true;
        }
        else if (avion.stare == "in_zbor") {
            avion.stare = "libera";
            pista.disponibila = true;
        }
    }
}

void simulareAutomata(std::vector<Avion>& avioane, std::vector<Pista>& piste) {
    while (true) {
        actualizeazaStari(avioane, piste);

        std::cout << "\n--- Status Aeroport Actualizat ---\n";
        for (size_t i = 0; i < avioane.size(); ++i) {
            std::cout << "Avion: " << avioane[i].id << " | Stare: " << avioane[i].stare
                << " | Pista: " << (piste[i].disponibila ? "Disponibila" : "Indisponibila") << "\n";
        }

        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
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
    aeroport.piste = piste;

    do {
        afisareMeniu();
        std::cout << "Introduceti alegerea: ";
        std::cin >> alegere;

        switch (alegere) {
        case 1:
            aeroport.vizualizareAvioane();
            break;
        case 2:
            aeroport.vizualizareAeroport();
            break;
        case 3:
            turnDeControl.vizualizareTurnDeControl();
            break;
        case 4:
            aeroport.vizualizarePiste();
            break;
        case 5:
            for (const auto& pilot : piloti) {
                pilot.vizualizarePilot();
            }
            break;
        case 6:
            simulareAutomata(avioane, piste);
            break;
        case 7:
            std::cout << "Iesire...\n";
            break;
        default:
            std::cout << "Alegere invalida. Va rugam sa incercati din nou.\n";
        }

        if (alegere != 7 && alegere != 6) {
            std::cout << "Apasati Enter pentru a continua...";
            std::cin.ignore();
            std::cin.get();
            system("CLS");
        }
    } while (alegere != 7);

    return 0;
}
