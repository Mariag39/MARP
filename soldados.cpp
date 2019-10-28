// María García Raldúa
// MARP17

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Grafo.h"
#include <algorithm>

using namespace std;

class minimo_soldado {
public:
	bool esposible;
	int minimo;
	int falso;
	minimo_soldado(Grafo const& g):marked(g.V(), false), num_minimo(0),
	v_cruces(g.V(),false),esposible(true), num(0){
		for (int v = 0; v < g.V(); ++v) {
			 minimo = 0;
			 falso = 0;
			if (!marked[v]) {
				++falso;
				dfs(g, v);
				
			}
			num += min(minimo,falso) ;
		}
	}
	int get_minimo() {
		return num;
	}
	
private:
	vector<bool> marked;
	vector<bool> v_cruces;
	int num_minimo;
	int num;
	void dfs(Grafo const& g, int v) {
		marked[v] = true;
		
		for (int w : g.ady(v)) {
			if (!marked[w]) {
				v_cruces[w] = !v_cruces[v];
				if (v_cruces[w])
					minimo++;
				else
					falso++;
				dfs(g, w);
			}
			else if (marked[w] && v_cruces[w] == v_cruces[v]) {
				esposible = false;
			}
		}
		
	}


};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int V, c;
	cin >> V;
	cin >> c;
	Grafo g(V);
	if (!std::cin)
		return false;
	int v, w;
	for (int i = 0; i < c; ++i) {
		cin >> v >> w;
		g.ponArista(v - 1, w - 1);
	}

	minimo_soldado s(g);
	//cout << s << endl;
	if (!s.esposible) {
		cout << "IMPOSIBLE" << endl;
	}
	else {
		cout << s.get_minimo() << endl;
	}
	
	

	
	// escribir sol


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
