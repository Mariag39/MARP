// María



#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <vector>
//#include "Grafo.h"
using namespace std;

using Grafo = vector<vector<int>>;

class noticias {
public:
	noticias(Grafo const& g): marked(g.size(),false),personas(g.size()) {
		for (int v = 0; v < g.size(); ++v) {
			if (!marked[v]) {
				int nn = 1;
				dfs(g, v, nn);

				personas[v] = nn;
			}
		}
	}

	vector<int> solucion() {
		return personas;
	}
	
private:
	vector<bool> marked;
	vector<int> personas;
	vector<int> size;
	

	void dfs(Grafo const& g, int v, int& nn) {
		marked[v] = true;
		
		for (int w : g[v]) {
			if (!marked[w]) {
				nn++;
				dfs(g, w,nn);
				personas[w] = nn;
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
	int n = 0;
	for (int i = 0; i < E; ++i) {
		cin >> n;
		if (n > 0) {
			cin >> v;
			v--;
			for (int i = 1; i < n; i++) {
				cin >> w;
				w--;
				grafo[v].push_back(w);
				grafo[w].push_back(v);
				v = w;
			}
		}
	}

	noticias g(grafo);
	for (int i = 0; i < g.solucion().size(); i++) {
		cout << g.solucion()[i] << " ";
	}

	cout << '\n';
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