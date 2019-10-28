// María García Raldúa
// MARP17

#include <iostream>
#include <iomanip>
#include <fstream>
#include "GrafoDirigido.h"
#include <algorithm>
#include <istream>
#include <vector>
#include <queue>
#include <string>

using namespace std;



class Esc_serp {
public:
	Esc_serp(GrafoDirigido const & G): marked(G.V()),disTo(G.V()) {
		
				bfs(G, 0);
		
	

	}
	

	int distMinima() {
		return disTo[disTo.size() - 1];
	}

private:
	vector<bool> marked;
	vector<int> disTo;
	int _min;
	
	void bfs(GrafoDirigido const & G,int s) {
		queue<int> q;
		disTo[s] = 0;
		marked[s] = true;
		q.push(s);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int w : G.ady(v)) {
				if (!marked[w]) {
					disTo[w] = disTo[v] + 1;
					marked[w] = true;
					q.push(w);
				}
			}
		}
	}
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N, K, S, E;
	cin >> N >> K >> S >> E; // número de filas y columnas

	if (!cin || N == 0 && K == 0 && S == 0 && E == 0)
		return false;
	GrafoDirigido g(N*N);
	int v, w;
	for (int i = 0; i < S + E; i++) {
		cin >> v >> w;
		g.ponArista(v - 1, w - 1);
	}

	for (int i = 0; i < g.V(); i++) {
		for (int j = 0; j <= K; j++) {
			if (j + i < g.V()){
				if (g.ady(i + j).size() > 0) {
					int x = g.ady(j + i).at(0);
					g.ponArista(i, x);
				}
				else g.ponArista(i, j + i);
			}
		}
	}
	
	Esc_serp es(g);
	cout << es.distMinima() << '\n';

	
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
