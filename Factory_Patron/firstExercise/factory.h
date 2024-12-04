#include <iostream>
#include <vector>
#include <string>

class Plato;

class Ingrediente {
protected:
    std::string name;
    float peso;  // Medido en gramos
    float price; // Soles por gramo
public:
    Ingrediente(std::string n, float p, float pr) : name(n), peso(p), price(pr) {}

    virtual void ingredienteLavado() = 0;
    virtual void ingredientePicado() = 0;
    virtual void ingredienteCocinado() = 0;
    virtual void ingredienteIntegrado() = 0;  

    friend class Plato;
};

class Papa : public Ingrediente {
public:
    Papa(float p, float pr) : Ingrediente("Papa", p, pr) {}

    void ingredienteLavado() {
        std::cout << "Lavando papa" << std::endl;
    };
    void ingredientePicado() {
        std::cout << "Picando papa" << std::endl;
    };
    void ingredienteCocinado() {
        std::cout << "Cocinando papa" << std::endl;
    };
    void ingredienteIntegrado() {
        std::cout << "Integrando papa en el plato" << std::endl;
    };
};

class Brocoli : public Ingrediente {
public:
    Brocoli(float p, float pr) : Ingrediente("Brocoli", p, pr) {}

    void ingredienteLavado() {
        std::cout << "Lavando Brocoli" << std::endl;
    };
    void ingredientePicado() {
        std::cout << "Picando Brocoli" << std::endl;
    };
    void ingredienteCocinado() {
        std::cout << "Cocinando Brocoli" << std::endl;
    };
    void ingredienteIntegrado() {
        std::cout << "Integrando Brocoli en el plato" << std::endl;
    };
};

class Zanahoria : public Ingrediente {
public:
    Zanahoria(float p, float pr) : Ingrediente("Zanahoria", p, pr) {}

    void ingredienteLavado() {
        std::cout << "Lavando Zanahoria" << std::endl;
    };
    void ingredientePicado() {
        std::cout << "Picando Zanahoria" << std::endl;
    };
    void ingredienteCocinado() {
        std::cout << "Cocinando Zanahoria" << std::endl;
    };
    void ingredienteIntegrado() {
        std::cout << "Integrando Zanahoria en el plato" << std::endl;
    };
};

class Cebolla : public Ingrediente {
public:
    Cebolla(float p, float pr) : Ingrediente("Cebolla", p, pr) {}

    void ingredienteLavado() {
        std::cout << "Lavando Cebolla" << std::endl;
    };
    void ingredientePicado() {
        std::cout << "Picando Cebolla" << std::endl;
    };
    void ingredienteCocinado() {
        std::cout << "Cocinando Cebolla" << std::endl;
    };
    void ingredienteIntegrado() {
        std::cout << "Integrando Cebolla en el plato" << std::endl;
    };
};

class Ajo : public Ingrediente {
public:
    Ajo(float p, float pr) : Ingrediente("Ajo", p, pr) {}

    void ingredienteLavado() {
        std::cout << "Lavando Ajo" << std::endl;
    };
    void ingredientePicado() {
        std::cout << "Picando Ajo" << std::endl;
    };
    void ingredienteCocinado() {
        std::cout << "Cocinando Ajo" << std::endl;
    };
    void ingredienteIntegrado() {
        std::cout << "Integrando Ajo en el plato" << std::endl;
    };
};

class Arroz : public Ingrediente {
public:
    Arroz(float p, float pr) : Ingrediente("Arroz", p, pr) {}

    void ingredienteLavado() {
        std::cout << "Lavando Arroz" << std::endl;
    };
    void ingredienteCocinado() {
        std::cout << "Cocinando Arroz" << std::endl;
    };
    void ingredientePicado() {};
    void ingredienteIntegrado() {
        std::cout << "Integrando Arroz en el plato" << std::endl;
    };
};

class Fideo : public Ingrediente {
public:
    Fideo(float p, float pr) : Ingrediente("Fideo", p, pr) {}

    void ingredienteLavado() {};
    void ingredientePicado() {};
    void ingredienteCocinado() {
        std::cout << "Cocinando Fideo" << std::endl;
    };
    void ingredienteIntegrado() {
        std::cout << "Integrando Fideo en el plato" << std::endl;
    };
};

class Plato {
private:
    std::string nombre;
    std::vector<Ingrediente*> ingredientes;
public:
    Plato(const std::string& nombre) : nombre(nombre) {}

    void agregarIngrediente(Ingrediente* ingrediente) {
        ingredientes.push_back(ingrediente);
    }

    void prepararPlato() {
        std::cout << "Preparando el plato: " << nombre << std::endl;
        for (auto& ingrediente : ingredientes) {
            ingrediente->ingredienteLavado();
            ingrediente->ingredientePicado();
            ingrediente->ingredienteCocinado();
            ingrediente->ingredienteIntegrado();
        }
        std::cout << "Plato listo: " << nombre << std::endl;
    }

    void showPlato(){
        float pesot = 0.0, precio = 0.0;
        for (auto i : this->ingredientes) {
            precio += (i->peso * i->price);
            pesot += i->peso;
        }
        Plato::prepararPlato();
        std::cout << "PESO: " << pesot << "\nPRECIO: " << precio << std::endl;
    }

    ~Plato() {
        for (auto& ingrediente : ingredientes) {
            delete ingrediente;
        }
    }
};

class CocinaFactory {
public:
    static Plato* crearPlato(int tipo) {
        Plato* plato = nullptr;
        switch (tipo) {
            case 1:
                plato = new Plato("Plato Vegetariano");
                plato->agregarIngrediente(new Papa(300, 0.5));  // 300 gramos, 0.5 soles por gramo
                plato->agregarIngrediente(new Brocoli(150, 0.8)); // 150 gramos, 0.8 soles por gramo
                plato->agregarIngrediente(new Zanahoria(100, 0.3)); // 100 gramos, 0.3 soles por gramo
                break;
            case 2:
                plato = new Plato("Plato de Arroz");
                plato->agregarIngrediente(new Arroz(250, 0.4));  // 250 gramos, 0.4 soles por gramo
                plato->agregarIngrediente(new Zanahoria(100, 0.3)); // 100 gramos, 0.3 soles por gramo
                break;
            case 3:
                plato = new Plato("Plato de Fideos");
                plato->agregarIngrediente(new Fideo(200, 0.6));  // 200 gramos, 0.6 soles por gramo
                plato->agregarIngrediente(new Zanahoria(100, 0.3)); // 100 gramos, 0.3 soles por gramo
                break;
            default:
                std::cout << "Opción de plato no válida." << std::endl;
                return nullptr;
        }
        return plato;
    }
};
