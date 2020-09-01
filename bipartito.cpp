﻿// María



#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <vector>
#include "Grafo.h"
using namespace std;

class bipartito {
public:
	bipartito(Grafo const& g) : marked(g.V(), false), colores(g.V(), false),noposible(false) {
		for (int v = 0; v < g.V(); ++v) {
			dfs(g, v);
		}
	}

	bool imposible() {
		return noposible;
	}

private:
	vector<bool> marked;
	vector<bool> colores;
	bool noposible;

	void dfs(Grafo const& g, int v) {
		marked[v] = true;
		for (int w : g.ady(v)) {
			if (!marked[w]) {
				colores[w] = !colores[v];
				dfs(g, w);
			}
			else if(marked[w] && colores[w] == colores[v]) {
				noposible = true;
				return;
			}
			
		}
	}
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int V, E;
	cin >> V >> E;
	if (!std::cin) {

		return false;
	}

	Grafo grafo(V);
	int v, w;
	for (int i = 0; i < E; ++i) {
		cin >> v >> w;
		grafo.ponArista(v, w);
	}
	
	bipartito b(grafo);

	if (b.imposible()) {
		cout << "NO" << '\n';
	}
	else {
		cout << "SI" << '\n';
	}

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}