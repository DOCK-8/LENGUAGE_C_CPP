#include "Simple_List.h"

int main(int n, char** arg){
  List lista("Hola");
  std::cout << "El contenido del nodo es: " << lista.get_root()->get_content() << std::endl;
  return 0;
}
