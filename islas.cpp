// María



#include <iostream>
#include <iomanip>
#include <fstream>
#include <istream>
#include <queue>
#include <vector>
#include "Grafo.h"
#include <string>
#include "GrafoValorado.h"
using namespace std;

//O(P log P) siendo P el numero de aristas

class islas {
public:
	islas(GrafoValorado<int> const& gv): marked(gv.V(),false), noposible(false), coste(0),conectados(0) {
		for (int i = 0; i < gv.V(); i++) {
			if (!marked[i]) {
				conectados++;
				if (conectados > 1) {
					noposible = true;
					return;
				}
				LazyPrim(gv);
			}
		}
		

		
	}

	bool imposible() { return noposible; }

	int total() { return coste; }

private:
	vector<bool> marked;
	queue<Arista<int>> mst;
	priority_queue<Arista<int>,vector<Arista<int>>, greater<Arista<int>>> pq;
	int coste;
	int conectados;
	bool noposible;

	void LazyPrim(GrafoValorado<int> const& gv) {
		visit(gv, 0);
		while (!pq.empty() && mst.size() < gv.V() - 1) {
			Arista<int> e = pq.top(); pq.pop(); 
			int v = e.uno(), w = e.otro(v);
			if (marked[v] && marked[w]) {
				continue;
			}
			mst.push(e);
			coste += e.valor();
			if (!marked[v]) visit(gv, v);
			if (!marked[w]) visit(gv, w);
		}
	}

	void visit(GrafoValorado<int> const& gv, int v) {
		marked[v] = true;
		for (Arista<int> e : gv.ady(v)) {
			if (!marked[e.otro(v)]) {
				
				pq.push(e);

			}
		}
	}

};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int I, P;
	cin >> I >> P;

	if (!std::cin) {
		return false;
	}

	GrafoValorado<int> g(I);

	int v, w,val;
	for (int i = 0; i < P; i++) {
		cin >> v >> w >> val;
		g.ponArista(Arista<int>(v - 1, w - 1, val));
	}
	islas i(g);
	if (i.imposible()) cout << "No hay puentes suficientes" << '\n';
	else cout << i.total() << '\n';

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

	};


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}