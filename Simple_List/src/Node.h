#include <iostream>

template <class T>
class Node{
  private:
    T content;
    Node<T>* next;
  public:
    Node();
    Node(T);
    ~Node();
    T get_content();
    void set_content(T);
    Node<T>* get_next();
    void set_next(Node<T>*);
};

template <class T>
Node<T>::Node():content(T()),next(nullptr){}

template <class T>
Node<T>::Node(T content):content(content), next(nullptr){}

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

template <class T>
Node<T>* Node<T>::get_next(){
  return this->next;
}
template <class T>
void Node<T>::set_next(Node<T>* next){
  if(this->next != nullptr)
    delete this->next;
  this->next = next;
}
