#include "builder.h"

int main(){
  laptopBuilder cotizar;
  std::cout << "Laptop Lenovo XY \n";

  laptop *lenovo = cotizar.opcion1();
  lenovo -> GetConfiguration();
  std::cout << "Precio : " << lenovo -> GetCost() << std::endl;

  computerBuilder builder;

  computer* comp1 = builder.opcion1();
  std::cout << "\nConfiguración de la computadora 1:\n";
  comp1->GetConfiguration();
  std::cout << "Precio : " << comp1 -> GetCost() << std::endl;

  computer* comp2 = builder.opcion2();
  std::cout << "\nConfiguración de la computadora 2:\n";
  comp2->GetConfiguration();
  std::cout << "Precio : " << comp2 -> GetCost() << std::endl;


  return 0;
}
