#include "Node.h"
template <class T>
class List {
  private:
    Node<T>* root;
  public:
    List();
    List(T);
    ~List();
    Node<T>* get_root();
    void set_root(Node<T>&);
};

template <class T>
List<T>::List():root(new Node<T>()){}

template <class T>
List<T>::List(T root):root(new Node<T>(root)){}

template <class T>
List<T>::~List(){
  delete(this->root);
  std::cout << "Se elimino la Lista Simple" << std::endl;
}

template <class T>
Node<T>* List<T>::get_root(){
  return this->root;
}

template <class T>
void List<T>::set_root(Node<T>& root){
  this->root = &root;
}
