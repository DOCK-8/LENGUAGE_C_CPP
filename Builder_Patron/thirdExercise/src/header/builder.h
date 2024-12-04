#include <iostream>
#include <vector>
#include <string>

class Pieza {
public:
    virtual std::string GetName() = 0;
    virtual float GetPrice() = 0;
    virtual void GetConfiguration() = 0;
    virtual ~Pieza() {}
};

class Puerta : public Pieza {
public:
    Puerta(std::string color) : color(color) {}
    std::string GetName() override { return "Puerta"; }
    float GetPrice() override { return 300.0; }
    void GetConfiguration() override {
        std::cout << "Puerta de color " << color << std::endl;
    }
private:
    std::string color;
};

class Llantas : public Pieza {
public:
    Llantas(std::string marca) : marca(marca) {}
    std::string GetName() override { return "Llantas"; }
    float GetPrice() override { return 500.0; }
    void GetConfiguration() override {
        std::cout << "Llantas de marca " << marca << std::endl;
    }
private:
    std::string marca;
};

class Timon : public Pieza {
public:
    Timon(std::string marca) : marca(marca) {}
    std::string GetName() override { return "Timon"; }
    float GetPrice() override { return 200.0; }
    void GetConfiguration() override {
        std::cout << "Timon de marca " << marca << std::endl;
    }
private:
    std::string marca;
};

class Motor : public Pieza {
public:
    Motor(std::string motorizacion) : motorizacion(motorizacion) {}
    std::string GetName() override { return "Motor"; }
    float GetPrice() override { return 3000.0; }
    void GetConfiguration() override {
        std::cout << "Motor con motorización " << motorizacion << std::endl;
    }
private:
    std::string motorizacion;
};

class Espejos : public Pieza {
public:
    Espejos(std::string color) : color(color) {}
    std::string GetName() override { return "Espejos"; }
    float GetPrice() override { return 150.0; }
    void GetConfiguration() override {
        std::cout << "Espejos de color " << color << std::endl;
    }
private:
    std::string color;
};

class Vidrios : public Pieza {
public:
    Vidrios(std::string color) : color(color) {}
    std::string GetName() override { return "Vidrios"; }
    float GetPrice() override { return 200.0; }
    void GetConfiguration() override {
        std::cout << "Vidrios de color " << color << std::endl;
    }
private:
    std::string color;
};

class Automovil {
public:
    void AddPieza(Pieza* pieza) {
        mPiezas.push_back(pieza);
    }

    float GetCost() {
        float cost = 0.0;
        for (auto& pieza : mPiezas) {
            cost += pieza->GetPrice();
        }
        return cost;
    }

    void GetConfiguration() {
        for (auto& pieza : mPiezas) {
            pieza->GetConfiguration();
        }
    }

    void ShowParts() {
        std::cout << "\nPiezas seleccionadas:" << std::endl;
        for (auto& pieza : mPiezas) {
            std::cout << pieza->GetName() << " - $ " << pieza->GetPrice() << std::endl;
        }
    }

private:
    std::vector<Pieza*> mPiezas;
};

std::string ElegirColor(std::vector<std::string>& colores) {
    std::cout << "Seleccione un color:" << std::endl;
    for (int i = 0; i < colores.size(); ++i) {
        std::cout << i + 1 << ". " << colores[i] << std::endl;
    }
    int opcion;
    std::cin >> opcion;
    return colores[opcion - 1];
}

std::string ElegirMarca(std::vector<std::string>& marcas) {
    std::cout << "Seleccione una marca:" << std::endl;
    for (int i = 0; i < marcas.size(); ++i) {
        std::cout << i + 1 << ". " << marcas[i] << std::endl;
    }
    int opcion;
    std::cin >> opcion;
    return marcas[opcion - 1];
}

std::string ElegirMotorizacion(std::vector<std::string>& motorizaciones) {
    std::cout << "Seleccione una motorización:" << std::endl;
    for (int i = 0; i < motorizaciones.size(); ++i) {
        std::cout << i + 1 << ". " << motorizaciones[i] << std::endl;
    }
    int opcion;
    std::cin >> opcion;
    return motorizaciones[opcion - 1];
}
