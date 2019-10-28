// Maria Garcia Raldua
//MARP17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "GrafoValorado.h"
using namespace std;
//amazon prime por 12 euros
class camiones {
public:
	camiones(GrafoValorado<int> const &g, int origen, int destino, int weight) :marked(g.V(), false), solucion(false),
	dest(destino),anch(weight){
		
				dfs(g,origen);
		
	}

	bool isPosible() {
		return solucion;
	}

private:
	vector<bool> marked;
	int orig;
	int dest;
	bool solucion;
	int anch;

	void dfs(GrafoValorado<int>const & g, int &origen) {
		marked[origen] = true;
		for (auto w : g.ady(origen)) {
			int other = w.otro(origen);
			if (!marked[other] && w.valor() >= anch) {
				if (other == dest) {
					solucion = true;
				}
				else {
					
					dfs(g, other);
				}
			}
		}
	
		
	}
};


bool resuelveCaso() {
	int V, E;
	cin >> V;
	cin >> E;
	if (!cin) {
		return false;
	}
	GrafoValorado<int> g(V);
	int v, w, value;
	for (int i = 0; i < E; ++i) {
		cin >> v >> w >> value;
		Arista<int> temp(v - 1, w - 1, value);
		g.ponArista(temp);
		
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v >> w >> value;
		camiones b(g,v - 1,w - 1, value);
		
		if (b.isPosible()) {
			cout << "SI" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
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
