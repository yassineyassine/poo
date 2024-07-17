#include <iostream>
using namespace std;

// Classe de base Article
class Article {
protected:
    string nom;
    double prix;

public:
    Article(const string& nom, double prix) : nom(nom), prix(prix) {}
    
    double getPrix(){
        return prix;
    }

    void setPrix(double prixIn){
        prix=prixIn;
    }
    virtual void afficher() const {
        std::cout << "Nom de l'article: " << nom << ", Prix: " << prix << " euros" << std::endl;
    }

    virtual ~Article() {}
};

// Classe dérivée ArticleEnSolde
class ArticleEnSolde : public Article {
private:
    double remise;

public:
    ArticleEnSolde(const string& nom, double prix, double remise)
        : Article(nom, prix), remise(remise) {}
        
         
    void setRemise(double remiseIn){
        remise=remiseIn;
    }
    
    
    
    double getPrix(){
        double prixSolde = prix * (1 - remise / 100);
        return prixSolde;
    }

    void afficher() {
        //double prixSolde = prix * (1 - remise / 100);
     //Article::afficher();
        std::cout << "Nom de l'article: " << nom << ", Prix original: " << prix << " euros, "
                  << "Rabais: " << remise << "%, Prix en solde: " << this->getPrix() << " euros" << std::endl;
    }
};


int main()
{
    Article article("Chaise", 50.0);
    ArticleEnSolde articleEnSolde("Table", 100.0, 20.0);

    article.afficher();
    articleEnSolde.afficher();


    return 0;
}
