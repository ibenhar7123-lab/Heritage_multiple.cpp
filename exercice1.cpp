
#include <iostream>
#include <string>
using namespace std;

class Personne {
protected:
    string nom, prenom;

public:
    Personne(string n, string p) : nom(n), prenom(p) {}

    void afficher() const {
        cout << "Nom : " << nom << endl;
        cout << "Prenom : " << prenom << endl;
    }
};

class Chercheur {
protected:
    string domaineRecherche;

public:
    Chercheur(string domaine) : domaineRecherche(domaine) {}

    void afficher() const {
        cout << "Domaine de recherche : "
             << domaineRecherche << endl;
    }
};

class EnseignantChercheur : public Personne,
                            public Chercheur {
public:
    EnseignantChercheur(string n, string p, string domaine)
        : Personne(n, p), Chercheur(domaine) {}

    void afficher() const {
        Personne::afficher();
        Chercheur::afficher();
    }
};

int main() {
    EnseignantChercheur e(
        "Benali", "Ahmed", "Intelligence artificielle"
    );

    e.afficher();
    return 0;
}
