// María García Raldúa
// MARP17

#include <iostream>
#include <iomanip>
#include <fstream>
#include "GrafoValorado.h"
#include <algorithm>
#include <vector>
#include <istream>
#include <queue>
#include <string>

using namespace std;

//coste O(E*logE)

bool operator<(const Arista<int> a, const Arista<int> b) {
	return a.valor() > b.valor();
}

class Archipielago {
public:
	Archipielago(const GrafoValorado<int> &g):marked(g.V(),false), dinero(0), isConnected(true),
	conections(0){
		for (int v = 0; v < g.V(); v++) {
			if (!marked[v]) {
				conections++; //lo que hace es que suma uno al principio y si hay una componente fuera del grafo inicial, suma mas de 1
				//y por tanto estaría mal porque nos faltarían puentes
				if (conections > 1) {
					isConnected = false;
					return;
				}
				LazyPrim(g);
			}
			
		}
	
	
	
	}

	int getSolution() {
		return dinero;
	}
	bool isconect() {
		return isConnected;
	}
	

private:
	vector<bool> marked;
	queue<Arista<int>> mst;
	priority_queue<Arista<int>> pq;
	int dinero;
	bool isConnected;
	int conections;

	void LazyPrim(const GrafoValorado<int> &g) {
		visit(g, 0);
		while (!pq.empty() && mst.size() < g.V() - 1) {
			Arista<int> e = pq.top(); pq.pop();
			int v = e.uno();
			int w = e.otro(v);
			if (marked[v] && marked[w]) {
				continue;
			}
			mst.push(e);
			dinero += e.valor();
			if (!marked[v]) {
				visit(g, v);

			}
			if (!marked[w]) {
				visit(g, w);
			}
		}
	}


	void visit(const GrafoValorado<int> &g, int v) {
		marked[v] = true;
		for (auto w : g.ady(v)) {
			if (!marked[w.otro(v)]) {
				pq.push(w);
			}
		}
	}
	
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int I, P;
	cin >> I;
	cin >> P; // islas y puentes
	int v, w, coste;
	if (!cin)
		return false;
	GrafoValorado<int> grafo(I);
	for (int i = 0; i < P; i++) {
		cin >> v >> w >> coste;
		
		grafo.ponArista(Arista<int>(v - 1, w - 1, coste));
	}

	Archipielago chi(grafo);
	if (chi.isconect()) {
		cout << chi.getSolution() << '\n';
	}
	else {
		cout << "No hay puentes suficientes" << '\n';
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

	while (resuelveCaso()) {

	}



	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}