#include "factory.h"

int main(){
  int type;
  while(1) {
    std::cout << std::endl << "Ingrese un tipo (1 a 3) o '0' para salir" << std::endl;
    std::cin >> type;
    if(!type) {
      break;
    }
    Plato *v = CocinaFactory::crearPlato(type);
    if(v) {
      v -> showPlato();
      delete v;
    }
  }
  std::  cout << "Saliendo ..." << std::endl;
  return 0;
}
