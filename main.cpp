#include <iostream>
using namespace std;

template<typename T>
class list_Iterator;

template<typename T>
class node{
private:
    T data;
    node<T> *next;
public:
    node(){
        data=0;
        next=NULL;
    }
    node(const node<T> &n){
        data=n.data;
        next=n.next;
    }
    T getData(){
        return data;
    }
    void setData(T d){
        data=d;
    }
    node* get_next(){
        return next;
    }
    void set_next(node<T> *n){
        next=n;
    }
};

template<typename T>
class pila{
private:
    node<T> *actual;
    int s;
public:
    pila(){
        cout<<"Construido"<<endl;
        actual=NULL;
        s=0;
    }
    ~pila(){
        while(actual!=NULL){
            delete actual;
            actual=actual->get_next();
        }
        cout<<"Destruido"<<endl;
    }
    node<T>* crear_nodo(T new_data){
        node<T> *new_node=new node<T>;
        new_node->setData(new_data);
        return new_node;
    }
    void push(T new_data){
        node<T> *new_node=crear_nodo(new_data);
        if(actual!=NULL){
            new_node->set_next(actual);
            actual=new_node;
        }
        else{
            actual=new_node;
        }
        cout<<"push: "<<new_data<<endl;
        s++;
    }
    int getSize(){
        return s;
    }
    void pop(){
        node<T>* aux=actual;
        T data=aux->getData();
        if(s!=0){
            delete aux;
            actual=actual->get_next();
            s--;
        }
        else{
            actual=NULL;
        }
        cout<<"pop: "<<data<<endl;
    }
    node<T>* get_actual(){
    	return actual;
	}
    list_Iterator<T> mostrar(){
        cout<<"Mostrando:"<<endl;
        list_Iterator<T> it;
        for(it=this->get_actual() ; it != NULL; ++it ){
            cout << *it << " -> ";
        }
        cout<<"NULL"<<endl;
    }
};

template<typename T>
class cola{
private:
    node<T> *head,*tail;
    int s;
public:
    cola(){
        cout<<"Construido"<<endl;
        head=NULL;
        tail=NULL;
        s=0;
    }
    ~cola(){
        while(head!=NULL){
            delete head;
            head=head->get_next();
        }
        cout<<"Destruido"<<endl;
    }
    node<T>* crear_nodo(T new_data){
        node<T> *new_node=new node<T>;
        new_node->setData(new_data);
        return new_node;
    }
    void push(T new_data){
        node<T> *new_node=crear_nodo(new_data);
        if(tail!=NULL){
            tail->set_next(new_node);
            tail=tail->get_next();
        }
        else{
            tail=new_node;
            head=new_node;
        }
        cout<<"push: "<<new_data<<endl;
        s++;
    }
    void pop(){
        node<T>* aux=head;
        T data=aux->getData();
        if(head!=tail){
            delete aux;
            head=head->get_next();
            s--;
        }
        else{
            head=NULL;
            tail=NULL;
        }
        cout<<"pop: "<<data<<endl;
    }
    node<T>* getNodo(int n){  //direccion de memoria
        int i=0;
        node<T>* aux=head;
        while(i!=n){
            aux=aux->get_next();
            i++;
        }
        return aux;
    }
    int getSize(){
        return s;
    }
    node<T>* get_head(){
    	return head;
	}
    node<T>* get_tail() {
        return tail;
	}
    /*void mostrar(){
        cout<<"Mostrando:"<<endl;
        node<T>* aux=head;
        while(aux!=NULL){
            cout<<aux->getData()<<" -> ";
            aux=aux->get_next();
        }
        cout<<"NULL"<<endl;
    }*/
    list_Iterator<T> mostrar(){
        cout<<"Mostrando:"<<endl;
        list_Iterator<T> it;
        for(it=this->get_head() ; it != NULL; ++it ){   //this->get_tail()
            cout << *it << " -> ";
        }
        cout<<"NULL"<<endl;
    }
};

template<typename T>
class list_Iterator{
private:
    node<T>* nodoIte;
public:
    list_Iterator(node<T>* nodo=NULL){
        nodoIte=nodo;
    }
	void operator=(node<T>* nodo){
		nodoIte=nodo;
	}
	node<T>* operator++(){
		nodoIte= nodoIte->get_next();
        return nodoIte;
	}
	T operator*(){
		return nodoIte->getData();
	}
	bool operator==(node<T>* nodo){
		return nodoIte== nodo;
	}
	bool operator!=(node<T> *nodo){
		return nodoIte!= nodo;
	}
};

int main()
{
    cola<int> cola;
    cola.push(3);
    cola.push(4);
    cola.push(5);
    cola.push(6);
    cola.push(7);
    cola.mostrar();
    cout<<"size: "<<cola.getSize()<<endl;
    cola.pop();
    cola.pop();
    cola.pop();
    cola.pop();
    cola.mostrar();
    cout<<"size: "<<cola.getSize()<<endl;

    cout<<"--------------------------------------------"<<endl;

    pila<int> pila;
    pila.push(3);
    pila.push(4);
    pila.push(5);
    pila.push(6);
    pila.push(7);
    pila.mostrar();
    cout<<"size: "<<pila.getSize()<<endl;
    pila.pop();
    pila.pop();
    pila.pop();
    pila.pop();
    pila.pop();
    pila.mostrar();
    cout<<"size: "<<pila.getSize()<<endl;

    return 0;
}
