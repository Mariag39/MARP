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



class camiones {
public:
	camiones(GrafoValorado<int> const& gv, int& orig, int& dest, int& v): marked(gv.V(),false),imposible(true),valor(0) {
		dfs(orig, dest, v,gv);
	}

	bool esimposible() {
		return imposible;
	}

private:
	vector<bool> marked;
	bool imposible;
	int valor;

	void dfs(int o, int d, int val, GrafoValorado<int> const& gv) {
		marked[o] = true;
		for (auto w : gv.ady(o)) {
			if (!marked[w.otro(o)]) {
				if (w.valor() >= val) {
					if (w.otro(o) == d) {
						imposible = false;
					}
					else {
						dfs(w.otro(o), d, val, gv);
					}
				}
				
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
	GrafoValorado<int> g(V);
	int v, w, value;
	for (int i = 0; i < E; i++) {
		cin >> v >> w >> value;
		g.ponArista(Arista<int>(v - 1, w - 1, value));
	}
	int n,o,d,val;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> o >> d >> val;
		o--;
		d--;
		camiones c(g, o, d, val);
		if (!c.esimposible()) cout << "SI" << '\n';
		else cout << "NO" << '\n';
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

	};


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}