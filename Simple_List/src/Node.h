#include <iostream>

template <class T>
class Node{
  private:
    T content;
  public:
    Node();
    Node(T);
    ~Node();
    T get_content();
    void set_content(T);
};

template <class T>
Node<T>::Node():content(T()){}

template <class T>
Node<T>::Node(T content):content(content){}

template <class T>
Node<T>::~Node(){
  std::cout << "Se elimino el nodo\nCONTENIDO: " << this->content;
}

template <class T>
T Node<T>::get_content(){
  return this->content;
}

template <class T>
void Node<T>::set_content(T content){
  this->content = content;
}
