// Maria Garcia Raldua
//MARP17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Grafo.h"
using namespace std;

class bipartito {
public:
	bipartito(Grafo const& g):marked(g.V(),false),v_azul(g.V(),false),
	v_naranja(g.V(),false),nar(0),azul(0), imposible(false){
		for (int v = 0; v < g.V(); ++v) {
			if (!marked[v]) {
				dfs(g,v);
			}
		}
	}

	bool isPosible() {
		return imposible;
	}

private:
	vector<bool> marked;
	vector<bool> v_azul;
	vector<bool> v_naranja;
	int nar, azul;
	bool imposible;
	void dfs(Grafo const& g, int v) {
		marked[v] = true;
		for (auto w : g.ady(v)) {
			if (!marked[w]) {
				v_azul[w] = !v_naranja[v];
				if (v_azul[w]) {
					azul++;
				}
				dfs(g, w);
			}
			else if (marked[w] && v_azul[w] == v_naranja[v]) {
				imposible = true;
			}
		}
	}
};


bool resuelveCaso() {
	int V,E;
	cin >> V;
	cin >> E;
	if (!cin) {
		return false;
	}
	Grafo g(V);
	int v, w;
	for (int i = 0; i < E; ++i) {
		cin >> v >> w;
		g.ponArista(v, w);
	}

	bipartito b(g);
	if (!b.isPosible()) {
		cout << "SI" << '\n';
	}
	else {
		cout << "NO" << '\n';
	}
	return true;
}


int main() {
	// Para la entrada por fichero.
 //Comentar para acepta el reto
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
