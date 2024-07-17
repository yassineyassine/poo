// Classe abstraite Véhicule
class Vehicule {
public:
    virtual void deplacer() const = 0; // Méthode virtuelle pure
    virtual void afficherType() const = 0; // Autre méthode virtuelle pure
    virtual ~Vehicule() {} // Destructeur virtuel
};


// Classe Voiture (dérivée de Vehicule)
class Voiture : public Vehicule {
public:
    void deplacer() const override {
        std::cout << "La voiture roule sur la route." << std::endl;
    }
    
    void afficherType() const override {
        std::cout << "C'est une voiture." << std::endl;
    }
};

// Classe Avion (dérivée de Vehicule)
class Avion : public Vehicule {
public:
    void deplacer() const override {
        std::cout << "L'avion vole dans le ciel." << std::endl;
    }
    
    void afficherType() const override {
        std::cout << "C'est un avion." << std::endl;
    }
};

int main() {
    Voiture maVoiture;
    Avion monAvion;

    // Tableau de pointeurs vers des Vehicules
    Vehicule* mesVehicules[] = { &maVoiture, &monAvion };

    for (Vehicule* vehicule : mesVehicules) {
        vehicule->afficherType(); // Appelle la méthode spécifique à chaque type
        vehicule->deplacer(); // Polymorphisme : appelle la méthode définie dans chaque classe
    }

    return 0;
}
