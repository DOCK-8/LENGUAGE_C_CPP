#include "builder.h"

void MostrarMenu() {
    std::cout << "\nBienvenido al configurador de automóviles. Por favor, elija una opción:" << std::endl;
    std::cout << "1. Elegir color de las puertas" << std::endl;
    std::cout << "2. Elegir marca de las llantas" << std::endl;
    std::cout << "3. Elegir marca del timon" << std::endl;
    std::cout << "4. Elegir motorización del motor" << std::endl;
    std::cout << "5. Elegir color de los espejos" << std::endl;
    std::cout << "6. Elegir color de los vidrios" << std::endl;
    std::cout << "7. Ver automóvil configurado" << std::endl;
    std::cout << "8. Salir" << std::endl;
}

int main() {
    Automovil autoSeleccionado;
    std::vector<std::string> colores = {"Rojo", "Azul", "Verde", "Negro", "Blanco"};
    std::vector<std::string> marcas = {"Michelin", "Goodyear", "Bridgestone", "Pirelli"};
    std::vector<std::string> motorizaciones = {"V6", "V8", "Eléctrico", "Híbrido"};
    
    int opcion;
    do {
        MostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::string color = ElegirColor(colores);
                autoSeleccionado.AddPieza(new Puerta(color));
                break;
            }
            case 2: {
                std::string marca = ElegirMarca(marcas);
                autoSeleccionado.AddPieza(new Llantas(marca));
                break;
            }
            case 3: {
                std::string marca = ElegirMarca(marcas);
                autoSeleccionado.AddPieza(new Timon(marca));
                break;
            }
            case 4: {
                std::string motorizacion = ElegirMotorizacion(motorizaciones);
                autoSeleccionado.AddPieza(new Motor(motorizacion));
                break;
            }
            case 5: {
                std::string color = ElegirColor(colores);
                autoSeleccionado.AddPieza(new Espejos(color));
                break;
            }
            case 6: {
                std::string color = ElegirColor(colores);
                autoSeleccionado.AddPieza(new Vidrios(color));
                break;
            }
            case 7:
                std::cout << "\nAutomóvil configurado:" << std::endl;
                autoSeleccionado.GetConfiguration();
                std::cout << "Costo total: $" << autoSeleccionado.GetCost() << std::endl;
                autoSeleccionado.ShowParts();
                break;
            case 8:
                std::cout << "Gracias por usar el configurador de automóviles." << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
                break;
        }

    } while (opcion != 8);

    return 0;
}
