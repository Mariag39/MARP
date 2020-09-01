// María



#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <vector>
#include "Grafo.h"
using namespace std;

class guardias {
public:
	guardias(Grafo const& g) : marked(g.V(), false),guards(g.V(),false),numguardsno(0),numguardssi(0), imposible(false),
	maximo(0){
		for (int v = 0; v < g.V(); ++v) {
			numguardssi = 0;
			numguardsno = 0;
			if (!marked[v]) {
				numguardsno++;
				dfs(g, v, numguardssi, numguardsno);
			}
			maximo += min(numguardssi, numguardsno);
		}
	}

	void solucion() {
		if (imposible) {
			cout << "IMPOSIBLE" << '\n';
		}
		else
			cout << maximo << '\n';
	}

private:
	vector<bool> marked;
	vector<bool> guards;
	bool imposible;
	int maximo;
	int numguardssi;
	int numguardsno;

	void dfs(Grafo const& g, int v, int& n, int& no) {
		marked[v] = true;
		for (int w : g.ady(v)) {
			if (!marked[w]) {
				guards[w] = !guards[v];
				if (guards[w])
					n++;
				else
					no++;
				dfs(g, w,n,no);
			}
			else if (marked[w] && guards[w] == guards[v]) {
				imposible = true;
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
		grafo.ponArista(v - 1, w - 1);
	}

	guardias g(grafo);
	g.solucion();
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