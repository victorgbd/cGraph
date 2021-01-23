#pragma once
#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <stack>
using namespace std;
class arista;
class vertice {
	vertice *sig;
	arista *ady;
	string dato;
	friend class grafo;
};
class arista {
	arista *sig;
	vertice *ady;
	int peso;
	friend class grafo;
};
class grafo {
	vertice *h;
	public:
		void inicializa();
		bool vacio();
		int tamano();
		vertice *get_vertice(string dato);
		void insert_ararista(vertice *origen, vertice *destino, int peso);
		void insert_vertice(string dato);
		void lista_adyasencia();
		void eliminar_arista(vertice *origen, vertice *destino);
		void anular();
		void eliminar_vertice(vertice *vetice);
		void recorrido_en_anchura(vertice *origen);
		void recorrido_en_profundidad(vertice *origen);
};
#endif 
