#include <cassert>
#include <cstddef>
#include <iostream>
#include <vector>
struct TableauDynamique {
    double* donnees{nullptr};
    std::size_t taille{0};
    std::size_t capacite{0};
};

void ajouter(TableauDynamique& t, double valeur)
{
    if (t.taille == t.capacite) {
        const std::size_t nouvelleCapacite =
            (t.capacite == 0) ? 4 : t.capacite * 2;

        double* nouveau = new double[nouvelleCapacite];

        for (std::size_t i{0}; i < t.taille; ++i) {
            nouveau[i] = t.donnees[i];
        }

        delete[] t.donnees;

        t.donnees = nouveau;
        t.capacite = nouvelleCapacite;
    }

    t.donnees[t.taille] = valeur;
    ++t.taille;
}

void liberer(TableauDynamique& t)
{
    delete[] t.donnees;
    t.donnees = nullptr;
    t.taille = 0;
    t.capacite = 0;
}

int main()
{
    TableauDynamique notes;
    
ajouter(notes, 12.0);
ajouter(notes, 15.0);

TableauDynamique copie = notes;

liberer(notes);
liberer(copie);

    for (int i{0}; i < 10; ++i) {
        ajouter(notes, 10.0 + i);

        std::cout << "Taille : " << notes.taille
                  << " | Capacite : " << notes.capacite
                  << '\n';
    }

    liberer(notes);

    return 0;
}
