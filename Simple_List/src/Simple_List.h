#include "Node.h"

template <class T>
class List {

  template <class U>
  friend std::ostream& operator<<(std::ostream&, List<U>&);

  private:
    Node<T>* root;
  public:
    List();
    List(T);
    ~List();
    Node<T>* get_root();
    void set_root(Node<T>&);
    void add(T);
    void remove(T);
    Node<T>* search(T);
    void change(T,T);
};

template <class T>
std::ostream& operator<<(std::ostream& os, List<T>& lista){
  Node<T>* aux = lista.get_root();
  while(aux != nullptr){
    os << " -> " << aux->get_content();
    os << std::endl;
    aux = aux->get_next();
  }
  return os;
}

template <class T>
List<T>::List():root(nullptr){}

template <class T>
List<T>::List(T root):root(new Node<T>(root)){}

template <class T>
List<T>::~List(){
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

template <class T>
void List<T>::add(T node){
  Node<T>* aux = root;
  if(aux == nullptr){
    root = new Node(node);
  }
  else{
    while(aux->get_next() != nullptr)
      aux = aux->get_next();
    aux->set_next(new Node<T>(node));
  }
}

template <class T>
void List<T>::remove(T node){
  Node<T>* aux = root;
  while(aux != nullptr && aux->get_content() != node)
    aux = aux->get_next();
  aux->set_next(aux->get_next()->get_next());
}

template <class T>
Node<T>* List<T>::search(T node){
  Node<T>* aux = root;
  while(aux != nullptr && aux->get_content() != node)
    aux = aux -> get_next();
  return aux;
}

template <class T>
void List<T>::change(T out, T in){
  search(out)->set_content(in);
}
