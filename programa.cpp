#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo *sig;
    nodo *ant;
};

class ListaDoble{
    private:
        nodo *pInicio;
    public:
        ListaDoble();
        void insInicio(void);
        void insFinal(void);
        void insertar(void);
        void insDespues(int, int);
        void insAntes(int, int);
        void eliminar(void);
        void mostrarLista(void);
        void mostrarLista(nodo *);
        /*void llenarArreglo(int);
        void mostrarTemperaturas(void);
        void mostrarMenor(void);
        void mostrarMayor(void);
        void mostrarPromedio(void);
        float sumarTemperaturas(int i);*/
        void menu(void);
};

ListaDoble::ListaDoble(){
    pInicio = NULL;
}

void ListaDoble::insInicio(void){
    nodo *nuevo;
    char resp;
    int dato;

    do{
        cout << "Desea ingresar un dato (s/n)? ";
        cin >> resp;
        if(resp == 's'){
            cout << "Digite el dato: ";
            cin >> dato;
            nuevo = new nodo;
            nuevo->dato = dato;
            nuevo->sig = pInicio;
            nuevo->ant = NULL;
            if(pInicio != NULL)
                pInicio->ant = nuevo;
            pInicio = nuevo;
        }
    }while(resp == 's');
}

void ListaDoble::insertar(void){
    char resp;
    int dato;
    int datoRef;
    do{
        cout << "Desea ingresar un dato (s/n)? ";
        cin >> resp;
        if(resp == 's'){
            cout << "Digite el dato: ";
            cin >> dato;
            cout << "Antes de que dato lo insertara? ";
            cin >> datoRef;
            insAntes(dato, datoRef);
        }
    }while(resp == 's');
}

void ListaDoble::insDespues(int dato, int datoRef){
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    if(pInicio == NULL){
        pInicio = nuevo;
        pInicio->ant = pInicio->sig = NULL;
    }
    else{
        nodo *s = pInicio;
        while(s->sig != NULL && s->dato != datoRef)
            s = s->sig;
        if(s->sig != NULL){
            nuevo->sig = s->sig;
            nuevo->ant = s;
            s->sig->ant = nuevo;
            s->sig = nuevo;
        }
        else{
            s->sig = nuevo;
            nuevo->ant = s;
            nuevo->sig = NULL;
        }
    }
}

void ListaDoble::insAntes(int dato, int datoRef){
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    if(pInicio == NULL){
        pInicio = nuevo;
        pInicio->ant = pInicio->sig = NULL;
    }
    else{
        nodo *s = pInicio;
        while(s->sig != NULL && s->dato != datoRef)
            s = s->sig;
    }
}

void ListaDoble::insFinal(void){
    nodo *nuevo;
    char resp;
    int dato;

    do{
        cout << "Desea ingresar un dato (s/n)? ";
        cin >> resp;
        if(resp == 's'){
            cout << "digite el dato: ";
            cin >> dato;
            nuevo = new nodo;
            nuevo->dato = dato;
            nodo *p = pInicio, *q = NULL;
            if(p != NULL){
                while(p != NULL){
                    q = p;
                    p = p->sig;
                }
                q->sig = nuevo;
                nuevo->sig = NULL;
            }
            else{
                pInicio = nuevo;
                nuevo->sig = NULL;
            }
        }
    }while(resp == 's');
}

void ListaDoble::eliminar(void){
    char resp;
    int dato;

    do{
        cout << "Desea eliminar un dato (s/n)? ";
        cin >> resp;
        if(resp == 's'){
            cout << "Digite el dato: ";
            cin >> dato;
            nodo *p = pInicio, *q = NULL;
            if(pInicio == NULL)
                cout << "La lista esta vacia. Nada que hacer." << endl;
            else{
                if(p->dato == dato){
                    pInicio = pInicio->sig;
                    delete p;
                }
                else{
                    while(p != NULL && p->dato != dato){
                        q = p;
                        p = p->sig;
                    }
                    if(p == NULL)
                        cout << "El dato no se encuentra en la lista" << endl;
                    else{
                        q->sig = p->sig;
                        delete p;
                    }
                }
            }
        }
    }while(resp == 's');
}

void ListaDoble::mostrarLista(void){
    nodo *s1 = pInicio;
    nodo *s2 = NULL;
    while(s1 != NULL){
        cout << s1->dato << "  ";
        s2 = s1;
        s1 = s1->sig;
    }
    cout << endl;
    while(s2 != NULL){
        cout << s2->dato << "  ";
        s2 = s2->ant;
    }
    cout << endl;
}

void ListaDoble::mostrarLista(nodo *p){
    if(p != NULL){
        cout << p->dato << "  ";
        mostrarLista(p->sig);
        cout << p->dato << "  ";
    }
    else
        cout << endl;
}

void ListaDoble::menu(void){
    cout << endl;
    cout << "Las opciones del menu son:" << endl;

    int opcion;
    do{
        cout << "1) Insertar al inicio." << endl
            << "2) Mostrar la lista." << endl
            << "3) Mostrar recursivamente." << endl
            << "4) Mostrar la mayor temperatura." << endl
            << "5) Promedio de las temperaturas registradas." << endl
            << "6) Insertar al final." << endl
            << "7) Insertar antes de un elto." << endl
            << "8) Eliminar elementos." << endl
            << "9) Salir." << endl
            << "Digite su opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                insInicio();
                break;
            case 2:
                mostrarLista();
                break;
            case 3:
                mostrarLista(pInicio);
                break;
            case 4:
                //mostrarMayor();
                break;
            case 5:
                //mostrarPromedio();
                break;
            case 6:
                insFinal();
                break;
            case 7:
                insertar();
                break;
            case 8:
                eliminar();
                break;
        }
    }while(opcion != 9);
}

int main(void){
    cout << endl;
    cout << "ADMINISTRACION DE UNA LISTA LINEAL SIMPLE" << endl << endl;

    ListaDoble miLista;
    miLista.menu();

    cout << endl;
    return 0;
}