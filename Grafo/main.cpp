#include "grafo.h"
#include <iostream>
int main() {
	grafo g;
	g.inicializa();
	g.insert_vertice("a");
	g.insert_vertice("b");
	g.insert_vertice("c");
	g.insert_vertice("d");
	g.insert_vertice("e");
	g.insert_vertice("f");
	g.insert_vertice("g");
	g.insert_ararista(g.get_vertice("a"), g.get_vertice("a"), 13);
	g.insert_ararista(g.get_vertice("a"), g.get_vertice("d"), 8);
	g.insert_ararista(g.get_vertice("b"), g.get_vertice("b"), 52);
	g.insert_ararista(g.get_vertice("b"), g.get_vertice("c"), 17);
	g.insert_ararista(g.get_vertice("b"), g.get_vertice("d"), 83);
	g.insert_ararista(g.get_vertice("b"), g.get_vertice("f"), 97);
	g.insert_ararista(g.get_vertice("b"), g.get_vertice("g"), 60);
	g.insert_ararista(g.get_vertice("c"), g.get_vertice("a"), 4);
	g.insert_ararista(g.get_vertice("d"), g.get_vertice("b"), 97);
	g.insert_ararista(g.get_vertice("d"), g.get_vertice("c"), 37);
	g.insert_ararista(g.get_vertice("d"), g.get_vertice("d"), 22);
	g.insert_ararista(g.get_vertice("d"), g.get_vertice("e"), 41);
	g.insert_ararista(g.get_vertice("d"), g.get_vertice("g"), 64);
	g.insert_ararista(g.get_vertice("e"), g.get_vertice("b"), 8);
	g.insert_ararista(g.get_vertice("e"), g.get_vertice("e"), 45);
	g.insert_ararista(g.get_vertice("e"), g.get_vertice("f"), 92);
	g.insert_ararista(g.get_vertice("f"), g.get_vertice("a"), 12);
	g.insert_ararista(g.get_vertice("f"), g.get_vertice("b"), 8);
	g.insert_ararista(g.get_vertice("f"), g.get_vertice("e"), 42);
	g.insert_ararista(g.get_vertice("g"), g.get_vertice("d"), 17);
	g.recorrido_en_anchura(g.get_vertice("b"));
	cout << endl;
	g.recorrido_en_profundidad(g.get_vertice("b"));
	cout << endl;
	g.lista_adyasencia();
	cout << g.tamano() << endl;
	cout << endl;
	g.eliminar_arista(g.get_vertice("b"), g.get_vertice("f"));
	g.lista_adyasencia();
	cout << endl;
	g.eliminar_vertice(g.get_vertice("b"));
	g.lista_adyasencia();
	//cout << g.tamano() << endl;
	system("pause");
	return 0;
}