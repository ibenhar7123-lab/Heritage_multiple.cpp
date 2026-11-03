
#include <iostream>
#include <string>
using namespace std;

class Utilisateur {
protected:
    int identifiant;
    string login;

public:
    Utilisateur(int id, string l)
        : identifiant(id), login(l) {}

    void afficherUtilisateur() const {
        cout << "Identifiant : " << identifiant << endl;
        cout << "Login : " << login << endl;
    }
};

class Administrateur : virtual public Utilisateur {
protected:
    string droitsAcces;

public:
    Administrateur(int id, string l, string droits)
        : Utilisateur(id, l), droitsAcces(droits) {}

    void gererSysteme() const {
        cout << "Gestion du systeme : droits "
             << droitsAcces << endl;
    }
};

class Moderateur : virtual public Utilisateur {
protected:
    int niveauModeration;

public:
    Moderateur(int id, string l, int niveau)
        : Utilisateur(id, l), niveauModeration(niveau) {}

    void modererContenu() const {
        cout << "Moderation du contenu : niveau "
             << niveauModeration << endl;
    }
};

class SuperUtilisateur : public Administrateur,
                         public Moderateur {
public:
    SuperUtilisateur(int id, string l,
                     string droits, int niveau)
        : Utilisateur(id, l),
          Administrateur(id, l, droits),
          Moderateur(id, l, niveau) {}

    void afficher() const {
        afficherUtilisateur();
        gererSysteme();
        modererContenu();
    }
};

int main() {
    int id, niveau;
    string login, droits;

    cout << "Identifiant : ";
    cin >> id;

    cout << "Login : ";
    cin >> login;

    cout << "Droits d'acces : ";
    cin >> droits;

    cout << "Niveau de moderation : ";
    cin >> niveau;

    SuperUtilisateur u(id, login, droits, niveau);

    cout << "\n--- Informations du super utilisateur ---"
         << endl;
    u.afficher();

    return 0;
}
