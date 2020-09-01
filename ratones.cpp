// María



#include <iostream>
#include <iomanip>
#include <fstream>
#include <istream>
#include <queue>
#include <vector>
#include <string>
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"
using namespace std;
const int INFINITO = 1000000000;
//O(P log P) siendo P el numero de aristas

class ratones {
public:
	ratones(GrafoDirigidoValorado<int> const& gv, int salida, int t) : marked(gv.V(), false),
		disToD(gv.V(), INFINITO), pq(gv.V()), dest(salida),tiempo(t), n_ratones(0) {
		for (int v = 0; v < gv.V(); ++v) {
			if (v != salida) {
				dijkstra(gv, v);
			}
		}

	}

	int solucion() {
		return n_ratones;
	}

private:
	vector<bool> marked;
	vector<int> disToD;
	IndexPQ<int> pq;
	int dest;
	int tiempo;
	int n_ratones;

	void dijkstra(GrafoDirigidoValorado<int> const& g, int s) {
		disToD[s] = 0;
		pq.push(s, 0);
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			if (v == dest) {
				
				if (disToD[v] <= tiempo) {
					n_ratones++;
								
				}
				break;

			}
			for (auto e : g.ady(v)) {
				relax(e);
			}
		}

	}

	void relax(AristaDirigida<int> e) {
		int v = e.from(), w = e.to();
		if (disToD[w] > disToD[v] + e.valor()) {
			disToD[w] = disToD[v] + e.valor();
			pq.update(w, disToD[w]);
		}
		
		
	}
	
	

	
	
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int N, S,T,P;
	cin >> N >> S >> T >> P;

	if (!std::cin) {
		return false;
	}
	GrafoDirigidoValorado<int> g(N);

	int v, w, val;

	for (int i = 0; i < P; i++) {
		cin >> v >> w >> val;
		g.ponArista({ v - 1,w - 1,val });
	}
	S--;
	ratones r(g, S, T);
	cout << r.solucion() << '\n';



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