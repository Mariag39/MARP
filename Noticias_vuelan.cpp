// Maria Garcia Raldua
//MARP17

//coste O(E + V) siendo E el número de aristas y V el número de vértices
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "ConjuntosDisjuntos.h"


using namespace std;
using Grafo = vector<vector<int>>;
class noticias {
public:
	vector<int> resultados;
	noticias(Grafo const& g) :marked(g.size(), false),component_(g.size()) {
		for (int v = 0; v < g.size(); v++) {
			
			if (!marked[v]) {
				
				int tam = dfs(g, v);
				sizes_.push_back(tam);
			}
			
		}
	}
	int solucion(int v) {
		return sizes_[component_[v]];
	}

	
private:
	vector<bool> marked;
	int numero;
	vector<int> component_;
	vector<int> sizes_;

	int dfs(Grafo const& g, int v) {
		int t = 1;
		marked[v] = true;
		component_[v] = sizes_.size();
		for (auto w : g[v]) {
			if (!marked[w]) {
				t += dfs(g, w);
				
			}
			
		}
		return t;
	}
};


bool resuelveCaso() {
	int V, E;
	cin >> V;
	cin >> E;
	if (!cin) {
		return false;
	}
	Grafo g(V);
	
	int n = 0;
	int v, u = 0;
	for (int i = 0; i < E; i++) {
		cin >> n;
		if (n > 0) {
			cin >> u;
			u--;
			for (int j = 1; j < n; j++) {
				cin >> v;
				v--;
				g[u].push_back(v);
				g[v].push_back(u);
				u = v;
			}
		}
	
	}
	
	noticias b(g);
	for (int i = 0; i < g.size(); i++) {
		cout << b.solucion(i) << ' ';
	}
	cout << '\n';
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
