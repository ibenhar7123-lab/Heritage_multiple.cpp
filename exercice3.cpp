
#include <iostream>
#include <string>
using namespace std;

class Vehicule {
protected:
    string marque, modele;

public:
    Vehicule(string ma, string mo)
        : marque(ma), modele(mo) {}
};

class Thermique : virtual public Vehicule {
protected:
    double consommation;

public:
    Thermique(string ma, string mo, double c)
        : Vehicule(ma, mo), consommation(c) {}
};

class Electrique : virtual public Vehicule {
protected:
    double autonomie;

public:
    Electrique(string ma, string mo, double a)
        : Vehicule(ma, mo), autonomie(a) {}
};

class Hybride : public Thermique, public Electrique {
public:
    Hybride(string ma, string mo, double c, double a)
        : Vehicule(ma, mo),
          Thermique(ma, mo, c),
          Electrique(ma, mo, a) {}

    void afficherCaracteristiques() const {
        cout << "Marque : " << marque << endl;
        cout << "Modele : " << modele << endl;
        cout << "Consommation : " << consommation
             << " L/100 km" << endl;
        cout << "Autonomie electrique : " << autonomie
             << " km" << endl;
    }
};

int main() {
    Hybride h("Toyota", "Prius", 4.2, 60);

    h.afficherCaracteristiques();
    return 0;
}
