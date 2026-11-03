
#include <iostream>
using namespace std;

class Technicien {
protected:
    double salaire;

public:
    Technicien(double s) : salaire(s) {}

    void afficherSalaire() const {
        cout << "Salaire du technicien : "
             << salaire << " DH" << endl;
    }
};

class Comptable {
protected:
    double salaire;

public:
    Comptable(double s) : salaire(s) {}

    void afficherSalaire() const {
        cout << "Salaire du comptable : "
             << salaire << " DH" << endl;
    }
};

class EmployePolyvalent : public Technicien,
                          public Comptable {
public:
    EmployePolyvalent(double st, double sc)
        : Technicien(st), Comptable(sc) {}

    void afficherTousSalaires() const {
        Technicien::afficherSalaire();
        Comptable::afficherSalaire();
    }
};

int main() {
    EmployePolyvalent e(5000, 6000);

    e.afficherTousSalaires();
    return 0;
}
