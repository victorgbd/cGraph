#include "grafo.h"

void grafo::inicializa() 
{
	h = NULL;
}
bool grafo::vacio() {

	return (h == NULL);
}
int grafo::tamano() 
{
	int cont = 0;
	vertice *aux;
	aux = h;
	while (aux != NULL) {
		aux = aux->sig;
		cont++;
	}
	return cont;
}
vertice *grafo::get_vertice(string dato) {
	vertice *aux;
	aux = h;
	while (aux != NULL) {
		if (aux->dato == dato) {
			return aux;
		}
		aux = aux->sig;
	}
	return NULL;
}
void grafo::insert_vertice(string dato) {
	vertice *nuevo = new vertice;
	nuevo->dato = dato;
	nuevo->sig = NULL;
	nuevo->ady = NULL;
	vertice *aux;
	aux = h;
	if (vacio()) {//llama a funcion vacio si la lista de vertice esta vacia
		h = nuevo;
	}
	else {//si no recorrer hasta el ultimo vertice y parar while antes de el final
		while (aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
}
void grafo::insert_ararista(vertice *origen, vertice *destino, int peso) {
	arista *nuevo = new arista;
	nuevo->peso = peso;
	nuevo->sig = NULL;
	nuevo->ady = NULL;
	arista *aux;
	aux = origen->ady;
	//cout << "el origen no tiene aristas" << endl;
	if (aux == NULL) {
		origen->ady = nuevo;
		nuevo->ady = destino;
	}
	else {
		while (aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
		nuevo->ady = destino;
	}
}
void grafo::lista_adyasencia() {
	vertice *veraux;
	arista *ariaux;
	veraux = h;
	while (veraux != NULL) {
		cout<<veraux->dato<<"->";
		ariaux = veraux->ady;
		while (ariaux != NULL) {
			cout << ariaux->ady->dato <<"->";
			ariaux = ariaux->sig;
		}

		veraux = veraux->sig;
		cout << endl;
	}
}
void grafo::anular() {
	vertice *aux;
	while (h != NULL) {
		aux = h;
		h = h->sig;
		delete (aux);
	}
}
void grafo::eliminar_vertice(vertice * vert)
{
	vertice *actual;
	vertice *anterior = new vertice;
	arista *aux;
	actual = h;
	while (actual!=NULL)
	{
		aux = actual->ady;
		while (aux!=NULL)
		{
			if (aux->ady == vert) {
				eliminar_arista(actual, aux->ady);
				break;
			}
			aux = aux->sig;
		}
		actual = actual->sig;
	}
	actual = h;
	if (h == vert) {
		h = h->sig;
		delete(actual);
	}
	else {
		while (actual != vert)
		{
			anterior = actual;
			actual = actual->sig;
		}
		anterior->sig = actual->sig;
		delete(actual);
	}
}
void grafo::recorrido_en_profundidad(vertice * origen)
{
	int flag = 0, flag2 = 0;
	vertice* actual;
	stack<vertice*> pila;
	list<vertice*> lista;
	list<vertice*>::iterator i;
	pila.push(origen);
	while (!pila.empty()) {
		actual = pila.top();
		pila.pop();
		for (i = lista.begin(); i != lista.end(); i++) {
			if (*i == actual) {
				flag = 1;
			}
		}
		if (flag == 0) {
			cout << actual->dato << ", ";
			lista.push_back(actual);
			arista* aux;
			aux = actual->ady;
			while (aux != NULL) {
				flag2 = 0;
				for (i = lista.begin(); i != lista.end(); i++) {
					if (aux->ady == *i) {
						flag2 = 1;
					}
				}
				if (flag2 == 0) {
					pila.push(aux->ady);
				}
				aux = aux->sig;

			}
		}
	}
}
void grafo::recorrido_en_anchura(vertice * origen)
{
	int flag = 0, flag2 = 0;
	vertice *actual;
	queue<vertice*> cola;
	list<vertice*> lista;
	list<vertice*>::iterator i;
	cola.push(origen);
	while (!cola.empty()) {
		flag = 0;
		actual = cola.front();
		cola.pop();
		for (i = lista.begin(); i != lista.end(); i++) {
			if (*i == actual) {
				flag = 1;
			}
		}
		if (flag == 0) {
			cout << actual->dato<< ", ";
			lista.push_back(actual);
			arista *aux;
			aux = actual->ady; 
			while (aux != NULL) {
				flag2 = 0;
				for (i = lista.begin(); i!=lista.end(); i++) {
					if (aux->ady == *i) {
						flag2 = 1;
					}
				}
				if (flag2 == 0) {
					cola.push(aux->ady);
				}
				aux = aux->sig;

			}
		}
	}
}
void grafo::eliminar_arista(vertice *origen, vertice *destino) {
	int flag = 0;
	arista *actual = new arista;
	arista *anterior = new arista;
	actual = origen->ady;
	if (actual == NULL) {
		cout << "el vertice actual no tiene aristas" <<endl ;
	}
	//para la primera arista
	else if (actual->ady == destino) {
		origen->ady = actual->sig;
		delete(actual);
	}
	else {
		while (actual != NULL) {
			if(actual->ady == destino) {
				flag = 1;
				anterior->sig = actual->sig;
				delete(actual);
				break;
			}
			anterior = actual;
			actual = actual->sig;
		}
		
		if (flag == 0) {
			cout <<"los vertices no estan enlazados" << endl;
		}
		
	}
}